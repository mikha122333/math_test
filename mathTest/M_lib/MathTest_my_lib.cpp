#include "MathTest_my_lib.h"
Task::Task(const double& min, const double& max, const char& operation ) {
	if (min > max)
		throw std::logic_error("min is to big");
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
MathTest::MathTest(const unsigned int& count,const double& min, const double& max,const char& op) {
	if (count == 0)
		throw std::range_error("trying to create Mathtest with 0 length");
	_tasks = new Task * [count];
	_count = count;
	_user_answers = new double[count];
	_correct_count = -1;
	for (int i = 0; i < count; i++) {
		_tasks[i] = new Task(min,max,op);
	}
}
MathTest::~MathTest() {
	for (int i = 0; i < _count; i++) {
		delete _tasks[i];
	}
	delete[] _tasks;
	delete[] _user_answers;
}
void MathTest::run()noexcept {
	_correct_count = 0;
	for (int i = 0; i < _count; i++) {
		std::cout << _tasks[i]->_num_1 << " " << _tasks[i]->operation_ << " " << _tasks[i]->_num_2 << " = ";
		std::cin >> _user_answers[i];
		if (_user_answers[i] == _tasks[i]->ans_)
			_correct_count++;
		system("cls");
	}
}
void MathTest::show_statistics()const noexcept {
	if (_correct_count == -1)
		throw std::logic_error("trying to get statisticks about test, without runnig it first");
	for (int i = 0; i < _count; i++) {
		std::cout << i + 1 << ". Question:" << _tasks[i]->_num_1 << " " << _tasks[i]->operation_ << " " << _tasks[i]->_num_2 << " correct ans:" << _tasks[i]->ans_ << " your ans:" << _user_answers[i] << std::endl;
	}
	std::cout << "number of correct ans: " << _correct_count<<std::endl;
}