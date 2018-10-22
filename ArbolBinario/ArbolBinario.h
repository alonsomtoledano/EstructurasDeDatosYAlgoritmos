#pragma once

struct NodoArbol {
	char dato;
	NodoArbol *izquierdo, *derecho;
};

struct TArbolBinario {
	NodoArbol *raiz;
};

void inicializa(TArbolBinario *R) {
	R->raiz = NULL;
}

bool vacio(TArbolBinario *R) {
	return (R->raiz == NULL);
}

NodoArbol* insertaNodo(char v, NodoArbol *izquierdo, NodoArbol *derecho) {
	NodoArbol *nodo = new NodoArbol;
	nodo->dato = v;
	nodo->izquierdo = izquierdo;
	nodo->derecho = derecho;
	return nodo;
}

void insertaRaiz(NodoArbol *&R, char v, NodoArbol *izquierdo, NodoArbol *derecho) {
	R = insertaNodo(v, izquierdo, derecho);
}

void insertaHijoIzquierdo(NodoArbol *&R, NodoArbol *izquierdo) {
	R->izquierdo = izquierdo;
}

void insertaHijoDerecho(NodoArbol *&R, NodoArbol *derecho) {
	R->derecho = derecho;
}

void preorder(NodoArbol *R) {
	if (R != NULL) {
		cout << R->dato << " ";
		preorder(R->izquierdo);
		preorder(R->derecho);
	}
}

void inorder(NodoArbol *R) {
	if (R != NULL) {
		inorder(R->izquierdo);
		cout << R->dato << " ";
		inorder(R->derecho);
	}
}

void postorder(NodoArbol *R) {
	if (R != NULL) {
		postorder(R->izquierdo);
		postorder(R->derecho);
		cout << R->dato << " ";
	}
}

void imprimeArbol(struct TArbolBinario *R) {
	cout << "Preorder: ";
	preorder(R->raiz);
	cout << "\n";
	cout << "Inorder: ";
	inorder(R->raiz);
	cout << "\n";
	cout << "Postorder: ";
	postorder(R->raiz);
	cout << "\n";
}

NodoArbol* busca(NodoArbol *R, char v) {
	NodoArbol *nodo = NULL;
	if (R != NULL) {
		if (R->dato == v)
			nodo = R;
		else {
			nodo = busca(R->izquierdo, v);
			if (nodo == NULL)
				nodo = busca(R->derecho, v);
		}
	}
	return nodo;
}

int altura(NodoArbol *R) {
	int total = 0, izquierdo = 0, derecho = 0;
	if (R == NULL)
		total = -1;
	else if (R != NULL) {
		izquierdo = izquierdo + 1 + altura(R->izquierdo);
		derecho = derecho + 1 + altura(R->derecho);
		if (izquierdo > derecho)
			total = izquierdo;
		else
			total = derecho;
	}
	return total;
}

int nodos(NodoArbol *R) {
	int total = 0;
	if (R != NULL)
		total = total + 1 + nodos(R->izquierdo) + nodos(R->derecho);
	return total;
}