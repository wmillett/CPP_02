
#include "Fixed.hpp"



Fixed::Fixed(){

    std::cout << "Default constructor called" << std::endl;
}


Fixed::Fixed(Fixed& other) : value(other.size){


    std::cout << "Copy constructor called" << std::endl;
}

Fixed::Fixed& operator=(const Fixed& other){

     std::cout << "Copy assignment constructor called" << std::endl;
}


Fixed::~Fixed(){

    std::cout << "Destructor called" << std::endl;
}