/*
 * Name       : Muhammad Arham Sikander
 * Reg No     : L1S26BSCS0059
 * Assignment : 02 - File Handling
 * Question   : Q3 - Scholarship List
 */

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

int main()
{
    char path[100];
    char name[30];
    char topName[30] = "";

    cout << "Enter the file name: ";
    cin.getline(path, 100);

    ifstream inFile(path);

    if (!inFile.is_open())
    {   
        cout << "Could not open " << path << "!" << endl;
        return 1;
    }

    int n;

    if (!(inFile >> n))
    {
        inFile.close();

        ofstream outFile("scholarship.txt");
        outFile.close();

        cout << "No students found!" << endl;
        return 0;
    }

    inFile.ignore(100, '\n');

    ofstream outFile("scholarship.txt");

    if (n > 30)
    {
        cout << "Too many students!" << endl;
        inFile.close();
        outFile.close();
        return 1;
    }

  

    int count = 0;
    int eligible = 0;

    double cgpa;
    double total = 0;
    double highest = -1;

    while (count < n && inFile.getline(name, 30, ','))
    {
        if (!(inFile >> cgpa))
        {
            break;
        }

        inFile.ignore(100, '\n');

        cout << "[" << name << "] CGPA: "
            << cgpa << endl;

        total = total + cgpa;
        count++;

        if (cgpa >= 3.50)
        {
            outFile << name << "," << cgpa << endl;
            eligible++;
        }

        if (cgpa > highest)
        {
            highest = cgpa;
            strcpy(topName, name);
        }
    }

    inFile.close();
    outFile.close();

    if (count < n)
    {
        cout << "Warning: only " << count
            << " of " << n << " records found." << endl;
    }

    if (count == 0)
    {
        cout << "No students found!" << endl;
    }
    else
    {
        cout << "Students: " << count << endl;

        cout << "Average CGPA: "
            << total / count << endl;

        cout << "Eligible for scholarship: "
            << eligible << endl;

        cout << "Top student: " << topName
            << " (" << highest << ")" << endl;
    }

    return 0;
}
