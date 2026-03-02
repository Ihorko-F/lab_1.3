#include <iostream>
#include <cstdio>
#include "Money.h"

using namespace std;

void normalizeAndRound(Money& m, bool roundFlag)
{
    if (m.kop >= 100)
    {
        m.grn += m.kop / 100;
        m.kop %= 100;
    }

    if (!roundFlag)
        return;

    int remainder = m.kop % 10;

    if (remainder >= 5)
        m.kop += (10 - remainder);
    else
        m.kop -= remainder;

    if (m.kop >= 100)
    {
        m.grn += 1;
        m.kop -= 100;
    }
}

void add(Money& m1, const Money& m2)
{
    m1.grn += m2.grn;
    m1.kop += m2.kop;
    normalizeAndRound(m1, false);
}

void multiply(Money& m, int number)
{
    m.grn *= number;
    m.kop *= number;
    normalizeAndRound(m, false);
}

void print(const Money& m)
{
    cout << m.grn << " UAH " << m.kop << " kop" << endl;
}

void runProgram()
{
    FILE* file;
    errno_t err = fopen_s(&file, "input.txt", "r");

    if (err != 0)
    {
        cout << "Error opening file!" << endl;
        return;
    }

    Money total = {0, 0};

    int grn, quantity;
    short int kop;

    while (fscanf_s(file, "%d %hi %d %*s", &grn, &kop, &quantity) == 3)
    {
        Money price = { grn, kop };

        multiply(price, quantity);
        add(total, price);
    }

    fclose(file);

    cout << "Total amount: ";
    print(total);

    normalizeAndRound(total, true);

    cout << "Amount to pay (rounded): ";
    print(total);
}