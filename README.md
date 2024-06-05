# XVega

[![Binder](https://mybinder.org/badge_logo.svg)](https://mybinder.org/v2/gh/QuantStack/xvega/stable?urlpath=lab%2Ftree%2Fnotebooks%2Fdemo.ipynb)
[![Build Status](https://github.com/QuantStack/xvega/workflows/CMake%20Build/badge.svg)](https://github.com/QuantStack/xvega/actions)

A C++ API for Vega-Lite (https://vega.github.io/vega-lite/).

**This is an early developer preview under active development.**

## Building from source

To build the package from source, execute the following:

```
mkdir build

cd build

cmake -DCMAKE_INSTALL_PREFIX=$CONDA_PREFIX .. -DCMAKE_BUILD_TYPE=Release

make -j ${CPU_COUNT} install
```

Use the library by including the following header:

```
#include "xvega/xvega.hpp"
```

## Dependencies

`xvega` depends on [nlohmann json](https://github.com/nlohmann/json) and the 
[xproperty](https://github.com/jupyter-xeus/xproperty) libraries:

|  `xvega`  |  `nlohmann json`  |  `xproperty`  |
|-----------|-------------------|---------------|
|  0.1.0    |      ^3.11.3      |    ^0.12.0    |

Prior to version 0.1.0, xvega was also depending on [xtl](https://github.com/xtensor-stack/xtl)

|  `xvega`  |  `xtl`  |  `nlohmann json`  |  `xproperty`  |
|-----------|---------|-------------------|---------------|
|  0.0.10   | ^0.7.0  |       ^3.7.3      |    ^0.11.0    |
|  0.0.9    | ^0.7.0  |       ^3.7.3      |    ^0.11.0    |

Note: Please make sure to have `jupyterlab` and `xeus-cling` installed in order to use `XVega` as a standalone library.

Also, `XVega` only works with `jupyterlab` (and not `jupyter notebook`) as of now.

## License

We use a shared copyright model that enables all contributors to maintain the copyright on their contributions.

This software is licensed under the BSD-3-Clause license. See the LICENSE file for details.
