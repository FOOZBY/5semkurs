#include "Header.h"

int main()
{
    //post 9,8 65,4 * 5 / 7 1,5 2 - ^ / 
    //inf (((9,8*65,4)/5)/(7^(1,5-2)))
    //pre  / / * 9,8 65,4 5 ^ 7 - 1,5 2
    setlocale(0, "");
	string str;
    cout << "Выберите тип вводимой записи:\n";
    cout << "0. Префиксная\n";
    cout << "1. Инфиксная\n";
    cout << "2. Постфиксная\n";
    int type;
    cin >> type;
    cout << "Введите запись: ";
    cin.clear();
    cin.ignore(32756, '\n');
    getline(cin, str);
    switch (type)
    {
    case 0:
        str = pre_to_post(str);
        break;
    case 1:
        str = inf_to_post(str);
        break;
    case 2:
        str = post_to_post(str);
        break;
    default:
        cout << "неверно введён тип записи\n";
        break;
    }
    count_post(str);
    system("pause");
}