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
```
xmake package
```

> ***Note:*** *This will generate a `build/packages/` directory in the **project's root directory**.*

### Upgrading
To upgrade the project's dependencies, run the following command:
```
xmake require --upgrade
```
