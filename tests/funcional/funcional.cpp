#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "../../src/controller/ControllerImpl.h" // Inclua a implementação do controlador
#include "../../src/observer/ObserverImpl.h" // Inclua a implementação do observador
#include "../../src/model/Task.h" // Inclua a definição de tarefa

TEST_CASE("Functional Tests") {
    SECTION("TaskController and ConcreteObserver Interaction") {
        TaskControllerImpl controller; // Instância do controlador
        ConcreteObserver observer; // Instância do observador

        controller.addObserver(&observer);

        // Simule a atualização do status da tarefa para concluída
        controller.updateTaskStatus(true);

        // Verifique se o observador foi notificado corretamente
        REQUIRE(observer.getUpdatedTask().getCompleted() == true);
    }

    SECTION("Task Creation and Assignment") {
        TaskControllerImpl controller; // Instância do controlador

        // Simule a criação de uma nova tarefa
        Task task = controller.createTask("Nova Tarefa");

        // Verifique se a tarefa foi criada corretamente
        REQUIRE(task.getDescription() == "Nova Tarefa");
        REQUIRE_FALSE(task.getCompleted());

        // Simule a atribuição da tarefa a um usuário
        User user("Usuário de Teste");
        controller.assignTask(task, user);

        // Verifique se a tarefa foi atribuída corretamente ao usuário
        REQUIRE(task.getAssignedUser() == user);
    }

    // Adicione mais seções conforme necessário para testar outros requisitos
}
