// Observer
class TaskObserver {
public:
    virtual void taskUpdated(const Task& task) = 0;
};
