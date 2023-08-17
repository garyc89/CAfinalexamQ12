#include "mbed.h"
#include "LSM6DSLSensor.h"

DevI2C devI2c(p9, p10);
LSM6DSLSensor acc_gyro(&devI2c, LSM6DSL_ACC_GYRO_I2C_ADDRESS_LOW);

PwmOut redLED(p23);
PwmOut greenLED(p24);
PwmOut blueLED(p25);

int main() {
    acc_gyro.init(NULL);
    acc_gyro.enable_x();
    acc_gyro.enable_g(); 

    while (true) {
        int32_t accelerometer[3] = {0};
        acc_gyro.get_x_axes(accelerometer);

        float x = accelerometer[0] / 32768.0f;
        float y = accelerometer[1] / 32768.0f;
        float z = accelerometer[2] / 32768.0f;

        redLED = (x + 1.0) / 2.0;  
        greenLED = (y + 1.0) / 2.0;
        blueLED = (z + 1.0) / 2.0;

        wait(0.01);
    }
}
