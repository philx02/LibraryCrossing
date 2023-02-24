#include "MyClass.h"

void std::default_delete< MyClass >::operator()(MyClass *iToDelete)
{
  delete iToDelete;
}
