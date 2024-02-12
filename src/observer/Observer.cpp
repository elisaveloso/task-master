#include "ObserverImpl.h"
#include <string>

using namespace std;

class TaskObserver {
public:
    virtual void taskUpdated(const Task& task) = 0;
};
