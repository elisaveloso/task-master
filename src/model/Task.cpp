#ifndef TASKIMPL_H
#define TASKIMPL_H

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

