#pragma once
#include <random>
#include <stdexcept>
#include<iostream>
struct Task {
	double _num_1;
	double _num_2;
	double ans_;
	char operation_;
	Task();
	Task(const double& min,const double& max,const char& operation='\0');
};
class MathTest {
	Task** _tasks;
	unsigned int _count;
	double* _user_answers;
	unsigned int _correct_count;
public:
	MathTest(const unsigned int& count);
	MathTest(const unsigned int& count, const double& min,const double& max,const char& op= '\0');
	~MathTest();
	void run();
	void show_statistics()const noexcept;
};