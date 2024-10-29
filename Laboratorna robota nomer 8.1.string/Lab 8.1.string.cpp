// Lab 8.1
// функції рядків string

#include <iostream>
#include <string>
#include <unordered_set>
#include <Windows.h>

using namespace std;


bool Include(const string& s, const string& cs)
{
    unordered_set<char> charSet(s.begin(), s.end()); 
    for (char c : cs)
    {
        if (charSet.find(c) == charSet.end())
            return false; 
    }
    return true; 
}

string Change(const string& s)
{
    string result;
    size_t pos = 0;

    while (pos < s.length())
    {
        size_t found = s.find("while", pos);
        if (found != string::npos)
        {
            result.append(s, pos, found - pos); 
            result += "**"; 
            pos = found + 5; 
        }
        else
        {
            result.append(s, pos, s.length() - pos); 
            break;
        }
    }
    return result; 
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    string str;
    cout << "Введіть рядок: ";
    getline(cin, str);

    const string cs = "while";
    if (Include(str, cs))
        cout << "yes" << endl;
    else
        cout << "no" << endl;

    string modifiedString = Change(str); 
    cout << "Змінений рядок: " << modifiedString << endl;

    return 0;
}

