#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed {

private:
    static const int bits;
    int value;

public:
    Fixed();
    Fixed(const int raw);
    Fixed(const float raw);
    Fixed(const Fixed& other);
    Fixed& operator=(const Fixed& other);
    ~Fixed();

    int getRawBits() const;
    void setRawBits(int const raw);

    float toFloat() const;
    int toInt() const;

    bool operator>(const Fixed& other) const;
    bool operator<(const Fixed& other) const;
    bool operator>=(const Fixed& other) const;
    bool operator<=(const Fixed& other) const;
    bool operator==(const Fixed& other) const;
    bool operator!=(const Fixed& other) const;

    Fixed operator+(const Fixed& other) const;
    Fixed operator-(const Fixed& other) const;
    Fixed operator*(const Fixed& other) const;
    Fixed operator/(const Fixed& other) const;

    Fixed& operator++();    // pre-increment
    Fixed operator++(int);  // post-increment
    Fixed& operator--();    // pre-decrement
    Fixed operator--(int);  // post-decrement

    static const Fixed& min(const Fixed& a, const Fixed& b);
    static const Fixed& min(const Fixed& a, const Fixed& b, const Fixed& c);
    static const Fixed& max(const Fixed& a, const Fixed& b);
    static const Fixed& max(const Fixed& a, const Fixed& b, const Fixed& c);
};

std::ostream& operator<<(std::ostream& os, const Fixed& fixed);

#endif
