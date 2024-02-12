#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "../../src/controller/ControllerImpl.h"
#include "../../src/model/Task.h"
#include "../../src/observer/ObserverImpl.h"

TEST_CASE("Unit Tests") {
    SECTION("TaskController") {
        TaskControllerImpl controller;
        ConcreteObserver observer;
        controller.addObserver(&observer);

        SECTION("Add Observer") {
            REQUIRE(controller.getObservers().size() == 1);
        }

        SECTION("Update Task Status") {
            controller.updateTaskStatus(true);
            REQUIRE(controller.getModel().getCompleted() == true);
        }

        SECTION("Assign Task to User") {
            Task task("Sample Task");
            User user("John Doe");

            controller.assignTask(task, user);
            REQUIRE(task.getAssignedUser().getName() == user.getName());
        }
    }

    SECTION("Task Model") {
        Task task("Sample Task");

        SECTION("Get Description") {
            REQUIRE(task.getDescription() == "Sample Task");
        }

        SECTION("Get and Set Completed Status") {
            REQUIRE(task.getCompleted() == false);

            task.setCompleted(true);
            REQUIRE(task.getCompleted() == true);
        }
    }

    SECTION("Observer") {
        ConcreteObserver observer;
        Task task("Sample Task");

        SECTION("Observer Task Update") {
            observer.taskUpdated(task);
            REQUIRE(observer.getUpdatedTask().getDescription() == "Sample Task");
        }
    }
}
