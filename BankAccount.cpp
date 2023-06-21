#include "BankAccount.h" // linking this required a whole youtube video
#include <iostream> // Miguel Hilario wuz here
#include <iomanip> 

BankAccount::BankAccount(double initialBalance, double interestRate) {
    this->initialBalance = initialBalance;
    this->interestRate = interestRate;
}

double BankAccount::calculateBalance(int years, double monthlyDeposit) {
    double balance = initialBalance;
    for (int i = 0; i < years; i++) {
        balance += balance * interestRate;
        if (monthlyDeposit != 0.0) {
            for (int j = 0; j < 12; j++) {
                balance += monthlyDeposit;
                balance += balance * interestRate / 12.0;
            }
        }
    }
    return balance;
}

void BankAccount::displayTable(int years, double monthlyDeposit) {
    std::vector<std::string> headers{"Month", "Opening Amount", "Deposited Amount", "Total", "Interest", "Closing Balance"};
    std::vector<std::vector<std::string>> tableData;

    int months = years * 12;
    double openingAmount = initialBalance;
    double closingBalance = openingAmount;
    double interest;
    double total;

    for (int i = 1; i <= months; i++) {
        if (i % 12 == 1) {
            openingAmount = closingBalance;
        }

        interest = openingAmount * interestRate / 12.0;
        total = openingAmount + monthlyDeposit;

        closingBalance = total + interest;

        tableData.push_back({
            std::to_string(i),
            std::to_string(openingAmount),
            std::to_string(monthlyDeposit),
            std::to_string(total),
            std::to_string(interest),
            std::to_string(closingBalance)
        });
    }

    // Display the table
    const int columnWidth = 16;

    // Display headers
    for (const auto& header : headers) {
        std::cout << std::setw(columnWidth) << std::left << header;
    }
    std::cout << std::endl;

    // Display data
    for (const auto& rowData : tableData) {
        for (const auto& cellData : rowData) {
            std::cout << std::setw(columnWidth) << std::left << cellData;
        }
        std::cout << std::endl;
    }
}

void BankAccount::displayYearEndReports(int years, double monthlyDeposit) {
    std::cout << "Year\tBalance\n";
    for (int i = 1; i <= years; i++) {
        double balance = calculateBalance(i, monthlyDeposit);
        std::cout << i << "\t$" << balance << std::endl;
    }
}