
#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed{

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


    int getRawBits( void ) const;
     void setRawBits( int const raw );
    float toFloat() const;
    int toInt() const;
};

std::ostream& operator<<(std::ostream& os, const Fixed& fixed);

#endif
