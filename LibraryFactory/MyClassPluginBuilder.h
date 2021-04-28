#pragma once

#include "MyClass.h"

#include <memory>

#define WIN32_LEAN_AND_MEAN
#include <Windows.h>

typedef HMODULE DynamicLibraryHandle;
typedef MyClass * (*FcnIMyClassVoid)(void);
typedef void (*FcnVoidIMyClass)(MyClass *);

class MyClassPluginBuilder
{
public:
  MyClassPluginBuilder(const char *iLibraryPath)
    : mLibraryHandle(LoadLibraryA(iLibraryPath))
    , mMyClassInstantiate(reinterpret_cast< FcnIMyClassVoid >(GetProcAddress(mLibraryHandle, "instantiateMyClass")))
    , mMyClassDestroy(reinterpret_cast< FcnVoidIMyClass >(GetProcAddress(mLibraryHandle, "destroyMyClass")))
  {
  }

  inline std::shared_ptr< MyClass > build() const
  {
    return std::shared_ptr< MyClass >(mMyClassInstantiate(), mMyClassDestroy);
  }

private:
  DynamicLibraryHandle mLibraryHandle;
  FcnIMyClassVoid mMyClassInstantiate;
  FcnVoidIMyClass mMyClassDestroy;
};
