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
    SUBCASE("same matrix"){
        vector<double> vector1;
        vector<double> vector2;
        
        for (double i = 0; i < 16; ++i){ vector1.push_back(i); }
        for (double i = 0; i < 16; ++i){ vector2.push_back(i); }
        
        Matrix a{vector1, 4, 4};
        Matrix b{vector2, 4, 4};
        
        CHECK_EQ(a != b, false);
        CHECK_EQ(a == b, true);
        CHECK_EQ(a >= b, true);
        CHECK_EQ(a > b, false);  
        CHECK_EQ(a <= b, true);
        CHECK_EQ(a < b, false);  
           
    }
    SUBCASE("a and b same size but differnt values(b have bigger values)")
    {
        vector<double> vector1;
        for (double i = 0; i < 9; ++i)
        {
            vector1.push_back(i);
        }
        vector<double> vector2;
        for (double i = 0; i < 9; ++i)
        {
            vector2.push_back(9);
        }
        Matrix a{vector1, 3, 3};
        Matrix b{vector2, 3, 3};
        CHECK_EQ(a > b, false);
        CHECK_EQ(a >= b, false);
        CHECK_EQ(a < b, true);
        CHECK_EQ(a <= b, true);
        CHECK_EQ(a == b, false);
        CHECK_EQ(a != b, true);
    }   
}
TEST_CASE("bad input *, *= ")
{
    /*
    in *, *= we need the mat1.col == mat2.row.
    and the array we push must be same size as the rows*cols.
    */
    vector<double> vector1;
    for (double i = 0; i < 16; ++i)
    {
        vector1.push_back(i);
    }
    vector<double> vector2;
    for (double i = 0; i < 9; ++i)
    {
        vector2.push_back(i);
    }
    Matrix a{vector1, 4, 4};
    Matrix b{vector2, 3, 3};
    CHECK_THROWS(a * b);
    CHECK_THROWS(b * a);
    CHECK_THROWS(a *= b);
    CHECK_THROWS(b *= a);
}

TEST_CASE("bad input +, -, +=, -= ")
{
    /*
    matrix a and matrix b are not equal in the size.
    in +, -, the rows and the cols must be equal.
    and the array we push must be same size as the rows*cols.
    */
    vector<double> vector1;
    for (double i = 0; i < 16; ++i)
    {
        vector1.push_back(i);
    }
    vector<double> vector2;
    for (double i = 0; i < 9; ++i)
    {
        vector2.push_back(i);
    }
    Matrix a{vector1, 4, 4};
    Matrix b{vector2, 3, 3};
    CHECK_THROWS(a + b);
    CHECK_THROWS(b + a);
    CHECK_THROWS(a - b);
    CHECK_THROWS(b - a);
    CHECK_THROWS(a += b);
    CHECK_THROWS(b += a);
    CHECK_THROWS(a -= b);
    CHECK_THROWS(b -= a);

    SUBCASE(" scalar * ")
    {
    vector<double> mat3v = {1, 2, 3, 4}; // matrix 2*2
    vector<double> mat3_4v = {2,4,6,8}; // matrix 2*2
    Matrix mat3(mat3v,2,2);
    Matrix mat3_4(mat3_4v,2,2);
    CHECK_EQ(mat3 * 2 == mat3_4, true);
    }
}