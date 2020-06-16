#include "iostream"
using namespace std;

bool prime(int x) {
	for (int i = 2; i <= sqrt(x); i++) {
		if (x % i == 0) {
			return false;
		}
	}
	return true;
}

void factorize(int x) {
	int div = 2;
	cout << x <<" = ";
	while (x > 1)
	{
		while (x % div == 0)
		{
			cout << div<< " * ";
			x = x / div;
		}
		div++;
	}
	cout << "1\n\n";
}

int gsd(int x, int y) {
	while (x != y) {
		if (x > y) {
			swap(x, y);
		}
		y = y - x;
	}
	return x;
}

int lcm(int x, int y) {
	return x * y / gsd(x, y);
}

int main()
{
	int x,y = 0;
	int q;

	do {
		cout << "1. Check for simplicity" << endl;
		cout << "2. Factorize" << endl;
		cout << "3. Find Greatest Common Divider" << endl;
		cout << "4. Find Least Common Multiple" << endl;
		cout << "0. Exit" << endl;
		cin >> q;
		switch (q) {

		case 1:
			cout << "\nEnter the number: ";
			cin >> x;
			if (x == 0 || x == 1)
				cout << "The number isn't prime and not composite" << endl;
			else if (prime(x))
				cout << "The number is prime" << endl;
			else
				cout << "The number isn't prime" << endl;
			break;

		case 2:
			cout << "\nEnter the number: ";
			cin >> x;
			factorize(x);
			break;

		case 3:
			cout << "\nEnter 2 numbers: ";
			cin >> x >> y;
			if (x == 0 || y == 0)
				cout << "GSD = 1" << endl<<endl;
			else
				cout << "GCD = " << gsd(x, y)<<endl;
			break;

		case 4:
			cout << "\nEnter 2 numbers: ";
			cin >> x >> y;
			cout << "LCM = " << lcm(x, y)<<endl;
			break;

		default:
			break;
		}
	} while (q != 0);
	system("pause");
	return 0;
}

