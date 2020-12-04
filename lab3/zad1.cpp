#include <iostream>
#include <string>
#include <vector>
#include <time.h>
#include <fstream>

using namespace std;

 class Macierz {
private:
  int rows, columns;
  vector <vector <double>> myMatrix;

public:
  Macierz(int vRows, int vColumns) {
    rows = vRows;
    columns = vColumns;
    vector <double> tempVector;
    for (int i = 0; i < columns; i++) {
      tempVector.push_back(0);
    }
    for (int i = 0; i < rows; i++) {
      myMatrix.push_back(tempVector);
    }
  }

  Macierz(int vRows) {
    rows = vRows;
    columns = vRows;
    vector <double> tempVector;
    for (int i = 0; i < columns; i++) {
      tempVector.push_back(0);
    }
    for (int i = 0; i < rows; i++) {
      myMatrix.push_back(tempVector);
    }
  }

  Macierz(string filename, string path) {
    ifstream file;
    file.open(path + filename, ios::out);
    if (file.good() == false) {
      cout << endl << "File error" << endl;
      return;
    }
    else {
      file >> Macierz::columns;
      file >> Macierz::rows;
      for (int i = 0; i < rows; i++) {
        vector <double> tempVector;
        double element;
        for (int j = 0; j < columns; j++) {
          file >> element;
          tempVector.push_back(element);
        }
        myMatrix.push_back(tempVector);
      }
    }
    file.close();
  }

  int getRows() {
    return rows;
  }

  int getColumns() {
    return columns;
  }

  void set(int n, int m, double val) {
    myMatrix[n][m] = val;
  }

  double get(int n, int m) {
    return myMatrix[n][m];
  }

  void print() {
    for (int i = 0; i < rows; i++) {
      for (int j = 0; j < columns; j++) {
        cout << get(i, j) << " ";
      }
      cout << endl;
    }
  }

  void add(Macierz& m2) {
    for (int i = 0; i < rows; i++) {
      for (int j = 0; j < columns; j++) {
        m2.set(i, j, (myMatrix[i][j] + m2.myMatrix[i][j]));
      }
    }
  }

  void substract(Macierz& m2) {
    for (int i = 0; i < rows; i++) {
      for (int j = 0; j < columns; j++) {
        m2.set(i, j, (myMatrix[i][j] - m2.myMatrix[i][j]));
      }
    }
  }

  void multiply(Macierz& m2) {
    double temp;
    if (columns == m2.rows) {
      for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
          temp = 0;
          for (int k = 0; k < columns; k++) {
            temp += myMatrix[i][k] * m2.myMatrix[k][j];
          }
          m2.set(i, j, temp);
        }
      }
    }
    else {
      cout << endl << "Bledna liczba kolumn lub wierszy" << endl;
      return;
    }
  }

  void store(string filename, string path) {
    fstream file;
    file.open(path + filename, ios::out);
    if (file.good() == false) {
      cout << endl << "File error" << endl;
      return;
    }
    else {
      file << columns << " " << rows << "\n";
      for (int j = 0; j < rows; j++) {
        for (int i = 0; i < columns; i++) {
          file << myMatrix[j][i] << " ";
        }
        file << "\n";
      }
    }
    file.close();
  }
};

int main() {
  srand(time(NULL));
  Macierz test(4, 5);
  Macierz square(6);
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

  Macierz m2(4, 5);

  for (int i = 0; i < m2.getRows(); i++) {
    for (int j = 0; j < m2.getColumns(); j++) {
      m2.set(i, j, rand() % 10);
    }
  }

  Macierz m3(4, 5);

  for (int i = 0; i < m3.getRows(); i++) {
    for (int j = 0; j < m3.getColumns(); j++) {
      m3.set(i, j, rand() % 10);
    }
  }

  Macierz m4(5, 6);

  for (int i = 0; i < m4.getRows(); i++) {
    for (int j = 0; j < m4.getColumns(); j++) {
      m4.set(i, j, rand() % 10);
    }
  }

  Macierz m5(5);

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
  Macierz matrixFromFile("matrix.txt", "../");

  matrixFromFile.print();
}