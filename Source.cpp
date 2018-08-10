#include<iostream>
#include <string>
#include <conio.h>
#include <locale>
using namespace std;
//...

// A utility function to get maximum value in arr[]
int getMax(int arr[], int n)
{
	int mx = arr[0];
	for (int i = 1; i < n; i++)
		if (arr[i] > mx)
			mx = arr[i];
	return mx;
}

void convertToASCII(string letter, int arr[])
{
	for (int i = 0; i < letter.length(); i++)
	{
		int x = letter.at(i);
		arr[i] = x;
	}
}
void convertToString(char* arry, int arr[], int len) {
	


	for (int i = 0; i < len; i++)
	{
		
		arry[i] = char(arr[i]);
	
	}
	arry[len] = '\0';
}


// A function to do counting sort of arr[] according to
// the digit represented by exp.
void countSort(int arr[], int n, int exp)
{
	int* output = new int[n]; // output array
	int i, count[10] = { 0 };

	// Store count of occurrences in count[]
	for (i = 0; i < n; i++)
		count[(arr[i] / exp) % 10]++;

	// Change count[i] so that count[i] now contains actual
	//  position of this digit in output[]
	for (i = 1; i < 10; i++)
		count[i] += count[i - 1];

	// Build the output array
	for (i = n - 1; i >= 0; i--)
	{
		output[count[(arr[i] / exp) % 10] - 1] = arr[i];
		count[(arr[i] / exp) % 10]--;
	}

	// Copy the output array to arr[], so that arr[] now
	// contains sorted numbers according to current digit
	for (i = 0; i < n; i++)
		arr[i] = output[i];
}

// The main function to that sorts arr[] of size n using 
// Radix Sort
void radixsort(int arr[], int n)
{
	// Find the maximum number to know number of digits
	int m = getMax(arr, n);

	// Do counting sort for every digit. Note that instead
	// of passing digit number, exp is passed. exp is 10^i
	// where i is current digit number
	for (int exp = 1; m / exp > 0; exp *= 10)
		countSort(arr, n, exp);
}
string mytolower(string s) {
	locale loc;
	for (string::size_type i = 0; i<s.length(); ++i)
		s[i] = tolower(s[i], loc);
	return s;
}
// A utility function to print an array
void print(string s)
{
	for (int i = 0; i < s.length(); i++)
		cout << s[i];
}

// Driver program to test above functions
int main()
{
	/**
	int num1 = 65;
	int num2 = 15;
	ostringstream oss;
	oss << num1 << num2;
	//Now, oss.str() gives us our string
	cout << oss.str();
	**/
	string plainText;

	cout << "Enter text to convert to ASCII: ";
	getline(cin, plainText);
	plainText = mytolower(plainText);
	int len = plainText.length();
	int* arr = new int[len];
	convertToASCII(plainText, arr);

	radixsort(arr, len);
	
	char* arry = new char[len];
	convertToString(arry, arr, len);
	string s1(arry);
	

	print(s1);
	_getch();
	return 0;
}



