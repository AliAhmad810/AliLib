#include "TrackingWheel.hpp"

namespace ali {

TrackingWheel::TrackingWheel(pros::MotorGroup* motors, float wheelDiameter, float distance, float gearRatio = 1.0) 
    : _motors(motors),
      _wheelDiameter(wheelDiameter),
      _distance(distance),
      _gearRatio(gearRatio)
    {}

TrackingWheel::TrackingWheel(pros::ADIEncoder* encoder, float wheelDiameter, float distance, float gearRatio = 1.0) 
  : _encoder(encoder),
    _wheelDiameter(wheelDiameter),
    _distance(distance),
    _gearRatio(gearRatio)
  {}

TrackingWheel::TrackingWheel(pros::Rotation* rotation, float wheelDiameter, float distance, float gearRatio = 1.0) 
  : _rotation(rotation),
    _wheelDiameter(wheelDiameter),
    _distance(distance),
    _gearRatio(gearRatio)
  {}

void TrackingWheel::reset() {
  if(_rotation != nullptr) {
    _rotation->reset_position();
  } 
  else if(_encoder != nullptr) {
    _encoder->reset();
  } 
  else if(_motors != nullptr) {
    _motors->tare_position();
  } 
}

float TrackingWheel::getAverageMotorPosition() {
  std::vector<double> motorPositions = _motors->get_positions();
  float total = 0;
  for(float motorPosition : motorPositions) {
    total += motorPosition;
  }
  return total / motorPositions.size();
}

float TrackingWheel::getDistanceTraveled() {
    if(_encoder != nullptr) {

  } else if(_encoder != nullptr) {

  } else { // if the wheel is not an ADI encoder or rotation sensor, we use motors
    
  }
}

float TrackingWheel::getOffset() {
    return _distance;
}

}