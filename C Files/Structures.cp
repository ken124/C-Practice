#include <stdio.h>

//Structures are kinda like classes in java

struct database {         //struct name
  /* data */
  int id_number;
  int age;
  float salary;
};

int main(int argc, char const *argv[]) {
  struct database employee;       //struct var name;

  employee.age = 22;
  employee.id_number = 1;
  employee.salary = 12000.21;

  printf("Employee Age: %d\n", employee.age);
  printf("Employee ID #: %d\n", employee.id_number);
  printf("Employee Salary: %f\n", employee.salary);

  return 0;
}
