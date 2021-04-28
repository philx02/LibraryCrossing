#include "ProblematicFactory.h"

MyClass * ProblematicFactory::create()
{
  return new MyClass();
}