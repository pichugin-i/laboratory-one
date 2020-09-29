#include "bitfield.h"
#include "set.h"

#include <iomanip>
#include <conio.h>

void main() {

  int k, count, na, m;

  setlocale(LC_ALL, "Russian");

  cout << "Введите целое количество чисел для составления множества простых чисел" << endl;
  cout << "Ввод: ";
  cin >> na;
  TSet pna(na + 1);
  // Заполняем множество.
  for (m = 2; m <= na; m++) {
    pna.InsElem(m);
  }
  // Проверка по sqrt(m). Проверка на кратность/исключение.
  for (m = 2; sqrt(m) <= na; m++) {
    // Если m в pna, происходит удаление кратных чисел.
    if (pna.IsMember(m)) {
      for (k = 2 * m; k <= na; k += m) {
        if (pna.IsMember(k)) {
          pna.DelElem(k);
        }
      }
    }
  }
  cout << endl;
  // Остальные элементы в pna будут простые числа.
  cout << "Вывод на экран множества некратных чисел" << endl;
  cout << pna << endl << endl;
  cout << "Вывод на экран простых чисел" << endl;
  count = 0;
  k = 1;
  for (m = 2; m <= na; m++) {
    if (pna.IsMember(m)) {
      count++;
      cout << setw(3) << m << " ";
      if (k++ % 10 == 0)
        cout << endl;
    }
  }
  cout << endl;
  cout << "Всего " << na << " чисел. " << " Из них "<< count << " простых." << endl;
}