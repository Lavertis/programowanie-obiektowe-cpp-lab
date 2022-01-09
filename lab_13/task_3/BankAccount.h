#pragma once

#include <string>

class BankAccount {
private:
    std::string last_name_;
    std::string account_number_;
    double balance_;
public:
    BankAccount(const std::string &lastName, const std::string &accountNumber, double balance);

    void deposit(double amount);

    void withdraw(double amount);

    bool isMillionaire() const;

    [[nodiscard]] const std::string &getLastName() const;

    void setLastName(const std::string &lastName);

    [[nodiscard]] const std::string &getAccountNumber() const;

    void setAccountNumber(const std::string &accountNumber);

    [[nodiscard]] double getBalance() const;

    void setBalance(double balance);
};