#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <iostream>
#include<locale.h>


#define max 30
#define tam 3
struct reg{
	int ativo;
	char nome[max];
	char cpf[max];
	char tel[max];
	char sexo[max];
	char ender[max];
	char email[max];
	char profissao[max];
};


main (){
setlocale(LC_ALL,"portuguese");
	struct reg agenda[tam];
	
	char menu, buscanome[max];
	char vazio[max]={'0'};
	int i, cont=0, cont1=1;
	
	for(i=0;i<tam;i++)
	agenda[i].ativo=0;	
	
	
	do{
		
		system("cls");
		fflush(stdin);
		printf("\n--------------- MENU PRINCIPAL ---------------");
		printf("\n A - Inserir");
		printf("\n B - Visualizar");
		printf("\n C - Alterar");
		printf("\n D - Excluir");
		printf("\n E - Sair");
		printf("\n\n Opção: ");
		
		
		switch (menu)
		{
			case 'A': system("cls");
				printf("\n Inserir");
			 	for(i=0;i<tam;i++)
					if(agenda[i].ativo==0 &&i<tam){
	   	  	    	
			   	  	    	printf("\n Ativo: %i",agenda[i].ativo);
			   	  	    	
						printf("\n Nome:  ");
			   	  	     	gets(agenda[i].nome);
			   	  	      fflush(stdin);
			   	  	      
			   	  	      printf("\n CPF: ");
			   	  		gets(agenda[i].cpf);
			   	  		fflush(stdin);
			   	  		
			   	  		printf("\n Telefone: ");
			   	  		gets(agenda[i].tel);
			   	  		fflush(stdin);
			   	  		
			   	  		printf("\n Sexo: ");
			   	  		gets(agenda[i].sexo);
			   	  		fflush(stdin);
			   	  		
			   	  	    	printf("\n Endereço: ");
			   	  		gets(agenda[i].ender);
			   	  		fflush(stdin);
			   	  		
			   	  		printf("\n Email: ");
			   	  		gets(agenda[i].email);
			   	  		fflush(stdin);
			   	  		
			   	  		printf("\n Profissão: ");
			   	  		gets(agenda[i].profissao);
			   	  		fflush(stdin);
			   	  		agenda[i].ativo=1;
						printf("\n Pressione uma tecla para voltar ao menu");
						getch();
						break;
					};
					 if(i==tam)
					
						cont++;
					
						printf("\n AGENDA CHEIA!");
			
			case 'B': system("cls");
			 	printf("\n Visualizar");
			           printf("\n\tDigite o Nome que deseja buscar:");
			           fflush(stdin);
			           gets(buscanome);
 
         			for(i=0;i<tam ;i++){
			     		if(strcmp (buscanome,agenda[i].nome)==0){
			              printf("\n Registro encontrado.\n");
			              printf("\n Ativo: %i",agenda[i].ativo);
	                 		  printf("\n Nome: %s", agenda[i].nome);
	                 		  printf("\n CPF: %s", agenda[i].cpf);
	                 		  printf("\n Telefone: %s", agenda[i].tel);
	                 		  printf("\n Sexo: %s", agenda[i].sexo);
	                 		  printf("\n Endereço: %s", agenda[i].ender);
	                 		  printf("\n Email: %s", agenda[i].email);
		   	              printf("\n Profissão: %s",agenda[i].profissao);
		   	              
			      }        i=tam;
                  }
              
              	printf("\n Registro não encontrado");
	   	
                	   
				printf("\n Pressione uma tecla para voltar ao menu");
			 	getch();
			 	break;
		     
		      case 'C': system("cls");
			 	printf("\n Alterar");
			 	printf("\n Digite o Nome que deseja Alterar:");
      			fflush(stdin);
      			gets(buscanome);

   				for(i=0;i<tam ;i++){
           				if(agenda[i].ativo==0){
  	  	  				printf("\nRegistro não encontrado ");
  	  	  		
				if(strcmp (buscanome,agenda[i].nome)==0){
	
	             	printf("\n Registro encontrado.\n");
			              printf("\n Ativo: %i",agenda[i].ativo);
	                 		  printf("\n Nome: %s", agenda[i].nome);
	                 		  printf("\n CPF: %s", agenda[i].cpf);
	                 		  printf("\n Telefone: %s", agenda[i].tel);
	                 		  printf("\n Sexo: %s", agenda[i].sexo);
	                 		  printf("\n Endereço: %s", agenda[i].ender);
	                 		  printf("\n Email: %s", agenda[i].email);
		   	              printf("\n Profissão: %s",agenda[i].profissao);
	   
		            printf("\n Selecione o campo que deseja alterar\n");
		            printf("\nAtivo: ");
		            scanf("%i",&agenda[i].ativo);		
	  	   }	     i=tam;
	    	 }
	    	}		printf("\n Pressione uma tecla para voltar ao menu");
			 	getch();
				break;
			
			case 'D': system("cls");
			 	printf("\n Excluir");
				printf("\n Digite o Nome que deseja excluir: ");
			      fflush(stdin);
			      gets(buscanome);
	
	   			for(i=0;i<tam ;i++){
	           			if(agenda[i].ativo==0){
	  	  	  			printf("\n Registro não encontrado ");
	  	  	     	
					   
				 }	i=tam;
		    	}
			
			
             
			 
			  if(strcmp (buscanome,agenda[i].nome)==0){
	
	             printf("\n Ativo: %i",agenda[i].ativo);
	                 		  printf("\n Nome: %s", agenda[i].nome);
	                 		  printf("\n CPF: %s", agenda[i].cpf);
	                 		  printf("\n Telefone: %s", agenda[i].tel);
	                 		  printf("\n Sexo: %s", agenda[i].sexo);
	                 		  printf("\n Endereço: %s", agenda[i].ender);
	                 		  printf("\n Email: %s", agenda[i].email);
		   	              printf("\n Profissão: %s",agenda[i].profissao);
	   
	            printf("\n Selecione com o numero zero o campo ativo para excluir o registro\n");
	            printf("\n Ativo: ");
	            scanf("%i",&agenda[i].ativo);
		}
	         if(agenda[i].ativo==0){
	    	   system("cls");
	           strcpy(agenda[i].nome,vazio);
	           strcpy(agenda[i].cpf,vazio);
	           strcpy(agenda[i].tel,vazio);
	           strcpy(agenda[i].sexo,vazio);
	           strcpy(agenda[i].ender,vazio);
	           strcpy(agenda[i].email,vazio);
	           strcpy(agenda[i].profissao,vazio);
	           
	      
	            printf("\n Nome: %s", agenda[i].nome);
	                 	printf("\n CPF: %s", agenda[i].cpf);
	                 	printf("\n Telefone: %s", agenda[i].tel);
	                 	printf("\n Sexo: %s", agenda[i].sexo);
	                	printf("\n Endereço: %s", agenda[i].ender);
	                 	printf("\n Email: %s", agenda[i].email);
		   	      printf("\n Profissão: %s",agenda[i].profissao);
	       
	             cont=tam-1;  
	              agenda[i].ativo=0;
		          }
		
	             }
	       
	       	     if(strcmp (buscanome,agenda[i].nome)!=0 && (i==tam)){
				
    	       			printf("\n Registro não encontrado ");
		      }
			 	//printf("\n Pressione uma tecla para voltar ao menu");
			 	getch();
			 	break;
			
			//case 'E': system("cls");
 				
 				printf("\nSaindo...");
 				getch();
 				break;
			
			//default : printf("\n Opcao invalida");
					printf("\n Pressione uma tecla para voltar ao menu");
					getch();
		}	
		while (menu!='E');
      }
				 	
		

	

