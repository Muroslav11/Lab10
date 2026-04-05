#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

struct Route {
    string startPoint;
    string endPoint;
    int routeNumber;
};

void CreateTXT(char* fname) {
    ofstream fout(fname, ios::app); 
    char ch;
    Route r;
    do {
        cout << "enter start point: "; cin >> r.startPoint;
        cout << "enter end point:   "; cin >> r.endPoint;
        cout << "enter route number: "; cin >> r.routeNumber;

        fout << r.startPoint << endl;
        fout << r.endPoint << endl;
        fout << r.routeNumber << endl;

        cout << "continue? (y/n): "; cin >> ch;
    } while (ch == 'y' || ch == 'Y');
    fout.close();
}

void PrintTXT(char* fname) {
    ifstream fin(fname);
    if (!fin) {
        cerr << "Error opening file" << endl;
        return;
    }
    Route r;
    cout << "\n" << setfill('-') << setw(60) << "-" << setfill(' ') << endl;
    cout << "| " << setw(20) << left << "Start Point"
        << "| " << setw(20) << left << "End Point"
        << "| " << setw(10) << left << "Number" << " |" << endl;
    cout << setfill('-') << setw(60) << "-" << setfill(' ') << endl;

    while (fin >> r.startPoint >> r.endPoint >> r.routeNumber) {
        cout << "| " << setw(20) << left << r.startPoint
            << "| " << setw(20) << left << r.endPoint
            << "| " << setw(10) << left << r.routeNumber << " |" << endl;
    }
    cout << setfill('-') << setw(60) << "-" << setfill(' ') << endl;
    fin.close();
}

void ProcessTXT(char* fname, int number) {
    ifstream fin(fname);
    Route r;
    bool found = false;
    while (fin >> r.startPoint >> r.endPoint >> r.routeNumber) {
        if (r.routeNumber == number) {
            cout << "\nRoute found:" << endl;
            cout << "Start: " << r.startPoint << " -> End: " << r.endPoint << endl;
            found = true;
            break;
        }
    }
    if (!found) cout << "\nRoute not found" << endl;
    fin.close();
}

int main() {
    char fname[100];
    int choice, number;

    cout << "enter file name: "; cin >> fname;

    do {
        cout << "\nMain Menu:" << endl;
        cout << "1. CreateTXT (Add)" << endl;
        cout << "2. PrintTXT" << endl;
        cout << "3. ProcessTXT (Search)" << endl;
        cout << "0. Exit" << endl;
        cout << "enter choice: "; cin >> choice;

        switch (choice) {
        case 1:
            CreateTXT(fname);
            break;
        case 2:
            PrintTXT(fname);
            break;
        case 3:
            cout << "enter route number: "; cin >> number;
            ProcessTXT(fname, number);
            break;
        }
    } while (choice != 0);

    return 0;
}