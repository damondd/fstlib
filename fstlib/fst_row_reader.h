// Dongdong:
// C++ fst row by row reader based on fstlib https://github.com/fstpackage/fstlib

#pragma once

#include <fstlib/fst_reader.h>

class FstRowReader : public FstReader {
public:
  FstRowReader(const std::string& filepath, const std::vector<std::string>& columns,
            int startRow = 1, int endRow = -1) :
        FstReader(filepath, columns, startRow, endRow),
        _ptrs(columns.size(), nullptr) {
  }

  template<class... Args>
  bool readRow(char& val, Args&... args) {
    if (_rowIdx < _rowCnt) {
      if (_ptrs[_colIdx] == nullptr) {
        std::shared_ptr<DestructableObject> col;
        FstColumnType colType;
        std::string   colName;
        short int     colScale;
        std::string   colAnnotation;
        _fstTable.GetColumn(_colIdx, col, colType, colName, colScale, colAnnotation);
        auto ptr = static_cast<ByteVector*>(col.get())->Data();
        _ptrs[_colIdx] = static_cast<void*>(ptr);
      }
      auto ptrint = static_cast<char*>(_ptrs[_colIdx]);
      val = ptrint[_rowIdx];
      ++_colIdx;

      return readRow(args...);
    }

    return false;
  }

  template<class... Args>
  bool readRow(int& val, Args&... args) {
    if (_rowIdx < _rowCnt) {
      if (_ptrs[_colIdx] == nullptr) {
        std::shared_ptr<DestructableObject> col;
        FstColumnType colType;
        std::string   colName;
        short int     colScale;
        std::string   colAnnotation;
        _fstTable.GetColumn(_colIdx, col, colType, colName, colScale, colAnnotation);
        auto ptr = static_cast<IntVector*>(col.get())->Data();
        _ptrs[_colIdx] = static_cast<void*>(ptr);
      }
      auto ptrint = static_cast<int*>(_ptrs[_colIdx]);
      val = ptrint[_rowIdx];
      ++_colIdx;

      return readRow(args...);
    }

    return false;
  }

  template<class... Args>
  bool readRow(long long& val, Args&... args) {
    if (_rowIdx < _rowCnt) {
      if (_ptrs[_colIdx] == nullptr) {
        std::shared_ptr<DestructableObject> col;
        FstColumnType colType;
        std::string   colName;
        short int     colScale;
        std::string   colAnnotation;
        _fstTable.GetColumn(_colIdx, col, colType, colName, colScale, colAnnotation);
        auto ptr = static_cast<LongVector*>(col.get())->Data();
        _ptrs[_colIdx] = static_cast<void*>(ptr);
      }
      auto ptrint = static_cast<long long*>(_ptrs[_colIdx]);
      val = ptrint[_rowIdx];
      ++_colIdx;

      return readRow(args...);
    }

    return false;
  }

  template<class... Args>
  bool readRow(double& val, Args&... args) {
    if (_rowIdx < _rowCnt) {
      if (_ptrs[_colIdx] == nullptr) {
        std::shared_ptr<DestructableObject> col;
        FstColumnType colType;
        std::string colName;
        short int colScale;
        std::string colAnnotation;
        _fstTable.GetColumn(_colIdx, col, colType, colName, colScale, colAnnotation);
        auto ptr = static_cast<DoubleVector*>(col.get())->Data();
        _ptrs[_colIdx] = static_cast<void*>(ptr);
      }
      auto ptrdouble = static_cast<double*>(_ptrs[_colIdx]);
      val = ptrdouble[_rowIdx];
      ++_colIdx;

      return readRow(args...);
    }

    return false;
  }

  template<class... Args>
  bool readRow(std::string& val, Args&... args) {
    if (_rowIdx < _rowCnt) {
      if (_ptrs[_colIdx] == nullptr) {
        std::shared_ptr<DestructableObject> col;
        FstColumnType colType;
        std::string colName;
        short int colScale;
        std::string colAnnotation;
        _fstTable.GetColumn(_colIdx, col, colType, colName, colScale, colAnnotation);
        auto ptr = static_cast<StringVector*>(col.get())->StrVec();
        _ptrs[_colIdx] = static_cast<void*>(ptr);
      }
      auto ptrstrvec = static_cast<std::vector<std::string>*>(_ptrs[_colIdx]);
      val = (*ptrstrvec)[_rowIdx];
      ++_colIdx;

      return readRow(args...);
    }

    return false;
  }

private:
  // Break up recursive variadic template
  template<class... Args>
  bool readRow() {
    // After read the whole row, get ready for the next row
    _colIdx = 0;
    ++_rowIdx;
    
    return true;
    // return _rowIdx <= _rowCnt ? true : false;
  }

private:
  std::size_t _rowIdx = 0;
  std::size_t _colIdx = 0;
  std::vector<void*> _ptrs{};
};

