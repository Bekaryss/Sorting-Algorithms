// Merge Sort.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>

using namespace std;

vector<int> merge(vector<int> left, vector<int> right) {
	vector<int> ret(left.size() + right.size());
	int left_cursor = 0, right_cursor = 0, ret_cursor = 0;

	while (left_cursor < left.size() && right_cursor < right.size()) {
		if (left[left_cursor] < right[right_cursor]) {
			ret[ret_cursor++] = left[left_cursor++];
		}
		else {
			ret[ret_cursor++] = right[right_cursor++];
		}
	}
	// append what is remain the above lists
	while (left_cursor < left.size()) {
		ret[ret_cursor++] = left[left_cursor++];
	}
	while (right_cursor < right.size()) {
		ret[ret_cursor++] = right[right_cursor++];
	}
	return ret;
}

vector<int> merge_sort(vector<int> input) {
	if (input.size() <= 1)
		return input;

	int pivot = input.size() / 2;
	vector<int> left(input.begin(), input.begin() + pivot);
	left = merge_sort(left);
	vector<int> right(input.begin() + pivot, input.end());
	right = merge_sort(right);
	return merge(left, right);
}

void PrintRes(vector<int> res) {
	for (int i = 0; i < res.size(); i++)
	{
		cout << res[i] << " ";
	}
	cout << endl;
}

int main()
{
	vector<int> input = { 4, 8, 7, 9, 3, 6, 1, 2, 0 , 3, 5 };
	PrintRes(merge_sort(input));
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
