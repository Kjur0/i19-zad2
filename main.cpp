#include "sortowanie.h"
#include "wyszukiwanie.h"

using namespace std;

int main() {
	char wyb;
wybor:
	cout << "Wybierz zestaw zadan\n\tA) Sortowanie\n\tB) Wyszukiwanie\nWybor: ";
	cin >> wyb;
	switch ( wyb ) {
	case 'A':
	case 'a':
		goto sort;
		break;
	case 'B':
	case 'b':
		goto wysz;
		break;
	default:
		cout << "Nie ma takiego zestawu zadan!" << endl;
		goto wybor;
		break;
	}

sort:
	cout << "Wybierz zadanie (2/3): ";
	cin >> wyb;
	switch ( wyb ) {
	case '2':
		sortmain1();
		break;
	case '3':
		sortmain2();
		break;
	default:
		cout << "Nie ma takiego zadania!" << endl;
		goto sort;
		break;
	}
	goto end;

wysz:
	cout << "Wybierz zadanie (1/2/3/4/5): ";
	cin >> wyb;
	switch ( wyb ) {
	case '1':
		wyszmain1();
		break;
	case '2':
		wyszmain2();
		break;
	case '3':
		wyszmain3();
		break;
	case '4':
		wyszmain4();
		break;
	case '5':
		wyszmain5();
		break;
	default:
		cout << "Nie ma takiego zadania!" << endl;
		goto wysz;
		break;
	}
	goto end;

end:
	cout << "Czy chcesz zakonczyc? (T/N): ";
	cin >> wyb;
	switch ( wyb ) {
	case 'T':
	case 't':
		return 0;
		break;
	case 'N':
	case 'n':
		goto wybor;
		break;
	default:
		cout << "Nie ma takiej opcji!" << endl;
		goto end;
		break;
	}
}