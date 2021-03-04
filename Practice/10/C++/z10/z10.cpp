#include <iostream>
using namespace std;
int main()
{
	int s, l1, l2, r1, r2, x1;
	cin >> s >> l1 >> l2 >> r1 >> r2;
	if (l1 < r1)
		x1 = l1;
	else
		x1 = r1;
	if (x1 + l2 == s)
		cout << x1 << " " << l2 << endl;
	else if (x1 + r2 == s)
		cout << x1 << " " << r2 << endl;
	else {
		if (x1 + l2 == s)
			cout << x1 << " " << l2 << endl;
		else if (x1 + r2 == s)
			cout << x1 << " " << r2 << endl;
		else
			cout << -1 << endl;
	}
	system("pause");
	return 0;
}