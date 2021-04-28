#include "SafeFactory.h"

MyClass * SafeFactory::doCreate()
{
  return new MyClass();
}
