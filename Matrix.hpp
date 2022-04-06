#pragma once
#include <iostream>
#include <vector>
#include <stdexcept>
#include <string>
using namespace std;

namespace zich
{
    class Matrix
    {
    private:
        
        int _row;
        
        int _col;
        
        vector<double> _data;

    public:

        int getRow()const{ return this->_row; }
        
        int getCol()const{ return this->_col; }

        Matrix operator-(const Matrix &mat);
        
        Matrix& operator-=(const Matrix &mat);

        Matrix operator+(Matrix const &mat);
        
        Matrix& operator+=(const Matrix &mat);
  
        vector<double> getData()const{ return this->_data; }

        Matrix operator*(const double scalar);
        
        Matrix& operator*=(const double scalar);
        
        void check(const Matrix mat)const;

        Matrix operator*(const Matrix &mat);
        
        Matrix& operator*=(const Matrix &mat);

        void setRow(int row){ this->_row = row; }
        
        void setCol(int col){ this->_col = col; }
        
        void setData(vector<double> data){ this->_data = data; }

        bool operator==(Matrix &mat);
       
        bool operator!=(Matrix &mat);
       
        bool operator<(Matrix &mat);
        
        vector<double> resize2(const Matrix &mat, vector<double> mat2);

        bool operator<=(Matrix &mat);
        
        bool operator>(Matrix &mat);
        
        void check3(const Matrix &mat);

        bool operator>=(Matrix &mat);
        
        void setMatrix(vector<double> data, int row, int col);
        

        friend ostream & operator << (ostream &out, const Matrix &mat);
        
        void check2(vector<double> data, int row, int col)const;
        
        friend Matrix operator*(const double scalar, Matrix &mat);
        
        vector<double> resize(vector<double> mat);

        friend Matrix operator+(Matrix &mat);
        

        friend Matrix operator-(Matrix &mat);

        Matrix(const vector<double> &data, const int row, const int col);
       
        ~Matrix();
        
    };
}