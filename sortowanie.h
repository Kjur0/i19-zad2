#pragma once

#include <cmath>
#include <ctime>
#include <iostream>
#include <string>

void swap(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}

int bubbleSort(int* array, int arraySize) {
	int swaps = 0;

	for ( int maxElement = arraySize; maxElement > 0; maxElement-- ) {
		for ( int index = 0; index < maxElement - 1; index++ ) {
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

	for ( int startScan = 0; startScan < arraySize - 1; startScan++ ) {
		int minIndex = startScan;
		int minValue = array[startScan];

		for ( int index = startScan + 1; index < arraySize; index++ ) {
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

	for ( int index = 1; index < arraySize; index++ ) {
		int unsortedValue = array[index];
		int scan = index;

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
	srand((unsigned int)time(NULL));

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

	std::cout << "Tablica przed sortowaniem:" << std::endl;
	for ( int i = 0; i < 20; i++ ) {
		std::cout << array0[i] << " ";
	}
	std::cout << std::endl << std::endl;

	std::cout << "Sortowanie babelkowe:" << std::endl;
	std::cout << "Liczba zamian: " << bubbleSort(array1, 20) << std::endl;
	for ( int i = 0; i < 20; i++ ) {
		std::cout << array1[i] << " ";
	}
	std::cout << std::endl << std::endl;

	std::cout << "Sortowanie przez wybor:" << std::endl;
	std::cout << "Liczba zamian: " << selectionSort(array2, 20) << std::endl;
	for ( int i = 0; i < 20; i++ ) {
		std::cout << array2[i] << " ";
	}
	std::cout << std::endl << std::endl;

	std::cout << "Sortowanie przez wstawianie:" << std::endl;
	std::cout << "Liczba zamian: " << insertionSort(array3, 20) << std::endl;
	for ( int i = 0; i < 20; i++ ) {
		std::cout << array3[i] << " ";
	}
	std::cout << std::endl << std::endl;

	system("pause");
}

void swap(std::string& a, std::string& b) {
	std::string temp = a;
	a = b;
	b = temp;
}

void bubbleSort(std::string* array, int arraySize) {
	for ( int maxElement = arraySize; maxElement > 0; maxElement-- ) {
		for ( int index = 0; index < maxElement - 1; index++ ) {
			if ( array[index] > array[index + 1] ) {
				swap(array[index], array[index + 1]);
			}
		}
	}
}

void selectionSort(std::string* array, int arraySize) {
	for ( int startScan = 0; startScan < arraySize - 1; startScan++ ) {
		int minIndex = startScan;
		std::string minValue = array[startScan];

		for ( int index = startScan + 1; index < arraySize; index++ ) {
			if ( array[index] < minValue ) {
				minValue = array[index];
				minIndex = index;
			}
		}

		swap(array[minIndex], array[startScan]);
	}
}

void insertionSort(std::string* array, int arraySize) {
	for ( int index = 1; index < arraySize; index++ ) {
		std::string unsortedValue = array[index];
		int		scan = index;

		while ( scan > 0 && array[scan - 1] > unsortedValue ) {
			array[scan] = array[scan - 1];
			scan--;
		}

		array[scan] = unsortedValue;
	}
}

void sortmain2() {
	std::string array[20];
	std::string tmp;

	std::cout << "Wprowadz 20 imion (oddziel spacjami, na koncu enter):" << std::endl;
	for ( int i = 0; i < 20; i++ ) {
		std::cin >> tmp;
		array[i] = tmp;
	}

	std::cout << "Tablica przed sortowaniem:" << std::endl;
	for ( int i = 0; i < 20; i++ ) {
		std::cout << array[i] << " ";
	}
	std::cout << std::endl << std::endl;

	char wyb;
sortmain2wyb:
	std::cout << "Wybierz sortowanie\n\tA)Sortowanie babelkowe\n\tB)Sortowanie przez wybieranie\n\tC)Sortowanie przez wstawianie\n" << "Wybor: ";
	std::cin >> wyb;
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
		std::cout << "Nie ma takiego sortowania!" << std::endl;
		goto sortmain2wyb;
		break;
	}
	std::cout << "Posortowana tablica:" << std::endl;
	for ( int i = 0; i < 20; i++ ) {
		std::cout << array[i] << " ";
	}
	std::cout << std::endl << std::endl;

	system("pause");
}