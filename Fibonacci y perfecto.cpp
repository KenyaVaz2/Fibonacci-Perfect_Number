#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM 100

// Funciones de Número Perfecto
void generarArreglo(long long int *A, int n);  
int Perfecto(int num, int *ct);
void MostrarPerfectos(long long int *A, int n, int *ct); 

// Funciones de Fibonacci 
void fibonacciIterativo(long long int *a, int n, int *ct); 
int fibonacciRecursivo(int n, int *ct); 
void llenarFibonacciR(long long int *a, int n, int *ct);
void mostrarFibonacci(long long int *a, int n);

void principal() 
{
    FILE *pf = fopen("Datos.csv", "w");
    if (pf == NULL) 
	{
        printf("Error al abrir el archivo\n");
        return; 
    }

    long long int A[TAM] = {0}; 
    int n, ct=0, op, res;  
    int num = 1;

    printf("\t Menu \t"); 
    printf("\n1.- Fibonacci: \n2.Numeros Perfectos:\n");
    scanf("%d", &op);
    
    if (op == 1) //fibonacci 
	{
        printf("\nFuncion Recursiva (1): \nFuncion Iterativa (2): \n"); 
        scanf("%d", &res);
		 
        clock_t start, end;  
        double timeT; 
        
        for(int i = 0; i < TAM; i++)
		{
               
            if(res == 1)
			{
                start = clock();
                llenarFibonacciR(A, num, &ct);
                end = clock();	
                
                timeT = ((double) (end - start)) / CLOCKS_PER_SEC;
            } 
			else if(res == 2) 
			{
                start = clock();
                fibonacciIterativo(A, num, &ct);	
                end = clock();
                
                timeT = ((double) (end - start)) / CLOCKS_PER_SEC;
            }
            //
            printf("A[%d] = %.4f segundos\n", i, timeT);
            
            start = clock();
            mostrarFibonacci(A, num);  
            end = clock();
        
            timeT = ((double) (end - start)) / CLOCKS_PER_SEC;
            
            fprintf(pf, "%d,%d\n", num, ct); //timeT
            fflush(pf);
            num += 5;	
        }
    } else if (op == 2) // numeros perfectos 
	{
        printf("Digita la cantidad de números perfectos que deseas ver: ");
        scanf("%d", &n);

        generarArreglo(A, n);
        MostrarPerfectos(A, n, &ct);
        
        for (int i = 0; i < n; i++)
		{
            fprintf(pf, "%lld,%d\n", A[i], ct);  // Cambiado a %lld
            fflush(pf);
        }
    }

    fclose(pf);
}

int main()
{
    principal();
}

void generarArreglo(long long int *A, int n) //perfecto
{  
    int numero = 2;  
    int count = 0;   
    int ct = 0;      

    while (count < n) 
	{
        if (Perfecto(numero, &ct)) 
		{
            A[count] = numero;  
            count++;  
        }
        numero++;  
    }
}

int Perfecto(int num, int *ct) //a priori y a posteriori
{
	int i; (*ct)++;
    int suma; (*ct)++;
    suma=0; (*ct)++;
    
    (*ct)++;
    for (int i = 1; i < num; i++) 
	{
        (*ct)++;
        if (num % i == 0) 
		{
			(*ct)++;
			(*ct)++;
            suma += i;  
        }
        (*ct)++;
        (*ct)++;
    }
    (*ct)++;
    (*ct)++;
    return suma == num;  
}

void MostrarPerfectos(long long int *A, int n, int *ct) //a posteriori
{  
	int i; (*ct)++;
    printf("Números perfectos: \n"); (*ct)++;
    (*ct)++;
    for (i = 0; i < n; i++) 
	{
		(*ct)++;
		(*ct)++;
        printf("[%lld] ", A[i]);  
        (*ct)++;
    }
    (*ct)++;
    (*ct)++;
    printf("\n");
}

// Funciones de Fibonacci 

void fibonacciIterativo(long long int *a, int num, int *ct) //a priori y a posteriori con contador y con tiempo 
{
    long long int x; (*ct)++;
    long long int y; (*ct)++;
    int i; (*ct)++;
    x=0; (*ct)++;
    y=1; (*ct)++;
    (*ct)++;
    for (i = 0; i < num; i++) 
	{
		(*ct)++;
        if (i == 0) {
			(*ct)++;
			(*ct)++;
            a[i] = 0;  
        } else if (i == 1) 
		{
			(*ct)++;
			(*ct)++;
            a[i] = 1;  
        } else {
            a[i] = x + y;  (*ct)++;
            x = y;   (*ct)++;
            y = a[i];  (*ct)++;
        }
        (*ct)++;
    	(*ct)++;
    }
    (*ct)++;
}

int fibonacciRecursivo(int num, int *ct) //a posteriori con contador y con tiempo
{
   
    if (num == 0)
	{
		(*ct)++;
		(*ct)++;
		return 0; 	
	} 
	(*ct)++;
    if (num == 1)
	{
		(*ct)++;
		(*ct)++;
		return 1;	
	}
	(*ct)++;
	(*ct)++;  
    return fibonacciRecursivo(num - 1, ct) + fibonacciRecursivo(num - 2, ct);
}

void llenarFibonacciR(long long int *a, int num, int *ct) 
{
    for (int i = 0; i < num; i++) 
	{
        a[i] = fibonacciRecursivo(i, ct);
    }
}

void mostrarFibonacci(long long int *a, int num) 
{
    for (int i = 0; i < num; i++) 
	{
        printf("[%lld] ", a[i]);   
    }
    printf("\n");
}

