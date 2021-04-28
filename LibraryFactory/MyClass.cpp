#include "MyClass.h"

namespace std
{

void default_delete< MyClass >::operator()(MyClass *iToDelete)
{
  delete iToDelete;
}

}
