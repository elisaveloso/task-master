#include "TaskImpl.h"

TaskImpl::TaskImpl(const std::string& description, bool completed) : Task(description), completed(completed) {}

TaskImpl::~TaskImpl() {}