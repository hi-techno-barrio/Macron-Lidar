#include <ros/ros.h>
#include <sensor_msgs/LaserScan.h>
#include <iostream>
#include <wiringPi.h>
#include <stdlib.h>

extern "C" int lidar_init(bool);
extern "C" int lidar_read(int);

#define PIN16 23
#define PIN18 24

//PIN16 is the pin #16 on the pi diagram
// use for setting up the motorcontroller

//PIN18 is the pin #18 on the pi diagram
// use for controlling the steps

void setUpPins(){
    system("gpio export 23 out");
    system("gpio export 24 out");
    system("gpio -g write 23 1");
}

void step(int steps){
    for(int i = 0; i<steps; i++){
        system("/home/ubuntu/gpioThing.sh");
    }
}

int main(int argc, char** argv){
    int fd = lidar_init(false);//set to true for printouts
    setUpPins();
    // If init failed
    if (fd == -1) {
        printf("initialization error\n");
    }

    ros::init(argc, argv, "laser_scan");

    ros::NodeHandle n;
    ros::Publisher scan_pub = n.advertise<sensor_msgs::LaserScan>("scan", 10);

    const unsigned int num_readings = 200; //number of readings in one packet.
    const unsigned int num_steps = 1;
    const double laser_frequency = 0.5/*MIGHT CHANGE*/; //how many spins in one second
    const unsigned short circle_segments = 1;
    const double pi = 3.141592;

    int i = 0;
    while(n.ok()){
        ros::Time scan_time = ros::Time::now();

        //sets up the relevant info about the laser
        sensor_msgs::LaserScan scan;
        scan.header.frame_id = "laser";
        scan.angle_min = i*((2.0/circle_segments)*pi); // angles in radians
        scan.angle_max = (++i)*((2.0/circle_segments)*pi);
        scan.angle_increment = 2*pi / (200/num_steps);
        scan.time_increment = (1 / laser_frequency) / (num_readings); //time between measurements in seconds
        scan.range_min = 0.1;//the distance range. in meters
        scan.range_max = 40.0;//set to 40 or less for our laser
        scan.scan_time = 0.02;
        scan.header.stamp = scan_time;

        //publish the data to /scan
        scan.ranges.resize(num_readings);
        for(unsigned int i = 0; i < num_readings; ++i){
            step(num_steps);
            scan.ranges[i] = lidar_read(fd)/100.0;
        }

        scan_pub.publish(scan);
    }
}
