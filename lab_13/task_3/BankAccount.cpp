#include "BankAccount.h"
#include <stdexcept>

BankAccount::BankAccount(const std::string &lastName, const std::string &accountNumber, double balance) :
        last_name_(lastName), account_number_(accountNumber), balance_(balance) {}

void BankAccount::deposit(double amount) {
    if (amount <= 0)
        throw std::invalid_argument("Amount to deposit must be greater than 0");

    balance_ += amount;
}

void BankAccount::withdraw(double amount) {
    if (amount <= 0)
        throw std::invalid_argument("Amount to withdraw must be greater than 0");
    if (amount > getBalance())
        throw std::runtime_error("Amount to deposit exceeds account balance");

    balance_ -= amount;
}

bool BankAccount::isMillionaire() const {
    return getBalance() >= 1000000;
}


const std::string &BankAccount::getLastName() const {
    return last_name_;
}

void BankAccount::setLastName(const std::string &lastName) {
    last_name_ = lastName;
}

const std::string &BankAccount::getAccountNumber() const {
    return account_number_;
}

void BankAccount::setAccountNumber(const std::string &accountNumber) {
    account_number_ = accountNumber;
}

double BankAccount::getBalance() const {
    return balance_;
}

void BankAccount::setBalance(double balance) {
    balance_ = balance;
}