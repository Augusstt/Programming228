#include <iostream>
#include <cmath>
#include <locale>
using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");

    double a;
    double b;
    double c;
    double x;
    double f;
    double g;
    cout << "Введите значение a: ";
    cin >> a;
    cout << "Введите значение b: ";
    cin >> b;
    cout << "Введите значение c: ";
    cin >> c;
    if (a == 0 && b == 0)
    {
        if (c == 0)
        {
            cout << "Все корни верны";
        }
        else
        {
            cout << "Нет корней";
        }
    }
    else if (a == 0)
    {
        if (c == 0)
        {
            cout << "Корнем уравнения являеться 0";
        }
        else
        {
            f = -1 * (c / b);
            cout << "Корень равен " << f << endl;
        }
    }
    else if (b == 0)
    {
        if (c == 0)
        {
            cout << "Корень уравнения 0";
        }
        else if ((-1 * (c / a)) > 0)
        {
            x = sqrt((-1 * (c / a)));
            cout << "Первый корень равен " << x << endl;
            x = -1 * sqrt((-1 * (c / a)));
            cout << "Второй корень равен " << x << endl;
        }
        else
        {
            cout << "Корни невещественные";
        }

    }
    else if (c == 0)
    {
        cout << "Первый корень равен" << 0 << endl;
        x = b / a;
        cout << "Второй корень равен " << x << endl;
    }
    else
    {
        if ((b * b - 4 * a * c) > 0)
        {
            x = (-1 * b + sqrt(b * b - 4 * a * c)) / (2 * a);
            cout << "Первый корень равен " << x << endl;
            x = (-1 * b - sqrt(b * b - 4 * a * c)) / (2 * a);
            cout << "Второй корень равен " << x << endl;
        }
        else if ((b * b - 4 * a * c) < 0)
        {
            cout << "Корни невещественные." << endl;
        }
        else
        {
            x = (-1 * b + sqrt(b * b - 4 * a * c)) / (2 * a);
            cout << "Корень равен " << x << endl;
        }
    }
    return 0;
}