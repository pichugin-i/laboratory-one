#pragma once
#ifndef _BITFIELD_H
#define _BITFIELD_H
#include <stdlib.h>
#include <iostream>

using namespace std;
typedef unsigned int TELEM;

class TBitField {
private:
  int BitLen; // Длина бит. поля и макс. кол-во элементов.
  TELEM* pMem; // Выделенная память для представления эл-тов.
  int MemLen; // Количество эл-тов Mem для представления бит.поля.

  // Методы реализации
  int GetMemIndex(const int n) const; // Индекс в pMem для бита n.
  TELEM GetMemMask(const int n) const; // Битовая маска для бита n.

public:
  TBitField(int len);
  TBitField(const TBitField& bf);
  ~TBitField();
  // Доступ к битам.
  int GetLength(void) const; // Получить длину (Количество битов).
  void SetBit(const int n); // Установить бит.
  void ClrBit(const int n); // Очистить бит.
  int GetBit(const int n) const; // Получить значение бита.
  // Битовые операции.
  int operator==(const TBitField& bf); // Оператор: сравнение.
  TBitField& operator=(const TBitField& bf); // Оператор: присваивание.
  TBitField operator|(const TBitField& bf); // Оператор:  "или"
  TBitField operator&(const TBitField& bf); // Оператор:  "и"
  TBitField operator~(void); // Оператор: отрицание
  friend istream& operator>>(istream& istr, TBitField& bf);
  friend ostream& operator<<(ostream& ostr, const TBitField& bf);
};
#endif