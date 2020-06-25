#include <stdio.h>
#include <stdlib.h>

#define TAM 7

void Cadastradas(int temp[])
{
     int i;
     int a=1;
     for(i=0;i<TAM;i++)
     {
         printf("temperatura do dia %d:%d\n",a,temp[i]);
         a++;
     }
}

void procura(int temp[],int valor)
{
     int i;
     int a=1;
     int existe=0;
     for(i=0;i<TAM;i++)
     {
         if(temp[i]==valor)
         {
            printf("\n\nTemperatura Encontrada!\n\n\nTemperatura do dia %d:%d\n\n",a,temp[i]);
            existe=1;
         }  
         a++;     
     }
     if(existe==0)
         printf("temperatura nao encontrada!");
}

int media(int temp[])
{
    int i;
    int soma=0;
    int media=0;
    for(i=0;i<TAM;i++)
       soma=temp[i]+soma;
    media=soma/TAM;
}
    
int maior(int temp[])
{
    int i;
    int maior=0;
    for(i=0;i<TAM;i++)
    {
        if(temp[i]>maior)
            maior=temp[i];
    }
    return maior;
}

int menor(int temp[])
{
    int i;
    int menor=100;
    for(i=0;i<TAM;i++)
    {
        if(temp[i]<menor)
            menor=temp[i];
    }
    return menor;
}

main()
{
  int i;
  int valor;
  int opcao=0;
  int temp[TAM];
  for(i=0;i<TAM;i++)
  {
      printf("Introduza as temperaturas da semana\n");
      scanf("%d",&temp[i]);
  }
  do
  {
     printf("\n"); 
     printf("    -----------------------------------------------------------\n"); 
     printf("   |1-Mostrar temperaturas cadastradas      					|\n");
     printf("   |2-Pesquizar a ocorrencia de uma temperatura                |\n");
     printf("   |3-Media da temperatura da semana                           |\n");
     printf("   |4-Temperatura mais elevada                                 |\n");
     printf("   |5-Temperatura mais baixa                                   |\n");
     printf("   |6-Sair                                                     |\n");
     printf("    -----------------------------------------------------------\n"); 
     printf("    opcao:");
     scanf("%d",&opcao);
     
     switch(opcao)
     {
          case 1:Cadastradas(temp);break;
               
          case 2:printf("Introduza a temperatura para procurar");
                 scanf("%d",&valor);
                 procura(temp,valor);break;
               
          case 3:printf("media:%d\n",media(temp));break;
               
          case 4:printf("Temperatura mais elevada:%d\n",maior(temp));break;
               
          case 5:printf("Temperatura mais baixa:%d\n",menor(temp));break;
                   
          case 6:printf("Encerrar o programa\n");break;    
     }
  }
  while(opcao!=6);                 
  system("PAUSE");	

}
