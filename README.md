Pandar40P_Apollo


Clone:
git clone https://github.com/HesaiTechnology/Pandar40P_Apollo.git


Build:
cd <project>
mkdir build ; cd build;
cmake .. ; make


Add to your project:
In CmakeList.txt:
add_subdirectory(<path_to>Pandar40P)

include_directories(
	<path_to>Pandar40P/include
)

target_link_libraries(<Your project>
  Pandar40P
)

In codes:
#include "pandar40p/pandar40p.h"
#include "pandar40p/point_types.h"
