#include "main.h"
#include "lemlib/api.hpp" // IWYU pragma: keep
#include "objects.hpp"
#include "tasks.hpp"
#include "intake.hpp"
#include "descore.hpp"
#include "matchloader.hpp"
#include "midgoal.hpp"
#include "score.hpp"
#include "trapdoor.hpp"

void on_center_button() {
	static bool pressed = false;
	pressed = !pressed;

	if (pressed) {
		pros::lcd::set_text(2, "Center Button is Pressed");
	} 

	else {
		pros::lcd::clear_line(2);
	}
}

void initialize() {
	pros::lcd::initialize();
	pros::lcd::set_text(1, "arson, yaaay!");

	pros::lcd::register_btn1_cb(on_center_button);

	initTasks();
}

void disabled() {

}

void competition_initialize() {

}

void autonomous() {
	// ZERO 33.6 106.19999999999999 0.0
	chassis.setPose(0, 0, 0, 700);
	chassis.moveToPose(0.0, 0.0, 0.0, 700);
	chassis.moveToPose(-1.5, -51.599999999999994, 0.0, 700);
	chassis.moveToPose(39.9, -64.8, 0.0, 700);
	chassis.moveToPose(27.0, -18.9, 0.0, 700);
	chassis.moveToPose(-32.699999999999996, -28.799999999999997, 0.0, 700);
	chassis.moveToPose(59.099999999999994, -46.199999999999996, 0.0, 700);
}

void opcontrol() {
	while (true) {
		// for those who aren't familiar with aircraft controls:
		// throttle is forward power
		// rudder is your yaw/turn
		int throttle = controller.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y);
        int rudder = controller.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_X);

        // standard movement
        chassis.arcade(throttle, rudder);

		updateIntake();
		updateScore();
		updateDescore();
		updateMidGoal();
		updateMatchLoader();
		updateTrapdoor();

		// standard wait 10 ms
		pros::delay(10);  
	}
}