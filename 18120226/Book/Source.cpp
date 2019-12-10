#include"process.h"
void print(int a, bool b = 0) {
	cout << a;
	cout << b;
}
void main() {

	process a;
	a.LoadData();
	a.Process();

	system("Pause");
}

