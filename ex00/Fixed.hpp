


#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed{

    private:
        static const int bits;
        int value;

    public:
        Fixed();
        Fixed(Fixed& other);
        Fixed& operator=(const Fixed& other);
        ~Fixed();

    int getRawBits( void ) const;
     void setRawBits( int const raw );
};






#endif