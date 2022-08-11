# FPmax* LIB

This is a C++ library based on the FPmax* algorithm for mining maximal frequent itemsets by Gösta Grahne and Jianfei Zhu [[1,2](#references)].

This project aims to make the FPmax* algorithm available as a shared library so you can call it directly from your code without needing file writing/reading and system calls.
Most of the original code (which is available from the [FIMI repository](http://fimi.uantwerpen.be/src)) is preserved.

## References

[1] G. Grahne and J. Zhu, "Efficiently Using Prefix-trees in Mining Frequent Itemsets", *Proceedings of the IEEE ICDM Workshop on Frequent Itemset Mining Implementations*, 2003. (Available [HERE](http://ceur-ws.org/Vol-90/grahne.pdf)).

[2] G. Grahne and J. Zhu, "Reducing the Main Memory Consumptions of FPmax* and FPclose", *Proceedings of the IEEE ICDM Workshop on Frequent Itemset Mining Implementations*, 2004. (Available [HERE](http://ceur-ws.org/Vol-126/zhu.pdf)).

## Compiling the shared library

```console
mkdir build
cd build
cmake .. -DCMAKE_BUILD_TYPE=Release
make lib
```
This will generate the library file (.so on Linux or .dll on Windows) in the `build` directory.

To test calling the shared library from a C++ code:
```console
make lib_test
ctest -R lib --verbose
```

## Using the shared library

You need to include the [`fpmax.h`](src/fpmax.h) header and call the `fpmax` function, which has 2 versions.

If you wish to handle input/output the same way you would with the original FPmax* executable (using files), go for the first version:<br>`void fpmax(char const * in, char const * out, unsigned int minsup)`

Otherwise, you can handle input/output in-memory:
1. Create a Dataset object (see [`data.h`](src/data.h) for the definition)
2. Call the second version of the function:<br>`FISet* fpmax(Dataset* dataset, unsigned int minsup, unsigned int nlargest=0)`
3. Get the return value, a pointer to an FISet object - a set of FrequentItemset objects (see [`fitemset.h`](src/fitemset.h) for their definitions)

To compile/link/run your program, you will need the compiled shared library and the following headers: {[`buffer.h`](src/buffer.h), [`data.h`](src/data.h), [`fitemset.h`](src/fitemset.h), [`fp_node.h`](src/fp_node.h), [`fp_tree.h`](src/fp_tree.h), [`fpmax.h`](src/fpmax.h), [`fsout.h`](src/fsout.h)}

For usage examples, see the code in the [`test`](test) folder or the following project:
- [MR-MS-ILS](https://github.com/MESS-2020-1/MR-MS-ILS-solver) (a MineReduce-based solver for a facility location problem)
