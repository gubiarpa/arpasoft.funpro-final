#include <iostream>
#define largo 100
using namespace std;

struct TAlumno {
	int nota;
	string nombre;
};

void leeNotas(int cant, TAlumno arrNotas[]) {
	for (int i = 0; i < cant; i++) {
		cout << "Alumno " << (i + 1) << endl;
		cout << "Nombre: "; cin >> arrNotas[i].nombre;
		cout << "Nota: "; cin >> arrNotas[i].nota;
		cout << endl;
	}	
	cout << "*********************" << endl;
}

void quickSort(TAlumno A[],int izq, int der) { 
	int i, j, x , aux; 
	string auxNombre;
	i = izq;
	j = der;
	x = A[(izq + der)/ 2].nota; 
	
	// Ordenamiento con pivote
	do { 
		while((A[i].nota > x) && (j <= der))
		{
			i++;
		}
		
		while((x > A[j].nota) && (j > izq))
		{
			j--;
		} 
		
		if (i <= j)
		{ 
			// Nombre
			auxNombre = A[i].nombre;
			A[i].nombre = A[j].nombre;
			A[j].nombre = auxNombre; 
			
			// Nota
			aux = A[i].nota;
			A[i].nota = A[j].nota;
			A[j].nota = aux; 
			
			i++; j--; 
		}
		
	} while(i <= j); 
	
	// Recursión a la izquierda
	if( izq < j ) 
		quickSort( A, izq, j ); 
	
	// Recursión a la derecha
	if( i < der ) 
		quickSort( A, i, der ); 
}

void imprimirAlumnos(TAlumno arrAlumnos[], int n) {
	for (int i = 0; i < n; i++) {
		cout << "Alumno " << (i + 1) << endl;
		cout << "Nombre: " << arrAlumnos[i].nombre << endl;
		cout << "Nota: " << arrAlumnos[i].nota << endl;
		cout << endl;
	}
}

int busquedaBinaria(TAlumno arrAlumnos[], int l, int r, string alumnoBuscar)
{
	if (r >= l) {
		int mid = l + (r - l) / 2;
		
		if (arrAlumnos[mid].nombre == alumnoBuscar)
			return mid;
		
		if (arrAlumnos[mid].nombre > alumnoBuscar)
			return busquedaBinaria(arrAlumnos, l, mid - 1, alumnoBuscar);
		
		return busquedaBinaria(arrAlumnos, mid + 1, r, alumnoBuscar);
	}
	
	return -1; // Si no se encuentra
}

int main() {	
	// Lectura y ordenamiento
	TAlumno arrAlumnos[largo];
	int n;
	do {
		cout << "Cantidad de elementos: "; cin >> n;
		cout << endl;
		if (n <= 0 || n > largo)
			cout << "Debe ingresar un valor > a 0 y < a " << largo << endl;
	} while (n <= 0 || n > largo);
	leeNotas(n, arrAlumnos);
	quickSort(arrAlumnos, 0, n - 1);
	imprimirAlumnos(arrAlumnos, n);
	
	// Consulta
	string alumnoBuscar;
	
	return 0;
}

