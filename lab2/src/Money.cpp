#include "Money.h"
#include <iostream>
#include <string>


std::string trimString(const std::string &str) {
    size_t pointPos = str.find('.');
    if (pointPos == std::string::npos) {
        pointPos = str.find(',');
    }

    if (pointPos < str.length()) {
        size_t digitsAfterPoint = str.length() - pointPos - 1;
        if (digitsAfterPoint >= 2) {
            return str.substr(0, pointPos + 3);
        } else if (digitsAfterPoint == 1) {
            return str.substr(0, pointPos + 2) + "0";
        } else {
            return str + "00";
        }
    } else {
        return str + ".00";
    }
}

Money::Money() : data(nullptr), len(0) {}

Money::Money(const std::string &t) {
    if (t.empty()) {
        throw std::invalid_argument("Пустая строка недопустима.");
    }

    for (char ch : t) {
        if (!std::isdigit(ch) && ch != '.' && ch != ',') {
            throw std::invalid_argument("Строка содержит недопустимые символы.");
        }
    }

    std::string str = trimString(t);
    size_t pointPos = str.find('.');
    if (pointPos == std::string::npos) {
        pointPos = str.find(',');
    }
    if (pointPos != std::string::npos) {
        str.erase(pointPos, 1);
    }

    len = str.length();
    data = new unsigned char[len];

    size_t j = 0;
    for (int i = len - 1; i >= 0; --i) {
        data[j++] = str[i] - '0';
    }
}
Money::Money(const Money &other) {
    len = other.len;
    data = new unsigned char[len];
    std::copy(other.data, other.data + len, data);
}

Money::Money(Money &&other) noexcept : data(other.data), len(other.len) {
    other.data = nullptr;
    other.len = 0;
}

Money::~Money() {
    delete[] data;
}

void Money::assign(const Money &other) {
    if (this != &other) {
        delete[] data;
        len = other.len;
        data = new unsigned char[len];
        std::copy(other.data, other.data + len, data);
    }
}

void Money::moveAssign(Money &&other) noexcept {
    if (this != &other) {
        delete[] data;
        data = other.data;
        len = other.len;
        other.data = nullptr;
        other.len = 0;
    }
}

void Money::adjustLengths(Money &other) {
    if (this->len != other.len) {
        size_t maxLen = std::max(this->len, other.len);

        if (this->len < maxLen) {
            unsigned char *newData = new unsigned char[maxLen];
            std::fill(newData, newData + maxLen,0);
            std::copy(this->data, this->data + this->len, newData);
            delete[] this->data;
            this->data = newData;
            this->len = maxLen;
        }

        if (other.len < maxLen) {
            unsigned char *newData = new unsigned char[maxLen];
            std::fill(newData, newData + maxLen,0);
            std::copy(other.data, other.data + other.len, newData);
            delete[] other.data;
            other.data = newData;
            other.len = maxLen;
        }
    }
}

Money Money::add(const Money &other) const {
    Money tempOther = other;
    Money tempThis = *this;

    tempThis.adjustLengths(tempOther);

    size_t maxLen = tempThis.len + 1;
    Money result;
    result.len = maxLen;
    result.data = new unsigned char[maxLen];
    std::fill(result.data, result.data + maxLen,0);

    int carry = 0;
    for (size_t i = 0; i < maxLen - 1; ++i) {
        int a = tempThis.data[i];
        int b = tempOther.data[i];
        int sum = a + b + carry;
        result.data[i] = sum % 10;
        carry = sum / 10;
    }

    if (carry > 0 && maxLen > 0) {
        result.data[maxLen - 1] = carry;
    } else {
        result.len--;
    }

    return result;
}

Money Money::subtract(const Money &other) const {
    Money tempOther = other;
    Money tempThis = *this;

    tempThis.adjustLengths(tempOther);

    size_t maxLen = tempThis.len;
    Money result;
    result.len = maxLen;
    result.data = new unsigned char[maxLen];
    std::fill(result.data, result.data + maxLen, 0);

    int borrow = 0;
    for (size_t i = 0; i < maxLen; ++i) {
        int a = tempThis.data[i];
        int b = tempOther.data[i];
        int diff = a - b - borrow;
        if (diff < 0) {
            diff += 10;
            borrow = 1;
        } else {
            borrow = 0;
        }
        result.data[i] = diff;
    }

    while (result.len > 1 && result.data[result.len - 1] == 0) {
        result.len--;
    }

    return result;
}

void Money::addAssign(const Money &other) {
    Money temp = this->add(other);
    this->assign(temp);
}

void Money::subtractAssign(const Money &other) {
    Money temp = this->subtract(other);
    this->assign(temp);
}

bool Money::equals(const Money &other) const {
    if (len != other.len) return false;
    for (size_t i = 0; i < len; ++i) {
        if (i < len && i < other.len && data[i] != other.data[i]) return false;
    }
    return true;
}

bool Money::lessThan(const Money &other) const {
    if (len != other.len) return len < other.len;
    for (int i = len - 1; i >= 0; --i) {
        if (i <len && i < other.len && data[i] != other.data[i]) {
            return data[i] < other.data[i];
        }
    }
    return false;
}

bool Money::greaterThan(const Money &other) const {
    return other.lessThan(*this);
}

void Money::printM() const {

    for (int i = len - 1; i >= 0; --i) {
        if (i == 1) {
            std::cout << '.';
        }
        std::cout <<char(data[i] + '0');
    }

    std::cout << std::endl;
}
