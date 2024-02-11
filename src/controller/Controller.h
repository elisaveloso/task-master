#pragma once

#include "../model/Task.h"
#include "../model/User.h" // Adicionar a inclusão da classe User
#include "../observer/observer.h"
#include <vector>

class TaskController {
protected:
    Task model;
    std::vector<TaskObserver*> observers;

public:
    virtual void addObserver(TaskObserver* observer);
    virtual void updateTaskStatus(bool completed);

    // Métodos adicionados para corresponder aos requisitos
    virtual void assignTask(Task& task, User& user); // Atribuir uma tarefa a um usuário
    virtual Task createTask(const std::string& description); // Criar uma nova tarefa
    virtual void addUser(User& user); // Adicionar um usuário
    virtual void removeUser(User& user); // Remover um usuário

protected:
    virtual void notifyObservers();
};
