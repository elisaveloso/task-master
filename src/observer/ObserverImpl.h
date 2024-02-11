#pragma once

#include "observer.h"

class ConcreteObserver : public TaskObserver {
public:
    void taskUpdated(const Task& task) override;
};
