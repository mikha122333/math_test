#pragma once
#include <random>
#include <stdexcept>
struct Task {
	double _num_1;
	double _num_2;
	double ans_;
	char operation_;
	Task();
	Task(const double min,const double max,const char operation='\0');
};
class MathTest {
	Task* _tasks;
	size_t _count;
	double* _usser_answers;
	size_t _correct_count;
public:
	MathTest(size_t count);
	MathTest(size_t count, int min, int max);
	MathTest(size_t count, int min, int max, char op);
	~MathTest();
	void run();
	void show_statistics()const noexcept;
};