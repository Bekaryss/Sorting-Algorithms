// Quick Sort.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>

using namespace std;

int partition(vector<int>& input, int lo, int hi) {
	int pivot = input[hi];
	int i = lo;
	for (int j = lo; j < hi; ++j) {
		if (input[j] < pivot) {
			int tmp = input[i];
			input[i] = input[j];
			input[j] = tmp;
			i++;
		}
	}
	int tmp = input[i];
	input[i] = input[hi];
 	input[hi] = tmp;
	return i;
}

void qSort(vector<int>& input, int lo, int hi) {
	if (lo < hi) {
		int p = partition(input, lo, hi);
		qSort(input, lo, p - 1);
		qSort(input, p + 1, hi);
	}
}

void quickSort(vector<int>& input) {
	int n = input.size();
	qSort(input, 0, n - 1);
}

int main()
{
	vector<int> input = { 5,3,2,1,8,9,10,25,4,7,4};
	quickSort(input);
	for (int i = 0; i < input.size(); i++) {
		cout << input[i] << " ";
	}
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
