#pragma once
#include "main.h"
#include "objects.hpp"

// intake state
extern int intakeState;

// intake toggled/pressed
extern bool intakePressed;

// initializing update and run functions for intake
void updateIntake();
void runIntake();