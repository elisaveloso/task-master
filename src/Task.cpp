#include "TaskImpl.h"
#include <string>

using namespace std;

// Model
class Task {
public:
    std::string description;
    bool completed;

    Task(const std::string& desc) : description(desc), completed(false) {}
};
