#include "sortowanie.h"
#include "wyszukiwanie.h"

int main() {
	char wyb;
wybor:
	cout << "Wybierz zestaw zadan" << endl << "\tA) Sortowanie" << endl << "Wybor: ";
	cin >> wyb;
	switch ( wyb ) {
	case 'A':
	case 'a':
		goto sort;
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

end:
	return 0;
}