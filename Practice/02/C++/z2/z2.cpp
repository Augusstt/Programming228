#include <iostream>
using namespace std;
int main()
{
    setlocale(0, "");
    int s, p;
    double k, pi;
    s = 3;
    p = 3.14;
    k = 3;
    pi = 3.14;
    cout << s << endl << p << endl << k << endl << pi << endl;
    cout << "int - тип данных, который используется для переменных, содержащих целые числа, а double - дробные. Поэтому при приравнии значения дробного числа к переменной с типом int, программа автоматически округляет по правилам математики и выводит целое число." << endl;
    system("pause");
    return 0;


}