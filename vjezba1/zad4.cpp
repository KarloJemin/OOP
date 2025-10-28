#include <iostream>

int& fun(int* niz, unsigned i) {
	return niz[i];
}


int main() {
	int niz[5] = {1, 2, 3, 4, 5};
	std::cout << niz << std::endl;
	fun(niz, 3) += 1;
	std::cout << niz << std::endl;

}