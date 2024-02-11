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
            // Verifique se o observador foi adicionado corretamente ao controlador
            REQUIRE(controller.getObservers().size() == 1);
        }

        SECTION("Update Task Status") {
            controller.updateTaskStatus(true);
            // Verifique se o status da tarefa foi atualizado corretamente
            REQUIRE(controller.getModel().getCompleted() == true);
        }
    }

    SECTION("Task Model") {
        Task task("Sample Task");

        SECTION("Get Description") {
            // Verifique se a descrição da tarefa é retornada corretamente
            REQUIRE(task.getDescription() == "Sample Task");
        }

        SECTION("Get and Set Completed Status") {
            // Verifique se o status de conclusão padrão é falso
            REQUIRE(task.getCompleted() == false);

            // Defina o status de conclusão como verdadeiro e verifique
            task.setCompleted(true);
            REQUIRE(task.getCompleted() == true);
        }
    }
}
