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

    Money &operator=(const Money &other);
    Money &operator=(Money &&other) noexcept;

    Money operator+(const Money &other) const;
    Money &operator+=(const Money &other);
    Money operator-(const Money &other) const;
    Money &operator-=(const Money &other);

    bool operator==(const Money &other) const;
    bool operator<(const Money &other) const;
    bool operator>(const Money &other) const;
    
    void printM() const;

    
    void adjustLengths(Money &other) ;
private:
    unsigned char *data;
    unsigned int len;

};

#endif
