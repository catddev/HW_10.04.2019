#include "Fraction.h"

Fraction::Fraction()
{
	a = 0;
	b = 1;//не делить на 0
}

Fraction::Fraction(int a, int b)
{
	this->a = a;
	this->b = b;
}

void Fraction::setFraction(int a, int b)
{
	this->a = a;
	this->b = b;
}

int Fraction::getA()
{
	return a;
}
int Fraction::getB()
{
	return b;
}

Fraction Fraction::operator+(Fraction obj)
{
	Fraction tmp(*this);
	if(b==obj.b){
		tmp.b = b;
		tmp.a = a + obj.a;
	}
	else if (b%obj.b || obj.b%b) {
		tmp.b = b > obj.b ? b : obj.b;
		tmp.a = b > obj.b ? (a + obj.a*b/obj.b) : (a*obj.b / b + obj.a);
	}
	else {
		tmp.b = b * obj.b;
		tmp.a = a * obj.b + obj.a*b;
	}
	return tmp;
}

Fraction Fraction::operator-(Fraction obj)
{
	Fraction tmp(*this);
	if (b == obj.b) {
		tmp.b = b;
		tmp.a = a - obj.a;
	}
	else if (b%obj.b || obj.b%b) {
		tmp.b = b > obj.b ? b : obj.b;
		tmp.a = b > obj.b ? (a - obj.a*b/obj.b) : (a*obj.b / b - obj.a);
	}
	else {
		tmp.b = b * obj.b;
		tmp.a = a * obj.b - obj.a*b;
	}
	return tmp;	
}

Fraction Fraction::operator*(Fraction obj)
{
	Fraction tmp(*this);
	tmp.b = b * obj.b;
	tmp.a = a * obj.a;

	return tmp;
}

Fraction Fraction::operator/(Fraction obj)
{
	Fraction tmp(*this);
	tmp.a = a * obj.b;
	tmp.b = b * obj.a;

	return tmp;
}

bool Fraction::operator==(Fraction obj)
{
	return((a/b)==(obj.a/obj.b));
}

//Fraction Fraction::reduct()
//{
//	int nod = 1;
//	int k1 = 0, k2 = 0;
//	if (a % 2 == 0)
//	{
//		a = a / 2;
//		k1++;
//	}
//	else if (a % 2 != 0 && a!=1)
//
//
//	return *this;
//}

void Fraction::print()
{
	cout << a << "/" << b << endl;
}
