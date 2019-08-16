#include <iostream>
#include <fstream>

using namespace std;

struct Item {
	int code;
	char name[30];
	char lastname[30];
	char city[50];
};

class ArchivoItem {

private:
	int totalRegistros = -1;

public:

	int buscarNombreB(const char* lookName) {
		Item struct_item;
		ifstream fileC("items.dat", ios::in | ios::binary);
		if (!fileC) {
			cout << "Error de apertura en el archivo!" << endl;
		}

		fileC.seekg(0, ios::end);
		int fileSize = fileC.tellg();
		totalRegistros = fileSize / sizeof(struct_item);

		int menor = 0;
		int mayor = totalRegistros - 1;
		int mitad = -1;

		while (menor <= mayor) {
			mitad = (mayor + menor) / 2;

			//lee el registro.
			int puntero = (mitad * sizeof(struct_item));
			fileC.seekg(puntero, ios::beg);
			fileC.read(reinterpret_cast<char*> (&struct_item), sizeof(struct_item));
			int resultado = strcmp(lookName, struct_item.name);

			if (resultado < 0) {
				mayor = mitad - 1;
			}
			else if (resultado > 0) {
				menor = mitad + 1;
			}
			else {
				cout << "Codigo: " << struct_item.code << " Nombre: " << struct_item.name
					<< " Apellidos: " << struct_item.lastname
					<< " Ciudad: " << struct_item.city << endl;
				return 1;
			}
		}
		return -1;
	}


};
