## fstlib

### Build

#### Linux
```
cd fstpackage/fstlib
mkdir build
cd build
# build release version (by default)
cmake -DCMAKE_INSTALL_PREFIX=/var/tmp/fstlib ..
# build debug version
# cmake -DCMAKE_INSTALL_PREFIX=/var/tmp/fstlib -DCMAKE_BUILD_TYPE=Debug ..
make
make install
```

#### Windows


