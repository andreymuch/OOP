#ifndef MONEY_H
#define MONEY_H

#include <iostream>
#include <stdexcept>
#include <string>

class Money {
public:
    Money();
    Money(const std::string &t);
    Money(const Money &other);
    Money(Money &&other) noexcept;

    ~Money();
    Money& operator=(const Money &other) = delete;

    void assign(const Money &other);
    void moveAssign(Money &&other) noexcept;

    Money add(const Money &other) const;
    void addAssign(const Money &other);
    Money subtract(const Money &other) const;
    void subtractAssign(const Money &other);

    bool equals(const Money &other) const;
    bool lessThan(const Money &other) const;
    bool greaterThan(const Money &other) const;

    void printM() const;

    void adjustLengths(Money &other);

private:
    unsigned char *data;
    size_t len;
};

#endif
