#include "ALI/api.hpp"

namespace ali {

Solenoid::Solenoid(char port, bool initState = false): _cylinder(port), _state(initState){
    _cylinder.set_value(_state);
}

void Solenoid::toggle() {
    _state = !_state;
    _cylinder.set_value(_state);
}

void Solenoid::setState(bool state) {
    _state = state;
    _cylinder.set_value(_state);
}

bool Solenoid::getState() const{
    return _state;
}

} // namespace ali