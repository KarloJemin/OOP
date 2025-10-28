#include <iostream>
#include <string>
#include <cctype>

int main() {
	std::string s;
	std::getline(std::cin, s);

	for (char& c:s) {
		if (std::isalpha(c)) {
			c = std::toupper(c);
		}
		else if (std::isdigit(c)) {
			c = '*';
		}
		else if (std::isspace(c)) {
			c = '_';
		}
	}

	std::cout << s << std::endl;
}
