#include "Matrix.hpp"
#include "doctest.h"
using namespace zich;

TEST_CASE("Difference size matrix"){
    vector<double> vector1;
    vector<double> vector2;
    for (double i = 0; i < 25; ++i){ vector1.push_back(i); }
    for (double i = 0; i < 36; ++i){ vector2.push_back(i); }
    Matrix a{vector1, 5, 5};
    Matrix b{vector2, 6, 6};
    CHECK_THROWS(b *= a);
    CHECK_THROWS(a *= b);
    CHECK_THROWS(b * a);
    CHECK_THROWS(a * b);
    CHECK_THROWS(b -= a);
    CHECK_THROWS(a -= b);
    CHECK_THROWS(b += a);
    CHECK_THROWS(a += b);
    CHECK_THROWS(b - a);
    CHECK_THROWS(a - b);
    CHECK_THROWS(b + a);
    CHECK_THROWS(a + b);
}
TEST_CASE("Same size matrix"){
        vector<double> vector1;
        vector<double> vector2;
        vector<double> vector3;
        vector<double> vector4;
        for (double i = 0; i < 16; ++i){ vector1.push_back(i); }
        for (double i = 0; i < 16; ++i){ vector2.push_back(20); }
        for (double i = 0; i < 16; ++i){ vector3.push_back(i); }
        for (double i = 0; i < 16; ++i){ vector4.push_back(i); }
        Matrix a{vector1, 4, 4};
        Matrix b{vector2, 4, 4};
        Matrix c{vector3, 4, 4};
        Matrix d{vector4, 4, 4};
        CHECK_EQ(a != b, true);
        CHECK_EQ(a == b, false);
        CHECK_EQ(a >= b, false);
        CHECK_EQ(a > b, false);  
        CHECK_EQ(a <= b, true);
        CHECK_EQ(a < b, true);  
        CHECK_EQ(c != d, false);
        CHECK_EQ(c == d, true);
        CHECK_EQ(c >= d, true);
        CHECK_EQ(c > d, false);
        CHECK_EQ(c <= d, true);
        CHECK_EQ(c < d, false);      
}
