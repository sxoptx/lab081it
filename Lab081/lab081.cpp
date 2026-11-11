#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>

using namespace std;

// Функція, яка обчислює кількість груп "while" у рядку
int Count(const char* str)
{
    int k = 0;
    for (int i = 0; str[i] != 0; i++)
        if (str[i] == 'w' && str[i + 1] == 'h' && str[i + 2] == 'i' && str[i + 3] == 'l' && str[i + 4] == 'e')
            k++;
    return k;
}

// Функція, яка замінює кожну групу "while" на "***"
// Результат записує в str (параметр) і повертає у вигляді нового рядка
char* Change(char* str)
{
    char* tmp = new char[strlen(str) + 1];
    char* t = tmp;

    int i = 0;
    while (str[i] != 0)
    {
        if (str[i] == 'w' && str[i + 1] == 'h' && str[i + 2] == 'i' && str[i + 3] == 'l' && str[i + 4] == 'e')
        {
            *t++ = '*';
            *t++ = '*';
            *t++ = '*';
            i += 5;
        }
        else
            *t++ = str[i++];
    }
    *t = '\0';

    strcpy(str, tmp);

    return tmp;
}

int main()
{
    char str[101];

    cout << "Enter string:" << endl;
    cin.getline(str, 100);

    cout << "String contained " << Count(str) << " groups of 'while'" << endl;

    char* dest = Change(str);

    cout << "Modified string (param) : " << str << endl;
    cout << "Modified string (result): " << dest << endl;

    delete[] dest;

    return 0;
}