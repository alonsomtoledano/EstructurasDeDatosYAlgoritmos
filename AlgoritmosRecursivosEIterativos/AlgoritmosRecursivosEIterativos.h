#pragma once

//Paridad de un numero n mediante restas

bool numParR(int n) {
	bool par = true;
	if (n == 0)
		par = true;
	else if (n == -1)
		par = false;
	else
		par = numParR(n - 2);
	return par;
}

bool numParI(int n) {
	bool par = true;
	while (n > 0)
		n = n - 2;
	if (n == 0)
		par = true;
	if (n == -1)
		par = false;
	return par;
}

//Paridad de un numero utilizando recursion indirecta

bool esParR(int n) {
	bool par = true;
	if (n == 0)
		par = true;
	else if (n == 1)
		par = esImparR(n);
	else
		par = esParR(n - 2);
	return par;
}

bool esImparR(int n) {
	bool par = true;
	if (n == 0)
		par = esParR(n);
	else if (n == 1)
		par = false;
	else
		par = esImparR(n - 2);
	return par;
}

//Producto de dos numeros positivos n y m mediante sumas

int productoR(int n, int m) {
	int resultado;
	if (n == 0 || m == 0)
		resultado = 0;
	else if (n == 1)
		resultado = m;
	else if (m == 1)
		resultado = n;
	else
		resultado = n + productoR(n, m - 1);
	return resultado;
}

int productoI(int n, int m) {
	int resultado = 0;
	for (int i = 0; i < m; i++)
		resultado = resultado + n;
	return resultado;
}

//Potencia de dos numeros calculada con productos

int potencia1R(int x, int n) {
	int resultado;
	if (n == 0)
		resultado = 1;
	else if (n == 1)
		resultado = x;
	else
		resultado = x * potencia1R(x, n - 1);
	return resultado;
}

int potencia2R(int x, int n) {
	int resultado;
	if (n == 0)
		resultado = 1;
	else if (n == 1)
		resultado = x;
	else if (n % 2 == 0)
		resultado = potencia2R(x, n / 2) * potencia2R(x, n / 2);
	else if (n % 2 == 1)
		resultado = x * potencia2R(x, n / 2) * potencia2R(x, n / 2);
	return resultado;
}

int potenciaI(int x, int n) {
	int resultado = 1;
	for (int i = 0; i < n; i++)
		resultado = resultado * x;
	return resultado;
}

//Factorial de un numero n mayor o igual que cero

int factorialR(int n) {
	int resultado;
	if (n == 0 || n == 1)
		resultado = 1;
	else
		resultado = n * factorialR(n - 1);
	return resultado;
}

int factorialI(int n) {
	int resultado = 1;
	int i = n;
	do {
		resultado = resultado * i;
		i--;
	} while (i > 0);
	if (n == 0)
		resultado = 1;
	return resultado;
}

//Sucesion de Fibonacci

int fibonacciR(int n) {
	int resultado;
	if (n < 2)
		resultado = n;
	else
		resultado = fibonacciR(n - 2) + fibonacciR(n - 1);
	return resultado;
}

int fibonacciI(int n) {
	int resultado;
	int * array = new int[n];
	array[0] = 0;
	array[1] = 1;
	for (int i = 2; i < n + 1; i++)
		array[i] = array[i - 2] + array[i - 1];
	resultado = array[n];
	return resultado;
}

//Cociente y resto de la division de dos numeros enteros

int cocienteR(int dividendo, int divisor) {
	int resultado;
	if (dividendo < divisor)
		resultado = 0;
	else
		resultado = 1 + cocienteR(dividendo - divisor, divisor);
	return resultado;
}

int cocienteI(int dividendo, int divisor) {
	int resultado = 0;
	if (dividendo < divisor)
		resultado = 0;
	while (dividendo >= divisor) {
		dividendo = dividendo - divisor;
		resultado++;
	}
	return resultado;
}

int restoR(int dividendo, int divisor) {
	int resultado;
	if (dividendo < divisor)
		resultado = dividendo;
	else
		resultado = restoR(dividendo - divisor, divisor);
	return resultado;
}

int restoI(int dividendo, int divisor) {
	int resultado;
	while (dividendo > divisor)
		dividendo = dividendo - divisor;
	if (dividendo < divisor)
		resultado = dividendo;
	else if (dividendo = divisor)
		resultado = 0;
	return resultado;
}

//Determinar si un numero entero es divisible por otro

bool multiploR(int dividendo, int divisor) {
	bool mult = true;
	if (dividendo == 0)
		mult = true;
	else if (dividendo < divisor)
		mult = false;
	else
		mult = multiploR(dividendo - divisor, divisor);
	return mult;
}

bool multiploI(int dividendo, int divisor) {
	bool mult = true;
	while (dividendo > divisor)
		dividendo = dividendo - divisor;
	if (dividendo == 0)
		mult = true;
	else if (dividendo < divisor)
		mult = false;
	return mult;
}

//Sumatoria de todos los numeros desde 1 hasta n

int sumatoriaR(int n) {
	int resultado;
	if (n == 0)
		resultado = 0;
	else
		resultado = n + sumatoriaR(n - 1);
	return resultado;
}

int sumatoriaI(int n) {
	int resultado = 0;
	int i = 1;
	while (i < n + 1) {
		resultado = resultado + i;
		i++;
	}
	return resultado;
}

//Sumatoria de los numeros pares desde 1 hasta n

int sumatoriaParR(int n) {
	int resultado;
	if (n < 2)
		resultado = 0;
	else if (n % 2 == 0)
		resultado = n + sumatoriaParR(n - 2);
	else
		resultado = n - 1 + sumatoriaParR(n - 2);
	return resultado;
}

int sumatoriaParI(int n) {
	int resultado = 0;
	int i = 2;
	if (n < 2)
		resultado = 0;
	else if (n % 2 == 0)
		while (i < n + 1) {
			resultado = resultado + i;
			i = i + 2;
		}
	return resultado;
}

//Sumatoria de los numeros impares desde 1 hasta n

int sumatoriaImparR(int n) {
	int resultado;
	if (n == 0 || n == 1)
		resultado = n;
	else if (n % 2 == 0)
		resultado = n - 1 + sumatoriaImparR(n - 2);
	else
		resultado = n + sumatoriaImparR(n - 2);
	return resultado;
}

int sumatoriaImparI(int n) {
	int resultado = 0;
	if (n == 0 || n == 1)
		resultado = n;
	else if (n % 2 != 0) {
		int i = 1;
		while (i < n + 1) {
			resultado = resultado + i;
			i = i + 2;
		}
	}
	else {
		int i = 2;
		while (i < n + 1) {
			resultado = resultado + i;
			i = i + 2;
		}
	}
	return resultado;
}

//Valor minimo de un vector

void minimoR(int v[], int n, int &min) {
	if (n == 1)
		min = v[0];
	else {
		minimoR(v, n - 1, min);
		if (min > v[n - 1])
			min = v[n - 1];
	}
}

void minimoI(int v[], int n, int &min) {
	min = v[0];
	if (n == 1)
		min = v[0];
	for (int i = 1; i < n; i++) {
		if (min > v[i])
			min = v[i];
	}
}

//Valor maximo de un vector

void maximoR(int v[], int n, int &max) {
	if (n == 1)
		max = v[0];
	else {
		maximoR(v, n - 1, max);
		if (max < v[n - 1])
			max = v[n - 1];
	}
}

void maximoI(int v[], int n, int &max) {
	max = v[0];
	if (n == 1)
		max = v[0];
	for (int i = 1; i < n; i++) {
		if (max < v[i])
			max = v[i];
	}
}

//Sumatoria de un vector

int sumatoriaR(int v[], int n) {
	int resultado = 0;
	if (n == 1)
		resultado = v[0];
	else
		resultado = v[n - 1], sumatoriaR(v, n - 1);
	return resultado;
}

int sumatoriaI(int v[], int n) {
	int resultado = 0;
	if (n == 1)
		resultado = v[0];
	else
		for (int i = 0; i < n; i++)
			resultado = resultado + v[i];
	return resultado;
}

//Sumatoria de los numeros pares de un vector

int sumatoriaParR(int v[], int n) {
	int resultado = 0;
	if (n == 1) {
		if (v[n - 1] % 2 == 0)
			resultado = v[0];
		else
			resultado = 0;
	}
	else {
		if (v[n - 1] % 2 == 0)
			resultado = sumatoriaParR(v, n - 1) + v[n - 1];
		else
			resultado = sumatoriaParR(v, n - 1);
	}
	return resultado;
}

int sumatoriaParI(int v[], int n) {
	int resultado = 0;
	if (n == 1) {
		if (v[0] % 2 == 0)
			resultado = v[0];
		else
			resultado = 0;
	}
	else
		for (int i = 0; i < n; i++)
			if (v[i] % 2 == 0)
				resultado = resultado + v[i];
	return resultado;
}

//Sumatoria de los numeros impares de un vector

int sumatoriaImparR(int v[], int n) {
	int resultado = 0;
	if (n == 1) {
		if (v[n] % 2 == 1)
			resultado = v[0];
		else
			resultado = 0;
	}
	else {
		if (v[n] % 2 == 1)
			resultado = v[n - 1] + sumatoriaImparR(v, n - 1);
		else
			resultado = sumatoriaImparR(v, n - 1);
	}
	return resultado;
}

int sumatoriaImparI(int v[], int n) {
	int resultado = 0;
	if (n == 1) {
		if (v[0] % 2 == 1)
			resultado = v[0];
		else
			resultado = 0;
	}
	else
		for (int i = 0; i < n; i++)
			if (v[i] % 2 == 1)
				resultado = resultado + v[i];
	return resultado;
}

//Promedio de los valores de un vector

double promedioR(int v[], int n, int total) {
	float resultado = 0;
	if (n < total) {
		if (n == 0)
			resultado = 0;
		else
			resultado = v[n - 1] + promedioR(v, n - 1, total);
	}
	else
		resultado = (v[n - 1] + promedioR(v, n - 1, total)) / total;
	return resultado;
}

double promedioI(int v[], int n, int total) {
	double resultado = 0, suma = 0;
	if (n == 1)
		suma = v[0];
	else
		for (int i = 0; i < n; i++)
			suma = suma + v[i];
	return resultado = suma / total;
}

//Existencia de un numero en un vector

bool existeR(int v[], int n, int valor) {
	bool esta = true;
	if (n != 0) {
		if (valor == v[n])
			esta = true;
		else if (valor != v[n])
			esta = existeI(v, n - 1, valor);
		else
			esta = false;
	}
	else
		esta = false;
	return esta;
}

bool existeI(int v[], int n, int valor) {
	bool esta = false;
	for (int i = 0; i < n; i++) {
		if (valor == v[i]) {
			esta = true;
			break;
		}
	}
	return esta;
}
