#include "View.h"
#include <iostream>

void TaskView::displayNotification(const std::string& message) {
    // Exibe a notificação na GUI
    std::cout << "Notificação: " << message << std::endl;
}

void TaskView::displayProgress(int progress) {
    // Exibe o progresso na GUI
    std::cout << "Progresso: " << progress << "%" << std::endl;
}

void TaskView::displayComment(const std::string& comment) {
    // Exibe o comentário na GUI
    std::cout << "Novo Comentário: " << comment << std::endl;
}

void TaskView::taskUpdated(const Task& task) {
    // Atualiza a GUI conforme necessário
    std::cout << "GUI Atualizada: Tarefa " << task.getDescription() << " - Concluída: " << task.getCompleted();
    std::cout << " - Prioridade: ";
    
    switch (task.getPriority()) {
        case Task::Priority::Low:
            std::cout << "Baixa";
            break;
        case Task::Priority::Medium:
            std::cout << "Média";
            break;
        case Task::Priority::High:
            std::cout << "Alta";
            break;
    }
    
    std::cout << std::endl;
}
