/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egermen <egermen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 16:05:11 by egermen           #+#    #+#             */
/*   Updated: 2024/11/05 16:05:12 by egermen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed {
private:
    int                 _fixedPointValue;
    static const int    _fractionalBits = 8;

public:
    Fixed();
    Fixed(const int value);
    Fixed(const float value);
    Fixed(const Fixed &other);
    Fixed &operator=(const Fixed &other);
    ~Fixed();

    float toFloat(void) const;
    int toInt(void) const;

    std::ostream &operator<<(std::ostream &out, const Fixed &fixed);
};

#endif
