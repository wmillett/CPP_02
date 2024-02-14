
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

//Comparison
bool Fixed::operator>(const Fixed& other) const {
    return this->value > other.value;
}

bool Fixed::operator<(const Fixed& other) const {
    return this->value < other.value;
}

bool Fixed::operator>=(const Fixed& other) const {
    return this->value >= other.value;
}

bool Fixed::operator<=(const Fixed& other) const {
    return this->value <= other.value;
}

bool Fixed::operator==(const Fixed& other) const {
    return this->value == other.value;
}

bool Fixed::operator!=(const Fixed& other) const {
    return this->value != other.value;
}

// Arithmetic operators
Fixed Fixed::operator+(const Fixed& other) const {
    return Fixed(this->toFloat() + other.toFloat());
}

Fixed Fixed::operator-(const Fixed& other) const {
    return Fixed(this->toFloat() - other.toFloat());
}

Fixed Fixed::operator*(const Fixed& other) const {
    return Fixed(this->toFloat() * other.toFloat());
}

Fixed Fixed::operator/(const Fixed& other) const {
    return Fixed(this->toFloat() / other.toFloat());
}

// Increment/Decrement operators
Fixed& Fixed::operator++() {
    ++this->value;
    return *this;
}

Fixed Fixed::operator++(int) {
    Fixed temp(*this);
    ++(*this);
    return temp;
}

Fixed& Fixed::operator--() {
    --this->value;
    return *this;
}

Fixed Fixed::operator--(int) {
    Fixed temp(*this);
    --(*this);
    return temp;
}

// Static member functions
const Fixed& Fixed::min(const Fixed& a, const Fixed& b) {
    return (a <= b) ? a : b;
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b, const Fixed& c) {
    return min(a, min(b, c));
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b) {
    return (a >= b) ? a : b;
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b, const Fixed& c) {
    return max(a, max(b, c));
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
