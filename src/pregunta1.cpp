#include <iostream>
#define MAX_ELEMENTOS 12 // Cantidad de notas
#define NOTA_INVALIDA -1 // Valor de nota inválida
using namespace std;

void ordenarNotas(int A[],int izq, int der) { 
	int i, j, x , aux; 
	i = izq;
	j = der;
	x = A[(izq + der)/ 2]; 
	
	// Ordenamiento con pivote
	do { 
		while((A[i] > x) && (j <= der))
		{
			i++;
		}
		
		while((x > A[j]) && (j > izq))
		{
			j--;
		} 
		
		if (i <= j)
		{ 
			aux = A[i]; A[i] = A[j]; A[j] = aux; 
			i++; j--; 
		}
	} while(i <= j); 
	
	// Recursión a la izquierda
	if( izq < j ) 
		ordenarNotas(A, izq, j); 
	
	// Recursión a la derecha
	if( i < der ) 
		ordenarNotas(A, i, der); 
}



void filtrarNotas(int A[], int multiplo) {	
	// Clonamos arreglo y limpiamos el original
	int B[MAX_ELEMENTOS];
	for (int i = 0; i < MAX_ELEMENTOS; i++) {
		B[i] = A[i];
		A[i] = NOTA_INVALIDA;
	}
	
	// Filtramos
	int iA = 0;
	for (int iB = 0; iB < MAX_ELEMENTOS; iB++) {
		if (
			( (iB == 0) || (B[iB] != B[iB - 1]) ) &&
			( B[iB] % multiplo == 0 )
		) {
			A[iA++] = B[iB];
		}
	}
}

void procesarNotas(int A[], int multiplo) {
	// 1. Primero, ordenamos
	ordenarNotas(A, 0, MAX_ELEMENTOS - 1);
	
	// 2. Remover duplicados
	filtrarNotas(A, multiplo);
}

void imprimirNotasProcesadas(int A[]) {
	int i = 0;
	while ( (i < MAX_ELEMENTOS) && (A[i] != NOTA_INVALIDA) ) {
		cout << A[i++] << " ";
	}
}

int main()
{	
	int multiplo;
	int notas[MAX_ELEMENTOS] = {2, 15, 12, 10, 9, 14, 9, 12, 4, 10, 11, 8};	
	cout << "Múltiplo: "; cin >> multiplo;
	procesarNotas(notas, multiplo);
	imprimirNotasProcesadas(notas);

	return 0;
}

