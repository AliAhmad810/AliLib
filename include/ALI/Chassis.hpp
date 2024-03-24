#pragma once
#include "api.h"

namespace ali {

/**
 * @brief Struct containing all telemetry devices of the drivetrain
*/
struct Telemetry {
    /**
     * Full telemetry configuration of the robot
     * Variables are passed in as pointers so devices that aren't used can be written as `nullptr`
     * This allows the Chassis class to only use one constructor
     * 
     * @param _imu pointer to the IMU sensor
    */
    Telemetry(pros::Imu* imu);
    pros::Imu* _imu;
};

/**
 * @brief Struct containing all drivetrain parameters
*/
struct Drivetrain{ 
    /**
     * Full drivetrain configuration of the robots. Values from this struct will be used
     * to calculate necessary units for odometry, movements, etc. Values set to 0 will 
     * be ignored.  
     * 
     * @param _leftMotors pointer to left drivetrain motor group
     * @param _rightMotors pointer to right drivetrain motor group
     * @param _wheelDiameter diameter of the drivetrain wheels, in inches
     * @param _gearRatio gear ratio formatted (wheel / motor)
     * @param _trackWidth center-to-center distance of the wheels on each side of the drivetrain, in inches
    */
    Drivetrain(pros::MotorGroup* leftMotors, pros::MotorGroup* rightMotors, float wheelDiameter, float gearRatio, float trackWidth);
    pros::MotorGroup* _leftMotors;
    pros::MotorGroup* _rightMotors;
    float _wheelDiameter;
    float _gearRatio;
    float _trackWidth;
};

class Chassis {

public:

    /**
     * @brief Chassis constructor
    */
    Chassis(Telemetry telemetry, Drivetrain drivetrain);

    /**
     * @brief Destroys the Chassis object
    */
    ~Chassis() = default;

private:

    Telemetry _telemetry;
    Drivetrain _drivetrain;

};

} // namespace ali