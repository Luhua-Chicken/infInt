/*
 * Copyright (c) 2025 chicken8225
 * All rights reserved.
 *
 * This file/program is protected by copyright law and international treaties.
 * Unauthorized reproduction or distribution of this file/program, or any portion
 * of it, may result in severe civil and criminal penalties.
 *
 * Date: 2025-07-21
 */
#include <algorithm>
#include <cctype>
#include <cstring>
#include <iostream>
#include <stdexcept>
#include <string>
#include <utility>
#include <vector>

#include "infInt.h"

void infInt::delZero(){
    if (num == "-0") num = "0";
    if (num.empty()) num = "0";
    int start = num[0] == '-';
    int pos = num.find_first_not_of('0', start);
    if (pos != std::string::npos) {
        num = num.substr(pos);
    }else {
        num = "0";
    }
}
bool infInt::isZero() const {
    return num == "0" || num == "-0";
}
infInt::infInt() : num("0") {}
infInt::infInt(const infInt& other) : num(other.num) {}
infInt::infInt(const infInt&& other) noexcept : num(std::move(other.num)) {}
infInt::infInt(const std::string s) : num(s) { delZero(); }
infInt::infInt(int x) : num(std::to_string(x)) {}
int infInt::to_int() const { return std::stoi(num); }
long infInt::to_long() const { return std::stol(num); }
infInt& infInt::operator=(const infInt& other) {
    if (this != &other) {
        num = other.num;
        delZero();
    }
    return *this;
}
infInt& infInt::operator=(infInt&& other) noexcept {
    if (this != &other) num = std::move(other.num);
    return *this;
}
infInt& infInt::operator=(const std::string& s) {
    num = s;
    delZero();
    return *this;
}
infInt& infInt::operator=(const int& x) {
    num = std::to_string(x);
    delZero();
    return *this;
}
std::ostream& operator<<(std::ostream& os, const infInt& n) {
    os << n.num;
    return os;
}
std::istream& operator>>(std::istream& is, infInt& n) {
    is >> n.num;
    int len = n.num.size();
    if (!std::isdigit(n.num[0])) {
        if (n.num[0] != '+' && n.num[0] != '-') {
            throw std::invalid_argument("The input is incorrect.");
        }
    }
    for(int i = 1; i < len; i++) {
        if (!std::isdigit(n.num[i])) throw std::invalid_argument("The input is incorrect.");
    }
    return is;
}
std::string infInt::copy() const {
    return num;
}
bool infInt::operator<(const infInt& other) const {
    return num < other.num;
}
bool infInt::operator==(const infInt& other) const {
    return num == other.num;
}
bool infInt::operator==(const std::string& s) const {
    return num == s;
}
bool infInt::operator==(const int& n) const {
    return *this == infInt(n);
}
bool infInt::operator>(const infInt& other) const {
    return num > other.num;
}
bool infInt::operator<=(const infInt& other) const {
    if (num == other.num || num < other.num) return true;
    else return false;
}
bool infInt::operator!=(const infInt& other) const {
    if (num == other.num) return false;
    else return true;
}
bool infInt::operator>=(const infInt& other) const {
    if (num == other.num || num > other.num) return true;
    else return false;
}
infInt infInt::operator+(const infInt& other) const {
    std::string a = num, b = other.num;
    std::reverse(a.begin(), a.end());
    std::reverse(b.begin(), b.end());
    if (a.size() < b.size()) std::swap(a, b);
    int len1 = a.size(), len2 = b.size(), carry = 0;
    std::string ans = "";
    for(int i = 0; i < len1; i++) {
        int res = a[i] - '0' + carry;
        if (len2 > i) res += b[i] - '0';
        carry = res / 10;
        res %= 10;
        ans += res + '0';
    }
    if (carry > 0) ans += carry + '0';
    std::reverse(ans.begin(), ans.end());
    return infInt(ans);
}
infInt infInt::operator-(const infInt& other) const {
    std::string a = num, b = other.num;
    std::string tmp = "";
    bool flag = false;
    if (a < b) {
        flag = true;
        std::swap(a, b);
    }
    std::reverse(a.begin(), a.end());
    std::reverse(b.begin(), b.end());
    int len1 = a.size(), len2 = b.size(), carry = 0;
    for(int i = 0; i < len1; i++) {
        int res = a[i] - '0' - carry;
        if (len2 > i) res -= b[i] - '0';
        carry = res < 0;
        res = (res + 10) % 10;
        tmp += res + '0';
    }
    std::reverse(tmp.begin(), tmp.end());
    if (flag) tmp = "-" + tmp;
    return infInt(tmp);
}
infInt infInt::operator*(const infInt& other) const {
    std::string a = num, b = other.num;
    std::reverse(a.begin(), a.end());
    std::reverse(b.begin(), b.end());
    int len1 = a.size(), len2 = b.size();
    std::vector<int> c(len1 + len2, 0);
    for (int i = 0; i < len1; i++) {
        for (int j = 0; j < len2; j++) {
            c[i + j] += (a[i] - '0') * (b[j] - '0');
        }
    }
    for (int i = 0; i < len1 + len2 - 1; i++) {
        c[i + 1] += c[i] / 10;
        c[i] %= 10;
    }
    std::string ans;
    for (int i = len1 + len2 - 1; i >= 0; i--) {
        ans += c[i] + '0';
    }
    return infInt(ans);
}
infInt infInt::operator/(const infInt& b) const {
    if (b.isZero()) throw std::domain_error("The divisor cannot be zero.");
    else if (*this < b) return infInt(0);
    else if (*this == b) return infInt(1);
    infInt a = *this, c = 0, d = 0;
    for(auto ch : num) {
        d = d * infInt(10) + infInt(ch - '0');
        int digit = 0;
        while (d > b) {
            d -= b;
            digit++;
        }
        c.num += std::to_string(digit);
    }
    c.delZero();
    return c;
}
infInt infInt::operator%(infInt b) const {
    return *this - *this / b * b;
}
infInt& infInt::operator+=(const infInt& other) {
    *this = *this + other;
    return *this;
}
infInt& infInt::operator-=(const infInt& other) {
    *this = *this - other;
    return *this;
}
infInt& infInt::operator*=(const infInt& other) {
    *this = *this * other;
    return *this;
}
infInt& infInt::operator/=(const infInt& other) {
    *this = *this / other;
    return *this;
}
infInt& infInt::operator%=(const infInt& other) {
    *this = *this % other;
    return *this;
}
infInt infInt::pow(const infInt& other) {
    infInt ans = 1, base = *this, exp = other;
    while (exp > 0) {
        if (exp % 2 == 1) ans *= base;
        base *= base;
        exp /= 2;
    }
    return ans;
}
