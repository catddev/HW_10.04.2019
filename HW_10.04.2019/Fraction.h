#pragma once
#include<iostream>
#include<fstream>
using namespace std;

//класс Fraction(простая дробь)
//	Арифметические операции для работы с дробями(перегрузите операторы + , -, *, / )
//	Проверка на равенство двух дробей(операция == )
//Реализовать вектор дробных чисел, а также меню для тестирования всех методов.
//Ваш проект должен работать как калькулятор для дробных чисел.

class Fraction {
private:
	int a;
	int b;
public: // ВСЕГДА ПАБЛИК!!!
	Fraction();
	Fraction(int a, int b);
	void setFraction(int a, int b);
	int getA();
	int getB();

	Fraction operator+(Fraction obj);
	Fraction operator-(Fraction obj);
	Fraction operator*(Fraction obj);
	Fraction operator/(Fraction obj);
	bool operator==(Fraction obj);
	//Fraction reduct();
	void print();
};