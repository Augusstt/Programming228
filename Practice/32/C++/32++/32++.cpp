// 32++.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <sstream>
#include <vector>
#include <array>
#include <string>
#include <fstream>
#include <algorithm>
using namespace std;

string ReplaceAll(std::string str, const std::string& from, const std::string& to) {
	size_t start_pos = 0;
	while ((start_pos = str.find(from, start_pos)) != std::string::npos) {
		str.replace(start_pos, from.length(), to);
		start_pos += to.length(); 
	}
	return str;
}

struct Passenger
{
	int id;
    bool survival;
    int pclass;
    string name;
    string sex;
    int age;
    int sibsp;
    int parch;
    string ticket;
    float fare;
    string cabin;
    string embarked;
};

std::vector<std::vector<std::string>> parse_cvs(
	std::istream& out,
	char end_ch = '\r',
	char quote_ch = '"',
	char sep_ch = ',')
{
	std::string line;
	std::string buffer;

	std::vector<std::string> seperated_string;
	std::vector<std::vector<std::string>> result;

	char quote_depth = 0;
	char pos = 0;

	while (getline(out, line, end_ch)) {
		pos = 0;
		quote_depth = 0;

		for (char ch : line) {
			if (ch == sep_ch) {
				switch (quote_depth) {
				case 0:
					seperated_string.push_back(buffer);
					buffer.clear();
					++pos;
					continue;
				case 2:
					seperated_string.push_back(buffer);
					buffer.clear();
					quote_depth = 0;
					++pos;
					continue;
				}
			}
			if (ch == quote_ch) {
				switch (quote_depth) {
				case 0:
					quote_depth = 1;
					continue;
				case 1:
					quote_depth = 2;
					continue;
				case 2:
					buffer.push_back(quote_ch);
					quote_depth = 1;
					continue;
				}
			}
			buffer.push_back(ch);
		}
		seperated_string.push_back(buffer);
		buffer.clear();

		result.push_back(seperated_string);
		seperated_string.clear();
	}
	return result;
}

istream& operator >> (istream& i, vector<Passenger>& passengers)
{
	auto matrix = parse_cvs(i);
	matrix.erase(matrix.begin());

	for (auto row : matrix) {
		Passenger p;

		p.id = std::stoi(row[0]);
		p.survival = std::stoi(row[1]);
		p.pclass = std::stoi(row[2]);
		p.name = row[3];
		p.sex = row[4];
		p.age = row[5] == "" ? 0 : std::stof(row[5]);
		p.sibsp = std::stoi(row[6]);
		p.parch = std::stoi(row[7]);
		p.ticket = row[8];
		p.fare = std::stof(row[9]);
		p.cabin = row[10];
		p.embarked = row[11][0];

		passengers.push_back(p);
	}

	return i;
}

ostream& operator << (ostream& o, vector <Passenger>& passengers)
{
	char sep = ',';
	char end = '\r';
	for (auto& pass : passengers) {
		std::string name = pass.name;
		name = ReplaceAll(name, "\"", "\"\"");

		o << pass.id << sep
			<< pass.survival << sep
			<< int(pass.pclass) << sep
			<< '"' << name << '"' << sep
			<< pass.sex  << sep
			<< int(pass.age) << sep
			<< int(pass.sibsp) << sep
			<< int(pass.parch) << sep
			<< pass.ticket << sep
			<< pass.fare << sep
			<< pass.cabin << sep
			<< pass.embarked
			<< end << std::flush;
	}
	return o;
}

int main()
{
    setlocale(LC_ALL, "rus");
    vector<Passenger> passengers;
    ifstream fin("train.csv");
	ofstream res("res.csv");
    fin >> passengers;

    vector<Passenger> surv_fem;
	sort(passengers.begin(), passengers.end(), [&](Passenger a, Passenger b) { return a.age < b.age; });
	for (auto& pass : passengers) {
		if (pass.sex == "female" && pass.pclass == 1 && pass.survival == 1) {
			surv_fem.push_back(pass);
		}
	}
	res << surv_fem;
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
