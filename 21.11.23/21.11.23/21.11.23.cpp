#include <iostream>
#include <ctime>
using namespace std;
struct DateBuy {
    int day;
    int month;
    int year;
    int daydevice;
    int monthdevice;
    int yeardevice;
};

struct Device {
    string devicetype;
    string devicename;
    string devicemodel;
    string brand;
    float price;
    DateBuy guarantee;
    int daytoday;
    int monthtoday;
    int yeartoday;
};

void RandomDevice(Device& d)
{
    cout << "Тип девайса: ";
    cin >> d.devicetype;
    cout << "Название девайса ";
    cin >> d.devicename;
    cout << "Модель девайса ";
    cin >> d.devicemodel;
    cout << "Бренд девайса ";
    cin >> d.brand;
    cout << "Ведите цену ";
    cin >> d.price;
    if (d.price < 0)
    {
        cout << "Неверная цена: " << "\n";
        throw "Ценовая ошибка";
    }
    cout << "Введите день: ";
    cin >> d.daytoday;
    if (d.daytoday < 0 || d.daytoday > 31)
    {
        cout << "Неверный день: " << "\n";
        throw "Ошибка дня";
    }
    cout << "Веедите месяц: ";
    cin >> d.monthtoday;
    if (d.monthtoday < 0 || d.monthtoday > 12)
    {
        cout << "Невереный месяц: " << "\n";
        throw "Ошибка месяца";
    }
    cout << "Введите год: ";
    cin >> d.yeartoday;
    if (d.yeartoday < 0)
    {
        cout << "Неверный год " << "\n";
        throw "Ошибка года";
    }
    d.guarantee.day = rand() % 28 + 1;
    d.guarantee.month = rand() % 12 + 1;
    d.guarantee.year = rand() % 4 + 2021;
    d.guarantee.daydevice = rand() % 28 + 1;
    d.guarantee.monthdevice = rand() % 12 + 1;
    d.guarantee.yeardevice = rand() % 3 + 2020;
}

void PrintDevice(const Device& d)
{
    cout << d.devicetype << "\n";
    cout << d.devicename << "\n";
    cout << d.devicemodel << "\n";
    cout << d.brand << "\n";
    cout << d.price << "$" << "\n";
    cout << "Покупка: " << d.guarantee.daydevice << "." << d.guarantee.monthdevice << "." << d.guarantee.yeardevice << "\n";
    cout << "Гарантия: " << d.guarantee.day << "." << d.guarantee.month << "." << d.guarantee.year << "\n";
}

void Guarantee(Device& d)
{
    if (d.yeartoday > d.guarantee.year)
    {
        cout << "Гарантия инактивна" << "\n";
    }
    else if (d.yeartoday < d.guarantee.year)
    {
        cout << "Гарантия активна" << "\n";
    }
    else if (d.yeartoday == d.guarantee.year and d.monthtoday < d.guarantee.month and d.daytoday < d.guarantee.day)
    {
        cout << "Гарантия просрочена" << "\n";
    }
    else if (d.yeartoday == d.guarantee.year and d.monthtoday > d.guarantee.month and d.daytoday > d.guarantee.day)
    {
        cout << "Гарантия инактивна" << "\n";
    }
    else if (d.yeartoday == d.guarantee.year and d.monthtoday == d.guarantee.month and d.daytoday < d.guarantee.day)
    {
        cout << "Гарантия просрочена" << "\n";
    }
    else if (d.yeartoday == d.guarantee.year and d.monthtoday == d.guarantee.month and d.daytoday > d.guarantee.day)
    {
        cout << "Гарантия инактивна" << "\n";
    }
    else
        cout << "Сегодня последний день";
}
int main()
{
    setlocale(LC_ALL, "Russian");
    srand(time(NULL));
    Device e;
    RandomDevice(e);
    PrintDevice(e);
    Guarantee(e);
}