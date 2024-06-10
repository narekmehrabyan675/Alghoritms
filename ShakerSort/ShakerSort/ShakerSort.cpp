#include <iostream>
using namespace std;
//Function swap
void Swap(int* Mas, int i)
{
	int temp;
	temp = Mas[i];
	Mas[i] = Mas[i - 1];
	Mas[i - 1] = temp;
}
//Function of Shaker Sort
void ShakerSort(int* Mas, int Start, int N)
{
	int Left, Right, i;
	Left = Start;
	Right = N - 1;
	while (Left <= Right)
	{
		for (i = Right; i >= Left; i--) {
			if (Mas[i - 1] > Mas[i]) Swap(Mas, i);
		}
		Left++;
		for (i = Left; i <= Right; i++) {
			if (Mas[i - 1] > Mas[i]) Swap(Mas, i);
		}
		Right--;
	}
}
//General funtion
int main()
{
	int n, k;
	cout << "Leinght of massive > "; 
	cin >> n;
	int* A = new int[n];
	for (k = 0; k < n; k++)
	{
		cout << k + 1 << " Element > ";
		cin >> A[k];
	}
	ShakerSort(A, 1, n);
	cout << "Resulting massive: ";
	for (k = 0; k < n; k++) {
		cout << " " << A[k];
	}
	return 0;
}
