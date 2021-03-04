#include <iostream>
using namespace std;
int main()
{
    setlocale(0, "");
    int count, k, c;
    cin >> c;
    if (c > 1000000000 || c < 0)
    {
        cout << endl;
        return main();
    }
    count = 0;
    k = 2;
    while (k * k <= c && count == 0)
    {
        if (c % k == 0)
            count++;
        k++;
    }
    if (count == 0)
        cout << "Простое" << endl;
    else
        cout << "Составное" << endl;
    system("pause");
    return 0;

}
