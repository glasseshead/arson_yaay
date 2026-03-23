#include "main.h"
#include "lemlib/api.hpp" // IWYU pragma: keep
#include "objects.hpp"
#include "intake.hpp"
#include "descore.hpp"
#include "matchloader.hpp"
#include "midgoal.hpp"
#include "tasks.hpp"

void initTasks() {
    pros::Task intakeTask(runIntake, "intake/outtake task");
    pros::Task intakeTask(runScore, "score task");
    pros::Task descoreTask(runDescore, "descore wing task");
    pros::Task descoreTask(runMatchLoader, "matchloader task");
    pros::Task descoreTask(runMidGoal, "mid goal task");
}