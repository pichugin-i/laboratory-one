#include "bitfield.h"
#include "set.h"

#include <iomanip>
#include <conio.h>

void main() {

  int k, count, na, m;

  setlocale(LC_ALL, "Russian");

  cout << "������� ����� ���������� ����� ��� ����������� ��������� ������� �����" << endl;
  cout << "����: ";
  cin >> na;
  TSet pna(na + 1);
  // ��������� ���������.
  for (m = 2; m <= na; m++) {
    pna.InsElem(m);
  }
  // �������� �� sqrt(m). �������� �� ���������/����������.
  for (m = 2; sqrt(m) <= na; m++) {
    // ���� m � pna, ���������� �������� ������� �����.
    if (pna.IsMember(m)) {
      for (k = 2 * m; k <= na; k += m) {
        if (pna.IsMember(k)) {
          pna.DelElem(k);
        }
      }
    }
  }
  cout << endl;
  // ��������� �������� � pna ����� ������� �����.
  cout << "����� �� ����� ��������� ��������� �����" << endl;
  cout << pna << endl << endl;
  cout << "����� �� ����� ������� �����" << endl;
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
  cout << "����� " << na << " �����. " << " �� ��� "<< count << " �������." << endl;
}