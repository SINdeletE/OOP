//
// Created by nuelex on 28/05/25.
//

#include "ElevatorSystem.hpp"

ElevatorSystem::ElevatorSystem()
{
    for (int i = 0; i < ELEVATORS; ++i)
        _elevators.push_back(std::make_shared<Elevator>());
}

