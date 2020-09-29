#pragma once
#include "bitfield.h"
class TSet {
private:
  int MaxPower; // Максимальная мощность множества.
  TBitField BitField; // Битовое поле хранения.
public:
  TSet(int mp);
  TSet(const TSet& s); // Конструктор копирования.
  TSet(const TBitField& bf); // Конструктор преобразования типа.
  operator TBitField(); // Преобразование типа к битовому полю.
  // доступ к битам
  int GetMaxPower(void) const; // Максимальная мощность множества.
  void InsElem(const int n); // Добавить элемент в множество.
  void DelElem(const int n); // Исключить элемент из множества.
  int IsMember(const int n) const; // Проверить наличие элемента в множестве.

  // теоретико-множественные операции (по лекции)

  int operator== (const TSet& s); // Оператор: сравнение
  TSet& operator=(const TSet& s); // Оператор: присваивание
  TSet operator+ (const TSet& s); // Оператор: объединение
  TSet operator* (const TSet& s); // Оператор: пересечение
  TSet operator~ (void); // Оператор: дополнение
  friend istream& operator>>(istream& istr, TSet& bf); // Ввод. Организация визуализации множества.
  friend ostream& operator<<(ostream& ostr, const TSet& bf); // Вывод. Организация визуал.
};
