#include <iostream>
using namespace std;
int main()
{
	setlocale(0, "");
	const int N = 9;
	char A[N];
	int i, n, j, w;
	w = 0;
	cout << "Введите количество билетов" << endl;
	cin >> n;
	for (j = 0; j < n; j++)
	{
		{
			for (i = 0; i < N; i++)
				cin >> A[i];
		}
		if (A[0] == 'a' && A[4] == '5' && A[5] == '5' && A[6] == '6' && A[7] == '6' && A[8] == '1')
		{
			for (i = 0; i < N; i++)
				cout << A[i];
			cout << " ";
			w = 1;
		}
	}
	if (w == 0)
		cout << "-1" << endl;
	system("pause");
	return 0;
}