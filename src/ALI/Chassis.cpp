#include "ALI/api.hpp"

namespace ali {

Telemetry::Telemetry (pros::Imu* imu) 
    : _imu(imu) 
    {}
    
Drivetrain::Drivetrain(pros::MotorGroup* leftMotors, pros::MotorGroup* rightMotors, float wheelDiameter, float gearRatio, float trackWidth)
    : _leftMotors(leftMotors),
      _rightMotors(rightMotors),
      _wheelDiameter(wheelDiameter),
      _gearRatio(gearRatio),
      _trackWidth(trackWidth)
    {}

Chassis::Chassis(Telemetry telemetry, Drivetrain drivetrain) 
    : _telemetry(telemetry),
      _drivetrain(drivetrain)
    {}


} // namespace ali