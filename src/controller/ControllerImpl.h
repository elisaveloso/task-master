#pragma once

#include "Controller.h"

class TaskControllerImpl : public TaskController {
public:
    // Sobrescreva os métodos existentes
    void addObserver(TaskObserver* observer) override;
    void updateTaskStatus(bool completed) override;
    void notifyObservers() override;

    // Adicione os novos métodos conforme os requisitos
    void assignTask(Task& task, User& user) override;
    Task createTask(const std::string& description) override;
    void addUser(User& user) override;
    void removeUser(User& user) override;
};
