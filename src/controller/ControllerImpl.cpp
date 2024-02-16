#include "ControllerImpl.h"

// Implementação do método para adicionar um observador
void TaskControllerImpl::addObserver(TaskObserver* observer) {
    observers.push_back(observer);
}

// Implementação do método para atualizar o status da tarefa
void TaskControllerImpl::updateTaskStatus(bool completed) {
    model.setCompleted(completed);
    notifyObservers();
}

// Implementação do método para notificar os observadores
void TaskControllerImpl::notifyObservers() {
    for (auto observer : observers) {
        observer->taskUpdated(model);
    }
}

// Implementação dos novos métodos adicionados conforme os requisitos
void TaskControllerImpl::assignTask(Task& task, User& user) {
    // Implemente a lógica para atribuir a tarefa ao usuário
}

Task TaskControllerImpl::createTask(const std::string& description) {
    // Implemente a lógica para criar uma nova tarefa
    Task newTask(description);
    return newTask;
}

void TaskControllerImpl::addUser(User& user) {
    // Implemente a lógica para adicionar um usuário
}

void TaskControllerImpl::removeUser(User& user) {
    // Implemente a lógica para remover um usuário
}

// Implementação dos métodos existentes

void TaskControllerImpl::addComment(Task& task, const std::string& comment) {
    // Adiciona o comentário à lista de comentários associada à tarefa
    comments[task].push_back(comment);
}
