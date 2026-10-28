/*
 * Name       : Muhammad Arham Sikander
 * Reg No     : L1S26BSCS0059
 * Assignment : 02 - File Handling
 * Question   : Q1 - Stock Report (Debugging)
 */

 
#include <iostream>
 // FIX 1: <fstream> is missing so ifstream and ofstream are unknown .
#include <fstream>           
using namespace std;

int main()
{
    ifstream inFile("stock.txt");

    // FIX 2: ! is missing so it doesn't check correctly.
    if (!inFile)
    {
        cout << "stock.txt not found!" << endl;
        return 1;
    }

    // FIX 3: ios::app using append .
    ofstream reorder("reorder.txt", ios::app);

    char code[10];
    int qty, count = 0, low = 0;
    double price;

    // FIX 4: Use double for decimal values .
    double total = 0;

    // FIX 5: Skip the first line because it contains the header.
    inFile.ignore(100, '\n');

    while (count < 50 && inFile >> code >> qty >> price)
    {
        count++;
        total = total + qty * price;

        if (qty < 10)
        {
            // FIX 6: endl starts each reorder item on a new line.
            reorder << code << " " << qty << endl;
            low++;
        }
    }

    inFile.close();
    reorder.close();

    cout << "Items: " << count << endl;
    cout << "Total stock value: " << total << endl;
    cout << "Low stock items: " << low << endl;

    return 0;
}