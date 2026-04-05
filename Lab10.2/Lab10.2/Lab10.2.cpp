#include <iostream>
#include <fstream>
#include <string>

using namespace std;

bool Process(char* fname)
{
    ifstream fin(fname);
    if (!fin)
    {
        cerr << "Error opening file" << endl;
        return false;
    }

    string s;
    while (fin >> s)
    {
        if (s.length() > 0 && s[0] == 'a')
        {
            fin.close();
            return true;
        }
    }

    fin.close();
    return false;
}

int main()
{
    char fname[100];
    cout << "enter file name: ";
    cin >> fname;

    if (Process(fname))
        cout << "yes" << endl;
    else
        cout << "no" << endl;

    return 0;
}