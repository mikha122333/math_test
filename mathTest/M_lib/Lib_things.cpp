#include "Lib_things.h"
Task::Task() {
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> random_num(-10000, 10000);
	std::uniform_int_distribution<> random_operation(0, 3);//+ - / * 
	_num_1 = random_num(gen);
	_num_2 = random_num(gen);
	switch (int i = random_operation(gen)) {
	case 0: operation_ = '+'; ans_ = _num_1 + _num_2; break;
	case 1:operation_ = '-'; ans_ = _num_1 - _num_2; break;
	case 2:operation_ = '/';
		while (_num_2 == 0) { _num_2 = random_num(gen); };
		ans_ = _num_1 / _num_2;
		break;
	case 3:operation_ = '*'; ans_ = _num_1 * _num_2; break;
	};
}
Task::Task(const double min, const double max, const char operation ) {
	if (min > max)
		throw std::logic_error("min>max");
	if (operation != '+' && operation != '-' && operation != '*' && operation != '/' && operation != '\0')
		throw std::logic_error("wrong operation");
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> random_num(min, max);
	_num_1 = random_num(gen);
	_num_2 = random_num(gen);
	int op;
	if (operation == '\0') {
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
	case 0: operation_ = '+'; ans_ = _num_1 + _num_2; break;
	case 1:operation_ = '-'; ans_ = _num_1 - _num_2; break;
	case 2:operation_ = '/';
		while (_num_2 == 0) { _num_2 = random_num(gen); };
		ans_ = _num_1 / _num_2;
		break;
	case 3:operation_ = '*'; ans_ = _num_1 * _num_2; break;
	};
}