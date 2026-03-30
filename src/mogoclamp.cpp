#include "mogoclamp.hpp"

// reset mobile goal clamp values

// was mobile goal clamp toggled just now?
// no, so it is false
bool MoGoClampPressed = false;
int MoGoClampState = 0;

void updateMoGoClamp() {
    // state = 0: down
    // state = 1: up

    // if mobile goal clamp control is pressed
    if (controller.get_digital(MoGoClampControl)) {
        if (!MoGoClampPressed) {
            // if mobile goal clamp is down put it up
            if(MoGoClampState == 0) {
                MoGoClampState = 1;
            }

            // if mobile goal clamp is up put it down
            else {
                MoGoClampState = 0;
            }
        }
        // mobile goal clamp was just toggled just now
        MoGoClampPressed = true;

    } 
    // mobile goal clamp was not toggled just now
    else {
        MoGoClampPressed = false;
    }
}

void runMoGoClamp() {
    while (true) {
        // based on our mobile goal clamp state, we toggle it up or down
        switch (MoGoClampState) {
            // mobile goal clamp up
            case 0:
                MoGoClampPistons.set_value(false);
            // mobile goal clamp down
            case 1:
                MoGoClampPistons.set_value(true);
        }
    }
}