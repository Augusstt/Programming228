#include <iostream>
#include <iterator>
#include <set>

using namespace std;

int main() {
    int n, t;
    setlocale(0, "");
    cout << "Введите колличество сигналов" << endl;
    cin >> n;
    multiset<int> a;
    cout << "Введите последовательность сигналов" << endl;
    for (int i = 0; i < n; ++i) {
        cin >> t;
        a.insert(t);
        int k = 0;//как счётчик
        multiset<int> b;
        for (auto l = a.begin(); l != a.end() && k < 5; ++l, ++k)
            b.insert(*l);

        copy(b.crbegin(), b.crend(), ostream_iterator<int>(cout, " ")); //cr - изменяет элементы в том случае, если нашёлся маньший минимального, который был найден до этого

        cout << '\n';
    }
}