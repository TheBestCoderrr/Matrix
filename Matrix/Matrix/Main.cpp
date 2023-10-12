#include <iostream>
#include <ctime>
#include "Matrix.h"
using namespace std;

int main() {
	srand(time(0));
	Matrix<int> result;
	Matrix<int> m1(3,3);
	m1.Init();
	cout << m1;
	Matrix<int> m2(3, 3);
	m2.Init();
	cout << m2;

	result = m1 + m2;
	cout << result;
	cout << endl;
	
	result = m1 - m2;
	cout << result;

	cout << endl;
	Matrix<int> m3(2, 3);
	m3.Init();
	cout << m3;
	Matrix<int> m4(3, 2);
	m4.Init();
	cout << m4;
	result = m3 * m4;
	cout << result;

	Matrix<char> m5(2, 2);
	m5.Init();
	cout << m5;
	Matrix<char> m6(2, 2);
	m6.Init();
	cout << m6;
	Matrix<char> result2;
	result2 = m5 + m6;
	cout << result2;
}