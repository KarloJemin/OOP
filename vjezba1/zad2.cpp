#include <iostream>

int usporedi(int n, int low = 10, int high = 100) {
	if (n < low)
		return low;
	else if (n > high)
		return high;
	else
		return n;
}

double usporedi(double n, double low = 10, double high = 100) {
	if (n < low)
		return low;
	else if (n > high)
		return high;
	else
		return n;
}


int main() {
	int a = 12;
	double b = 9.3;
	std::cout << usporedi(a);
	std::cout << '\n';
	std::cout << usporedi(b);

}

