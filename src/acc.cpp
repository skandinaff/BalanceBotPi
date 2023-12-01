#include <iostream>
#include <unistd.h>
#include <linux/i2c-dev.h>
#include "../include/acc.h"
#include "../drivers/MMA7455.h"

// Assuming MMA7455 class and related constants are defined elsewhere
// ...
MMA7455 mma;

void setup_acc() {
    // The address can be changed making the option of connecting multiple devices
    mma.getAddr_MMA7455(MMA7455_DEFAULT_ADDRESS_ACCEL); // 0x1D

    // The Accelerometer's Measurement Range can be changed via the following function:
    mma.setAccelRange(ACCEL_RANGE_2G); // 2 g

    
    mma.begin();

    mma.setUpAccelerometer();
    //usleep(1000000); // 1 second delay
}

void loop_acc() {
    uint8_t error;
    int8_t address;

    // MMA7455 Accelerometer Address
    //address = mma.mma_i2cAddress;

    // The i2c_scanner uses the return value of
    // the Write.endTransmisstion to see if
    // a device did acknowledge to the address.
    
    if (ioctl(mma.geti2cFile(), I2C_SLAVE, mma.mma_i2cAddress) < 0) {
        perror("Failed to acquire bus access and/or talk to slave");
        exit(1);
    }

    //error = write(i2cFile, &address, 1);
    //if (error == 0) {
        std::cout << "Getting Acceleration Data Readings from MMA7455" << std::endl;
        std::cout << std::endl;

        // Set up the sensor for Accelerometer

        //usleep(5000); // 500ms delay

        // Display the results for Acceleration
        mma.Measure_Accelerometer();

        // Output Data to Screen
        std::cout << "Acceleration in X-Axis: " << mma.mma_accelData.X << std::endl;
        std::cout << "Acceleration in Y-Axis: " << mma.mma_accelData.Y << std::endl;
        std::cout << "Acceleration in Z-Axis: " << mma.mma_accelData.Z << std::endl;
        std::cout << std::endl;
        std::cout << "        ***************************        " << std::endl;
        std::cout << std::endl;
        //usleep(1000000); // 1 second delay
    /*
    }
     else {
        std::cout << "MMA7455 Disconnected!" << std::endl;
        std::cout << std::endl;
        std::cout << "        ************        " << std::endl;
        std::cout << std::endl;
    }
    */
    //usleep(1000000); // 1 second delay
    usleep(100000); // 1 second delay
}
