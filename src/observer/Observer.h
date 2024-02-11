#pragma once

#include "../model/Task.h"

class TaskObserver {
public:
    virtual void taskUpdated(const Task& task) = 0;
};
