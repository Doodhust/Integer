#include "Integer.hpp"



using namespace arbitrary_precision_arithmetic;

void Integer::RemoveLeadingZero() {
    while (this->number.size() > 1 && this->number.back() == 0) {
        this->number.pop_back();
    }
}

Integer Integer::abs() const {
    Integer result(*this);
    result.sign = false;
    return result;
}

Integer::Integer() {
    this->number.push_back(0);
}
Integer::Integer(const Integer& other) {
    this->number = other.number;
    this->BASE = other.BASE;
    this->sign = other.sign;
}
Integer& Integer::operator=(const Integer& other) = default;
Integer::Integer(char a) {
    if (a < 0) {
        this->sign = false;
        a = static_cast<char>(-a);
    } else {
        this->sign = true;
    }
    this->number[0] = (static_cast<int>(a) % BASE);
}

Integer::Integer(unsigned char a) {
    this->sign = true;
    this->number[0] = (static_cast<int>(a) % BASE);
}

Integer::Integer(unsigned short a) {
    this->sign = true;
    this->number[0] = a % BASE;
}

Integer::Integer(short a) {
    if (a < 0) {
        this->sign = false;
        a = static_cast<short>(-a);
    } else {
        this->sign = true;
    }
    this->number[0] = (a % BASE);
}

Integer::Integer(unsigned int a) {
    this->sign = true;
    do {
        this->number.push_back(a % BASE);
        a /= BASE;
    } while (a != 0);
}

Integer::Integer(int a) {
    if (a < 0) {
        this->sign = false;
        a = -a;
    } else {
        this->sign = true;
    }
    do {
        this->number.push_back(a % BASE);
        a /= BASE;
    } while (a != 0);
}

Integer::Integer(unsigned long a) {
    this->sign = true;
    do {
        this->number.push_back(a % BASE);
        a /= BASE;
    } while (a != 0);
}

Integer::Integer(long a) {
    if (a < 0) {
        this->sign = false;
        a = -a;
    } else {
        this->sign = true;
    }
    do {
        this->number.push_back(a % BASE);
        a /= BASE;
    } while (a != 0);
}

Integer::Integer(unsigned long long a) {
    this->sign = true;

    do {
        this->number.push_back(a % BASE);
        a /= BASE;
    } while (a != 0);
}

Integer::Integer(long long a) {
    if (a < 0) {
        this->sign = false;
        a = -a;
    } else {
        this->sign = true;
    }
    do {
        this->number.push_back(a % BASE);
        a /= BASE;
    } while (a != 0);
}

Integer::~Integer() = default;

bool Integer::operator==(const Integer& other) const {
    Integer first = *this;
    if (first.sign != other.sign) {
        return false;
    }
    if (first.number.size() != other.number.size()) {
        return false;
    }
    for (size_t i = 0; i < first.number.size(); ++i) {
        if (first.number[i] != other.number[i]) {
            return false;
        }
    }
    return true;
}
bool Integer::operator<(const Integer& other) const {
    Integer first = *this;
    if (first == other) {
        return false;
    }

    if (!first.sign) {
        if (!other.sign) {
            return (-(other) < -(first));
        } else {
            return true;
        }
    }
    else if (!other.sign) {
        return false;
    }
    else {
        if (first.number.size() < other.number.size()) {
            return true;
        }
        else if(first.number.size() > other.number.size()) {
            return false;
        }
        bool check;
        for (size_t i = first.number.size() - 1; i >= 0; --i) {
            if (first.number[i] != other.number[i]) {
                check = first.number[i] < other.number[i];
                return check;
            }
        }
        return false;
    }
}
bool Integer::operator!=(const Integer& other) const {
    Integer first = *this;
    return !(first == other);
}
bool Integer::operator<=(const Integer& other) const {
    Integer first = *this;
    return (first < other || first == other);
}
bool Integer::operator>(const Integer& other) const {
    Integer first = *this;
    return !(first <= other);
}
bool Integer::operator>=(const Integer& other) const {
    Integer first = *this;
    return !(first < other);
}


Integer Integer::operator-() const {
    Integer copy(*this);
    copy.sign = !copy.sign;
    return copy;
}
Integer Integer::operator-(const Integer& other) const {
    Integer first = *this;
    if (!other.sign) {
        return first + (-other);
    }
    else if (!first.sign) {
        return -(-first + other);
    }
    else if (first < other) {
        return -(other - first);
    }
    int res = 0;
    for (size_t i = 0; i < other.number.size() || res != 0; ++i) {
        first.number[i] -= static_cast<long long int>(res) + (i < other.number.size() ? other.number[i] : 0);
        res = first.number[i] < 0;
        if (res != 0 ) {
            first.number[i] += Integer::BASE;
        }
    }
    first.RemoveLeadingZero();
    return first;
}
Integer& Integer::operator-=(const Integer& other) {
    return *this = (*this - other);
}
Integer& Integer::operator--() {
    return *this -= 1;
}
Integer Integer::operator--(int) {
    *this -= 1;
    return *this + 1;
}

Integer Integer::operator+() const {
    return *this;
}
Integer Integer::operator+(const Integer& other) const {
    Integer first = *this;
    if (!other.sign) {
        if (!first.sign) {
            return -(-other + (-first));
        } else {
            return first - (-other);
        }
    }
    else if (!first.sign) {
        return  other - (-first);
    }
    int res = 0;
    for (size_t i = 0; i < std::max(other.number.size(), first.number.size()) || res != 0; ++i) {
        if (i == first.number.size()) {
            first.number.push_back(0);
        }
        first.number[i] += static_cast<unsigned long long int>(res) + (i < other.number.size() ? other.number[i] : 0);
        res = first.number[i] >= Integer::BASE;
        if (res != 0) first.number[i] -= Integer::BASE;
    }
    return first;
}
Integer& Integer::operator+=(const Integer& other) {
    return *this = (*this + other);
}
Integer& Integer::operator++() {
    return *this += 1;
}
Integer Integer::operator++(int) {
    *this += 1;
    return *this - 1;
}
void Integer::ShiftRight() {
    if (this->number.empty()) {
        this->number.push_back(0);
        return;
    }
    this->number.push_back(this->number[this->number.size()-1]);
    for (size_t i = this->number.size() - 2; i > 0; --i) {
        this->number[i] = this->number[i - 1];
    }
    this->number[0] = 0;
}

void Integer::shift(size_t count) {
    for(size_t i = 0; i < count; i++)
        number.insert(number.begin(),0);
}

int findRes(const Integer& first, const Integer& second, int base) {
    long long l = 0, r = base - 1;

    while(l != r) {
        long long m = (l + r) >> 1;

        if(second * m >= first) r = m;
        else l = m + 1;
    }

    if(second * l > first) l--;

    return l;
}

Integer Integer::operator/(const Integer& other) const {
    Integer mine = *this;
    if (other == 0) {
        throw std::invalid_argument("Divide by zero");
    }

    if(mine.abs() < other.abs()) return 0;

    Integer result, current(mine.abs()); // текущий

    for(long long i = static_cast<long long>(mine.number.size()) - 1; i >= 0; i--) {
        Integer buffer(other.abs()); // буфер
        buffer.shift(i);
        int r = findRes(current, buffer, Integer::BASE);
        current -= buffer * r;
        result.shift(1);
        result += r;
    }


    result.sign = mine.sign != other.sign;

    return result;

}

Integer& Integer::operator/=(const Integer& other) {
    return *this = (*this / other);
}
Integer Integer::operator%(const Integer& other) const {
    Integer first = *this;
    Integer result = first - (first / other) * other;
    if (!result.sign) {
        result.sign = true;
    }
    return result;
}
Integer& Integer::operator%=(const Integer& other) {
    return *this = (*this % other);
}
Integer Integer::operator*(const Integer& other) const {
    Integer first = *this;
    Integer result;
    result.number.resize(first.number.size() + other.number.size());
    for (size_t i = 0; i < first.number.size(); ++i) {
        int carry = 0;
        for (size_t j = 0; j < other.number.size() || carry != 0; ++j) {

            int64_t cur = result.number[i + j] +
                          first.number[i] * 1LL * (j < other.number.size() ? other.number[j] : 0) + carry;
            result.number[i + j] = static_cast<int>(cur % Integer::BASE);
            carry = static_cast<int>(cur / Integer::BASE);
        }
    }
    (first.sign == other.sign) ? result.sign = true : result.sign = false;
    result.RemoveLeadingZero();
    return result;
}
Integer& Integer::operator*=(const Integer& other) {
    return *this = (*this * other);
}
template <typename OStream>
OStream&& arbitrary_precision_arithmetic::operator<<(OStream&& os, const Integer& other) {
    if (!other.sign) {
        os << '-';
    }
    os << other.number.back();
    char oldFill = os.fill('0');
    for (long long i = static_cast<long long>(other.number.size()) - 2; i >= 0; --i) {
        os << std::setw(9) << other.number[i];
    }
    os.fill(oldFill);
    return os;
}
Integer::operator bool() const {
    return *this != 0;
}
template <typename T>
T Integer::Conversation() const {
    auto res = static_cast<T>(number[0] + ((number.size() > 1) ? number[1] * BASE : 0));
    if (std::is_unsigned<T>::value) {
        if (!sign) {
            res *= -1;
        }
    }
    if (!sign) {
        res *= -1;
    }
    return res;
}
Integer::operator char unsigned() const {
    return Conversation<unsigned char>();
}
Integer::operator char() const {
    return Conversation<char>();
}
Integer::operator short unsigned int() const {
    return Conversation<short unsigned int>();
}
Integer::operator short int() const {
    return Conversation<short int>();
}
Integer::operator unsigned int() const {
    return Conversation<unsigned int>();
}
Integer::operator int() const {
    return Conversation<int>();
}
Integer::operator long unsigned int() const {
    return Conversation<long unsigned int>();
}
Integer::operator long int() const {
    return Conversation<long int>();
}
Integer::operator long long unsigned int() const {
    return Conversation<long long unsigned int>();
}
Integer::operator long long int() const {
    return Conversation<long long int>();
}
