#include <iostream>
using namespace std;

void print_factorization(unsigned int n)
{
    int i = 2;
    while (n > 1)
    {
        int k = 0;
        while (n % i == 0)
        {
            k++;
            n = n / i;
        }
        if (k > 0)
        {
            cout << i;
            if (k > 1)
                cout << "^" << k;
            if (n > 1)
                cout << "*";
        }
        i++;
    }

}
int main()
{
    setlocale(0, "");
    int n;
    cout << "Введите число" << endl;
    cin >> n;

    print_factorization(n);
}