#include<iostream>
using namespace std;
int main()
{
	setlocale(LC_ALL, "ru");
	const int n = 37;
	int a[n];
	int x = 0;
	int q = 0;
	int w = 0;
	int p = 0;
	for (int i = 0; i < n; i++)
	{
		a[i] = 0;
	}
	int red[18] = { 1,3,5,7,9,12,14,16,18,19,21,23,25,27,30,32,34,36 };
	while (1)
	{
		cin >> x;
		if (x < 0)
		{
			break;
		}
		else
		{
			a[x]++;
			for (int i = 0; i <= 17; i++)
			{
				if (x == red[i])
				{
					q++;
					break;
				}
				else if (i == 17)
				{
					w++;
				}
			}
		}
		for (int i = 0; i < n; i++)
		{
			if (a[i] > p) p = a[i];
		}
		for (int i = 0; i < n; i++)
		{
			if (a[i] == p) cout << i << " ";
		}
		cout << endl;
		for (int i = 0; i < n; i++)
		{
			if (a[i] == 0) cout << i << " ";
		}
		cout << endl << "Красные: " << q << " Черные: " << w << endl;
	}
}
