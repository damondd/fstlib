// Dongdong:
// C++ fst column by column reader based on fstlib https://github.com/fstpackage/fstlib

#pragma once

#include <fstlib/fst_reader.h>

class FstColReader : public FstReader {
public:
  FstColReader(const std::string& filepath, const std::vector<std::string>& columns,
            int startRow = 1, int endRow = -1) :
        FstReader(filepath, columns, startRow, endRow),
        _columns(columns) {
  }

  std::vector<char> readCharCol(const std::string& colName) {
    auto it = std::find(_columns.begin(), _columns.end(), colName);
    if (it != _columns.end()) {
      auto colIdx = std::distance(_columns.begin(), it);
      std::shared_ptr<DestructableObject> col;
      FstColumnType type;
      std::string   name;
      short int     scale;
      std::string   annotation;
      _fstTable.GetColumn(colIdx, col, type, name, scale, annotation);
      auto ptr = static_cast<ByteVector*>(col.get())->Data();
      return std::vector<char>(ptr, ptr + _rowCnt);
    }

    return {};
  }

  std::vector<int> readIntCol(const std::string& colName) {
    auto it = std::find(_columns.begin(), _columns.end(), colName);
    if (it != _columns.end()) {
      auto colIdx = std::distance(_columns.begin(), it);
      std::shared_ptr<DestructableObject> col;
      FstColumnType type;
      std::string   name;
      short int     scale;
      std::string   annotation;
      _fstTable.GetColumn(colIdx, col, type, name, scale, annotation);
      auto ptr = static_cast<IntVector*>(col.get())->Data();
      return std::vector<int>(ptr, ptr + _rowCnt);
    }

    return {};
  }

  std::vector<long long> readLongCol(const std::string& colName) {
    auto it = std::find(_columns.begin(), _columns.end(), colName);
    if (it != _columns.end()) {
      auto colIdx = std::distance(_columns.begin(), it);
      std::shared_ptr<DestructableObject> col;
      FstColumnType type;
      std::string   name;
      short int     scale;
      std::string   annotation;
      _fstTable.GetColumn(colIdx, col, type, name, scale, annotation);
      auto ptr = static_cast<LongVector*>(col.get())->Data();
      return std::vector<long long>(ptr, ptr + _rowCnt);
    }

    return {};
  }

  std::vector<double> readDoubleCol(const std::string& colName) {
    auto it = std::find(_columns.begin(), _columns.end(), colName);
    if (it != _columns.end()) {
      auto colIdx = std::distance(_columns.begin(), it);
      std::shared_ptr<DestructableObject> col;
      FstColumnType type;
      std::string   name;
      short int     scale;
      std::string   annotation;
      _fstTable.GetColumn(colIdx, col, type, name, scale, annotation);
      auto ptr = static_cast<DoubleVector*>(col.get())->Data();
      return std::vector<double>(ptr, ptr + _rowCnt);
    }

    return {};
  }

  std::vector<std::string> readStringCol(const std::string& colName) {
    auto it = std::find(_columns.begin(), _columns.end(), colName);
    if (it != _columns.end()) {
      auto colIdx = std::distance(_columns.begin(), it);
      std::shared_ptr<DestructableObject> col;
      FstColumnType type;
      std::string   name; short int     scale;
      std::string   annotation;
      _fstTable.GetColumn(colIdx, col, type, name, scale, annotation);
      auto ptr = static_cast<StringVector*>(col.get())->StrVec();
      return *ptr;
    }

    return {};
  }

private:
  const std::vector<std::string> _columns;
};

