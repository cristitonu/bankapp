#ifndef BANK_H
#define BANK_H
using namespace std;
#include <string>
#include <vector>

class BankAccount
{
private:
    string numarulContului;
    double balantaContului;

public:
    BankAccount(const string& numarulContului, double balantaInitiala);
    ~BankAccount();
    string getNumarulContului() const;
    double getBalanta() const;
    void depunere(double suma);
    void retragere(double suma);
    void transfer(BankAccount& destinatar, double suma);
};

#endif
