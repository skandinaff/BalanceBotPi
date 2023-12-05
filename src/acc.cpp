#include "../include/acc.h"

void Accelerometer::setup() {
    mma.getAddr_MMA7455(MMA7455_DEFAULT_ADDRESS_ACCEL); // 0x1D
    mma.setAccelRange(ACCEL_RANGE_2G); // 2 g
    mma.begin();
    mma.setUpAccelerometer();
}

void Accelerometer::startLoop() {
    continueLoop = true;
    loop();
}

void Accelerometer::stopLoop() {
    continueLoop = false;
}

void Accelerometer::loop() {
    uint8_t error;
    int8_t address;

    if (ioctl(mma.geti2cFile(), I2C_SLAVE, mma.mma_i2cAddress) < 0) {
        perror("Failed to acquire bus access and/or talk to slave");
        exit(1);
    }
    while(continueLoop) {
        mma.Measure_Accelerometer();
        /*
        std::cout << "Getting Acceleration Data Readings from MMA7455" << std::endl;
        std::cout << std::endl;
        // Output Data to Screen
        std::cout << "Acceleration in X-Axis: " << mma.mma_accelData.X << std::endl;
        std::cout << "Acceleration in Y-Axis: " << mma.mma_accelData.Y << std::endl;
        std::cout << "Acceleration in Z-Axis: " << mma.mma_accelData.Z << std::endl;
        std::cout << std::endl;
        std::cout << "        ***************************        " << std::endl;
        std::cout << std::endl;
        */
        printf("X: %d, Y: %d, Z: %d\n", mma.mma_accelData.X, mma.mma_accelData.Y, mma.mma_accelData.Z );

        usleep(250000); // 0.25 second delay
    }
}