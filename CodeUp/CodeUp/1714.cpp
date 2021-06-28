#include <iostream>
using namespace std;

int main() {
	int number;

	cin >> number; //9876 
	
	while (1) {
		cout << number % 10;
		number /= 10;
		if (number == 0) {
			break;
		}
	}
	return 0;
}
