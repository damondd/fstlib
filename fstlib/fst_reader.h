// Dongdong:
// C++ fst reader based on fstlib https://github.com/fstpackage/fstlib

#pragma once

#include <fstlib/fstcore/interface/fststore.h>
#include <fstlib/fsttable.h>
#include <fstlib/columnfactory.h>

#define DISALLOW_COPY_MOVE_AND_ASSIGN(TypeName) \
  TypeName(const TypeName&) = delete;           \
  TypeName(TypeName&&) = delete;                \
  void operator=(const TypeName&) = delete;     \
  void operator=(TypeName&&) = delete

class FstReader {
public:
  DISALLOW_COPY_MOVE_AND_ASSIGN(FstReader);

  FstReader(const std::string& filepath, const std::vector<std::string>& columns,
        int startRow = 1, int endRow = -1) {
    FstStore fstStore(filepath);

    std::unique_ptr<StringArray> colSelection;
    if (!columns.empty()) {
      colSelection = std::make_unique<StringArray>();
      colSelection->SetArray(const_cast<std::vector<std::string>&>(columns));
    }

    std::unique_ptr<IColumnFactory> columnFactory = std::make_unique<ColumnFactory>();
    std::vector<int> keyIndex;
    std::unique_ptr<StringArray> selectedCols = std::make_unique<StringArray>();

    fstStore.fstMeta(columnFactory.get());
    fstStore.fstRead(_fstTable, colSelection.get(), startRow, endRow, columnFactory.get(),
                     keyIndex, selectedCols.get());
    _rowCnt = _fstTable.NrOfRows();
  }

protected:
  FstTable _fstTable;

  std::size_t _rowCnt = 0;
};

