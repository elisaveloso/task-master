#ifndef TASK_H
#define TASK_H

#include <string>

using namespace std;

class Task{
    public:
         
         virtual ~Task() {}

         virtual void setDescription( string description) = 0;
         virtual void getDescription()  = 0;

         virtual void setStatus(bool staus) = 0;
         virtual void getStatus()  = 0;
}

#endif