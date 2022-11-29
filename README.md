# CommonLibSSE-NG Template

This is a basic plugin template for use with CommonLibSSE-NG.

### Dependencies
* [XMake](https://xmake.io) [2.7.2+]
* C++20 Compiler (MSVC, Clang?)

## Getting started
```bat
git clone https://github.com/Qudix/template-commonlibsse-ng
cd template-commonlibsse-ng
```

### Building
To build the project, run the following command:
```bat
xmake
```

> ***Note:*** *This will generate a `build/windows/` directory in the **project's root directory**.*

### Packaging
To package the project, run the following command:
```bat
xmake package
```

> ***Note:*** *This will generate a `build/packages/` directory in the **project's root directory**.*

### Upgrading
To upgrade the project's dependencies, run the following command:
```bat
xmake require --upgrade
```

### Project Generation
To generate a Visual Studio Project, run the following command:
```bat
xmake project -k vsxmake
```
If that command fails due to an "`unsupported windows/x86`" error, try specifying the correct arch:
```bat
xmake project -k vsxmake -a x64
```

> ***Note:*** *This will generate a `vsxmakeXXXX/` directory in the **project's root directory** using the latest version of Visual Studio installed on the system.*

## Dependency Options
Some dependencies, like `commonlibsse-ng`, provide options to customize various features:

### `commonlibsse-ng`
|     Option     |  Type   |              Description             | Default |
|     :---:      |  :---:  |                 :---:                |  :---:  |
|   skyrim_se    |  bool   | Enable runtime support for Skyrim SE |  true   |
|   skyrim_ae    |  bool   | Enable runtime support for Skyrim AE |  true   |
|   skyrim_vr    |  bool   | Enable runtime support for Skyrim VR |  true   |
|   skse_xbyak   |  bool   | Enable trampoline support for Xbyak  |  false  |

Example ( `xmake.lua` )
```lua
add_requires("commonlibsse-ng", { configs = { skyrim_vr = false, skse_xbyak = true }})
```
