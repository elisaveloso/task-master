#pragma once

#include "../model/Task.h"
#include "../model/User.h"
#include "../observer/Observer.h"
#include <vector>

class TaskController {
protected:
    Task model;
    std::vector<TaskObserver*> observers;
    std::map<Task, std::vector<std::string>> comments; // Armazena os comentários associados a cada tarefa

public:
    virtual void addObserver(TaskObserver* observer);
    virtual void updateTaskStatus(bool completed);

    virtual void assignTask(Task& task, User& user); // Atribuir uma tarefa a um usuário
    virtual Task createTask(const std::string& description); // Criar uma nova tarefa
    virtual void addUser(User& user); // Adicionar um usuário
    virtual void removeUser(User& user); // Remover um usuário
    virtual void addComment(Task& task, const std::string& comment); // Adicionar um comentário a uma tarefa

protected:
    virtual void notifyObservers();
};
