#include "iostream";
using namespace std;
void EnterArray(int* , int);
void DisplayArray(int* , int);
void QuickSort(int* , int, int);
void NewSortedArray(int*, int*, int, int&);
void Swap(int&, int&);
int dimention(int, int);
int main()
{
	while (true)
	{
		const int N = 100;
		int n, k, s = 0, l = 0;
		cout << "enter the size of array:\n";
		n = dimention(N, l);
		int*a = new int[n];
		int*b = new int[n];
		EnterArray(a, n);
		QuickSort(a, 0, n - 1);
		cout << "sourted array:\n";
		DisplayArray(a, n);
		NewSortedArray(a, b, n, s);
		cout << "new sourted array:\n";
		DisplayArray(b, s);
		system("pause");
		system("cls");
		cout << "Do you want to continue?\n";
		cout << "1.yes 2.no\n";
		cin >> k;
		if (k == 2)break;
	}
	return 0;
}
int dimention(int N, int l)
{
	while (true)
	{
		cout << "enter 0 < n <= " << N << endl;
		cin >> l;
		if (l > 0 && l <= N)
		{
			return l;
			break;
		}
	}
} 
void EnterArray(int* a, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << "array" << " [" << (i + 1) << "]\n";
		cin >> *a++;
	}
}
void QuickSort(int* a, int n)
{
	QuickSort(a, 0, n - 1);
}
void QuickSort(int* a, int left, int right)
{
	int i = left;
	int j = right;
	int middle = a[(left + right) / 2];
	while (i <= j)
	{
		while (a[i] < middle)i++;
		while (a[j] > middle)j--;
		if (i <= j)
		{
			Swap(a[i], a[j]);
			i++; j--;
		}
	}
	if (left < j)
		QuickSort(a, left, j);
	if (right > i)
		QuickSort(a, i, right);

}
void DisplayArray(int* a, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << "arr[" << i + 1 << "]=";
		cout << *a++ << "\n";
	}

}
void NewSortedArray(int* a, int* b, int n, int& s)

{
	int k = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (*(a + i) == *(a + j))
			{
				k++; break;
			}
			

		}
		if (!k)
		{
			*(b + s) = *(a + i);
			s++;

			
		}
		k = 0;
		
	}
}
void Swap(int &a, int &b)
{
	int t = a;
	a = b;
	b = t;
}



