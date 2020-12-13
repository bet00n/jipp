#include "../include/matrix.hpp"

int main() {
  srand(time(NULL));
  Matrix test(4, 5);
  Matrix square(6);
  int testRows = test.getRows();
  int testColumns = test.getColumns();
  int squareRows = square.getRows();

  cout << "Konstruktor pierwszej macierzy 4x5: " << endl;
  test.print();

  cout << endl << "Konstruktor macierzy kwadratowej 6x6: " << endl;
  square.print();

  test.set(2, 3, 4.5);
  cout << endl << "Wypisanie wartosci elementu (2, 3) macierzy test: " << endl;
  cout << test.get(2, 3) << endl;
  square.set(4, 6, -2.5);
  cout << endl << "Wypisanie wartosci elementu (4, 6) macierzy square: " << std::endl;
  cout << square.get(4, 6) << endl;

  Matrix m2(4, 5);

  for (int i = 0; i < m2.getRows(); i++) {
    for (int j = 0; j < m2.getColumns(); j++) {
      m2.set(i, j, rand() % 10);
    }
  }

  Matrix m3(4, 5);

  for (int i = 0; i < m3.getRows(); i++) {
    for (int j = 0; j < m3.getColumns(); j++) {
      m3.set(i, j, rand() % 10);
    }
  }

  Matrix m4(5, 6);

  for (int i = 0; i < m4.getRows(); i++) {
    for (int j = 0; j < m4.getColumns(); j++) {
      m4.set(i, j, rand() % 10);
    }
  }

  Matrix m5(5);

  for (int i = 0; i < m5.getRows(); i++) {
    for (int j = 0; j < m5.getColumns(); j++) {
      m5.set(i, j, rand() % 10);
    }
  }

  cout << endl << "Macierz m2: " << endl;
  m2.print();
  cout << endl << "Macierz m3: " << endl;
  m3.print();
  cout << endl << "Macierz m4: " << endl;
  m4.print();

  m3.add(m2);

  cout << endl << "Dodawanie macierzy: " << endl;
  m2.print();

  m2.substract(m3);

  cout << endl << "Odejmowanie macierzy: " << endl;
  m3.print();

  m2.multiply(m4);

  cout << endl << "Mnozenie macierzy: " << endl;
  m4.print();

  m5.store("matrix.txt", "../"); // Zapisanie macierzy do pliku

  cout << endl << "Macierz z pliku: " << endl;
  Matrix matrixFromFile("matrix.txt", "../");

  matrixFromFile.print();
}