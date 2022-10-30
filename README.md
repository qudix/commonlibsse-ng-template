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

## Extra
### Project Generation
To generate a Visual Studio Project, run the following command:
```bat
xmake project -k vsxmake
```

> ***Note:*** *This will generate a `vsxmakeXXXX/` directory in the **project's root directory** using the latest version of Visual Studio installed on the system. Any project or file changes will require re-running the above command.*
