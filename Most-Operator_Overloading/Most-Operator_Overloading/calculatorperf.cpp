#include "stdafx.h"
#include "calculator.h"

calculator::calculator() {
	endint = 0;
	enddouble = 0;
}
calculator calculator::operator+ (int x) {
	calculator *ptr = new calculator();
	ptr->endint = x;
	return *ptr;
}
calculator calculator:: operator+ (float x) {
	calculator *ptr = new calculator();
	ptr->enddouble = x;
	return *ptr;
}
calculator calculator:: operator- (int x) {
	calculator *ptr = new calculator();
	ptr->endint = x;
	return *ptr;
}
calculator calculator:: operator- (float x) {
	calculator *ptr = new calculator();
	ptr->enddouble = x;
	return *ptr;
}
calculator calculator:: operator* (int x) {
	calculator ptr;
	ptr.endint = x;
	return ptr;
}
calculator calculator:: operator* (float x) {
	calculator *ptr = new calculator();
	ptr->enddouble = x;
	return *ptr;
}
calculator calculator:: operator/ (int x) {
	calculator *ptr = new calculator();
	ptr->endint = x;
	return *ptr;
}
calculator calculator:: operator/ (float x) {
	calculator *ptr = new calculator();
	ptr->enddouble = x;
	return *ptr;
}
calculator calculator:: operator= (calculator *ptr) {
	if (ptr->endint != 0)
		this->endint = ptr->endint;
	else
		this->enddouble = ptr->enddouble;
	return *this;
}
void calculator:: display(calculator *ptr) {
	if (ptr->endint != 0)
		printf("%d", ptr->endint);
	else
		printf("%.2f", ptr->enddouble);
}