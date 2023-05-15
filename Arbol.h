#include <iostream>
#include <sstream>
#include <string>
#include <windows.h>
#include <conio.h>
#include "Nodo.h"
using namespace std;

class Arbol {
private:
	Nodo *raiz = new Nodo();
	string NodosHermanos, NodosPadres, NodosHijosIzq, NodosHijosDer, NodosHojas; 
public:
	void inicializar() {
		raiz = NULL;
	}

	Nodo* GetRaiz() {
		return raiz;
	}
	bool EsVacio() {
		if (raiz == NULL) {
			return true;
		}
		else {
			return false;
		}
	}

	void insertar(int n) {
		Nodo* nuevo = new Nodo();
		Nodo* aux = new Nodo(); 
		nuevo = nuevo->Crear(n);
		if (EsVacio()) { //Cuando el arbol es vacio
			raiz = nuevo;
		}
		else {
			SiguienteNodo(raiz, nuevo); //Recorrido recursivo
		}
	}

	void SiguienteNodo(Nodo* aux, Nodo* nuevo) {
		if (aux == NULL) {
			return;
		}
		else {
			if (nuevo->GetIdentificador() < aux->GetIdentificador()) { //Recorrido a la izquierda
				if (aux->GetApuntadorIzq() != NULL) {
					SiguienteNodo(aux->GetApuntadorIzq(), nuevo);
				}
				else {
					aux->setApuntadorIzq(nuevo);
				}
			}
			else {
				if (nuevo->GetIdentificador() > aux->GetIdentificador()) { //Recorrido a la derecha
					if (aux->GetApuntadorDer() != NULL) {
						SiguienteNodo(aux->GetApuntadorDer(), nuevo);
					}
					else {
						aux->setApuntadorDer(nuevo);
					}
				}
			}
		}
	}

	int GetLongitud(Nodo* aux, int n, int longitud) {
		if (aux != NULL) {
			if (n != aux->GetIdentificador()) { //Recorrer el arbol
				if (n < aux->GetIdentificador() && aux->GetApuntadorIzq() != NULL) {
					GetLongitud(aux->GetApuntadorIzq(), n, longitud + 1);
				}else {
					if (aux->GetApuntadorDer() != NULL) {
						GetLongitud(aux->GetApuntadorDer(), n, longitud + 1);
					}
				}
			}else {
				if (n == aux->GetIdentificador()) {
					return longitud;
				}else {
					return -1;
				}
			}
		}else {
			return -1;
		}
	}

	void getAlturaBuscar(Nodo* aux, int num) {
		if (aux == NULL) {
			return;
		}
		else {
			if (aux->GetIdentificador() == num) {
				cout << getAltura(aux) << endl; 
			}
			getAlturaBuscar(aux->GetApuntadorIzq(), num);
			getAlturaBuscar(aux->GetApuntadorDer(), num);
		}
	}
	
	int getAltura(Nodo *aux) {
		if (aux != NULL) {
			int contIzq, contDer;
			contIzq = getProfundidad(aux->GetApuntadorIzq()) + 1;
			contDer = getProfundidad(aux->GetApuntadorDer()) + 1;
			if (contIzq > contDer) {
				return contIzq;
			}
			else {
				return contDer;
			}
		}
		else {
			return -1;
		}
	}
	 
	//Profundidad
	int getProfundidad(Nodo* aux) {
		if (aux != NULL) {
			int contIzq, contDer;
			contIzq = getProfundidad(aux->GetApuntadorIzq()) + 1;
			contDer = getProfundidad(aux->GetApuntadorDer()) + 1;
			if (contIzq > contDer) {
				return contIzq;
			}
			else {
				return contDer;
			}
		}
		else {
			return -1;
		}
	}

	void PreOrden(Nodo* aux) {
		if (aux == NULL) { //caso base
			return;
		}
		else {
			//paso 1: imprime el dato del nodo actual
			cout << aux->GetIdentificador() << endl;
			//paso 2: recorre el arbol izquierdo
			PreOrden(aux->GetApuntadorIzq());
			//paso 3: recorre el arbol derecho
			PreOrden(aux->GetApuntadorDer());
		}
	}


	void Orden(Nodo* aux) {
		if (aux == NULL) {
			return;
		}
		else {
			//paso 1: recorre el arbol a la izquierda
			Orden(aux->GetApuntadorIzq());
			//paso 2: imprime el nodo
			cout << aux->GetIdentificador()<<endl;
			//paso 3:
			Orden(aux->GetApuntadorDer());
		}
	}

	void PostOrden(Nodo* aux) {
		if (aux == NULL) {
			return;
		}
		else {
			//paso 1: recorre el arbol a la izquierda
			PostOrden(aux->GetApuntadorIzq());
			//paso 2: recorre a la derecha
			PostOrden(aux->GetApuntadorDer());
			//paso 3:imprime el dato
			cout << aux->GetIdentificador()<<endl;
		}
	}

	string getNodosHermanos(Nodo* aux) {
		if (aux == NULL){
			return "";
		} else {
			if (aux->GetApuntadorIzq() != NULL and aux->GetApuntadorDer() != NULL) {
				stringstream ssizq, ssder;
				ssizq << aux->GetApuntadorIzq()->GetIdentificador();
				ssder << aux->GetApuntadorDer()->GetIdentificador();
				if (NodosHermanos == "")
					NodosHermanos = "[" + ssizq.str() + " y " + ssder.str() + "]";
				else
					NodosHermanos = NodosHermanos + ", " + "[" + ssizq.str() + " y " + ssder.str() + "]";
			}
			getNodosHermanos(aux->GetApuntadorIzq());
			getNodosHermanos(aux->GetApuntadorDer());
		}
		return NodosHermanos; 
	}

	string getNodosPadres(Nodo* aux) {
		if (aux == NULL)
			return "";
		else {
			if (aux->GetApuntadorIzq() != NULL || aux->GetApuntadorDer() != NULL) {
				stringstream ssr;
				ssr << aux->GetIdentificador();
				if (NodosPadres == "")
					NodosPadres = "[" + ssr.str() + "]";
				else
					NodosPadres = NodosPadres + ", " + "[" + ssr.str() + "]"; 
				
			}
			getNodosPadres(aux->GetApuntadorIzq());
			getNodosPadres(aux->GetApuntadorDer()); 
		}
		return NodosPadres;
	}

	string getNodosHijos(Nodo* aux) {
		if (aux == NULL)
			return "";
		else {
			if (aux->GetApuntadorIzq() != NULL) {
				stringstream ssIzq;
				ssIzq << aux->GetIdentificador();
				if (NodosHijosIzq == "")
					NodosHijosIzq = "[" + ssIzq.str() + "]";
				else
					NodosHijosIzq = NodosHijosIzq + ", " + "[" + ssIzq.str() + "]";
			}

			if (aux->GetApuntadorDer() != NULL) {
				stringstream ssDer;
				ssDer << aux->GetIdentificador();
				if (NodosHijosDer == "")
					NodosHijosDer = "[" + ssDer.str() + "]";
				else
					NodosHijosDer = NodosHijosDer + ", " + "[" + ssDer.str() + "]";
			}

			getNodosHijos(aux->GetApuntadorIzq());
			getNodosHijos(aux->GetApuntadorDer());
		}
		return NodosHijosIzq; 
		return NodosHijosDer; 
	}

	string getNodosHojas(Nodo* aux) {
		if (aux == NULL)
			return "";
		else {
			if (aux->GetApuntadorIzq() == NULL && aux->GetApuntadorDer() == NULL) {
				stringstream ssr;
				ssr << aux->GetIdentificador();
				if (NodosHojas == "")
					NodosHojas = "[" + ssr.str() + "]";
				else
					NodosHojas = NodosHojas + ", " + "[" + ssr.str() + "]";
			}
			getNodosHojas(aux->GetApuntadorIzq());
			getNodosHojas(aux->GetApuntadorDer());
		}
		return NodosHojas;
	}




	/*void BuscarEliminar(Nodo* aux, Nodo* previo, int n) { //Busaca el nodo
		if (aux == NULL) {
			return;
		}
		else {
			if (n < aux->GetIdentificador() ) {
				BuscarEliminar(aux->GetApuntadorIzq(), aux, n);
			}
			else {
				if (n > aux->GetIdentificador()) {
					BuscarEliminar(aux->GetApuntadorDer(), aux, n); 
				}
				else {
					EliminarNodo(aux);  
					if (previo->GetApuntadorIzq() != aux) {
						previo->apuntadorIzq = NULL;
					}
					else {
						previo->apuntadorDer = NULL; 
					}
					delete aux; 
					return; 
				}
			}
		}
	}*/


	void BuscarEliminar(Nodo* aux, int n) {
		if (aux == NULL) {
			return;
		}
		else {
			if (aux->GetIdentificador() == n) {
				EliminarNodo2(aux);  
				return;
			}
			else {
				if (n < aux->GetIdentificador()) {
					BuscarEliminar(aux->GetApuntadorIzq(), n);
				}
				else {
					BuscarEliminar(aux->GetApuntadorDer(), n);
				}
			}
		}
	}



	/*void BuscarEliminar2(Nodo* aux, Nodo* previo, int n) { //Busaca el nodo
		if (aux == NULL) { 
			return;
		}
		else {
			if (n < aux->GetIdentificador()) {
				BuscarEliminar2(aux->GetApuntadorIzq(), aux, n);
			}
			else {
				if (n > aux->GetIdentificador()) {
					BuscarEliminar2(aux->GetApuntadorDer(), aux, n);
				}
				else {
					if (previo->GetApuntadorIzq() != NULL || previo->GetApuntadorDer() !=NULL ) {
						EliminarNodo(previo); 
					}
					aux->apuntadorIzq = NULL;
					aux->apuntadorDer = NULL;  
					delete previo; 
					return;
				}
			}
		}
	}*/

	/*void EliminarNodo(Nodo* aux) { //Solo elimina hijos
			if (aux->GetApuntadorIzq() != NULL) {
				EliminarNodo(aux->GetApuntadorIzq());
			}
			if (aux->GetApuntadorDer() != NULL) {
				EliminarNodo(aux->GetApuntadorDer());
			}
			delete aux;
	} */

	/*void EliminarNodo(Nodo* aux) { //Solo elimina hijos
		if (aux->GetApuntadorIzq() == NULL && aux->GetApuntadorDer() == NULL) {
			delete aux;
		}
		else {
			if (aux->GetApuntadorIzq() != NULL) {
				EliminarNodo(aux->GetApuntadorIzq());
			}
			if (aux->GetApuntadorDer() != NULL) {
				EliminarNodo(aux->GetApuntadorDer());
			}
		}
	}*/ 

	void EliminarNodo2(Nodo* aux) {
		if (aux == NULL) {
			return;
		}
		else {
			EliminarNodo2(aux->GetApuntadorIzq()); 
			EliminarNodo2(aux->GetApuntadorDer()); 
			delete aux;  
		}
	}


	void show(Nodo *aux, int x, int y, int level) {
		if (aux == NULL) {
			return;
		}
		else {
			gotoxy(x, y); 
			cout << aux->GetIdentificador();
			switch (level) {
			case 0:
				show(aux->GetApuntadorIzq(), x-30, y + 3, level+1);
				show(aux->GetApuntadorDer(), x + 30, y + 3, level + 1);
				break;
			case 1:
				show(aux->GetApuntadorIzq(), x - 12, y + 3, level + 1);
				show(aux->GetApuntadorDer(), x + 12, y + 3, level + 1);
				break;
			case 2:
				show(aux->GetApuntadorIzq(), x - 7, y + 3, level + 1);
				show(aux->GetApuntadorDer(), x + 7, y + 3, level + 1);
				break;
			case 3:
				show(aux->GetApuntadorIzq(), x - 4, y + 3, level + 1);
				show(aux->GetApuntadorDer(), x + 4, y + 3, level + 1);
				break;
			case 4:
				show(aux->GetApuntadorIzq(), x - 2, y + 3, level + 1);
				show(aux->GetApuntadorDer(), x + 2, y + 3, level + 1);
			case 5:
				show(aux->GetApuntadorIzq(), x - 2, y + 3, level + 1);
				show(aux->GetApuntadorDer(), x + 2, y + 3, level + 1);
				break;
			} 
		}
	}

	void gotoxy(int x, int y) {
		HANDLE hcon = GetStdHandle(STD_OUTPUT_HANDLE);
		COORD dwPos;
		dwPos.X = x;
		dwPos.Y = y;
		SetConsoleCursorPosition(hcon, dwPos); 
	}

	void background() {
		int i = 2;
		for (int y = 0; y < 7; y++) {
			gotoxy(0,i);
			cout << "Nivel " << y;
			for (int x = 8; x < 135; x++) {
				gotoxy(x,i);
				cout << "- ";
			}
			i = i + 3;

		}
	}
};
