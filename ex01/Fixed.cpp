
#include "Fixed.hpp"

const int Fixed::bits = 8;

Fixed::Fixed() : value(0) {
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int raw) {
    std::cout << "Int constructor called" << std::endl;
    this->value = raw << bits;
}

Fixed::Fixed(const float raw) {
    std::cout << "Float constructor called" << std::endl;
    this->value = static_cast<int>(raw * (1 << bits) + 0.5f);
}

Fixed::Fixed(const Fixed& other) : value(other.value) {
    std::cout << "Copy constructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed& other) {
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other) {
        this->value = other.value;
    }
    return *this;
}

Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits() const {
    std::cout << "getRawBits member function called" << std::endl;
    return this->value;
}

void Fixed::setRawBits(int const raw) {
    std::cout << "setRawBits member function called" << std::endl;
    this->value = raw;
}

float Fixed::toFloat() const {
    return static_cast<float>(this->value) / (1 << bits);
}

int Fixed::toInt() const {
    return this->value >> bits;
}

std::ostream& operator<<(std::ostream& os, const Fixed& fixed) {
    os << fixed.toFloat();
    return os;
}
