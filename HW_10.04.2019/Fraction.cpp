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

Fraction Fraction::reduct()
{
	int nod=1;
	int c = a < b ? a : b;
	for (int i = c; i > 0; i--) {
		if (a % i == 0 && b % i == 0) {
			nod = i;
			break;
		}
	}
	a /= nod;
	b /= nod;
	//if (a == b) return
	return *this;
}

void Fraction::print()
{
	cout << a << "/" << b << endl;
}
