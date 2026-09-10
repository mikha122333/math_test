#pragma once
#include <random>
#include <stdexcept>
struct Task {
	double num_1_;
	double num_2_;
	double ans_;
	char operation_;
	Task();
	Task(const double min,const double max,const char operation='\0');
};
Task::Task() {
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> random_num(-10000, 10000);
	std::uniform_int_distribution<> random_operation(0,3);//+ - / * 
	num_1_ = random_num(gen);
	num_2_ = random_num(gen);
	switch (int i = random_operation(gen)) {
	case 0: operation_ = '+'; ans_ = num_1_ + num_2_; break;
	case 1:operation_ = '-'; ans_ = num_1_ - num_2_; break;
		case 2:operation_ = '/';
			while (num_2_ == 0) { num_2_ = random_num(gen); };
			ans_ = num_1_ / num_2_;
			break;
		case 3:operation_ = '*'; ans_ = num_1_ * num_2_; break;
	};
}
Task::Task(const double min, const double max, const char operation = '\0') {
	if (min > max)
		throw std::logic_error("min>max");
	if (operation != '+' && operation != '-' && operation != '*' && operation != '/' && operation != '\0')
		throw std::logic_error("wrong operation");
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> random_num(min, max);
	num_1_ = random_num(gen);
	num_2_ = random_num(gen);
	int op;
	if(operation=='\0'){
		std::uniform_int_distribution<> random_operation(0, 3);//+ - / *
		op = random_operation(gen);
	}
	else {
		if (operation == '+')
			op = 0;
		else if (operation == '-')
			op = 1;
		else if (operation == '/')
			op = 2;
		else if (operation == '*')
			op = 3;
	}
	switch (op) {
	case 0: operation_ = '+'; ans_ = num_1_ + num_2_; break;
	case 1:operation_ = '-'; ans_ = num_1_ - num_2_; break;
	case 2:operation_ = '/';
		while (num_2_ == 0) { num_2_ = random_num(gen); };
		ans_ = num_1_ / num_2_;
		break;
	case 3:operation_ = '*'; ans_ = num_1_ * num_2_; break;
	};
}
class MathTest {};