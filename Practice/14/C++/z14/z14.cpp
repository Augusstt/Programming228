#include <iostream>
using namespace std;
int main()
{
    setlocale(0, "");
    int n, count, i;
    cin >> n;
    if (n > 1000000000000000 || n < 0)
    {
        cout << "Неправильно! Попробуйте ещё раз!" << endl;
        return main();
    }
    count = 0;
    for (i = 1; i <= n; i = i * 2)
        count++;
    cout << count << endl;
    system("pause");
    return 0;
}