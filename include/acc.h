#pragma once
#include <iostream>
#include <unistd.h>
#include <linux/i2c-dev.h>
#include "../include/acc.h"
#include "../drivers/MMA7455.h"

class Accelerometer {
public:
    //Accelerometer(){};  // Constructor to initialize the control variable
    void setup();
    void loop();
    void startLoop(); // Method to start the loop
    void stopLoop();  // Method to stop the loop

private:
    MMA7455 mma; // Assuming MMA7455 class is defined in MMA7455.h
    bool continueLoop; // Control variable for the loop
};