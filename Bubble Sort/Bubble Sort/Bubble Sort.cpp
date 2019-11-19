// Bubble Sort.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

template <typename T>
void bubble_sort(T& a) {
	for (std::size_t i = 0; a.size() && i < a.size() - 1; ++i) {
		for (std::size_t j = i; j + 1 > 0; j--) {
			if (a[j] > a[j + 1]) {
				std::swap(a[j], a[j + 1]);
			}
		}
	}
}

template <typename T>
void invert_string(T& a) {
	std::size_t length = a.size();
	for (std::size_t i = 0; i < length / 2; i++) {
		std::swap(a[i], a[length - i - 1]);
	}
}

int main()
{
	std::vector<int> v;
	v.push_back(7);
	v.push_back(1000);
	v.push_back(134);
	v.push_back(23);
	v.push_back(1);
	for (int i : v) {
		std::cout << i << " ";
	}
	std::cout << std::endl;
	bubble_sort(v); 
	for (int i : v) {
		std::cout << i << " ";
	}
	std::cout << std::endl;
	std::string str = "abcdefg";
	invert_string(str);
	std::cout << str << std::endl;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
