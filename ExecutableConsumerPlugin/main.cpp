#include <MyClassPluginBuilder.h>

int main()
{
#if _DEBUG
  MyClassPluginBuilder wPluginBuilder("../Debug/LibraryFactory.dll");
#else
  MyClassPluginBuilder wPluginBuilder("../Release/LibraryFactory.dll");
#endif
  auto wMyObject = wPluginBuilder.build();
  
  return 0;
}
