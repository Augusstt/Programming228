#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <cpp_httplib/httplib.h>
#include <nlohmann/json.hpp>

int mode = 0;
bool tts_bool = true;
int i = 0;






using json = nlohmann::json;

using namespace httplib;


json config() {
    std::ifstream conf_file("config.json");
    json conf;
    std::string str;
    if (conf_file.is_open())
    {
        getline(conf_file, str, '\0');
        conf = json::parse(str);
        conf_file.close();

    }
    return conf;
}


int count() {
    json conf = config();
    int c = 0;
    bool flag = true;
    while (flag)
    {
        if (to_string(conf["webhooks"][c]) != "null") {
            c++;
        }
        else
        {
            flag = false;
        }

    }
    return c;
}

std::string File_parse(std::string FileName) {
    std::ifstream file_html(FileName);
    std::string str;
    if (file_html.is_open()) {
        getline(file_html, str, '\0');
        file_html.close();
    }
    return str;
}

void delet(std::string link) {
    json conf = config();



    int leng = count();
    for (int i = 0; i < leng; i++)
    {
        if ('"' + link + '"' == to_string(conf["webhooks"][i])) {
            conf["webhooks"].erase(conf["webhooks"].begin() + i);
            std::ofstream conf_file("config.json");
            conf_file << conf;
        }
    }

}

void Sett(std::string set) {
    json conf = config();

    std::ofstream File_config("config.json");


    conf["webhooks"].push_back(set);

    File_config << conf;

}

std::string FileHtml() {
    std::string in = File_parse("index.html");
    std::string link = "http://localhost:1234/Webhooks?del=";
    std::string n;
    std::string ad = File_parse("add.html");
    json conf = config();

    int num = in.find("{webhooks_list}");
    in.replace(num, 15, "");
    if (to_string(conf["webhooks"][0]) == "null") {
    }
    else
    {
        for (int i = 0; i < count(); i++)
        {
            n = ad;
            int f = n.find("{Webhook URL}");
            n.replace(f, 13, conf["webhooks"][i]);

            int s = n.find("?{webhook_URL}}");
            n.replace(s, 15, conf["webhooks"][i]);

            in.replace(num, 0, n);
        }
    }
    return in;
}

std::string basket(json req) {
    i += 1;
    json j = json::parse(File_parse("check.json"));
    j["user_id"] = req["session"]["user"]["user_id"];
    json s = {
        {"item", req["request"]["nlu"]["tokens"][3]},
        {"price", req["request"]["nlu"]["entities"][0]["value"]}
    };
    j["check"].push_back(s);
    std::ofstream Check_File("check.json");

    Check_File << j;

    return "";
}

std::string del(json req) {
    json check = json::parse(File_parse("check.json"));
    std::string ret = "no";
    for (int s = 0; s < i; s++)
    {
        if (check["check"][s]["item"] == req["request"]["nlu"]["tokens"][3])
        {
            ret = "ok";
            check["check"].erase(check["check"].begin() + s);
        }
    }
    std::ofstream Check_File("check.json");

    Check_File << check;
    i -= 1;
    return ret;
}

void clear() {
    i = 0;
    json j = json::parse(File_parse("check.json"));
    j["check"] = {};
    std::ofstream Check_File("check.json");
    Check_File << j;

}

int summ() {
    json j = json::parse(File_parse("check.json"));
    int sum = 0;
    for (int s = 0; s < i; s++)
    {
        sum += j["check"][s]["price"];
    }
    return sum;
}

std::string propert() {
    json j = json::parse(File_parse("check.json"));

    std::string str;
    for (int s = 0; s < i; s++)
    {
        str += to_string(j["check"][s]["item"]) + '\t' + to_string(j["check"][s]["price"]) + '\n';
    }
    return str;
}

void end_of_purchase() {
    json conf = config();
    json check = json::parse(File_parse("check.json"));

    std::string str;
    int c = count();
    for (int i = 0; i < c; i++)
    {
        str = conf["webhooks"][i];
        Client cli(str.c_str());
        auto res = cli.Post("/", to_string(check), "application/json");
        if (res) {
            // Проверяем статус ответа, т.к. может быть 404 и другие
            if (res->status == 200) {
                // В res->body лежит string с ответом сервера
                std::cout << res->body << std::endl;
            }
            else {
                std::cout << "Status code: " << res->status << std::endl;
            }
        }
        else {
            auto err = res.error();
            std::cout << "Error code: " << err << std::endl;
        }
    }

}


std::string answer(std::string command, json req) {
    json answere = json::parse(File_parse("hello.json"));
    std::string tts;
    std::string text;
    json help_state_buttons = {

    {
        {"title", u8"Корзина"},
        {"hide", true}
    },
    {
        {"title", u8"Выйти из этого режима"},
        {"hide", true}
    }
    };
    json talk_no = {

   {
       {"title", u8"Помощь"},
       {"hide", true}
   },
   {
       {"title", u8"Говорить"},
       {"hide", true}
   }
    };
    json button_basket = {
        {
            {"title",u8"Очистить корзину"},
            {"hide",true}
        },
        {
            {"title",u8"Что в корзине"},
            {"hide",true}
        },
        {
            {"title",u8"сумма"},
            {"hide",true}
        },
        {
            {"title",u8"завершить покупку"},
            {"hide",true}
        },
        {

            {"title", u8"Выйти из этого режима"},
            {"hide", true}
        }
    };


    if (command == u8"выйти из этого режима")
    {
        text = u8"Что-то не так?";
        if (tts_bool) {
            tts = u8"Что-то не так?";
        }
        else {
            answere["response"]["buttons"] = talk_no;
            tts = "";
        }
        answere["response"]["text"] = text;
        answere["response"]["tts"] = tts;

        mode = 0;
    }
    else if (command == u8"молчать") {
        text = u8"Молчу,молчу";
        tts = u8"";
        answere["response"]["text"] = text;
        answere["response"]["tts"] = tts;
        answere["response"]["buttons"] = talk_no;
        tts_bool = false;
    }
    else if (command == u8"говорить") {
        text = u8"ОК";
        tts = u8"ok";
        answere["response"]["text"] = text;
        answere["response"]["tts"] = tts;
        tts_bool = true;
    }
    else if (mode == 0 && command == u8"помощь") {
        text = u8"Корзина. Поможет организовать покупки";
        if (tts_bool) {
            tts = u8"Корзина. Поможет организовать покупки";
        }
        else {
            tts = "";
        }
        answere["response"]["text"] = text;
        answere["response"]["tts"] = tts;
        answere["response"]["buttons"] = help_state_buttons;
        mode += 1;
    }
    else if (mode == 1 && command == u8"корзина")
    {
        text = u8"Чтобы что-нибудь добавить в корзину \nНужно написать команду 'Добавь в корзину' \nНапример \n'Добавь в корзину огурцы 20 рублей' \nЧтобы что-нибудь удалить из корзины \nНужно написать команду 'Удалить из корзины' \nНапример \n'удалить из корзины огурцы'";
        if (tts_bool) {
            tts = u8"Чтобы что-нибудь добавить в корзину \nНужно написать команду 'Добавь в корзину' \nНапример \n'Добавь в корзину огурцы 20 рублей' \nЧтобы что-нибудь удалить из корзины \nНужно написать команду 'Удалить из корзины' \nНапример \n'удалить из корзины огурцы'";
        }
        else {
            tts = "";
        }
        answere["response"]["text"] = text;
        answere["response"]["tts"] = tts;
        answere["response"]["buttons"] = button_basket;
        mode += 1;
    }
    else if (mode == 2)
    {
        if (req["request"]["nlu"]["tokens"][0] == u8"добавь") {

            basket(req);
            text = u8"Добавлено";
            if (tts_bool) {
                tts = u8"добавлено";
            }
            else
            {
                tts = "";
            }

        }
        else if (req["request"]["nlu"]["tokens"][0] == u8"удалить")
        {
            if (i != 0) {
                std::string d = del(req);
                if (d == "ok") {
                    text = u8"Удалено";
                    if (tts_bool) {
                        tts = u8"удалено";
                    }
                    else
                    {
                        tts = "";
                    }
                }
                else
                {
                    text = u8"Товара в корзине нет";
                    if (tts_bool) {
                        tts = u8"Товара в корзине нет";
                    }
                    else
                    {
                        tts = "";
                    }
                }
            }
            else
            {
                text = u8"Корзина и так пуста";
                if (tts_bool) {
                    tts = u8"Корзина и так пуста";
                }
                else
                {
                    tts = "";
                }
            }


        }
        else if (command == u8"очистить корзину") {
            clear();
            text = u8"Корзина пуста";
            if (tts_bool) {
                tts = u8"корзина пуста";
            }
            else
            {
                tts = "";
            }
        }
        else if (command == u8"сумма") {
            if (i != 0) {
                std::string sum = std::to_string(summ());
                text = sum;
                if (tts_bool) {
                    tts = sum;
                }
                else
                {
                    tts = "";
                }
            }
            else
            {
                text = u8"Корзина пуста";
                if (tts_bool) {
                    tts = u8"Корзина пуста";
                }
                else
                {
                    tts = "";
                }
            }
        }
        else if (command == u8"что в корзине") {
            if (i != 0) {
                std::string prop = propert();
                text = prop;
                if (tts_bool) {
                    tts = prop;
                }
                else
                {
                    tts = "";
                }
            }
            else
            {
                text = u8"Корзина пуста";
                if (tts_bool) {
                    tts = u8"Корзина пуста";
                }
                else
                {
                    tts = "";
                }
            }
        }
        else if (command == u8"завершить покупку") {
            end_of_purchase();
            text = u8"OK";
            if (tts_bool) {
                tts = u8"OK";
            }
            else
            {
                tts = "";
            }
            clear();
        }
        else {
            text = u8"Такой команды нет";
            if (tts_bool) {
                tts = u8"такой команды нет";
            }
            else {
                tts = "";
            }
        }

        answere["response"]["text"] = text;
        answere["response"]["tts"] = tts;
        answere["response"]["buttons"] = button_basket;
    }
    else
    {
        text = u8"Такой команды нет";
        if (tts_bool) {
            tts = u8"такой команды нет";
        }
        else {
            answere["response"]["buttons"] = talk_no;
            tts = "";
        }
        answere["response"]["text"] = text;
        answere["response"]["tts"] = tts;
    }
    return to_string(answere);
}

void gen_response(const Request& req, Response& res) {
    res.set_content(FileHtml(), "text/html; charset=UTF-8");
}

void gen_response_webhooks(const Request& req, Response& res) {

    if (req.has_param("del")) {
        delet(req.get_param_value("del"));
    }
    else if (req.has_param("set"))
    {
        Sett(req.get_param_value("set"));
    }
    res.set_content(FileHtml(), "text/html; charset=UTF-8");
}

void post_respons(const Request& req, Response& res) {
    // Выводим на экран тело запроса
    std::string str = "";
    // Отправляем ответ
    json j = json::parse(req.body.c_str());
    if (j["session"]["new"]) {
        str = File_parse("hello.json");
        mode = 0;


        json j = json::parse(File_parse("check.json"));
        j["user_id"] = "";
        j["check"] = {};
        std::ofstream Check_File("check.json");
        Check_File << j;


    }
    else
    {

        str = answer(j["request"]["command"], j);

    }
    res.set_content(str, "application/json; charset=UTF-8");
}


int main() {
    Server svr;
    svr.Get("/Webhooks", gen_response);
    svr.Post("/Webhooks", gen_response_webhooks);
    svr.Post("/", post_respons);
    std::cout << "Start server... OK\n";
    svr.listen("localhost", 1234);
}