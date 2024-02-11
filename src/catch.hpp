// Arquivo: tests/functional/gui_tests.cpp
#include "catch.hpp"
#include "../src/view/View.h"

TEST_CASE("GUI Functionality Tests") {
    SECTION("Verify Task Creation in GUI") {
        // Simular a criação de uma tarefa na GUI
        View view;
        Task task = view.createTask("Nova Tarefa");

        // Verificar se a tarefa foi criada corretamente
        REQUIRE(view.getTaskCount() == 1);
        REQUIRE(view.getTaskDescription(0) == "Nova Tarefa");
        REQUIRE(task.getDescription() == "Nova Tarefa");
        REQUIRE_FALSE(task.getCompleted());
    }

    SECTION("Verify Task Priority Setting in GUI") {
        // Simular a definição de prioridade de uma tarefa na GUI
        View view;
        Task task = view.createTask("Tarefa com Prioridade");
        view.setTaskPriority(task, Task::Priority::High);

        // Verificar se a prioridade da tarefa foi definida corretamente
        REQUIRE(view.getTaskPriority(task) == Task::Priority::High);
    }

    // Adicione mais seções conforme necessário para testar outras funcionalidades da GUI
}
