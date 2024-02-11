#include "View.h"
#include <iostream>

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