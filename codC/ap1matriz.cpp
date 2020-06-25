#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <iostream>

#define l 4
#define c 4

int main(){
	
    int i,j,menor,soma=0,aux=0,matriz[l][c]; 
    char op;
	

	
	do{	
		system("cls");
		fflush(stdin);
		printf("\n 1- Menor elemento");
		printf("\n 2- Soma dos elementos");
		printf("\n 3- Troca de elementos");
		printf("\n 4- Sair");
		printf("\n\n Opcao: ");
		op=getche();
		op=toupper(op);
		
		
		switch (op){
			case '1': system("cls");
				for(i=0;i<l;i++){			
					for(j=0;j<c;j++){
					
					printf("\nDigite um numero: ", i,j);
					scanf("%d", &matriz[i][j]);
					if(i==0 && j==0){
						menor=matriz[0][0];
					}
					if(matriz[i][j]<menor){
            				menor=matriz[i][j];
					}
				}
				}
				printf("\n\nO menor numero e: [%d]",menor);
				break;
			
			case '2': system("cls");
				for(i=0;i<l;i++){
					for (j=0;j<c;j++){
					
					printf("\nDigite os valores para matriz[%d][%d]\n", i, j);
					scanf("%d", &matriz[i][j]);
				}
			}
				
				if(i==j){
				soma = soma + matriz[i][j];
				}
				printf("\n\n Soma = %i", soma); 
				break;
			
			case '3': system("cls");
				for(j=0;j<c;j++){
					
        				aux = matriz[1][c];
        				matriz[1][c] = matriz[j][c];
       				matriz[j][c] = aux;
					      			
				}
				printf("\n", j);
				break;
			
			case '4': system("cls");
 				
 				printf("\nEncerrando...");
 				break;
			
			default : printf("\n Opcao invalida");
		}			
			
		return 0;
	}	
	while (op!= '4');
}


