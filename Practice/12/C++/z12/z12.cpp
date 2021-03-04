#include <iostream>
using namespace std;
int main()
{
	setlocale(0, "");
	int i, m, n, k;
	cout << endl;
	cin >> m;
	if (m > 1000000000 && m < 0)
	{
		cout << endl;
		return main();
	}
	k = 1;
	for (i = 1; i <= m; i++)
		k = i * k;
	cout << k << endl;
	system("pause");
	return 0;
}