#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H

#include <vector>
#include <string>

class BankAccount {
private:
    double initialBalance;
    double interestRate;

public:
    BankAccount(double initialBalance, double interestRate);
    double calculateBalance(int years, double monthlyDeposit = 0.0);
    void displayTable(int years, double monthlyDeposit = 0.0);
    void displayYearEndReports(int years, double monthlyDeposit = 0.0);
};

#endif