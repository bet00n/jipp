#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

bool compare(pair<string, double>& x, pair<string, double>& y) {
  return x.second < y.second;
}

class Employee {
public:
  string id;  //identyfikator pracownika
  string name;
  string surname;
  string departmentId;  //identyfikator działu w którym pracuje dane osoba
  string position;  //stanowisko na którym pracuje dana osoba

  Employee(string id, string name, string surname, string position)
    : id(id), name(name), surname(surname), position(position)
  {}
};

class HRMS {
public:
  vector<Employee> allEmployees;  //kontener w którym będą przechowywani wszyscy pracownicy
  map<string, string> employeeToDepartment;  //kontener w którym będzie przechowywane mapowanie
  map<string, double> salaries;  //kontener przechowywujący informacje o zarobkach pracowników

  void add(Employee employee, string departmentId, double salary) {
    employee.departmentId = departmentId;
    allEmployees.push_back(employee);
    salaries[employee.id] = salary;
    employeeToDepartment[employee.id] = departmentId;
  }

  void printDepartment(string departmentId) {
    cout << "Employees in department " << departmentId << ": " << endl;
    for (auto& it : employeeToDepartment) {
      if (it.second == departmentId) {
        cout << "Employee Id: " << it.first << " => " << "Department Id: " << it.second << endl;
      }
    }
  }

  void changeSalary(string employeeId, double salary) {
    salaries[employeeId] = salary;  
  }

  void printSalaries() {
    cout << "Salaries: " << endl;
    for (auto& it : salaries) {
      cout << "Employee Id: " << it.first << " => " << it.second << " $" << endl;
    }
  }

  void printSalariesSorted() {
    vector<pair<string, double>> V;
    for (auto& it : salaries) {
      V.push_back(it);
    }
    sort(V.begin(), V.end(), compare);
    cout << "Salaries Sorted: " << endl;
    for (auto& it : V) {
      cout << "Employee Id: " << it.first << " => " << it.second << endl;
    }
  }
};

int main() {
  Employee emp1("A", "Adam", "Antyk", "Aktor");
  Employee emp2("B", "Beata", "Brodka", "Brukarz");
  Employee emp3("C", "Czarek", "Czarny", "Ceglarz");
  Employee emp4("D", "Dariusz", "Dąb", "Drwal");
  Employee emp5("E", "Ewa", "Ełk", "Egzorcystka");
  Employee emp6("F", "Filip", "Fudala", "Flecista");
  Employee emp7("G", "Grzegorz", "Grudziądz", "Geolog");
  Employee emp8("H", "Halina", "Harakiri", "Haker");
  Employee emp9("I", "Izyda", "Inna", "Inspektor");
  Employee emp10("J", "Jan", "Juhas", "Jubiler");

  HRMS HR;
  HR.add(emp1, "1", 13000);
  HR.add(emp2, "2", 70000);
  HR.add(emp3, "3", 12000);
  HR.add(emp4, "1", 8000);
  HR.add(emp5, "2", 3000);
  HR.add(emp6, "3", 12000);
  HR.add(emp7, "1", 16000);
  HR.add(emp8, "2", 5000);
  HR.add(emp9, "3", 2000);
  HR.add(emp10, "1", 5000);

  HR.printDepartment("1");
  cout << endl << endl;
  HR.printDepartment("2");
  cout << endl << endl;
  HR.printDepartment("3");
  cout << endl << endl;
  HR.printSalaries();
  cout << endl << endl;
  HR.changeSalary("A", 20000);
  HR.changeSalary("J", 5500);
  HR.changeSalary("E", 10000);
  HR.printSalariesSorted();
  cout << endl << endl;
}