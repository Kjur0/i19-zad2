#pragma once

#include <cmath>
#include <ctime>
#include <iostream>
#include <string>

using namespace std;

void swap(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}

int bubbleSort(int* array, int arraySize) {
	int swaps = 0;

	int maxElement;
	int index;

	for ( maxElement = arraySize; maxElement > 0; maxElement-- ) {
		for ( index = 0; index < maxElement - 1; index++ ) {
			if ( array[index] > array[index + 1] ) {
				swap(array[index], array[index + 1]);
				swaps++;
			}
		}
	}

	return swaps;
}

int selectionSort(int* array, int arraySize) {
	int swaps = 0;

	int startScan;
	int minIndex;
	int minValue;
	int index;

	for ( startScan = 0; startScan < arraySize - 1; startScan++ ) {
		minIndex = startScan;
		minValue = array[startScan];

		for ( index = startScan + 1; index < arraySize; index++ ) {
			if ( array[index] < minValue ) {
				minValue = array[index];
				minIndex = index;
			}
		}

		swap(array[minIndex], array[startScan]);
		swaps++;
	}

	return swaps;
}

int insertionSort(int* array, int arraySize) {
	int swaps = 0;

	int index;
	int scan;
	int unsortedValue;

	for ( index = 1; index < arraySize; index++ ) {
		unsortedValue = array[index];
		scan = index;

		while ( scan > 0 && array[scan - 1] > unsortedValue ) {
			array[scan] = array[scan - 1];
			swaps++;
			scan--;
		}

		array[scan] = unsortedValue;
	}

	return swaps;
}

void sortmain1() {
	srand(time(NULL));

	int array0[20];
	int array1[20];
	int array2[20];
	int array3[20];
	int tmp;

	for ( int i = 0; i < 20; i++ ) {
		tmp = rand() % 100 + 1;
		for ( int j = i; j >= 0; j-- ) {
			if ( array0[j] == tmp ) {
				tmp = rand() % 100 + 1;
				j = i;
			}
		}
		array0[i] = tmp;
		array1[i] = tmp;
		array2[i] = tmp;
		array3[i] = tmp;
	}

	cout << "Tablica przed sortowaniem:" << endl;
	for ( int i = 0; i < 20; i++ ) {
		cout << array0[i] << " ";
	}
	cout << endl << endl;

	cout << "Sortowanie babelkowe:" << endl;
	cout << "Liczba zamian: " << bubbleSort(array1, 20) << endl;
	for ( int i = 0; i < 20; i++ ) {
		cout << array1[i] << " ";
	}
	cout << endl << endl;

	cout << "Sortowanie przez wybor:" << endl;
	cout << "Liczba zamian: " << selectionSort(array2, 20) << endl;
	for ( int i = 0; i < 20; i++ ) {
		cout << array2[i] << " ";
	}
	cout << endl << endl;

	cout << "Sortowanie przez wstawianie:" << endl;
	cout << "Liczba zamian: " << insertionSort(array3, 20) << endl;
	for ( int i = 0; i < 20; i++ ) {
		cout << array3[i] << " ";
	}
	cout << endl << endl;

	system("pause");
}

void swap(string& a, string& b) {
	string temp = a;
	a = b;
	b = temp;
}

void bubbleSort(string* array, int arraySize) {
	int maxElement;
	int index;

	for ( maxElement = arraySize; maxElement > 0; maxElement-- ) {
		for ( index = 0; index < maxElement - 1; index++ ) {
			if ( array[index] > array[index + 1] ) {
				swap(array[index], array[index + 1]);
			}
		}
	}
}

void selectionSort(string* array, int arraySize) {
	int startScan;
	int minIndex;
	string minValue;
	int index;

	for ( startScan = 0; startScan < arraySize - 1; startScan++ ) {
		minIndex = startScan;
		minValue = array[startScan];

		for ( index = startScan + 1; index < arraySize; index++ ) {
			if ( array[index] < minValue ) {
				minValue = array[index];
				minIndex = index;
			}
		}

		swap(array[minIndex], array[startScan]);
	}
}

void insertionSort(string* array, int arraySize) {
	int index;
	int scan;
	string unsortedValue;

	for ( index = 1; index < arraySize; index++ ) {
		unsortedValue = array[index];
		scan = index;

		while ( scan > 0 && array[scan - 1] > unsortedValue ) {
			array[scan] = array[scan - 1];
			scan--;
		}

		array[scan] = unsortedValue;
	}
}

void sortmain2() {
	string array[20];
	string tmp;

	cout << "Wprowadz 20 imion (oddziel spacjami, na koncu enter):" << endl;
	for ( int i = 0; i < 20; i++ ) {
		cin >> tmp;
		array[i] = tmp;
	}

	cout << "Tablica przed sortowaniem:" << endl;
	for ( int i = 0; i < 20; i++ ) {
		cout << array[i] << " ";
	}
	cout << endl << endl;

	char wyb;
sortmain2wyb:
	cout << "Wybierz sortowanie\n\tA)Sortowanie babelkowe\n\tB)Sortowanie przez wybieranie\n\tC)Sortowanie przez wstawianie\n" << "Wybor: ";
	cin >> wyb;
	switch ( wyb ) {
	case 'A':
	case 'a':
		bubbleSort(array, 20);
		break;
	case 'B':
	case 'b':
		selectionSort(array, 20);
		break;
	case 'C':
	case 'c':
		insertionSort(array, 20);
		break;
	default:
		cout << "Nie ma takiego sortowania!" << endl;
		goto sortmain2wyb;
		break;
	}
	cout << "Posortowana tablica:" << endl;
	for ( int i = 0; i < 20; i++ ) {
		cout << array[i] << " ";
	}
	cout << endl << endl;

	system("pause");
}