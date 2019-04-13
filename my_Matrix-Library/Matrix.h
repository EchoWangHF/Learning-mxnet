#pragma once
#include<stdio.h>
#include<string>
#include<vector>
#include<iostream>
#include<assert.h>
#include<thread>


template<typename T> class Matrix;
template<typename T> std::ostream &operator<<(std::ostream &os, const Matrix<T> &mat);

template<typename T>
class Matrix {

public:
	friend std::ostream &operator<< <T>(std::ostream &os, const Matrix<T> &mat);

	int rows;
	int cols;

	//�������ƺ���;
	Matrix();
	Matrix(int rows, int cols);
	Matrix(const std::vector<std::vector<T>> &_data);

	Matrix(const Matrix<T> &other);
	Matrix& operator=(const Matrix<T> &other);
	~Matrix();

	//������Ա������
	inline T &at(int row_index, int col_index);
	inline T &at(int row_index, int col_index) const;
	void clear();
	Matrix add(const Matrix<T> &other); //��
	Matrix sub(const Matrix<T> &other); //��
	Matrix mul(const Matrix<T> &other); //��
	Matrix t();                         //ת��
	Matrix inv();                       //��
	Matrix zero();
	Matrix zero(int row,int col);
	Matrix operator+ (const Matrix<T> &other);
	Matrix operator- (const Matrix<T> &other);
	Matrix operator* (const Matrix<T> &other);
	Matrix operator* (const T &const_temp);
	Matrix operator/ (const T &const_temp);
	void push_back(std::vector<T> vec);
private:
	T * m_data;

	//˽�й��ܺ�����
	void vector_mul_vector(int row, const Matrix<T> &mat, T *data);
};

