#include "gtest/gtest.h"
#include "Integer.hpp"

using namespace std;
using namespace arbitrary_precision_arithmetic;


TEST(Constructor, defoltConstructor) {
    EXPECT_TRUE(Integer() == Integer());
}

TEST(Constructor, copyConstructor) {
    Integer a;
    EXPECT_TRUE(a == Integer(a));
}
TEST(Constructor, equal) {
    Integer a(-123);
    Integer b = a;
    EXPECT_TRUE(a == b);
}
TEST(Constructor, unintConstructor) {
    EXPECT_TRUE(Integer(123123) == Integer(123123));
}
TEST(Constructor, intConstructor) {
    EXPECT_TRUE(Integer(-123123) == Integer(-123123));
}
TEST(Constructor, uncharConstructor) {
    EXPECT_TRUE(Integer(123) == Integer(123));
}
TEST(Constructor, charConstructor) {
    EXPECT_TRUE(Integer(-123) == Integer(-123));
}
TEST(Constructor, unshortConstructor) {
    EXPECT_TRUE(Integer(1230) == Integer(1230));
}
TEST(Constructor, shortConstructor) {
    EXPECT_TRUE(Integer(-1230) == Integer(-1230));
}
TEST(Constructor, unlongConstructor) {
    EXPECT_TRUE(Integer(12300) == Integer(12300));
}
TEST(Constructor, longConstructor) {
    EXPECT_TRUE(Integer(-12300) == Integer(-12300));
}
TEST(Constructor, unlonglongConstructor) {
    EXPECT_TRUE(Integer(9999999999999) == Integer(9999999999999));
}
TEST(Constructor, longlongConstructor) {
    EXPECT_TRUE(Integer(-999999999999) == Integer(-999999999999));
}

TEST(Comparators, less1) {
    EXPECT_FALSE(Integer(123456789987654321) < Integer(123456789987654321));
}
TEST(Comparators, less2) {
    EXPECT_FALSE(Integer(-12345678998765432) < Integer(-123456789987654321));
}
TEST(Comparators, less3) {
    EXPECT_FALSE(Integer(123456789987654321) < Integer(-123456789987654321));
}
TEST(Comparators, less4) {
    EXPECT_TRUE(Integer(-123456789987654321) < Integer(123456789987654321));
}
TEST(Comparators, less5) {
    EXPECT_TRUE(Integer(10000000) < Integer(10000000000000000));
}
TEST(Comparators, less6) {
    EXPECT_TRUE(Integer(1111111111111111111) < Integer(1111111111111111112));
}
TEST(Comparators, notEq){

    EXPECT_TRUE(Integer(123123) != (123122));
}
TEST(Comparators, notEq1){
    EXPECT_TRUE(Integer(-123123) != (123122));
}
TEST(Comparators, notEq2){
    EXPECT_TRUE(Integer(10000000000000000) != (10000000));
}
TEST(Comparators, lessEq){
    EXPECT_TRUE(Integer(123123) <= (123123));
};
TEST(Comparators, lessEq1){
    EXPECT_TRUE(Integer(123122) <= (123123));
};
TEST(Comparators, more){
    EXPECT_TRUE(Integer(123123) > (123122));
};
TEST(Comparators, more1){
    EXPECT_TRUE(Integer(123123) > (-123123));
};
TEST(Comparators, more3){
    EXPECT_TRUE(Integer(10000000000) > (-1000000000));
};
TEST(Comparators, moreEq){
    EXPECT_TRUE(Integer(10000000000) >= (10000000000));
};
TEST(Comparators, moreEq1){
    EXPECT_TRUE(Integer(10000000000) >= (-10000000000));
};
TEST(Comparators, moreEq2){
    EXPECT_TRUE(Integer(0) >= (0));
};

TEST(plusOperators, unPlus) {
    Integer a (10000000000);
    EXPECT_TRUE(+a == 10000000000);
};
TEST(plusOperators, sumInt) {
    Integer a (214748364);
    Integer b (214748364);
    Integer c(214748364*2);
    EXPECT_TRUE(c == a + b);
};
TEST(plusOperators, sumLongLong) {
    Integer a(9999999999999999);
    Integer b(9999999999999999);
    Integer c (a+b);
    EXPECT_TRUE(c == a+b);
}
TEST(plusOperators, sumMinus) {
    Integer a(-123123);
    Integer b(-10);
    Integer c(-123133);
    EXPECT_TRUE(c == a+b);
}
TEST(plusOperators, sumDifSign) {
    Integer a(-123123);
    Integer b(10);
    Integer c(-123113);
    EXPECT_TRUE(c == a+b);
}
TEST(plusOperators, sumEq) {
    Integer a(100000000000000);
    Integer c(100000000000000);
    Integer b(0);
    a += b;
    EXPECT_TRUE(a == c);
}
TEST(plusOperators, sumEqDifSign) {
    Integer a(100000000000000);
    Integer b(-1234567);
    a += b;
    Integer c(100000000000000-1234567);
    EXPECT_TRUE(c == a);
}
TEST(plusOperators, sumSameNumber) {
    Integer a(100000000000000);
    Integer b(-100000000000000);
    a += b;
    Integer c(0);
    EXPECT_TRUE(c == a);
}
TEST(plusOperators, postIncrement) {
    Integer a(123123);
    Integer c(123123);
    EXPECT_TRUE(a++ == c);
}
TEST(plusOperators, preIncrement) {
    Integer a(123123);
    Integer c(123124);
    EXPECT_TRUE(++a == c);
}
TEST(minusOperators, unMinus) {
    Integer a (10000000000);
    a = -a;
    EXPECT_TRUE(a == -10000000000);
};
TEST(minusOperators, difInt) {
    Integer a (214748364);
    Integer b (214748364);
    Integer c(0);
    EXPECT_TRUE(c == a - b);
};
TEST(minusOperators, difLongLong) {
    Integer a(9999999999999999);
    Integer b(9999999999999999);
    Integer c (a-b);
    EXPECT_TRUE(c == a-b);
}
TEST(minusOperators, difMinus) {
    Integer a(-123123);
    Integer b(-10);
    Integer c(-123113);
    EXPECT_TRUE(c == a-b);
}
TEST(minusOperators, difDifSign) {
    Integer a(-123123);
    Integer b(10);
    Integer c(-123133);
    EXPECT_TRUE(c == a-b);
}
TEST(minusOperators, difEq) {
    Integer a(100000000000000);
    Integer c(100000000000000);
    Integer b(0);
    a -= b;
    EXPECT_TRUE(a == c);
}
TEST(minusOperators, difEqDifSign) {
    Integer a(100000000000000);
    Integer b(-1234567);
    a += b;
    Integer c(100000000000000-1234567);
    EXPECT_TRUE(c == a);
}
TEST(minusOperators, difSameNumber) {
    Integer a(-100000000000000);
    Integer b(-100000000000000);
    a -= b;
    Integer c(0);
    EXPECT_TRUE(c == a);
}
TEST(minusOperators, postDecrement) {
    Integer a(123123);
    Integer c(123123);
    EXPECT_TRUE(a-- == c);
}
TEST(minusOperators, preDecrement) {
    Integer a(123125);
    Integer c(123124);
    EXPECT_TRUE(--a == c);
}

TEST(multiplication, multInt){
    Integer a(123123);
    Integer b(1222);
    Integer c;
    c = a * b;
    EXPECT_TRUE(c == a * b);
}
TEST(multiplication, multInt1){
    Integer a(123123);
    Integer b(1);
    Integer c;
    c = a * b;
    EXPECT_TRUE(c == a * b);
}
TEST(multiplication, multInt2){
    Integer a(123123);
    Integer b(0);
    Integer c(0);
    EXPECT_TRUE(c == a * b);
}
TEST(multiplication, multNegativeInt){
    Integer a(-123123);
    Integer b(1222);
    Integer c(-123123 * 1222);
    EXPECT_TRUE(c == a * b);
}
TEST(multiplication, multNegativeInt1){
    Integer a(-123123);
    Integer b(-1222);
    Integer c(-123123 * -1222);
    EXPECT_TRUE(c == a * b);
}
TEST(multiplication, multLongLong){
    Integer a(99999999999999999);
    Integer b(99999999999999999);
    Integer c = a * b;
    EXPECT_TRUE(c == a * b);
}
TEST(multiplication, multEq){
    Integer a(123123);
    Integer c(123123 * 2);
    Integer b(2);
    a *= b;
    EXPECT_TRUE(c == a );
}
TEST(multiplication, multEq1){
    Integer a(123123);
    Integer c(123123);
    Integer b(99999999999999999);
    a *= b;
    EXPECT_TRUE(a == c * b);
}
TEST(multiplication, multEq2){
    Integer a(99999999999999999);
    Integer b(0);
    a *= b;
    EXPECT_TRUE(a == b);
}

TEST(Division, normalDiv) {
    Integer a(1000000);
    Integer b(100);
    Integer c = a / b;
    EXPECT_TRUE(c == a / b);
}

TEST(Division, divEq) {
    Integer a(1234567899876543210);
    Integer b(-123123);
    Integer c(a / b);
    a /= b;
    EXPECT_TRUE(c == a);
}
TEST(Division, zeroDiv) {
    Integer a(123456789987654321);
    Integer b(0);
    EXPECT_ANY_THROW(a / b);
}
TEST(Division, divEq1) {
    Integer a(-123456789987654321);
    Integer b(-123123);
    Integer c(a / b);
    a /= b;
    EXPECT_TRUE(c == a);
}
TEST(Division, divEqZero) {
    Integer a(123456789987654321);
    Integer b(0);
    EXPECT_ANY_THROW(a /= b);
}
TEST(resDivision, normalDiv) {
    Integer a(1000000);
    Integer b(100);
    Integer c = a % b;
    EXPECT_TRUE(c == a % b);
}
TEST(resDivision, normalDiv1) {
    Integer a(123456789987654321);
    Integer b(123123);
    Integer c = a % b;
    EXPECT_TRUE(c == a % b);
}
TEST(resDivision, difSignDiv) {
    Integer a(123456789987654321);
    Integer b(-123123);
    Integer c = a % b;
    EXPECT_TRUE(c == a % b);
}
TEST(resDivision, zeroDiv) {
    Integer a(123456789987654321);
    Integer b(0);
    EXPECT_ANY_THROW(a % b);
}
TEST(resDivision, divEq) {
    Integer a(123456789987654321);
    Integer b(-123123);
    Integer c(a % b);
    a %= b;
    EXPECT_TRUE(c == a);
}
TEST(resDivision, divEq1) {
    Integer a(-123456789987654321);
    Integer b(-123123);
    Integer c(a % b);
    a %= b;
    EXPECT_TRUE(c == a);
}
TEST(resDivision, divEqZero) {
    Integer a(123456789987654321);
    Integer b(0);
    EXPECT_ANY_THROW(a %= b);
}

TEST(conversion,toBool) {
    Integer a(123123);
    EXPECT_TRUE(bool(a));
}
TEST(conversion,toBool1) {
    Integer a(0);
    EXPECT_FALSE(bool(a));
}
TEST(conversion,toBool2) {
    Integer a(-123123);
    EXPECT_TRUE(bool(a));
}
TEST(conversion,toUnChar) {
    Integer a(127);
    EXPECT_TRUE(a.Conversation<unsigned char>() == 127);
}
TEST(conversion,toUnChar1) {
    Integer a(0);
    EXPECT_TRUE(a.Conversation<unsigned char>() == 0);
}
TEST(conversion,toChar) {
    Integer a(123);
    EXPECT_TRUE(a.Conversation<char>() == 123);
}
TEST(conversion,toChar1) {
    Integer a(-123);
    EXPECT_TRUE(a.Conversation<char>() == -123);
}
TEST(conversion,toUnShort) {
    Integer a(65534);
    EXPECT_TRUE(a.Conversation<unsigned short int>()== 65534);
}
TEST(conversion,toUnShort1) {
    Integer a(0);
    EXPECT_TRUE(a.Conversation<unsigned short int>() == 0);
}
TEST(conversion,toShort) {
    Integer a(15000);
    EXPECT_TRUE(a.Conversation<short int>() == 15000);
}
TEST(conversion,toShort1) {
    Integer a(0);
    EXPECT_TRUE(a.Conversation<short int>() == 0);
}
TEST(conversion,toShort2) {
    Integer a(-15000);
    EXPECT_TRUE(a.Conversation<short int>() == -15000);
}
TEST(conversion,toUnInt) {
    Integer a(4294967295);
    EXPECT_TRUE(a.Conversation<unsigned int>()== 4294967295);
}
TEST(conversion,toUnInt1) {
    Integer a(0);
    EXPECT_TRUE(a.Conversation<unsigned int>() == 0);
}
TEST(conversion,toInt) {
    Integer a(2147483647);
    EXPECT_TRUE(a.Conversation<int>() == 2147483647);
}
TEST(conversion,toInt1) {
    Integer a(0);
    EXPECT_TRUE(a.Conversation<int>() == 0);
}
TEST(conversion,toInt2) {
    Integer a(-2147483648);
    EXPECT_TRUE(a.Conversation<int>() == -2147483648);
}
TEST(conversion,toUnLong) {
    Integer a(4294967295);
    EXPECT_TRUE(a.Conversation<unsigned long>()== 4294967295);
}
TEST(conversion,toUnLong1) {
    Integer a(0);
    EXPECT_TRUE(a.Conversation<unsigned long>() == 0);
}
TEST(conversion,toLong) {
    Integer a(2147483647);
    EXPECT_TRUE(a.Conversation<long>() == 2147483647);
}
TEST(conversion,toLong1) {
    Integer a(0);
    EXPECT_TRUE(a.Conversation<long>() == 0);
}
TEST(conversion,toLong2) {
    Integer a(-2147483648);
    EXPECT_TRUE(a.Conversation<long>() == -2147483648);
}
TEST(conversion,toUnLongLong) {
    Integer a(184467440737095516);
    EXPECT_TRUE(a.Conversation<unsigned long long>()== 184467440737095516);
}
TEST(conversion,toUnLongLong1) {
    Integer a(0);
    EXPECT_TRUE(a.Conversation<unsigned long long>() == 0);
}
TEST(conversion,toLongLong) {
    Integer a(922337203685477580);
    EXPECT_TRUE(a.Conversation<long long>() == 922337203685477580);
}
TEST(conversion,toLongLong1) {
    Integer a(0);
    EXPECT_TRUE(a.Conversation<long long>() == 0);
}
TEST(conversion,toLongLong2) {
    Integer a(-922337203685477580);
    EXPECT_TRUE(a.Conversation<long long>() == -922337203685477580);
}