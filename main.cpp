#include "BankAccount.h"
#include <iostream>
#include <iomanip>
#include <string>

// Function to pause the program and wait for user input
void pause() {
    std::cout << "Press any key to continue...";
    std::cin.ignore();
    std::cin.get();
}

int main() {
    double initialBalance, interestRate, monthlyDeposit;
    int numYears;

    std::string title = "DATA";

    int totalWidth = 40; // Total width of the console

    int titleWidth = title.length();
    int asteriskWidth = (totalWidth - titleWidth) / 2; //ensure asteriks even on both sides

    std::string asteriskLine(asteriskWidth, '*');
    std::string centeredTitle = asteriskLine + title + asteriskLine;

    std::cout << centeredTitle << std::endl;

    std::cout << "Initial Investment Amount: $";
    std::cin >> initialBalance;

    std::cout << "Monthly Deposit: $";
    std::cin >> monthlyDeposit;

    std::cout << "Annual Interest (Compounded): ";
    std::cin >> interestRate;

    std::cout << "Number of Years: ";
    std::cin >> numYears;

    BankAccount account(initialBalance, interestRate);

    std::cout << std::setw(totalWidth) << std::setfill('*') << "" << std::endl;
    std::cout << std::setfill(' '); //nice little breaker of asteriks

    std::cout << "\nTable without Monthly Deposits:\n";
    account.displayTable(numYears);

    std::cout << "\nTable with Monthly Deposits:\n";
    account.displayTable(numYears, monthlyDeposit);

    std::cout << "\nYear-End Reports:\n";
    account.displayYearEndReports(numYears, monthlyDeposit);

    std::cout << std::setw(totalWidth) << std::setfill('*') << "" << std::endl;

    // Pause before exiting
    pause();

    return 0;
}