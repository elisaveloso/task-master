#ifndef CONTROLLERIMPL_H
#define CONTROLLERIMPL_H

#include "Controller.h"

class TaskControllerImpl : public TaskController {
public:
    // Sobrescreva os métodos existentes
    void addObserver(TaskObserver* observer) override;
    void updateTaskStatus(bool completed) override;
    void notifyObservers() override;

    void assignTask(Task& task, User& user) override;
    Task createTask(const std::string& description) override;
    void addUser(User& user) override;
    void removeUser(User& user) override;
    void addComment(Task& task, const std::string& comment) override; // Adiciona um comentário a uma tarefa
};

#endif
