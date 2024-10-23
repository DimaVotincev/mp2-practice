﻿// ННГУ, ИИТММ, Курс "Алгоритмы и структуры данных"
//
// Copyright (c) Сысоев А.В.
//
//

#ifndef __TDynamicMatrix_H__
#define __TDynamicMatrix_H__

#include <iostream>

using namespace std;

const int MAX_VECTOR_SIZE = 100000000;
const int MAX_MATRIX_SIZE = 10000;

// Динамический вектор - 
// шаблонный вектор на динамической памяти
template<typename T>
class TDynamicVector
{
protected:
  size_t sz;
  T* pMem;
public:
  TDynamicVector(size_t size = 1) 
  {
      if (size > MAX_VECTOR_SIZE) {
          throw "max vector size reached";
      }
    if (sz == 0)
      throw out_of_range("Vector size should be greater than zero");
    sz = size;
    pMem = new T[sz]();// {}; // У типа T д.б. констуктор по умолчанию
  }
  TDynamicVector(T* arr, size_t s) : sz(s)
  {
    assert(arr != nullptr && "TDynamicVector ctor requires non-nullptr arg");
    pMem = new T[sz];
    std::copy(arr, arr + sz, pMem);
  }
  TDynamicVector(const TDynamicVector& v)
  {
      sz = v.sz;
      pMem = new T[sz];
      for (int i = 0; i < sz; i++) {
          pMem[i] = v.pMem[i];
      }

      // throw "Method is not implemented";
  }
  TDynamicVector(TDynamicVector&& v) noexcept
  {
      pMem = nullptr;
      swap(*this, v);
  }
  ~TDynamicVector()
  {
      if (pMem != nullptr) {
          delete[] pMem;
      }
  }
  TDynamicVector& operator=(const TDynamicVector& v)
  {
      if (this == &v) {
          return *this;
      }
      if (sz != v.sz) {
          delete[]pMem;
          sz = v.sz;
          pMem = new T[sz];
      }
      for (int i = 0; i < sz; i++) {
          pMem[i] = v.pMem[i];
      }
      return *this;
  }
  TDynamicVector& operator=(TDynamicVector&& v) noexcept
  {
      swap(*this, v);
      return *this;
  }

  size_t size() const noexcept { return sz; }

  // индексация
  T& operator[](size_t ind)
  {
      if (ind < 0 || ind >= MAX_VECTOR_SIZE) throw "ind < 0";
      return (pMem[ind]);
  }
  const T& operator[](size_t ind) const
  {
      if (ind < 0 || ind >= MAX_VECTOR_SIZE) throw "ind < 0";
      return (pMem[ind]);
  }
  // индексация с контролем
  T& at(size_t ind)
  {
      throw "Method is not implemented";
  }
  const T& at(size_t ind) const
  {
      throw "Method is not implemented";
  }

  // сравнение
  bool operator==(const TDynamicVector& v) const noexcept
  {
      if (sz != v.sz) {
          return 0;
      }
      for (int i = 0; i < sz; i++) {
          if (pMem[i] != v[i]) {
              return 0;
          }
      }
      return 1;
  
  }
  bool operator!=(const TDynamicVector& v) const noexcept
  {
      return !((*this) == v);
  }

  // скалярные операции
  TDynamicVector operator+(T val)
  {
      TDynamicVector<T> answ(size());
      for (int i = 0; i < size(); i++) {
          answ[i] = pMem[i] + val;
      }
      return answ;
      
  }
  TDynamicVector operator-(T val)
  {
      TDynamicVector<T> answ(size());
      for (int i = 0; i < size(); i++) {
          answ[i] = pMem[i] - val;
      }
      return answ;
      
  }
  TDynamicVector operator*(T val)
  {
      TDynamicVector<T> answ(size());
      for (int i = 0; i < size(); i++) {
          answ[i] = pMem[i] * val;
      }
      return answ;
  }

  // векторные операции
  TDynamicVector operator+(const TDynamicVector& v)
  {
      TDynamicVector<T> answ(size());
      for (int i = 0; i < size(); i++) {
          answ[i] = pMem[i] + v[i];
      }
      return answ;
      
  }
  TDynamicVector operator-(const TDynamicVector& v)
  {
      TDynamicVector<T> answ(size());
      for (int i = 0; i < size(); i++) {
          answ[i] = pMem[i] + v[i];
      }
      return answ;
  }
  T operator*(const TDynamicVector& v) noexcept(noexcept(T()))
  {
      T answ = 0;
      for (int i = 0; i < size(); i++) {
          answ += pMem[i] * v[i];
      }
      return answ;
  }

  friend void swap(TDynamicVector& lhs, TDynamicVector& rhs) noexcept
  {
    std::swap(lhs.sz, rhs.sz);
    std::swap(lhs.pMem, rhs.pMem);
  }

  // ввод/вывод
  friend istream& operator>>(istream& istr, TDynamicVector& v)
  {
    for (size_t i = 0; i < v.sz; i++)
      istr >> v.pMem[i]; // требуется оператор>> для типа T
    return istr;
  }
  friend ostream& operator<<(ostream& ostr, const TDynamicVector& v)
  {
    for (size_t i = 0; i < v.sz; i++)
      ostr << v.pMem[i] << ' '; // требуется оператор<< для типа T
    return ostr;
  }
};


// Динамическая матрица - 
// шаблонная матрица на динамической памяти
template<typename T>
class TDynamicMatrix : private TDynamicVector<TDynamicVector<T>>
{
  using TDynamicVector<TDynamicVector<T>>::pMem;
  using TDynamicVector<TDynamicVector<T>>::sz;
public:
  TDynamicMatrix(size_t s = 1) : TDynamicVector<TDynamicVector<T>>(s)
  {
    for (size_t i = 0; i < sz; i++)
      pMem[i] = TDynamicVector<T>(sz);
  }

  using TDynamicVector<TDynamicVector<T>>::operator[];

  // сравнение
  bool operator==(const TDynamicMatrix& m) const noexcept
  {
      throw "Method is not implemented";
  }

  // матрично-скалярные операции
  TDynamicMatrix operator*(const T& val)
  {
      throw "Method is not implemented";
  }

  // матрично-векторные операции
  TDynamicVector<T> operator*(const TDynamicVector<T>& v)
  {
      throw "Method is not implemented";
  }

  // матрично-матричные операции
  TDynamicMatrix operator+(const TDynamicMatrix& m)
  {
      throw "Method is not implemented";
  }
  TDynamicMatrix operator-(const TDynamicMatrix& m)
  {
      throw "Method is not implemented";
  }
  TDynamicMatrix operator*(const TDynamicMatrix& m)
  {
      throw "Method is not implemented";
  }

  // ввод/вывод
  friend istream& operator>>(istream& istr, TDynamicMatrix& v)
  {
      throw "Method is not implemented";
  }
  friend ostream& operator<<(ostream& ostr, const TDynamicMatrix& v)
  {
      throw "Method is not implemented";
  }
};

#endif