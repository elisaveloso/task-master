#include "ObserverImpl.h"
#include <string>

using namespace std;

// Observer
class TaskObserver {
public:
    virtual void taskUpdated(const Task& task) = 0;
};
