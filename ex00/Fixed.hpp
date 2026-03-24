/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egermen <egermen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 16:04:55 by egermen           #+#    #+#             */
/*   Updated: 2024/11/06 12:52:17 by egermen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

class Fixed {
private:
    int                 _fixedPointValue;
    static const int    _fractionalBits = 8;

public:
    Fixed();
    Fixed(const Fixed &other);
    Fixed &operator=(const Fixed &other);
    ~Fixed();

    int getRawBits(void) const;
    void setRawBits(int const raw);
};

#endif
