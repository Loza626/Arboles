#include <iostream>
using namespace std;

struct  Nodo
{
	int dato;
	struct Nodo* izquierdo;
	struct Nodo* derecho;
	struct Nodo* padre;
};

struct  Nodo* Crear(int n, struct Nodo* Padre) {
	struct Nodo* nuevoNodo = new Nodo();
	nuevoNodo->dato = n;
	nuevoNodo->izquierdo = NULL;
	nuevoNodo->derecho = NULL;
	nuevoNodo->padre = Padre;
	return nuevoNodo;
}
struct Nodo* arbol = NULL;

void Insertar(struct  Nodo*& arbol, int n, struct Nodo* padre) {
	if (arbol == NULL) {
		struct  Nodo* nuevoNodo = Crear(n, padre);
		arbol = nuevoNodo;
	}
	else {
		int raiz = arbol->dato;
		if (n != raiz) {
			if (n < raiz) {
				Insertar(arbol->izquierdo, n, arbol);
			}
			else {
				Insertar(arbol->derecho, n, arbol);
			}
		}
		else {
			cout << "No pueden ir arboles con raices iguales";
		}
	}
}
void Inorden(struct  Nodo* arbol) {
	if (arbol == NULL) {
		return;
	}
	else {
		Inorden(arbol->izquierdo);
		cout << " - " << arbol->dato;
		Inorden(arbol->derecho);
	}
}
void Preorden(struct  Nodo* arbol) {
	if (arbol == NULL) {
		return;
	}
	else {
		cout << " - " << arbol->dato;
		Preorden(arbol->izquierdo);
		Preorden(arbol->derecho);
	}
}
void Postorden(struct  Nodo* arbol) {
	if (arbol == NULL) {
		return;
	}
	else {
		Postorden(arbol->izquierdo);
		Postorden(arbol->derecho);
		cout << " - " << arbol->dato;
	}
}
bool Buscar(struct Nodo* arbol, int dato) {
	if (arbol == NULL) {
		return false;
	}
	else if (arbol->dato == dato)
	{
		return true;
	}
	else if (arbol->dato > dato) {
		Buscar(arbol->izquierdo, dato);
	}
	else {
		Buscar(arbol->derecho, dato);
	}
}
void DestroyNode(struct Nodo* nodo) {
	nodo->izquierdo = NULL;
	nodo->derecho = NULL;
	delete nodo;
}
void ReplaceNodo(struct Nodo* arbol, struct Nodo* nuevonNodo) {

	if (arbol->padre) {
		if (arbol->dato == arbol->padre->izquierdo->dato) {
			arbol->padre->izquierdo = nuevonNodo;
		}
		else if (arbol->dato == arbol->padre->derecho->dato)
		{
			arbol->padre->derecho = nuevonNodo;
		}
	}

	if (nuevonNodo) {
		nuevonNodo->padre = arbol->padre;
	}
}
struct Nodo* NodoMenor(struct Nodo* arbol) {
	if (arbol == NULL) {
		return NULL;
	}
	if (arbol->izquierdo) {
		return NodoMenor(arbol->izquierdo);
	}
	else {
		return arbol;
	}
}
void DeleteNodo(struct Nodo* nodo) {
	if (nodo->izquierdo && nodo->derecho) {
		struct Nodo* nodoMenor = NodoMenor(arbol->derecho);
		arbol->dato = nodoMenor->dato;
		DeleteNodo(nodoMenor);;
	}
	else if (nodo->izquierdo) {
		ReplaceNodo(nodo, nodo->izquierdo);
		DestroyNode(nodo);
	}
	else if (nodo->derecho) {
		ReplaceNodo(nodo, nodo->derecho);
		DestroyNode(nodo);
	}
	else {
		ReplaceNodo(nodo, NULL);
		DestroyNode(nodo);
	}
}
void DeleteSearchNode(struct Nodo* arbol, int dato) {
	if (arbol == NULL) {
		return;
	}
	else if (dato < arbol->dato) {
		DeleteSearchNode(arbol->izquierdo, dato);
	}
	else if (dato > arbol->dato) {
		DeleteSearchNode(arbol->derecho, dato);
	}
	else {
		DeleteNodo(arbol);
	}
}

int main()
{
	int dato;
	for (int i = 0; i < 5; i++)
	{
		cout << "Ingrese el " << i + 1 << " dato: "; cin >> dato;
		Insertar(arbol, dato, NULL);
	}

	cout << "Inorden : "; Inorden(arbol); cout << endl;
	cout << "Postorden : "; Postorden(arbol); cout << endl;
	cout << "Preorden : "; Preorden(arbol); cout << endl;

	DeleteSearchNode(arbol, 5);
	cout << "Preorden : "; Preorden(arbol); cout << endl;
}


