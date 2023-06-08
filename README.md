# Data-Structure-Templates
Simple data structure templates written using modern c++.

Made as a learning project to learn and implement modern C++ functionalities including but not limited to template classes, move semantics, smart pointers, OOP concepts like class relations, and design principles.

## Overview
Custom data structures like a node, doubly linked list and more (to come).

## Building
To compile all targets (all individual files in `src`), run:
```bash
make all
```

To compile individual targets (see `Makefile` for target names), run:
```bash
make <target-name>
```

For example, to build for linked list usage only:
```bash
make linkedlist
```

## Sample Usage
Sample usage files are in `src` e.g. `src/linkedListUsage.cc`

## Directory Structure
```
- interfaces  
--- <interface implementations for the data structure templates>  
- templates  
--- <data structure template files>  
- src  
--- <sample usage files>  
- logging  
--- <source files for the custom logging mechanism>  
- error  
--- <header source files for error reporting mechanism>  
- expected-lite 
--- <submodule used for nonstd::expected<>
```
