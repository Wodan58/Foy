Foy
---

Build|Linux|Windows
---|---|---
status|[![GitHub CI build status](https://github.com/Wodan58/Moy/actions/workflows/cmake.yml/badge.svg)](https://github.com/Wodan58/Moy/actions/workflows/cmake.yml)|[![AppVeyor CI build status](https://ci.appveyor.com/api/projects/status/github/Wodan58/Moy?branch=master&svg=true)](https://ci.appveyor.com/project/Wodan58/Moy)

This repository implements [Joy](https://github.com/Wodan58/Joy) and uses the
[BDW garbage collector](https://github.com/ivmai/bdwgc). It is a FORTH inspired
Joy.

Build instructions
------------------

    mkdir build
    cd build
    cmake ..
    cmake --build .

Build with MSVC
---------------

Install bdwgc in a bdwgc-subdirectory.

    mkdir build
    cd build
    cmake ..
    cmake --build . --config Release
    copy Release\joy.exe

Running
-------

    joy -h

gives an overview of available options.

See also
--------

Implementation|Dependencies
--------------|------------
[42minjoy](https://github.com/Wodan58/42minjoy)|
[joy0](https://github.com/Wodan58/joy0)|
[Joy](https://github.com/Wodan58/Joy)|
[joy1](https://github.com/Wodan58/joy1)|[BDW garbage collector](https://github.com/ivmai/bdwgc)
[Moy](https://github.com/Wodan58/Moy)|[BDW garbage collector](https://github.com/ivmai/bdwgc) and [Lex & Yacc](https://sourceforge.net/projects/winflexbison/files/win_flex_bison-latest.zip)

Documentation|
-------------|
[Legacy Docs](https://wodan58.github.io)
[User Manual](https://wodan58.github.io/j09imp.html)
