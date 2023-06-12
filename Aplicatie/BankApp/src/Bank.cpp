#include "Bank.h"
#include <iostream>
using namespace std;

BankAccount::BankAccount(const string& numarulContului, double initialBalance)
    : numarulContului(numarulContului), balantaContului(initialBalance) {}

BankAccount::~BankAccount()
{
}

string BankAccount::getNumarulContului() const
{
    return numarulContului;
}

double BankAccount::getBalanta() const
{
    return balantaContului;
}

void BankAccount::depunere(double suma)
{
    balantaContului += suma;
}

void BankAccount::retragere(double suma)
{
    if (balantaContului >= suma)
    {
        balantaContului -= suma;
    }
    else
    {
        cout << "Fonduri insuficiente." << endl;
    }
}

void BankAccount::transfer(BankAccount& recipient, double suma)
{
    if (balantaContului >= suma)
    {
        balantaContului -= suma;
        recipient.depunere(suma);
        cout << "Transfer efectuat cu succes." << endl;
    }
    else
    {
        cout << "Fonduri insuficiente pentru transfer." << endl;
    }
}
