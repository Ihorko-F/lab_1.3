#pragma once

struct Money
{
    int grn;
    short int kop;
};

void add(Money& m1, const Money& m2);
void multiply(Money& m, int number);
void normalizeAndRound(Money& m, bool roundFlag);
void print(const Money& m);

void runProgram();