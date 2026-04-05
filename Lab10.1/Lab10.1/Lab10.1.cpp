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
    while (getline(fin, s))
    {
        if (s.length() < 2) continue;

        for (unsigned i = 0; i < s.length() - 1; i++)
        {
            if ((s[i] == 'a' && s[i + 1] == 'a') ||
                (s[i] == 'b' && s[i + 1] == 'b') ||
                (s[i] == 'c' && s[i + 1] == 'c'))
            {
                fin.close();
                return true;
            }
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
        cout << "Found: aa, bb or cc" << endl;
    else
        cout << "Not found" << endl;

    return 0;
}