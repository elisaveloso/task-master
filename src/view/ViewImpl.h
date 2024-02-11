#ifndef VIEWIMPL_H
#define VIEWIMPL_H

#include <string>
#include "View.h"

class ViewImpl : public TaskView {
public:
    void taskUpdated(const Task& task) override;
};

#endif  // VIEWIMPL_H
