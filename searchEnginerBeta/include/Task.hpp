#ifndef __TASK_HPP__
#define __TASK_HPP__

#include "DataBag.hpp"

#include <functional>

using Task = std::function<void(DataBag *dataPtr)>;

#endif