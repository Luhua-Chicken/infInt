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
#ifndef INFINT_H
#define INFINT_H

#include <algorithm>
#include <cctype>
#include <cstring>
#include <iostream>
#include <stdexcept>
#include <string>
#include <utility>
#include <vector>

class infInt {
private:
    std::string num;
    
    void delZero();
    bool isZero() const;

public:
    infInt();
    infInt(const infInt& other);
    infInt(const std::string& s);
    infInt(int x);
    
    int to_int() const;
    long to_long() const;
    
    infInt& operator=(const infInt& other);
    infInt& operator=(const infInt&& other) noexcept;
    infInt& operator=(const std::string& s);
    infInt& operator=(const int& x);
    
    friend std::ostream& operator<<(std::ostream& os, const infInt& n);
    friend std::istream& operator>>(std::istream& is, infInt& n);
    
    std::string copy() const;
    
    bool operator<(const infInt& other) const;
    bool operator==(const infInt& other) const;
    bool operator==(const std::string& s) const;
    bool operator==(const int n) const;
    bool operator>(const infInt& other) const;
    bool operator<=(const infInt& other) const;
    bool operator!=(const infInt& other) const;
    bool operator>=(const infInt& other) const;
    
    infInt operator+(const infInt& other) const;
    infInt operator-(const infInt& other) const;
    infInt operator*(const infInt& other) const;
    infInt operator/(const infInt& other) const;
    infInt operator%(const infInt& other) const;
    
    infInt& operator+=(const infInt& other);
    infInt& operator-=(const infInt& other);
    infInt& operator*=(const infInt& other);
    infInt& operator/=(const infInt& other);
    infInt& operator%=(const infInt& other);
    
    infInt pow(const infInt& other) const;
};
#endif
