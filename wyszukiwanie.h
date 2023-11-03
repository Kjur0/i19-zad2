#pragma once

#include <cmath>
#include <ctime>
#include <iostream>
#include <vector>

int sequentialSearchCount(int array[], int value, int arraySize) {
	int count = 0;

	for ( int index = 0; index < arraySize; index++ ) {
		if ( array[index] == value ) {
			count++;
		}
	}

	return count;
}

void wyszmain1() {
	srand((unsigned int)time(NULL));

	int array[20];
	int tmp;

	for ( int i = 0; i < 20; i++ ) {
		tmp = rand() % 20 + 1;
		array[i] = tmp;
	}

	std::cout << "Wylosowano nastepujace liczby: " << std::endl;
	for ( int i = 0; i < 20; i++ ) {
		std::cout << array[i] << " ";
	}
	std::cout << std::endl;

	std::cout << "Podaj liczbe do wyszukania: ";
	std::cin >> tmp;

	int count = sequentialSearchCount(array, tmp, 20);

	std::cout << "Liczba wystapien: " << count << std::endl;

	system("pause");
}

std::vector<int> sequentialSearchIndex(int array[], int value, int arraySize) {
	std::vector<int> indexes;

	int count = sequentialSearchCount(array, value, arraySize);

	for ( int i = 0; i <= count; i++ ) {
		int index = 0;
		if ( i > 0 ) {
			index = indexes[i - 1];
		}
		while ( index < arraySize ) {
			if ( array[index] == value ) {
				indexes[i] = index;
				break;
			}
			index++;
		}
	}

	return indexes;
}

void wyszmain2() {
	srand((unsigned int)time(NULL));

	int array[20];
	int tmp;

	for ( int i = 0; i < 20; i++ ) {
		tmp = rand() % 20 + 1;
		array[i] = tmp;
	}

	std::cout << "Wylosowano nastepujace liczby: " << std::endl;
	for ( int i = 0; i < 20; i++ ) {
		std::cout << array[i] << " ";
	}
	std::cout << std::endl;

	std::cout << "Podaj liczbe do wyszukania: ";
	std::cin >> tmp;

	int count = sequentialSearchCount(array, tmp, 20);

	std::cout << "Liczba wystapien: " << count << std::endl;

	std::vector<int> indexes = sequentialSearchIndex(array, tmp, 20);

	std::cout << "Indeksy wystapien: " << std::endl;
	for ( int i = 0; i < indexes.size(); i++ ) {
		std::cout << indexes[i] << " ";
	}

	system("pause");
}

bool sequentialSearch(int array[], int value, int arraySize) {
	for ( int index = 0; index < arraySize; index++ ) {
		if ( array[index] == value ) {
			return true;
		}
	}

	return false;
}

void wyszmain3() {
	int correctCodes[] = { 5658845, 4520125, 7895122, 8777541, 8451277, 1302850, 8080152, 4562555, 5552012, 5050552, 7825877, 1250255, 1005231, 6545231, 3852085, 7576651, 7881200, 4581002 };
	int code;

	std::cout << "Podaj kod: ";
	std::cin >> code;

	if ( sequentialSearch(correctCodes, code, 18) ) {
		std::cout << "Kod poprawny" << std::endl;
	}
	else {
		std::cout << "Kod niepoprawny" << std::endl;
	}

	system("pause");
}

bool binarySearch(int array[], int value, int arraySize) {
	for ( int index = 1; index < arraySize; index++ ) {
		int unsortedValue = array[index];
		int scan = index;

		while ( scan > 0 && array[scan - 1] > unsortedValue ) {
			array[scan] = array[scan - 1];
			scan--;
		}

		array[scan] = unsortedValue;
	}

	int first = 0;
	int last = arraySize - 1;
	int middle;

	while ( first <= last ) {
		middle = (first + last) / 2;

		if ( array[middle] == value ) {
			return true;
		}
		else if ( array[middle] > value ) {
			last = middle - 1;
		}
		else {
			first = middle + 1;
		}
	}

	return false;
}

void wyszmain4() {
	int correctCodes[] = { 5658845, 4520125, 7895122, 8777541, 8451277, 1302850, 8080152, 4562555, 5552012, 5050552, 7825877, 1250255, 1005231, 6545231, 3852085, 7576651, 7881200, 4581002 };
	int code;

	std::cout << "Podaj kod: ";
	std::cin >> code;

	if ( binarySearch(correctCodes, code, 18) ) {
		std::cout << "Kod poprawny" << std::endl;
	}
	else {
		std::cout << "Kod niepoprawny" << std::endl;
	}

	system("pause");
}

int sequentialSearchComps(int array[], int value, int arraySize) {
	int comps = 0;

	for ( int index = 0; index < arraySize; index++ ) {
		comps++;
		if ( array[index] == value ) {
			break;
		}
	}

	return comps;
}

int binarySearchComps(int array[], int value, int arraySize) {
	int comps = 0;

	for ( int index = 1; index < arraySize; index++ ) {
		int unsortedValue = array[index];
		int scan = index;

		while ( scan > 0 && array[scan - 1] > unsortedValue ) {
			array[scan] = array[scan - 1];
			scan--;
		}

		array[scan] = unsortedValue;
	}

	int first = 0;
	int last = arraySize - 1;
	int middle;

	while ( first <= last ) {
		middle = (first + last) / 2;

		comps++;
		if ( array[middle] == value ) {
			break;
		}
		else if ( array[middle] > value ) {
			last = middle - 1;
		}
		else {
			first = middle + 1;
		}
	}

	return comps;
}

void wyszmain5() {
	srand((unsigned int)time(NULL));

	int array[20];
	int tmp;

	for ( int i = 0; i < 20; i++ ) {
		tmp = rand() % 100 + 1;
		for ( int j = i; j >= 0; j-- ) {
			if ( array[j] == tmp ) {
				tmp = rand() % 100 + 1;
				j = i;
			}
		}
		array[i] = tmp;
	}

	std::cout << "Wylosowano nastepujace liczby: " << std::endl;
	for ( int i = 0; i < 20; i++ ) {
		std::cout << array[i] << " ";
	}
	std::cout << std::endl;

	tmp = array[rand() % 20];

	std::cout << "Wyszukiwana liczba: " << tmp << std::endl;

	std::cout << "\nSortowanie sekwencyjne\nLiczba porownan: " << sequentialSearchComps(array, tmp, 20) << std::endl;

	std::cout << "\nSortowanie binarne\nLiczba porownan: " << binarySearchComps(array, tmp, 20) << std::endl;

	system("pause");
}