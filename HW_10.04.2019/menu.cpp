#include"menu.h"

void menu(Vector v)
{
	int x, y;
	while (true) {
		Fraction f3;
		char choice;
		cout << "Enter 1 to use your own numbers" << endl;
		cout << "Enter 2 to use array of fractions" << endl;
		int var;
		cin >> var;
		if (var == 1) {
			int a, b, c, d;
			cout << "enter numerator1, denominator1, operation (+, -, *, /), numerator2, denominator2" << endl;
			cin >> a >> b >> choice >> c >> d;
			cout << "=";
			Fraction f1(a, b);
			Fraction f2(c, d);
			
			if (choice == 0) break;
			switch (choice)
			{
			case '+':
				f3=(f1 + f2);
				f3.reduct();
				f3.print();
				break;
			case '-':
				f3 = (f1 - f2);
				f3.reduct();
				f3.print();
				break;
			case '*':
				f3=(f1 * f2);
				f3.reduct();
				f3.print();
				break;
			case '/':
				f3=(f1 / f2);
				f3.reduct();
				f3.print();
				break;
			case '==':
				if (f1 == f2) cout << "fractions are equal" << endl;
				break;
			}
		}
		else if (var == 2) {
			cout << "enter indexes of fractions from the array, then (+, -, *, /)" << endl;
			for (int i = 0; i < v.size(); i++)
			{
				cout << i << " - ";
				v[i].print();
			}
			int x, y;
			cin >> x >> y >> choice;
			cout << "=";
			if (choice == 0) break;
			switch (choice)
			{
			case '+':
				f3 = (v[x] + v[y]);
				f3.reduct();
				f3.print();
				break;
			case '-':
				f3=(v[x] - v[y]);
				f3.reduct();
				f3.print();
				break;
			case '*':
				f3=(v[x] * v[y]);
				f3.reduct();
				f3.print();
				break;
			case '/':
				f3=(v[x] / v[y]);
				f3.reduct();
				f3.print();
				break;
			case '==':
				if (v[x] == v[y]) cout << "fractions are equal" << endl;
				break;
			}
		}
	}
}