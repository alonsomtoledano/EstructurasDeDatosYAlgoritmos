#pragma once

struct NodoArbol {
	int dato;
	NodoArbol *izquierdo, *derecho;
};

struct TArbolBinarioBusqueda {
	NodoArbol *raiz;
};

void inicializa(TArbolBinarioBusqueda *R) {
	R->raiz = NULL;
}

bool vacio(TArbolBinarioBusqueda *R) {
	return (R->raiz == NULL);
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

void imprimeArbol(struct TArbolBinarioBusqueda *R) {
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

NodoArbol* insertaNodo(int v) {
	NodoArbol *nodo = new NodoArbol;
	nodo->dato = v;
	nodo->izquierdo = NULL;
	nodo->derecho = NULL;
	return nodo;
}

void inserta(NodoArbol *&R, int v) {
	if (R == NULL)
		R = insertaNodo(v);
	else {
		if (v < R->dato)
			inserta(R->izquierdo, v);
		else if (v > R->dato)
			inserta(R->derecho, v);
	}
}

NodoArbol* busca(NodoArbol *R, int v) {
	NodoArbol *p = NULL;
	if (R!=NULL) {
		if (R->dato == v) {
			p = R;
		}
		else {
			p = busca(R->izquierdo, v);
			if (p == NULL)
				p = busca(R->derecho, v);
		}
	}
	return p;
}

NodoArbol* minimoRecursivo(NodoArbol *R) {
	NodoArbol *p = new NodoArbol;
	if (R == NULL)
		p = NULL;
	else {
		p = minimoRecursivo(R->izquierdo);
		if (R->izquierdo == NULL)
			p = R;
	}
	return p;
}

NodoArbol* maximoRecursivo(NodoArbol *R) {
	NodoArbol *p;
	if (R == NULL)
		p = NULL;
	else {
		p = maximoRecursivo(R->derecho);
		if (R->derecho == NULL)
			p = R;
	}
	return p;
}

NodoArbol* minimoIterativo(NodoArbol *R) {
	NodoArbol *p = R;
	if (R == NULL)
		p = NULL;
	else {
		while (R->izquierdo != NULL)
			R = R->izquierdo;
		p = R;
	}
	return p;
}

NodoArbol* maximoIterativo(NodoArbol *R) {
	NodoArbol *p = R;
	if (R == NULL)
		p = NULL;
	else {
		while (R->derecho != NULL)
			R = R->derecho;
		p = R;
	}
	return p;
}

int eliminaMinimo(NodoArbol *&R) {
	int minimo;
	if (R != NULL) {
		if (R->izquierdo == NULL) {
			minimo = R->dato;
			R = R->derecho;
		}
		else
			minimo = eliminaMinimo(R->izquierdo);
	}
	else
		minimo = 0;
	return minimo;
}

void elimina(NodoArbol *&R, int v) {
	if (R != NULL) {
		if (v < R->dato)
			elimina(R->izquierdo, v);
		else {
			if (v > R->dato)
				elimina(R->derecho, v);
			else {
				if (R->izquierdo == NULL && R->derecho == NULL) {
					NodoArbol *p = R;
					R = NULL;
					delete(p);
				}
				else {
					if (R->izquierdo == NULL)
						R = R->derecho;
					else {
						if (R->derecho == NULL)
							R = R->izquierdo;
						else
							R->dato = eliminaMinimo(R->derecho);
					}
				}
			}
		}
	}
}

int altura(NodoArbol *R) {
	int alturaArbol, alturaDer, alturaIzq;
	if (R == NULL)
		alturaArbol = -1;
	else {
		alturaDer = altura(R->derecho);
		alturaIzq = altura(R->izquierdo);
		if (alturaDer > alturaIzq)
			alturaArbol = 1 + alturaDer;
		else
			alturaArbol = 1 + alturaIzq;
	}
	return alturaArbol;
}

int nodos(NodoArbol *R) {
	int cont;
	if (R == NULL)
		cont = 0;
	else
		cont = nodos(R->izquierdo) + nodos(R->derecho) + 1;
	return cont;
}