#pragma once

#include <string>

class Task {
public:
    Task(const std::string& desc);

    const std::string& getDescription() const;
    bool getCompleted() const;
    void setCompleted(bool completed);

    // Novo método para definir a prioridade da tarefa
    enum Priority { Low, Medium, High };
    Priority getPriority() const;
    void setPriority(Priority priority);

private:
    std::string description;
    bool completed;
    Priority priority; // Adicionamos a prioridade como membro privado
};

// Task.cpp
#include "Task.h"

Task::Task(const std::string& desc) : description(desc), completed(false), priority(Priority::Low) {}

const std::string& Task::getDescription() const {
    return description;
}

bool Task::getCompleted() const {
    return completed;
}

void Task::setCompleted(bool completed) {
    this->completed = completed;
}

Task::Priority Task::getPriority() const {
    return priority;
}

void Task::setPriority(Priority priority) {
    this->priority = priority;
}
