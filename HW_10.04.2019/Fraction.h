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
	int c;
public: // ВСЕГДА ПАБЛИК!!!
	Fraction();
	Fraction(int a, int b);
	Fraction(int a, int b, int c);
	void setFraction(int a, int b, int c);
	int getA();
	int getB();
	int getC();

	Fraction operator+(Fraction obj);
	Fraction operator-(Fraction obj);
	Fraction operator*(Fraction obj);
	Fraction operator/(Fraction obj);
	Fraction operator=(Fraction obj);
	bool operator==(Fraction obj);
	Fraction reduct();
	void print();
};