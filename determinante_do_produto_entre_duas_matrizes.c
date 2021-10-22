#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>


#define Ma 6 //Name
#define NaMb 14 //Name+last name
#define Nb 8 //last name

//Na and Mb are equal.

int CMA (int A[Ma][NaMb]);
int CMB (int B[NaMb][Nb]);
int CMC (int A[Ma][NaMb], int B[NaMb][Nb], int C[Ma][Nb]);
double DetC(int C[Ma][Nb], int orderC);
int cofactorC(int C[][Nb], int orderC, int row, int column);

int main (){
	
	
	srand((unsigned)time(NULL)); //to get random numbers
	
	int matrixA[Ma][NaMb], matrixB[NaMb][Nb], matrixC[Ma][Nb];
	int orderC=Nb;
	
	CMA(matrixA); // matrix reference A
	printf("\n\n");
	CMB(matrixB); // matrix reference B
	printf("\n\n");
	CMC(matrixA, matrixB, matrixC);	// matrix reference C
	printf("\n\n"); 
	printf("The determinant value is: %.0lf", DetC(matrixC, orderC));
	
	
	printf("\n\n");
	system("pause");
	return 0;
}

int CMA (int A[Ma][NaMb]){ // matrix row = name ; column = name + last name
	
	int i,j;
	
	for(i=0;i<Ma;i++){
		for(j=0;j<NaMb;j++){
			A[i][j]=rand()%10; // random number for row and column 
		}
	}
	printf("\n\n");  // print matrix
	
	for(i=0;i<Ma;i++){
		for(j=0;j<NaMb;j++){
			printf("%d ", A[i][j]);
			}
			printf("\n");
	}
	
}

int CMB (int B[NaMb][Nb]){  // matrix row = name + last name ; column = last name 
	
	int i,j;
	
	for(i=0;i<NaMb;i++){
		for(j=0;j<Nb;j++){
			B[i][j]=rand()%10;
		}
	}
	printf("\n\n");  // print matrix
	for(i=0;i<NaMb;i++){
		for(j=0;j<Nb;j++){
			printf("%d ", B[i][j]);
			}
			printf("\n");
	}
	
}

int CMC (int A[Ma][NaMb], int B[NaMb][Nb], int C[Ma][Nb]){

	
	int i, j, mult, aux=0;
	
	for(i=0;i<Ma;i++){   
		for(j=0;j<Nb;j++){
			C[i][j]=0;
			for(mult=0;mult<NaMb;mult++){
				aux+= A[i][mult]*B[mult][j];  // matrix multplication
			}
			C[i][j]=aux;
			aux=0;
		}
	}
	for(i=0;i<Ma;i++){   // print multiplication
		for(j=0;j<Nb;j++){
			printf("%d\t", C[i][j]);
		}
		printf("\n");  // print a squared matrix
	}
	
}

double DetC(int C[Ma][Nb], int orderC){  // matrix C determinant 
	int det = 0.0, j;
   
   if (orderC == 1) {
      det = C[0][0];
   } else {
      for (j = 0; j < orderC; j++) {
         det = det + C[0][j] * cofactorC(C, orderC, 0, j);
      }
   }
   
   return det;
}

int cofactorC(int C[][Nb], int orderC, int row, int column){ // determinant cofactor 
   int submatrix[Ma][Nb];
   int n = orderC - 1;
   int i, j;
   
   int x = 0;
   int y = 0;
   for (i = 0; i < orderC; i++) {
      for (j = 0; j < orderC; j++) {
         if (i != row && j != column) {
            submatrix[x][y] = C[i][j];
            y++;
            if (y >= n) {
               x++;
               y = 0;
            }
         }
      }
   }
   
   return pow(-1.0, row + column) * DetC(submatrix, n);
}