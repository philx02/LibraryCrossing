#pragma once

#include "DllSwitch.h"
#include "MyClass.h"

#include <memory>

class SafeFactory
{
public:  
  // Note that this function will not be not part of the DLL, so no std::unique_ptr
  // crosses a library boundary! It is going to be built in the client's translation
  // units, therefore it uses the std::unique_ptr of the client. Also note that there
  // is no need to explicitely provide a custom deleter, since a partial specialization of
  // std::default_delete exists for the class MyClass (see MyClass.h).
  inline static std::unique_ptr< MyClass > create()
  {
    return std::unique_ptr< MyClass >(doCreate());
  }

private:
  SafeFactory();

  static LIBRARYFACTORY_API MyClass * doCreate();
};
