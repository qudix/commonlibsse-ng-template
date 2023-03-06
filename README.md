# CommonLibSSE-NG Plugin Template

This is a basic plugin template using CommonLibSSE-NG.

### Dependencies
* [XMake](https://xmake.io) [2.7.4+]
* C++20 Compiler (MSVC, Clang?)

## Getting started
```bat
git clone https://github.com/Qudix/template-commonlibsse-ng
cd template-commonlibsse-ng
```

### Building
To build the project, run the following command:
```bat
xmake build
```

> ***Note:*** *This will generate a `build/windows/` directory in the **project's root directory**.*

### Packaging
To package the project, run the following command:
```bat
xmake package
```

> ***Note:*** *This will generate a `build/packages/` directory in the **project's root directory**.*

### Upgrading
To upgrade the project's dependencies, run the following commands:
```bat
xmake repo --update
xmake require --upgrade
```

### Project Generation
To generate a Visual Studio project, run the following command:
```bat
xmake project -k vsxmake
```

> ***Note:*** *This will generate a `vsxmakeXXXX/` directory in the **project's root directory** using the latest version of Visual Studio installed on the system.*

## Documentation
Please refer to the [Wiki](../../wiki/Home) for more advanced topics.
