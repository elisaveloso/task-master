#ifndef TASKIMPL_H
#define TASKIMPL_H

#include "Task.h"

class TaskImpl : public Task {
public:
    TaskImpl(const std::string& description = "", bool completed = false);
    virtual ~TaskImpl();
};

#endif
