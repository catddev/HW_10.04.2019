#pragma once
#include"Fraction.h"

class Vector
{
private:
	Fraction *els;
	int cur_size;
	int buf_size;
public:
	Vector();
	Vector(int size);
	Vector(const Vector& obj);
	int size();
	void add(Fraction el);
	Fraction & operator[](int index);
	void print();
	~Vector();
};