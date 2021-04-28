#pragma once

#include "DllSwitch.h"

#include <memory>

class LIBRARYFACTORY_API MyClass
{
};

namespace std
{

// The following is a partial specialization of default_delete used by unique_ptr
// for the class MyClass. You need this for all types that the factory can create.
template<>
class LIBRARYFACTORY_API default_delete< MyClass >
{
public:
  void operator()(MyClass *iToDelete);
};

}
