#include <iostream>
using namespace std;
int main()
{
    setlocale(0, "");
    int h1, m1, h2, m2;
    cin >> h1; cin.get();
    cin >> m1;
    if (h1 > 23 || h1 < 0 || m1 > 59 || m1 < 0)
    {
        cout << "Неправильно! Попробуйте ещё раз!" << endl;
        return main();
    }
    cin >> h2; cin.get();
    cin >> m2;
    if (h2 > 23 || h2 < 0 || m2 > 59 || m2 < 0)
    {
        cout << "Неправильно! Попробуйте ещё раз!" << endl;
        return main();
    }
    if (h2 - h1 == 0 && abs(m2 - m1) <= 15)
        cout << "Встреча состоится" << endl;
    else
        cout << "Встреча не состоится" << endl;
    system("pause");
    return 0;


}