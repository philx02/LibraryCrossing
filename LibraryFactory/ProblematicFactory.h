#pragma once

#include "DllSwitch.h"
#include "MyClass.h"

class ProblematicFactory
{
public:
  static LIBRARYFACTORY_API MyClass * create();

private:
  ProblematicFactory();
};
