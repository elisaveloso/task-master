#include "ControllerImpl.h"
#include <string>

using namespace std;


// Controller
class TaskController {
private:
    Task model;
    std::vector<TaskObserver*> observers;

public:
    void addObserver(TaskObserver* observer) {
        observers.push_back(observer);
    }

    void updateTaskStatus(bool completed) {
        model.completed = completed;
        notifyObservers();
    }

private:
    void notifyObservers() {
        for (auto observer : observers) {
            observer->taskUpdated(model);
        }
    }
};
