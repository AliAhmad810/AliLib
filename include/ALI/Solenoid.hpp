#pragma once
#include "api.h"

namespace ali {

class Solenoid {

public:

    /**
     * @brief Solenoid constructor
     * 
     * @param port port that the solenoid is connected to
     * @param initState initial state of the pneumatic cylinder
    */
    Solenoid(char port, bool initState = false);

    /**
     * @brief Destroys the Solenoid object
    */
    ~Solenoid() = default;

    /**
     * @brief Toggles the solenoid state
    */
    void toggle();

    /**
     * @brief Sets the state of the solenoid object
     * 
     * @param state state to set the solenoid to
    */
    void setState(bool state);

    /**
     * @brief Returns the state of the solenoid object
     * 
     * @return if the cylinder is extended or not
    */
    bool getState() const;

private:

    bool _state;
    pros::ADIDigitalOut _cylinder;

};

} // namespace ali