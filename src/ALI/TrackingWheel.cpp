#include "ALI/api.hpp"

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
  if(this->_rotation != nullptr) {
    _rotation->reset_position();
  } 
  else if(this->_encoder != nullptr) {
    _encoder->reset();
  } 
  else if(this->_motors != nullptr) {
    _motors->tare_position();
  } 
}

float TrackingWheel::getDistanceTraveled() {
  if(this->_encoder != nullptr) {
    return (float(this->_encoder->get_value()) * this->_wheelDiameter * M_PI / 360) / this->_gearRatio;
  } 
  else if(this->_encoder != nullptr) {
    return (float(this->_rotation->get_position()) * this->_wheelDiameter * M_PI / 36000) / this->_gearRatio;
  } 
  else { // if  not an ADI encoder or rotation sensor, use motors
    std::vector<pros::motor_gearset_e_t> motorRPM = this->_motors->get_gearing();
    
  }
}

float TrackingWheel::getOffset() {
    return _distance;
}

}