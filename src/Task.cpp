#include "TaskImpl.h"
#include <string>

using namespace std;

// Model
class Task {

    std::string description;
    bool completed;
    
public:
    Task(const std::string& desc) : description(desc), completed(false) {}
};
