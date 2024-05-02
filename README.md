# c64-fujinet-test

A test application to use c64 fujinet-lib implementation before first release.

## building

See Makefile for current supported make tasks:

- targets: `clean disk test test-disk release`
- `test` will run VICE and requires VICE_HOME set.
- `disk` requires c1541 on the path to create/edit disks

Example of building disk image and running it under VICE:

```bash
$ make clean test-disk
-------------------------------------
Building c64
-------------------------------------
Removing build
Removing obj
Removing dist
mkdir -p obj
cl65 -t c64 -c --create-dep obj/main.d --include-dir src/common --include-dir src/c64 --include-dir src -DVERSION_STRING=\"1.0.0\" -Osir -o obj/main.o src/main.c
mkdir -p build
cl65 -t c64  -o build/test1.c64 obj/main.o
mkdir -p dist
cp build/test1.c64 dist/test1.c64.prg
creating dist/test1.d64
c1541 -format "test1,01" d64 dist/test1.d64
formatting in unit 8 ...
copying dist/test1.c64.prg as test1.c64.prg
c1541 -attach dist/test1.d64 -write dist/test1.c64.prg test1.c64.prg
writing file `TEST1.C64.PRG' as `TEST1.C64.PRG' to unit 8
/c/8bit/c64/SDL2VICE-3.8-win64/x64sc dist/test1.d64
```
