#include <iostream>
#define MAX_ELEMENTOS 12 // Cantidad de notas
#define MULTIPLO 5 // múltiplo escogido
#define NOTA_INVALIDA -1 // Valor de nota inválida
using namespace std;

void quickSort(int A[],int izq, int der) { 
	int i, j, x , aux; 
	i = izq;
	j = der;
	x = A[(izq + der)/ 2]; 
	
	// Ordenamiento con pivote
	do { 
		while((A[i] < x) && (j <= der))
		{
			i++;
		}
		
		while((x < A[j]) && (j > izq))
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
		quickSort(A, izq, j); 
	
	// Recursión a la derecha
	if( i < der ) 
		quickSort(A, i, der); 
}

/*
void volteaArregloProcesado(int A[]) {
	// Busca máxima posición
	int maxPosicion = 0;
	while (A[maxPosicion] != NOTA_INVALIDA) {
		maxPosicion++;
	}
	
	// Invierte el arreglo
	for (int i = 0; i <= maxPosicion / 2; i++) {
		int temp = A[i];
		A[i] = A[maxPosicion - i];
		A[maxPosicion] = temp;
	}
}
*/

void filtrarNotas(int A[], int multiplo) {	
	// Clonamos arreglo
	int B[MAX_ELEMENTOS];
	for (int i = 0; i < MAX_ELEMENTOS; i++) {
		B[i] = A[i];
	}
	
	// Limpiamos el arreglo original (con -1)
	for (int i = 0; i < MAX_ELEMENTOS; i++) {
		A[i] = NOTA_INVALIDA;
	}
	
	// Filtramos
	int iA = 0;
	for (int iB = 0; iB < MAX_ELEMENTOS; iB++) {
		if ( (iB == 0) || ( (B[iB] != B[iB - 1]) && (B[iB] % multiplo == 0) ) ) {
			A[iA] = B[iB];
			iA++;
		}
	}
	
	/*
	// Invertimos el orden del arreglo procesado
	volteaArregloProcesado(A);
	*/
}

void procesarNotas(int A[], int multiplo) {
	// 1. Primero, ordenamos
	quickSort(A, 0, MAX_ELEMENTOS - 1);
	
	// 2. Remover duplicados
	filtrarNotas(A, multiplo);
}

void imprimirNotasProcesadas(int A[]) {
	int i = 0;
	while ( (i < MAX_ELEMENTOS) && (A[i] != NOTA_INVALIDA) ) {
		cout << A[i] << " ";
		i++;
	}
}

int main()
{	
	int notas[MAX_ELEMENTOS] = {15, 12, 4, 10, 9, 14, 9, 12, 4, 10, 11, 8};	
	procesarNotas(notas, MULTIPLO);
	imprimirNotasProcesadas(notas);

	return 0;
}

