#ifndef TASKIMPL_H
#define TASKIMPL_H

#include <string>
#include "Task.h"

using namespace std;

class TaskImpl : public Task{
    public:
        TaskImpl(string description = "", bool completed = false);

        virtual ~TaskImpl();

    protected:
        string description;
        bool completed;
    
    private:
    
}