#include <iostream>
using namespace std;
int main()
{
    setlocale(0, "");
    int a, b;
    double  c, d;
    cout << "Введите целые числа a и b, а также дробные c и d" << endl;
    cout << "a = ";
    cin >> a;
    cout << "b = ";
    cin >> b;
    cout << "c = ";
    cin >> c;
    cout << "d = ";
    cin >> d;
    cout << "a*b = " << a * b << endl << "a+b = " << a + b << endl << "a-b = " << a - b << endl << "a/b = " << a / b << endl;
    cout << "a*c = " << a * c << endl << "a+c = " << a + c << endl << "a-c = " << a - c << endl << "a/c = " << a / c << endl;
    cout << "d*b = " << d * b << endl << "d+b = " << d + b << endl << "d-b = " << d - b << endl << "d/b = " << d / b << endl;
    cout << "d*c = " << d * c << endl << "d+c = " << d + c << endl << "d-c = " << d - c << endl << "d/c = " << d / c << endl;
    system("pause");
    return 0;
}