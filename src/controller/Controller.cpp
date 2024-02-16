#include "Controller.h"
#include "ControllerImpl.h"
#include <string>

using namespace std;


// Controller
class TaskController {
private:
    Task model;
    std::vector<TaskObserver*> observers;

public:
    void addObserver(TaskObserver* observer) {
        observers.push_back(observer);
    }

    void updateTaskStatus(bool completed) {
        model.completed = completed;
        notifyObservers();
    }

private:
    void notifyObservers() {
        for (auto observer : observers) {
            observer->taskUpdated(model);
        }
    }
};

// Implementação do método para atribuir uma tarefa a um usuário
void TaskController::assignTask(Task& task, User& user) {
    // Lógica para atribuir a tarefa ao usuário
    // Implemente de acordo com os requisitos do sistema
}

// Implementação do método para criar uma nova tarefa
Task TaskController::createTask(const std::string& description) {
    // Crie uma nova tarefa e retorne
    Task newTask(description);
    return newTask;
}

// Implementação do método para priorizar uma tarefa
void Task::setPriority(Priority priority) {
    this->priority = priority;
}

// Implementação do método para adicionar um usuário ao sistema
void TaskController::addUser(User& user) {
    // Adicione o usuário ao sistema
    // Implemente de acordo com os requisitos do sistema
}

// Implementação do método para remover um usuário do sistema
void TaskController::removeUser(User& user) {
    // Remova o usuário do sistema
    // Implemente de acordo com os requisitos do sistema
}

void TaskController::addComment(Task& task, const std::string& comment) {
    // Adiciona o comentário à lista de comentários associada à tarefa
    comments[task].push_back(comment);
}