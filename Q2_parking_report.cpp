/*
 * Name       : Muhammad Arham Sikander
 * Reg No     : L1S26BSCS0059
 * Assignment : 02 - File Handling
 * Question   : Q2 - Parking Report
 */
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

int main()
{
    ifstream inFile("parking.txt");

    if (!inFile)
    {
        cout << "parking.txt not found!" << endl;
        return 1;
    }

    int d, m, y;
    char slash;

    inFile >> d >> slash >> m >> slash >> y;
    inFile.ignore(100, '\n');
    inFile.ignore(100, '\n');

    ofstream outFile("receipts.txt");

    cout << "Parking report for " << d << "/" << m << "/" << y << endl;
    outFile << "Receipts for " << d << "/" << m << "/" << y << endl;

    char plate[15];
    char longestPlate[15] = "";
    char type;
    char colon1, colon2;

    int inHour, inMinute, outHour, outMinute;
    int vehicles = 0;
    int cars = 0;
    int bikes = 0;
    int totalCollected = 0;
    int longestTime = -1;

    while (inFile >> plate >> type  >> inHour >> colon1 >> inMinute >> outHour >> colon2 >> outMinute)
    {
        int start = inHour * 60 + inMinute;
        int finish = outHour * 60 + outMinute;
        int minutes = finish - start;

        int hours = minutes / 60;
        int remainingMinutes = minutes % 60;

        int chargedHours = (minutes + 59) / 60;

        if (chargedHours == 0)
        {
            chargedHours = 1;
        }

        int fee;

        if (type == 'C')
        {
            fee = chargedHours * 100;
            cars++;
        }
        else
        {
            fee = chargedHours * 40;
            bikes++;
        }

        char vehicleType[5];

        if (type == 'C')
        {
            strcpy(vehicleType, "Car");
        }
        else
        {
            strcpy(vehicleType, "Bike");
        }

        cout << plate << " " << vehicleType << " "
            << hours << " h " << remainingMinutes
            << " min Fee: " << fee << endl;

        outFile << plate << " " << fee << endl;

        vehicles++;
        totalCollected = totalCollected + fee;

        if (minutes > longestTime)
        {
            longestTime = minutes;
            strcpy(longestPlate, plate);
        }
    }

    if (vehicles == 0)
    {
        cout << "No vehicles found!" << endl;
    }
    else
    {
        cout << "Vehicles: " << vehicles << endl;
        cout << "Cars: " << cars << " Bikes: " << bikes << endl;
        cout << "Total collected: " << totalCollected << endl;

        cout << "Longest stay: " << longestPlate << " ("
            << longestTime / 60 << " h "
            << longestTime % 60 << " min)" << endl;
    }

    inFile.close();
    outFile.close();

    return 0;
}