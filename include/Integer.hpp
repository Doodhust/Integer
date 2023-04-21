#pragma once

// Arbitrary-precision arithmetic representation of integers
#include <vector>
#include <iostream>
#include <iomanip> //   for setw()
#include <cmath>
namespace arbitrary_precision_arithmetic {
    class Integer final {
    public:
        Integer();
        Integer(const Integer&);

        // Some methods
        Integer abs() const;

        Integer& operator=(const Integer&);
        // Integer& operator=(Integer&&);  // -__-

        // These constructors could be rewritten using templates
        // It's simple to use it in this task:
        // - Just try to use it,
        // - Remove repeating code &
        // - Don't forget to test it with different types
        // Oh, yeah, don't forget to specialize constructor from Integer type
        Integer(char unsigned);
        Integer(char);

        Integer(short unsigned);
        Integer(short);

        Integer(unsigned int);
        Integer(int);

        Integer(long unsigned);
        Integer(long);

        Integer(long long unsigned);
        Integer(long long);

        ~Integer();

        // arithmetic unary operators
        Integer operator-() const;
        Integer& operator--();
        Integer operator--(int);

        Integer operator+() const;
        Integer& operator++();
        Integer operator++(int);

        // arithmetic binary operators
        Integer operator-(const Integer&) const;
        Integer& operator-=(const Integer&);

        Integer operator+(const Integer&) const;
        Integer& operator+=(const Integer&);

        Integer operator*(const Integer&) const;
        Integer& operator*=(const Integer&);

        Integer operator/(const Integer&) const;
        Integer& operator/=(const Integer&);

        Integer operator%(const Integer&) const;
        Integer& operator%=(const Integer&);

        // Conversion operators... Why don't you still use the templates?
        explicit operator bool() const;
        explicit operator char unsigned () const;
        explicit operator char () const;
        explicit operator short unsigned int() const;
        explicit operator short int() const;
        explicit operator unsigned int() const;
        explicit operator int() const;
        explicit operator long unsigned int() const;
        explicit operator long int() const;
        explicit operator long long unsigned int() const;
        explicit operator long long int() const;


        // Comparators
        [[nodiscard]]bool operator==(const Integer&) const;
        [[nodiscard]]bool operator!=(const Integer&) const;
        [[nodiscard]]bool operator<(const Integer&) const;
        [[nodiscard]]bool operator<=(const Integer&) const;
        [[nodiscard]]bool operator>(const Integer&) const;
        [[nodiscard]]bool operator>=(const Integer&) const;
        // ...or you could read about operator<=> and implement it instead of
        // implementation of comparators above

        void ShiftRight();
        void RemoveLeadingZero();
        void shift(size_t count);
        template <typename T>
        T Conversation() const;
        // Output stream print helper
        template <typename OStream>
        friend OStream&& operator<<(OStream&&, const Integer&);

    private:
        int BASE = 1e9;
        std::vector<int64_t>number;
        bool sign = true;
    };



// also you could implement your own string-literal for this type
// Integer ""_li(const char*);

}  // namespace arbitary_precision_arithmetic
