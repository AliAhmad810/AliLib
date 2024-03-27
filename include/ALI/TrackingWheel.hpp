#pragma once
#include "api.h"

namespace ali {
    
class TrackingWheel {

public:

    TrackingWheel(pros::MotorGroup* motors, float wheelDiameter, float distance, float gearRatio = 1.0);

    TrackingWheel(pros::ADIEncoder* encoder, float wheelDiameter, float distance, float gearRatio = 1.0);

    TrackingWheel(pros::Rotation* rotation, float wheelDiameter, float distance, float gearRatio = 1.0);

    ~TrackingWheel() = default;

    void reset();

    float getDistanceTraveled();

    float getOffset();

private:
    pros::MotorGroup* _motors;
    pros::ADIEncoder* _encoder;
    pros::Rotation* _rotation;
    float _wheelDiameter;
    float _distance;
    float _gearRatio;

    float getAverageMotorPosition();
};

} // namespace ali