#include <iostream>
#include "ArchivoItem.h"

using namespace std;

int main() {

	struct Item struct_item;
	ArchivoItem ai;
	int resp = -1;

	do {
		cout << "---------------------" << endl
			<< "	Examen Parcial" << endl
			<< "1. Buscar por nombre (binariamente) " << endl
			<< "2. Salir" << endl
			<< "---------------------" << endl;
		cin >> resp;

		if (resp == 1) {
			char nombres[30];;
			cout << "Ingrese nombre a buscar: " << endl;
			cin >> nombres;

			int res = ai.buscarNombreB(nombres);
			((res < 0) ? cout << "No se encontro el nombre." << endl : cout << "Nombre encontrado. " << endl);
		}

	} while (resp != 2);

	return 0;
}