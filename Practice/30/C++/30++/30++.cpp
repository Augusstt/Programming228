// 30++.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include<iostream>
#include <vector>
#include <string>
#include <random>
using namespace std;

struct Coin
{
    int count;
};

struct Rune
{
    int level;
    enum Element
    {
        Fire,
        Air,
        Earth,
        Water,
    }
    elem;
};

struct Weapon
{
    int damage;
    int critical;
    int durability;
};

struct Armor
{
    int guard;
    int durability;
};

struct Item
{
    enum class ItemType
    {
        Coin,
        Rune,
        Weapon, 
        Armor
    } type;
    union four
    {
        Coin c;
        Rune r;
        Weapon w;
        Armor a;
    }value;
};

using LootBox = vector<Item>;

Item Bag()
{
    int k;
    vector<Item> bag;
    Item add;
    for (int i = 0; i < 16; i++)
    {
        switch (i)
        {
        case 0:
        {
            add = { Item::ItemType::Coin };
            add.value.c.count = 1000;
            k = 5000;
            break;
        }
        case 1:
        {
            add = { Item::ItemType::Rune };
            add.value.r.level = 1;
            add.value.r.elem = Rune::Element::Fire;
            k = 600;
            break;
        }
        case 2:
        {
            add = { Item::ItemType::Rune };
            add.value.r.level = 1;
            add.value.r.elem = Rune::Element::Air;
            k = 1400;
            break;
        }
        case 3:
        {
            add = { Item::ItemType::Rune };
            add.value.r.level = 1;
            add.value.r.elem = Rune::Element::Earth;
            k = 700;
            break;
        }
        case 4:
        {
            add = { Item::ItemType::Rune };
            add.value.r.level = 1;
            add.value.r.elem = Rune::Element::Water;
            k = 1300;
            break;
        }
        case 5:
        {
            add = { Item::ItemType::Rune };
            add.value.r.level = 5;
            add.value.r.elem = Rune::Element::Fire;
            k = 60;
            break;
        }
        case 6:
        {
            add = { Item::ItemType::Rune };
            add.value.r.level = 5;
            add.value.r.elem = Rune::Element::Air;
            k = 140;
            break;
        }
        case 7:
        {
            add = { Item::ItemType::Rune };
            add.value.r.level = 5;
            add.value.r.elem = Rune::Element::Earth;
            k = 70;
            break;
        }
        case 8:
        {
            add = { Item::ItemType::Rune };
            add.value.r.level = 5;
            add.value.r.elem = Rune::Element::Water;
            k = 130;
            break;
        }
        case 9:
        {
            add = { Item::ItemType::Rune };
            add.value.r.level = 10;
            add.value.r.elem = Rune::Element::Fire;
            k = 6;
            break;
        }
        case 10:
        {
            add = { Item::ItemType::Rune };
            add.value.r.level = 10;
            add.value.r.elem = Rune::Element::Air;
            k = 14;
            break;
        }
        case 11:
        {
            add = { Item::ItemType::Rune };
            add.value.r.level = 10;
            add.value.r.elem = Rune::Element::Earth;
            k = 7;
            break;
        }
        case 12:
        {
            add = { Item::ItemType::Rune };
            add.value.r.level = 10;
            add.value.r.elem = Rune::Element::Water;
            k = 13;
            break;
        }
        case 13:
        {
            add = { Item::ItemType::Weapon };
            add.value.w.damage = 100;
            add.value.w.critical = 0;
            add.value.w.durability = 100;
            k = 140;
            break;
        }
        case 14:
        {
            add = { Item::ItemType::Weapon };
            add.value.w.damage = 75;
            add.value.w.critical = 50;
            add.value.w.durability = 100;
            k = 140;
            break;
        }
        case 15:
        {
            add = { Item::ItemType::Armor };
            add.value.a.durability = 100;
            add.value.a.guard = 50;
            k = 280;
            break;
        }
        }
        while (k)
        {
            bag.push_back(add);
            k--;
        }
    };
    int random = 1 + rand() % 10000;
    return (bag[random]);
}

Item operator ++ (Item add)
{
    Item item = Bag();
    return item;
}

LootBox& operator << (LootBox& loot, Item i)
{
    loot.push_back(i);
    return loot;
}

ostream& operator << (ostream& ostream, Item i)
{
    if (i.value.c.count == 1000)
        ostream << i.value.c.count << " Coins " << endl;
    if (i.value.r.level == 1 || i.value.r.level == 5 || i.value.r.level == 10)
    {
        switch (i.value.r.elem)
        {
        case 0:
        {
            ostream << "Rune of Fire " << i.value.r.level << " level" << endl;
            break;
        }
        case 1:
        {
            ostream << "Rune of Air " << i.value.r.level << " level" << endl;
            break;
        }
        case 2:
        {
            ostream << "Rune of Earth " << i.value.r.level << " level" << endl;
            break;
        }
        case 3:
        {
            ostream << "Rune of Water " << i.value.r.level << " level" << endl;
            break;
        }
        }
    }
        if (i.value.w.damage == 100 && i.value.w.critical == 0)
            ostream << "God Killer" << endl;
        if (i.value.w.damage == 75 && i.value.w.critical == 50)
            ostream << "Demon Slayer" << endl;
        if (i.value.a.guard == 50)
            ostream << "Bronezhiletka " << endl;
        return ostream;
}

ostream& operator << (ostream& ostream, LootBox loot)
{
    for (int i = 0; i < loot.size(); i++)
    {
        ostream << loot[i] << endl;
    }
    return ostream;
}

LootBox generateLootBox()
{
    LootBox end;
    for (int i = 0; i < 3; i++)
    {
        Item add = {};
        end << ++add;
    }
    return end;
}
int main()
{
    setlocale(0, "");
    string line;
    cout << "Открыть лутбокс? Yes/No" << endl;
    cin >> line;
    if (line == "Y" or line == "yes" or line == "y" or line == "YES" or line == "Yes")
    {
        cout << generateLootBox() << endl;
        return main();
    }
    else if (line == "NO" or line == "N" or line == "n" or line == "no" or line == "No")
    {
        return 0;
    }
    else
    {
        return main();
    }
}


// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл