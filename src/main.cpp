#include "../controller/ControllerImpl.h" // Inclua a implementação do controlador
#include "../view/ViewImpl.h" // Inclua a implementação da visualização
#include "../model/Task.h"
#include "../model/User.h" // Inclua a definição de usuário, se aplicável

int main() {
    TaskControllerImpl controller; // Instância do controlador
    ViewImpl view; // Instância da visualização

    // Adicione um observador para a visualização ao controlador
    controller.addObserver(&view);

    // Simule a criação de uma tarefa e sua atribuição a um usuário
    Task task = controller.createTask("Nova Tarefa");
    User user("Usuário de Teste"); // Crie um usuário, se aplicável
    controller.assignTask(task, user);

    // Atualize o status da tarefa para concluída
    controller.updateTaskStatus(true);

    // Implemente o restante da lógica conforme necessário

    return 0;
}
