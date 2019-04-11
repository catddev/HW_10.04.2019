#include"menu.h"

int main() {
	Fraction f;
	Vector v;
	ifstream in_file("in.txt");
	int a, b;
	while (!in_file.eof()) {
		in_file >> a >> b;
		f.setFraction(a, b);
		v.add(f);
	}

	menu(v);

	system("pause");
	return 0;
}