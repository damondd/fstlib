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

### C++ Usage

#### FstRowReader: read row by row
```
#include <fstlib/fst_row_reader.h>
#include <cstdio>

std::string file = "/path_to_your.fst";

std::vector<std::string> columns = {"StringCol", "IntCol", "DoubleCol"};
// FstRowReader reader(file, columns); // all rows: 1 to -1
FstRowReader reader(file, columns, 1, 10); // from the first row to row 10: 1 to 10

std::string stringVal;
int intVal;
double doubleVal;

while (reader.readRow(stringVal, intVal, doubleVal) {
  std::printf("readRow: stringVal=%s, intVal=%d, doubleVal=%.6f\n",
      stringVal.c_str(), intVal, doubleVal);
}
```

#### FstColReader: read column by column
```
#include <fstlib/fst_col_reader.h>
#include <cstdio>

std::string file = "/path_to_your.fst";

std::vector<std::string> columns = {"StringCol", "IntCol", "DoubleCol"};
// FstRowReader reader(file, columns); // all rows: 1 to -1
FstRowReader reader(file, columns, 1, 10); // from the first row to row 10: 1 to 10

std::vector<std::string> stringVec = reader.readStringCol("StringCol");
std::vector<int> intVec = reader.readIntCol("IntCol");
std::vector<double> doubleVec = reader.readDoubleCol("DoubleCol");
for (auto i = 0; i < stringVec.size(); ++i) {
  std::printf("readCol: stringVal=%s, intVal=%d, doubleVal=%.6f\n",
      stringVec[i].c_str(), intVec[i], doubleVec[i]);
}
```

