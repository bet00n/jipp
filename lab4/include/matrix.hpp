#include "../libs/libs.hpp"

using namespace std;

 class Matrix {
private:
  int rows, columns;
  vector <vector <double>> myMatrix;

public:
  Matrix(int vRows, int vColumns) {
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

  Matrix(int vRows) {
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

  Matrix(string filename, string path) {
    ifstream file;
    file.open(path + filename, ios::out);
    if (file.good() == false) {
      cout << endl << "File error" << endl;
      return;
    }
    else {
      file >> Matrix::columns;
      file >> Matrix::rows;
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

  void add(Matrix& m2) {
    for (int i = 0; i < rows; i++) {
      for (int j = 0; j < columns; j++) {
        m2.set(i, j, (myMatrix[i][j] + m2.myMatrix[i][j]));
      }
    }
  }

  void substract(Matrix& m2) {
    for (int i = 0; i < rows; i++) {
      for (int j = 0; j < columns; j++) {
        m2.set(i, j, (myMatrix[i][j] - m2.myMatrix[i][j]));
      }
    }
  }

  void multiply(Matrix& m2) {
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

