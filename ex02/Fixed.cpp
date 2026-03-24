/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egermen <egermen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 16:05:26 by egermen           #+#    #+#             */
/*   Updated: 2024/11/05 16:05:26 by egermen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : _value(0) {}

Fixed::Fixed(const float value) {
    _value = roundf(value * (1 << _fractionalBits));
}

Fixed::Fixed(const Fixed &other) {
    *this = other;
}

Fixed &Fixed::operator=(const Fixed &other) {
    if (this != &other) {
        _value = other._value;
    }
    return *this;
}

Fixed::~Fixed() {}

Fixed Fixed::operator+(const Fixed &other) const {
    Fixed result;
    result._value = this->_value + other._value;
    return result;
}

Fixed Fixed::operator-(const Fixed &other) const {
    Fixed result;
    result._value = this->_value - other._value;
    return result;
}

Fixed Fixed::operator*(const Fixed &other) const {
    Fixed result;
    result._value = (this->_value * other._value) >> _fractionalBits;
    return result;
}

Fixed Fixed::operator/(const Fixed &other) const {
    Fixed result;
    result._value = (this->_value << _fractionalBits) / other._value;
    return result;
}

bool Fixed::operator>(const Fixed &other) const {
    return this->_value > other._value;
}

bool Fixed::operator<(const Fixed &other) const {
    return this->_value < other._value;
}

bool Fixed::operator>=(const Fixed &other) const {
    return this->_value >= other._value;
}

bool Fixed::operator<=(const Fixed &other) const {
    return this->_value <= other._value;
}

bool Fixed::operator==(const Fixed &other) const {
    return this->_value == other._value;
}

bool Fixed::operator!=(const Fixed &other) const {
    return this->_value != other._value;
}

Fixed &Fixed::operator++() {
    _value++;
    return *this;
}

Fixed Fixed::operator++(int) {
    Fixed temp = *this;
    ++(*this);
    return temp;
}

Fixed &Fixed::operator--() {
    _value--;
    return *this;
}

Fixed Fixed::operator--(int) {
    Fixed temp = *this;
    --(*this);
    return temp;
}

Fixed &Fixed::min(Fixed &a, Fixed &b) {
    return (a < b) ? a : b;
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b) {
    return (a < b) ? a : b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b) {
    return (a > b) ? a : b;
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b) {
    return (a > b) ? a : b;
}

float Fixed::toFloat() const {
    return (float)_value / (1 << _fractionalBits);
}

int Fixed::toInt() const {
    return _value >> _fractionalBits;
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed) {
    out << fixed.toFloat();
    return out;
}
