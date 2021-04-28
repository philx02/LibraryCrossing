#include "MyClassPluginBuilder.h"
#include <iostream>

extern "C"
{
LIBRARYFACTORY_API MyClass * instantiateMyClass();
LIBRARYFACTORY_API void destroyMyClass(MyClass *);
}

MyClass * instantiateMyClass()
{
  std::cout << "instantiateMyClass" << std::endl;
  return new MyClass();
}

void destroyMyClass(MyClass *iMyClass)
{
  std::cout << "destroyMyClass" << std::endl;
  delete iMyClass;
}
