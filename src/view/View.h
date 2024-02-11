#pragma once

#include "../observer/observer.h"
#include "../model/Task.h" // Adicione a inclusão da classe Task

class TaskView : public TaskObserver {
public:
    void taskUpdated(const Task& task) override;
};

