#include <iostream>
#include <iomanip>
#include "include/cpp_httplib/httplib.h"
#include <string>
#include <fstream>
#include <ctime>
#include "include/nlohmann/json.hpp"
#include "include/Loginer.hpp"

using namespace httplib;
using json = nlohmann::json;
using namespace std;

// В этой функции формируем ответ сервера на запрос
void gen_response(const Request& req, Response& res2) {
	// Создаём клиент и привязываем к домену. Туда пойдут наши запросы
	Client cli("http://worldtimeapi.org");
	// Отправляем get-запрос и ждём ответ, который сохраняется в переменной res
	auto res = cli.Get("/api/timezone/Europe/Simferopol");
	// res преобразуется в true, если запрос-ответ прошли без ошибок
	if (res) {
		// Проверяем статус ответа, т.к. может быть 404 и другие
		if (res->status == 200) {
			// В res->body лежит string с ответом сервера
			cout « res->body « endl;
		}
		else {
			cout « "Status code: " « res->status « endl;
		}
	}
	else {
		auto err = res.error();
		cout « "Error code: " « err « endl;
	}
	// Создаём клиент и привязываем к домену. Туда пойдут наши запросы
	Client clin("http://api.openweathermap.org");
	// Отправляем get-запрос и ждём ответ, который сохраняется в переменной wea
	auto wea = clin.Get("/data/2.5/onecall?lat=44.952116&lon=34.102411&exclude=minutly,hourly,alerts,daily&appid=6344d2bfcd7fb080af9274bbfa07a4f7&lang=eng&units=metric");
	// wea преобразуется в true, если запрос-ответ прошли без ошибок
	if (wea) {
		// Проверяем статус ответа, т.к. может быть 404 и другие
		if (wea->status == 200) {
			// В wea->body лежит string с ответом сервера
			cout « wea->body « endl;
		}
		else {
			cout « "Status code: " « wea->status « endl;
		}
	}
	else {
		auto err2 = wea.error();
		cout « "Error code: " « err2 « endl;
	}

	json j = json::parse(res->body);
	// Достаём значение времени
	string time = j["datetime"];
	cout « "Время " « time « endl;


	json j2 = json::parse(wea->body);
	// Достаём значения погодных условий
	int temperatura = j2["current"]["temp"];
	string pogoda = j2["current"]["weather"][0]["description"].get<string>();

	json j3 = temperatura;
	json j4 = pogoda;
	res2.set_content(j3, "text/json; charset=UTF-8");
	res2.set_content(j4, "text/json; charset=UTF-8");

	string strina;
	ifstream file2("fole.html"); // Файловая переменная
	if (file2.is_open())
	{
		getline(file2, strina, '\0');
		file2.close();
	}
	else
	{
		res2.set_content("Error! Could not open `template.html` file.", "text/plain;charset=utf-8");
		return;
	}

	size_t found = strina.find("hourly[i]");
	strina.replace(1, 2, strina);
	;

}
void gen_response_raw(const Request& req, Response& res2) {


	Client cli("http://worldtimeapi.org");
	auto res = cli.Get("/api/timezone/Europe/Simferopol");
	if (res) {
		if (res->status == 200) {
			cout « res->body « endl;
		}
		else {
			cout « "Status code: " « res->status « endl;
		}
	}
	else {
		auto err = res.error();
		cout « "Error code: " « err « endl;
	}
	Client clin("http://api.openweathermap.org");
	auto wea = clin.Get("/data/2.5/onecall?lat=44.952116&lon=34.102411&exclude=minutly,hourly,alerts,daily&appid=3d39302576a79c67051688878116f7c4&lang=eng&units=metric");
	if (wea) {
		if (wea->status == 200) {
			cout « wea->body « endl;
		}
		else {
			cout « "Status code: " « wea->status « endl;
		}
	}
	else {
		auto err2 = wea.error();
		cout « "Error code: " « err2 « endl;
	}

	json j = json::parse(res->body);
	string time = j["datetime"];
	cout « "Время " « time « endl;


	json j2 = json::parse(wea->body);
	int temperatura = j2["current"]["temp"];
	string pogoda = j2["current"]["weather"][0]["description"].get<string>();
	res2.set_content(j2.dump(), "text/json; charset=UTF-8");

}

int main() {
	Server svr; // Создаём сервер (пока-что не запущен)
	svr.Get("/", gen_response); // Вызвать функцию gen_response если кто-то обратиться к корню "сайта"
	std::cout « "Start server... OK\n";
	svr.listen("localhost", 3000);
}