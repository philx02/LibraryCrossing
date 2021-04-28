#include <ProblematicFactory.h>
#include <SafeFactory.h>

// change this undef to a define to see the heap corruption assert in debug
#undef USE_PROBLEMATIC_FACTORY_AND_CAUSE_HEAP_CORRUPTION

int main()
{
#ifdef USE_PROBLEMATIC_FACTORY_AND_CAUSE_HEAP_CORRUPTION
  {
    // this allocation is done the the DLL
    auto wMyObject = ProblematicFactory::create();
    // this deallocation is done in the current assembly
    delete wMyObject;
    // when the DLL and this assembly are linked with the exact same CRT DLL,
    // the delete will work properly, otherwise, it will cause heap corruption.
  }
#endif

  {
    // always use auto when possible!
    auto wMyObject = SafeFactory::create();
    // When the program will hit the following curly brace, wMyObect will be automatically deleted
    // using the custom deleter provided in MyClass.h. No need to send it back to a de-allocation
    // function of the library!
  } 

  {
    // std::unique_ptr can be automatically promoted to a std::shared_ptr
    // and the custom deleter follows, feels like magic!
    std::shared_ptr< MyClass > wMyObject = SafeFactory::create();
    // Same behavior as the example above, since the shared count will reach zero on the following
    // curly brace.
  }
  
  return 0;
}
