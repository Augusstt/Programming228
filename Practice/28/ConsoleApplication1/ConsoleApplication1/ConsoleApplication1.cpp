#include<vector>
#include <iostream>
#include <algorithm>
#include<map>
void print_factorization(unsigned int n)
{
    std::map  <unsigned int, unsigned int> dict;
    int div = 2;
    while (n > 1)
    {
        for (unsigned int i = 2; i <= n; i++)
        {
            if (!(n % i))
            {
                n /= i;

                dict[i] = dict.count(i) ? dict[i] + 1 : 1;
                break;
            }
        }
    }
    std::cout << "1";
    for (auto now : dict)
    {
        if (now.second > 1)
        {
            std::cout << "*" << now.first << "^" << now.second;
        }
        else
        {
            std::cout << "*" << now.first;
        }
    }
}
int main()
{
    unsigned int n;
    std::cin >> n;
    print_factorization(n);
}
