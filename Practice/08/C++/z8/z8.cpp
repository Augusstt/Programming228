#include <iostream>
#include <cmath>
#include <locale>
using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    double a, d, c;
    char b;
    cin >> a >> b >> c;

    switch (b)
    {
    case '+':
    {
        d = a + c;
        cout << d;
    }
    break;
    case '-':
    {
        d = a - c;
        cout << d;
    }
    break;
    case '*':
    {
        d = a * c;
        cout << d;
    }
    break;
    case '/':
        if (c == 0)
        {
            cout << "Некорректный ввод";
        }
        else
        {
            d = a / c;
            cout << d;
        }
        break;
    case '%':
        if (c == 0)
        {
            cout << "Некорректный ввод";
        }
        else
        {
            d = a / c;
            cout << d;
        }
        break;
    default:
        cout << "Вводим без шуток!";
    }

    return 0;
}