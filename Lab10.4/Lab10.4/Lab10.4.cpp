#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int getValidInt(string msg) {
    int x;
    while (true) {
        cout << msg;
        if (cin >> x) {
            cin.ignore(10000, '\n');
            return x;
        }
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "Error! Enter integer\n";
    }
}

void CreateTXT(char* fname) {
    ofstream f(fname, ios::app);
    char ch;
    string s;
    do {
        cout << "Enter line: ";
        getline(cin, s);
        f << s << endl;

        cout << "Continue? (y/n): ";
        cin >> ch;
        cin.ignore(10000, '\n'); 
    } while (ch == 'y' || ch == 'Y');
    f.close();
}

void PrintTXT(char* fname) {
    ifstream f(fname);
    if (!f) {
        cout << "File not found!\n";
        return;
    }
    string s;
    cout << "\n--- FILE CONTENT ---\n";
    while (getline(f, s))
        cout << s << endl;
    cout << "--------------------\n";
    f.close();
}

int CountStartChar(char* fname, char c) {
    ifstream f(fname);
    string s;
    int k = 0;
    while (getline(f, s)) {
        if (s.length() > 0 && s[0] == c)
            k++;
    }
    f.close();
    return k;
}

int CountSameStartEnd(char* fname) {
    ifstream f(fname);
    string s;
    int k = 0;
    while (getline(f, s)) {
        if (s.length() > 0 && s[0] == s[s.length() - 1])
            k++;
    }
    f.close();
    return k;
}

int CountAllSame(char* fname) {
    ifstream f(fname);
    string s;
    int k = 0;
    while (getline(f, s)) {
        if (s.length() == 0) continue;
        bool ok = true;
        for (size_t i = 1; i < s.length(); i++) {
            if (s[i] != s[0]) {
                ok = false;
                break;
            }
        }
        if (ok) k++;
    }
    f.close();
    return k;
}

int CountEmpty(char* fname) {
    ifstream f(fname);
    string s;
    int k = 0;
    while (getline(f, s)) {
        if (s.length() == 0)
            k++;
    }
    f.close();
    return k;
}

void WriteResult(char* outname, int k1, int k2, int k3, int k4) {
    ofstream g(outname);
    g << "1. Lines starting with given char: " << k1 << endl;
    g << "2. Lines with same start and end: " << k2 << endl;
    g << "3. Lines with all identical chars: " << k3 << endl;
    g << "4. Empty lines: " << k4 << endl;
    g.close();
}

int main() {
    char fname[100], resName[100];
    int choice;

    cout << "Enter source file name: ";
    cin >> fname;

    do {
        cout << "\n===== MAIN MENU =====\n";
        cout << "1. Create / Edit file\n";
        cout << "2. Print file content\n";
        cout << "3. Analyze and save results\n";
        cout << "0. Exit\n";

        choice = getValidInt("Choice: ");

        switch (choice) {
        case 1:
            CreateTXT(fname);
            break;
        case 2:
            PrintTXT(fname);
            break;
        case 3:
            char target;
            cout << "Enter char to count start lines: ";
            cin >> target;
            cout << "Enter result file name: ";
            cin >> resName;

            int k1 = CountStartChar(fname, target);
            int k2 = CountSameStartEnd(fname);
            int k3 = CountAllSame(fname);
            int k4 = CountEmpty(fname);

            WriteResult(resName, k1, k2, k3, k4);

            cout << "\nAnalysis complete. Results saved to " << resName << endl;
            break;
        }
    } while (choice != 0);

    return 0;
}