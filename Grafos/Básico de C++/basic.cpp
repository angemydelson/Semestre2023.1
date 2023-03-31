#include <iostream>
#include <iomanip>
using namespace std;

int main(){
    int number, horas;
    float valor;
    cin >> number >> horas >> valor;
    float salary = valor * horas;
    std::cout << "NUMBER = " << number <<"\n" << "SALARY = U$ "<< std::fixed << std::setprecision(2) << salary <<"\n";


   
    return 0;
}