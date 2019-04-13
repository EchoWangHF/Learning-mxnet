#pragma once
#include<opencv2/core/core.hpp>
#include<vector>
#include<random>
#include<ctime>
#include<cmath>
#include<fstream>
#include<iostream>

//����
struct Parameters
{
	int iteration = 0;          //����������
	int optimizer = 1;          //�Ż�����ѡ��
	float alpha = 0.01;         //�ݶ��½��Ĳ�����
	int classify_num = 2;        //��������the number of category 
	float lamda = 0.001;        //˥��Ȩ�أ�
	int batch_size = 50;        //
	int K = 5;                  //KNN�㷨��K;
};

class NN
{
	//ȫ�������磻
public:
	NN(std::vector<int> network_size,Parameters Para) :NN_size(network_size),para(Para) {}
	~NN() {
		NN_size.clear();
		NN_w.clear();
		NN_der_w.clear();
		NN_der_b.clear();
		traindata.release();
		trainlabel.release();
	}

	void train(cv::Mat traindata, cv::Mat trainlabel);
	void predict(cv::Mat testdata, cv::Mat testlabel);
	void saveModel(std::string model_path = "");
	void loadModel(std::string model_path = "");
private:
	std::vector<int> NN_size;
	std::vector<cv::Mat> NN_w;
	std::vector<cv::Mat> NN_b;

	std::vector<cv::Mat> NN_der_w;
	std::vector<cv::Mat> NN_der_b;

	Parameters para;
	cv::Mat traindata, trainlabel;


	void Mat_Shuffle(cv::Mat &data, cv::Mat &label);
	cv::Mat RandMat(int rows, int cols);
	cv::Mat One_hot(cv::Mat mat, int K);
	inline int Argmax(cv::Mat mat);

	void Mini_SGD(int mini_batch_begin);

	cv::Mat forward(cv::Mat data);
    void backprop(int index);
	double Loss();

	inline float sigmoid(float z);
	cv::Mat sigmoid(cv::Mat z);
	cv::Mat mean_exp(cv::Mat z);
	inline float der_sigmoid(float z);
	cv::Mat der_sigmoid(cv::Mat z);

};

