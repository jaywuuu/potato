# potato
I like potatoes.

```
clone repo
git submodule init
git submodule update --init
make (just kidding no makefile yet)
```

Build steps with just CMake:

Build LLVM:
```
mkdir build && cd build && mkdir llvm && cd llvm
cmake ../../third_party/llvm-project/llvm -DLLVM_ENABLE_PROJECTS="mlir" -DLLVM_TARGETS_TO_BUILD="X86;AArch64" -DCMAKE_BUILD_TYPE=RelWithDebInfo
cmake --build .
```
Build potato:
```
cd build
cmake ../
cmake --build .
```