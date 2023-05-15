#include <iostream>
using namespace std;

class Nodo {
private:
	int identificador;
public:
	Nodo* apuntadorIzq;
	Nodo* apuntadorDer;

	Nodo* Crear(int n) {
		Nodo* nuevo = new Nodo();
		nuevo->identificador = n;
		nuevo->apuntadorIzq = NULL;
		nuevo->apuntadorDer = NULL;
		return nuevo;
	}

	int GetIdentificador() {
		return identificador;
	}

	Nodo* GetApuntadorIzq() {
		return apuntadorIzq;
	}

	Nodo* GetApuntadorDer() {
		return apuntadorDer;
	}

	void setApuntadorIzq(Nodo* next) { //Conectar
		apuntadorIzq = next;
	}

	void setApuntadorDer(Nodo* next) {
		apuntadorDer = next;
	}
};

