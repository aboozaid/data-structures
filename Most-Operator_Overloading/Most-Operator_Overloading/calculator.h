#pragma once
class calculator {
	int endint;
	double enddouble;
public:
	calculator();
	calculator operator+ (int);
	calculator operator+ (float);
	calculator operator- (int);
	calculator operator- (float);
	calculator operator* (int);
	calculator operator* (float);
	calculator operator/ (int);
	calculator operator/ (float);
	calculator operator= (calculator *);
	void display(calculator *);
};
