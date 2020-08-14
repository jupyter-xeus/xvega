# XVega

A C++ backend for vega-lite (link).

**This is an early developer preview under active development.**

## Building from source

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

## License

We use a shared copyright model that enables all contributors to maintain the copyright on their contributions.

This software is licensed under the BSD-3-Clause license. See the LICENSE file for details.
