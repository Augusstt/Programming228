// 29++.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include<map>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <iomanip>
using namespace std;

struct students {
    string name;
    int group;
    int m, p, h, pr;
    map<string, int> exams = { {"math", m},
                              {"phys", p},
                              {"hist", h},
                              {"prog", pr} };
};

template <class T>
vector<T> BozoSort(vector<T> array, bool t = true)
{
    bool sorted = false;
    int n = array.size();
    while (!sorted)
    {
        if (t)
        {
            int index1 = rand() % n;
            int index2 = rand() % n;
            T temp = array[index1];
            array[index1] = array[index2];
            array[index2] = temp;
            sorted = true;
            for (int i = 1; i < n; i++)
            {
                if (array[i - 1] > array[i])
                {
                    sorted = false;
                    break;
                }
            }
        }
        else
        {
            int index1 = rand() % n;
            int index2 = rand() % n;
            T temp = array[index1];
            array[index1] = array[index2];
            array[index2] = temp;
            sorted = true;
            for (int i = 1; i < n; i++)
            {
                if (array[i - 1] < array[i])
                {
                    sorted = false;
                    break;
                }
            }
        }
    }
    return array;
}

ostream& operator << (ostream& out, students stud) {
    out << "+------------+-------+------+------+------+------+\n"
        << "| Name       | Group | Math | Phys | Hist | Prog |\n"
        << "+------------+-------+------+------+------+------+\n"
        << "|" << setw(11) << stud.name << " | " << stud.group << " "
        << "    | " << stud.exams.at("math")
        << "    | " << stud.exams.at("phys")
        << "    | " << stud.exams.at("hist")
        << "    | " << stud.exams.at("prog")
        << "    |\n"
        << "+------------+-------+------+------+------+------+\n";
    return out;
}

ostream& operator << (ostream& out, vector<students> student)
{
    out << "+------------+-------+------+------+------+------+\n"
        << "| Name       | Group | Math | Phys | Hist | Prog |\n"
        << "+------------+-------+------+------+------+------+\n";
    for (const auto& stud : student) {
        out << "|" << setw(11) << stud.name << " | " << stud.group << " "
            << "    | " << stud.exams.at("math")
            << "    | " << stud.exams.at("phys")
            << "    | " << stud.exams.at("hist")
            << "    | " << stud.exams.at("prog")
            << "    |\n"
            << "+------------+-------+------+------+------+------+\n";
    }
    return out;
}

bool operator > (students& a, students& b) {
    return a.name > b.name;
}

bool operator < (students& a, students& b) {
    return a.name < b.name;
}

int main()
{
    srand(time(NULL));
    vector<students> student
    {
        students{"Malfoy D", 1, 5, 5, 5, 5},
        students{"Plov M", 1, 4, 3, 4, 4},
        students{"Umerov T", 3, 3, 2, 2, 3},
        students{"Sheih I", 2, 3, 5, 3, 2},
        students{"Jan P", 3, 3, 3, 4, 3},
        students{"Krisa L", 3, 3, 3, 4, 2},
        students{"Phisihka N", 4, 2, 3, 2, 2},
        students{"Najiha M", 4, 2, 3, 2, 2},
        students{"Mopedovna N", 4, 2, 3, 3, 2},
        students{"Dunya J", 2, 5, 5, 5, 4},
    };

    vector<students> have_two;
    for (int i = 0; i < 10; i++)
    {
        if (student[i].exams.at("math") == 2 or student[i].exams.at("phys") == 2 or student[i].exams.at("hist") == 2 or student[i].exams.at("prog") == 2)
            have_two.push_back(student[i]);
    }

    if (have_two.empty())
    {
        cout << "Not found" << endl;
        return 0;
    }
    else
        cout << BozoSort(have_two);

    cout << endl << "Expulsion" << endl;
    int i = rand() % have_two.size();
    cout << have_two[i];
}
// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
