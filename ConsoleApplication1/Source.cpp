#include "iostream";
using namespace std;
void EnterArray(int* , int);
void DisplayArray(int* , int);
void QuickSort(int* , int, int);
void NewSortedArray(int*, int*, int, int&);
void Swap(int&, int&);
int main()
{
	int n, s = 0;
	cout << "enter the size of array:\n";
	cin >> n;
	int*a = new int[n];
	int*b = new int[];
	EnterArray(a, n);
	QuickSort(a, 0, n - 1);
	cout << "sourted array:\n";
	DisplayArray(a, n);
	NewSortedArray(a, b, n, s);
	cout << "new sourted array:\n";
	DisplayArray(b, s);
	system("pause");
	return 0;
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



