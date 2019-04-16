#include "Fraction.h"

Fraction::Fraction()
{
	a = 0;
	b = 1;//не делить на 0
	c = 0;
}

Fraction::Fraction(int a, int b)
{
	this->a = a;
	this->b = b;
	this->c = 0;
}

Fraction::Fraction(int a, int b, int c)
{
	this->a = a;
	this->b = b;
	this->c = c;
}

void Fraction::setFraction(int a, int b, int c)
{
	this->a = a;
	this->b = b;
	this->c = c;
}

int Fraction::getA()
{
	return a;
}
int Fraction::getB()
{
	return b;
}

int Fraction::getC()
{
	return c;
}

Fraction Fraction::operator+(Fraction obj)
{
	Fraction tmp(*this);
	if(b==obj.b){
		tmp.b = b;
		tmp.a = a + obj.a;
	}
	else if (b%obj.b==0 || obj.b%b==0) {
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
	else if (b%obj.b==0 || obj.b%b==0) {
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

Fraction Fraction::operator=(Fraction obj)
{
	this->a = obj.a;
	this->b = obj.b;
	return *this;
}

bool Fraction::operator==(Fraction obj)
{
	return((a/b)==(obj.a/obj.b));
}

Fraction Fraction:: reduct()
{
	if (a % b == 0) {
		c = a / b;
		a = b = 0;
		return *this;
	}
	int nod=1;
	int k = a < b ? a : b;
	for (int i = k; i > 0; i--) {
		if (a % i == 0 && b % i == 0) {
			nod = i;
			break;
		}
	}
	a /= nod;
	b /= nod;
	
	return *this;
}

void Fraction::print()
{
	if (c != 0) {
		cout << c << endl;
	}
	else cout << a << "/" << b << endl;
}
