#pragma once
#include <iostream>
using namespace std;
template<class type>
class Matrix
{
private:
	type** matrix;
	size_t rows;
	size_t cols;
public:
	Matrix();
	Matrix(const size_t r, const size_t c);
	Matrix(const type** m, const size_t r, const size_t c);
	Matrix(const Matrix& m);
	~Matrix();


	void setMatrix(const type** m);
	type** getMatrix();
	void setRows(const size_t r);
	size_t getRows();
	void setCols(const size_t c);
	size_t getCols();

	void Init();

	type FindMax();
	type FindMin();

	bool EqualMatrix(const Matrix& R);
	bool EqualMatrixCols1Rows2(const Matrix& R);

	Matrix& operator=(const Matrix& m);
	Matrix operator+(const Matrix& R);
	Matrix operator-(const Matrix& R);
	Matrix operator*(const Matrix& R);
};

template<class type>
Matrix<type>::Matrix() {
	matrix = NULL;
	rows = 0;
	cols = 0;
}

template<class type>
Matrix<type>::Matrix(const size_t r, const size_t c) {
	rows = r;
	cols = c;
	matrix = new type * [rows];
	for (int i = 0; i < rows; i++)
		matrix[i] = new type[cols];
}

template<class type>
Matrix<type>::Matrix(const type** m, const size_t r, const size_t c) : Matrix(r, c) {
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++)
			matrix[i][j] = m.matrix[i][j];
	}	
}

template<class type>
Matrix<type>::Matrix(const Matrix<type>& m) :  Matrix(m.rows, m.cols){
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++)
			matrix[i][j] = m.matrix[i][j];
	}
}

template<class type>
Matrix<type>::~Matrix() { delete[] matrix; }

template<class type>
void Matrix<type>::setMatrix(const type** m){ 
	delete[] matrix;
	rows = m.rows;
	cols = m.cols;
	matrix = new type * [rows];
	for (int i = 0; i < rows; i++)
		matrix[i] = new type[cols];
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++)
			matrix[i][j] = m.matrix[i][j];
	}
}
template<class type>
type** Matrix<type>::getMatrix() { return matrix;  }
template<class type>
void Matrix<type>::setRows(const size_t r) { rows = r;  }
template<class type>
size_t Matrix<type>::getRows() { return rows;  }
template<class type>
void Matrix<type>::setCols(const size_t c) { cols = c; }
template<class type>
size_t Matrix<type>::getCols() { return cols; }

template<class type>
void Matrix<type>::Init() {
	if (is_same<type, float>::value) {
		float a;
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < cols; j++) {
				matrix[i][j] = rand() % 2000 - 1000;
				a = rand() % 2000;
				while (a > 1)
					a /= 10;
				if(matrix[i][j] >= 0) matrix[i][j] += a;
				else matrix[i][j] -= a;
			}
		}
	}
	else if(is_same<type, int>::value){
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < cols; j++)
				matrix[i][j] = rand() % 2000 - 1000;
		}
	}
	else {
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < cols; j++)
				matrix[i][j] = rand() % 126 + 1;
		}
	}
}

template<class type>
istream& operator>>(istream& in, Matrix<type>& m) {
	for (int i = 0; i < m.getRows(); i++) {
		for (int j = 0; j < m.getCols(); j++) {
			cout << "Enter item: ";
			in >> m.getMatrix()[i][j];
		}
	}
	return in;
}

template<class type>
ostream& operator<<(ostream& out, Matrix<type>& m) {
	for (int i = 0; i < m.getRows(); i++) {
		for (int j = 0; j < m.getCols(); j++)
			out << m.getMatrix()[i][j] << ' ';
		out << endl;
	}
	out << endl;
	return out;
}

template<class type>
type Matrix<type>::FindMax(){
	type max = matrix[0][0];
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			if (matrix[i][j] > max)
				max = matrix[i][j];
		}
	}
	return max;
}

template<class type>
type Matrix<type>::FindMin(){
	type min = matrix[0][0];
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			if (matrix[i][j] < min)
				min = matrix[i][j];
		}
	}
	return min;
}

template<class type>
Matrix<type>& Matrix<type>::operator=(const Matrix<type>& m) {
	delete[] matrix;
	rows = m.rows;
	cols = m.cols;
	matrix = new type * [rows];
	for (int i = 0; i < rows; i++)
		matrix[i] = new type[cols];
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++)
			matrix[i][j] = m.matrix[i][j];
	}
	return *this;
}

template<class type>
bool Matrix<type>::EqualMatrix(const Matrix<type>& R) {
	return (rows == R.rows) && (cols == R.cols);
}

template<class type>
bool Matrix<type>::EqualMatrixCols1Rows2(const Matrix<type>& R) {
	return cols == R.rows;
}

template<class type>
Matrix<type> Matrix<type>::operator+(const Matrix<type>& R) {
	if(EqualMatrix(R) == false)
		exit(-1);
	Matrix result;
	result.rows = rows;
	result.cols = cols;
	result.matrix = new type * [rows];
	for (int i = 0; i < rows; i++)
		result.matrix[i] = new type[cols];
 	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++)
			result.matrix[i][j] = matrix[i][j] + R.matrix[i][j];
	}
	return result;
}

template<class type>
Matrix<type> Matrix<type>::operator-(const Matrix<type>& R) {
	if(EqualMatrix(R) == false)
		exit(-1);
	Matrix result;
	result.rows = rows;
	result.cols = cols;
	result.matrix = new type * [rows];
	for (int i = 0; i < rows; i++)
		result.matrix[i] = new type[cols];
 	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++)
			result.matrix[i][j] = matrix[i][j] - R.matrix[i][j];
	}
	return result;
}

template<class type>
Matrix<type> Matrix<type>::operator*(const Matrix<type>& R) {
	if(EqualMatrixCols1Rows2(R) == false)
		exit(-1);
	else {
		Matrix result;
		result.rows = rows;
		result.cols = R.cols;
		result.matrix = new type * [result.rows];
		for (int i = 0; i < result.rows; i++)
			result.matrix[i] = new type[result.cols];
		for (int i = 0; i < result.rows; i++) {
			for (int j = 0; j < result.cols; j++) {
				result.matrix[i][j] = 0;
				for (int l = 0; l < cols; l++)
					result.matrix[i][j] += matrix[i][l] * R.matrix[l][j];
			}
		}
		return result;
	}
}