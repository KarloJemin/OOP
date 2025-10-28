#include <iostream>

int* fib(int n) {
	int* arr = new int[n] {1, 1};
	for (int i=2 ; i<=n ; i++) {
		arr[i] = arr[i - 1] + arr[i - 2];
	}
	return arr;
}

void main() {
	int n = 15;
	int* niz_pn = fib(n);
	for (int i = 0; i <= n; i++)
		std::cout << niz_pn[i] << "  ";	
}
