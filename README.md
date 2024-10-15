Foy
===

Build|Linux
---|---
status|[![GitHub CI build status](https://github.com/Wodan58/Foy/actions/workflows/cmake.yml/badge.svg)](https://github.com/Wodan58/Foy/actions/workflows/cmake.yml)

This repository implements [Joy](https://github.com/Wodan58/Joy) and uses the
[BDW garbage collector](https://github.com/ivmai/bdwgc). It is a FORTH inspired
Joy. Unlike [Moy](https://github.com/Wodan58/Moy) it uses only one type of
vector and starts evaluating as soon as a symbol has been seen, not waiting for
the final stop. It is an experiment.

Build instructions
------------------

    mkdir build
    cd build
    cmake ..
    cmake --build .

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
[Comparison (PDF)](https://github.com/Wodan58/HET/blob/master/doc/FIB.pdf)
[Maintenance Manual (PDF)](https://github.com/Wodan58/G3/blob/master/JOP.pdf)
