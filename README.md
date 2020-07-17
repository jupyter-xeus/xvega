To build the package from source, execute the following:

```
mkdir build

cd build

cmake -D CMAKE_INSTALL_PREFIX=$CONDA_PREFIX ..

make install
```

Use the library by including the following header:

```
#include "xvega/xvega.hpp"
```
