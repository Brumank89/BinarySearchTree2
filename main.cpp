//Alarcón Alarcón Jonatan	Examen segundo parcial
#include <iostream>
#include "Arbol.h"
using namespace std;

int main() {
	Arbol arb;
	int opc, n;
	arb.inicializar();
	do {
		system("cls");
		cout << "Ingrese la opcion que desea: " << endl;
		cout << " 1.- Agregar nodo" << endl;
		cout << " 2.- Eliminar un nodo" << endl;
		cout << " 3.- Recorrer por preorden" << endl;
		cout << " 4.- Recorrer por orden" << endl;
		cout << " 5.- Recorrer por postorden" << endl;
		cout << " 6.- Obtener altura" << endl;
		cout << " 7.- Obtener profundidad" << endl;
		cout << " 8.- Obtener longitud" << endl;
		cout << " 9.- Desplegar nodos hermanos" << endl;
		cout << " 10.- Mostrar arbol" << endl;
		cout << " 11.- Salir" << endl;
		cin >> opc;
		switch (opc) {
		case 1:
			cout << "Selecciono 'Agregar nodo' " << endl;
			cout << "Ingrese el dato que desea guardar: ";
			cin >> n;
			arb.insertar(n);
			cout << "El dato se ingreso" << endl;
			system("pause");
			break;
		case 2:
			cout << "Selecciono 'Eliminar nodo' " << endl;
			cout << "Ingrese el dato que desea eliminar: ";
			cin >> n;
			arb.BuscarEliminar(arb.GetRaiz(), n);
			cout << "El dato se elimino" << endl;
			system("pause");
			break;
		case 3:
			cout << "Selecciono 'Recorrer por preorden' " << endl;
			arb.PreOrden(arb.GetRaiz());
			cout << endl;
			system("pause");
			break;

		case 4:
			cout << "Selecciono 'Recorrer por orden' " << endl;
			arb.Orden(arb.GetRaiz());
			cout << endl;
			system("pause");
			break;
		case 5:
			cout << "Selecciono 'Recorrer por postorden' " << endl;
			arb.PostOrden(arb.GetRaiz());
			cout << endl;
			system("pause");
			break;
		case 6:
			cout << "Selecciono 'Obtener altura' " << endl;
			cout << "Digite el dato del que quiere saber la altura: ";
			cin >> n;
			cout << "La altura es: ";
			arb.getAlturaBuscar(arb.GetRaiz(), n);
			cout << endl;
			system("pause");
			break;
		case 7:
			cout << "Selecciono 'Obtener profundidad' " << endl;
			if (arb.getProfundidad(arb.GetRaiz()) == -1) {
				cout << "No hay datos" << endl;
				system("pause");
			}
			else {
				cout << "El nivel es: ";
				cout << arb.getProfundidad(arb.GetRaiz());
				cout << endl;
				system("pause");
			}
			break;
		case 8:
			cout << "Selecciono 'Obtener longitud' " << endl;
				cout << "Ingrese el dato que desea: ";
				cin >> n;
				cout << "La longitud es: ";
				cout << arb.GetLongitud(arb.GetRaiz(), n, 0);
				cout << endl;
				system("pause");
				
			break;
		case 9:
			cout << "Selecciono 'Desplegar nodos hermanos' " << endl;
			cout << "Nodos Hermanos: ";
			cout << arb.getNodosHermanos(arb.GetRaiz());
			system("pause");
			break;

		case 10:
			cout << "Selecciono 'Mostrar arbol' " << endl;
			system("cls");
			arb.background();
			arb.show(arb.GetRaiz(), 70, 2, 0);
			_getch();
			system("cls");
			cout << "Nodos padres: ";
			cout << arb.getNodosPadres(arb.GetRaiz());
			cout << endl;
			cout << "Nodos Hijos: ";
			cout << arb.getNodosHijos(arb.GetRaiz());
			cout << endl;
			cout << "Hojas: ";
			cout << arb.getNodosHojas(arb.GetRaiz());
			cout << endl;
			system("pause");
			break;
		}

	} while (opc != 11);
	return 0;
}
