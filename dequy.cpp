#include<iostream>
using namespace std;

// factorial
long factorial(long x) {
   	if (x > 1)
   	return (x * factorial(x-1));
 	else
 	return 1;
}
int main() {
 	long res = factorial(4);
 	return 0;
}


// tìm so.
int search(int key, int a[], int low, int high) {
	 if (low > high) return -1;
	 int mid = (low + high) / 2;
	 if (a[mid] == key) return mid;
	 if (a[mid] > key)
	 return search(key, a, low, mid-1);
	 return search(key, a, mid+1, high);
}

// hanoi Tower
void HaNoiTower(int n, int a, int b, int c)
{
	if (n == 1)
		cout << a << " ----> " << b << endl;
	else
	{
		HaNoiTower(n - 1, a, c, b); // chuyen n-1 dia tu a sang c
		cout << a << " ----> " << b << endl; // chuyen 1 dia a sang b
		HaNoiTower(n - 1, c, b, a); // chuyen n-1 dia tu c sang b
	}
}
