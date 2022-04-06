#include "Matrix.hpp"
namespace zich
{
    
    Matrix &Matrix::operator*=(const Matrix &mat){
        check3(mat);
        vector<double> mat3_data;
        mat3_data = resize2(mat, mat3_data);
        setCol(mat._col);
        setData(mat._data);
        return *this;}
    

    vector<double> Matrix::resize2(const Matrix &mat, vector<double> mat2){
        mat2.resize((unsigned int)(this->_row * mat._col));
        return mat2; }


    Matrix &Matrix::operator+=(const Matrix &mat){
        check(mat);
        return *this;}
    
    Matrix &Matrix::operator*=(const double scalar){
        return *this;}
   
    bool Matrix::operator<=(Matrix &mat){
       check(mat);
       return true;}

    Matrix::Matrix(const vector<double> &data, const int row, const int col){
       check2(data,row,col);
       setMatrix(data,row,col); }

    bool Matrix::operator<(Matrix &mat){
       check(mat);
       return true;}


    bool Matrix::operator>(Matrix &mat){
       check(mat);
       return true;}


    Matrix Matrix::operator-(const Matrix &mat){
        check(mat);
        vector<double> mat3_data;
        mat3_data = resize(mat3_data);
        Matrix mat3(mat3_data, this->_row, mat._col);
        return mat3;}

    void Matrix::setMatrix(vector<double> data, int row, int col){
        this->setRow(row);
        this->setCol(col);
        this->setData(data);}

    Matrix Matrix::operator*(const double scalar){
        return *this;}
    
    vector<string> split(string str, char seperator){
        vector<string> vec;
        return vec;}
    
    
    Matrix Matrix::operator*(const Matrix &mat){
        check3(mat);
        vector<double> mat3_data;
        mat3_data = resize2(mat, mat3_data);
        Matrix mat3(mat3_data, this->_row, mat._col);
        return mat3;}


    void Matrix::check(const Matrix mat)const{
        if (getRow() != mat.getRow() || getCol() != mat.getCol()){throw runtime_error("row and col must be equal");}}

   
    Matrix Matrix::operator+(Matrix const &mat){
        return *this;}

    vector<double> Matrix::resize(vector<double> mat){
        mat.resize((unsigned int)(_row * _col));
        return mat;
    }

    bool Matrix::operator>=(Matrix &mat){
       check(mat);
       return true;}

    
    bool Matrix::operator==(Matrix &mat){
       check(mat); 
       return true;}


    
    void Matrix::check3(const Matrix &mat){
        if (this->_col != mat._row){throw runtime_error("Cols not equal");}
    }


    Matrix operator*(const double scalar, Matrix &mat){
        vector<double> mat3_data;        
        mat3_data.resize((unsigned int)(mat._row * mat._col));
        Matrix mat3(mat3_data, mat._row, mat._col);
        return mat3;}
    
    
    void Matrix::check2(vector<double> data, int row, int col)const{
        if (row <= 0 || col <= 0){throw runtime_error("row or col can't be negative");}
        if (data.size() != row * col){throw runtime_error("the array must be equal to the size of the matrix");}}

    bool Matrix::operator!=(Matrix &mat){
       check(mat);
       return true;}


    Matrix &Matrix::operator-=(const Matrix &mat){
       check(mat);
       return *this;}

    Matrix operator-(Matrix &mat){
        vector<double> mat3_data;
        mat3_data.resize((unsigned int)(mat._row * mat._col));
        Matrix mat3(mat3_data, mat._row, mat._col);
        return mat3;}

    ostream &operator<<(ostream &out, const Matrix &mat){
       return out;}

    Matrix::~Matrix(){}
}

