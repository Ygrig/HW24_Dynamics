#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

template <typename T>
void fill_arr(T arr[], const int length, int begin, int end) {
	srand(time(NULL));
	for (int i = 0; i < length; i++)
		arr[i] = rand() % (end - begin) + begin;
}

template <typename T>
void show_arr(T arr[], const int length) {
	cout << '[';
	for (int i = 0; i < length; i++)
		cout << arr[i] << ", ";
	cout << "\b\b]\n";
}

template <typename T>
void resize_arr(T*& arr, int length1, int length2) {
	T* tmp = new T[length2]{};
	for (int i = 0; i < length2; i++) {
		if (i < length1)
			tmp[i] = arr[i];
		else
		tmp[i] = 0;
	}
	delete[]arr;
	arr = tmp;
	}

	
int main() {

	int n, m;

	//Task 24.1. Third array
	cout << "Task 1. Third array.\n";
	cout << "Enter the size of array A: \n";
	cin >> n;
	int* arrA = new int[n];
	cout << "Enter the size of array B: \n";
	cin >> m;
	int* arrB= new int[m];
	fill_arr(arrA, n, 1, 11);
	fill_arr(arrB, m, 3, 31);
	cout << "\nArray A:\n";
	show_arr(arrA, n);
	cout << "\nArray B:\n";
	show_arr(arrB, m);
	int* arrC = new int[n+m];
	for (int i = 0; i < n; i++)
		arrC[i] = arrA[i];
	for (int i = n; i < n+m; i++)
		arrC[i] = arrB[i-n];
	cout << "\nArray C:\n";
	show_arr(arrC, n+m);
	delete[]arrA;
	delete[]arrB;
	cout << "\n\n";

	//Task 24.2. Resize
	cout << "Task 2. Resize array.\n";
	cout << "Enter the initial size of array: \n";
	cin >> n;
	int* arr = new int[n];
	fill_arr(arr, n, 1, 21);
	cout << "Initial array: \n";
	show_arr(arr, n);
	cout << "Enter new size of array: \n";
	cin >> m;
	resize_arr(arr, n, m);
	cout << "Resized array:\n";
	n = m;
	show_arr(arr,n);

		
	return 0;
}