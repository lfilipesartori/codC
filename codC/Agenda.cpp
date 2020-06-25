#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>     
#include <locale.h>   
#define TAM 100        

typedef struct Agenda{
        char nome[50];
        char fone[17];
        char email[80];
}contatos;

/*============  Prototipos  ===============*/
void Incluir(void);    // função para Incluir dados
void Visualizar(void); // função para Mostrar os contatos ja incluidos
void Organizar(void);  // função para Colocar em ordem os contatos da agenda
void Pesquisar(void);  // função para Pesquisar contatos
char AddMais();       // função para Adicionar mais contatos na agenda
void Apagar(void);   // função para Apaga todos os contatos na agenda

/*============  Variaveis Globais  =============*/
static int qtd = 0;     
contatos max[TAM];     
FILE *arq;              

/*========  Incluir Contatos na Agenda  ===========*/
void Incluir(void){
     int cont = 0;   
     int retorno;    
     char op = 's';  

     arq = fopen("agenda.txt", "a");
     if (arq == NULL){
        printf ("Erro!\nO arquivo da lista não pode ser aberto!\n");
        getch();
        exit(1);
     }
     while ((cont < TAM) && (op == 's')){
           printf (" Digite o nome: ");
           gets(max[cont].nome);
           printf (" Digite o numero: ");
           gets(max[cont].fone);
           printf (" Digite o E-mail: ");
           gets(max[cont].email);

           // fwrite grava 1 contato na struct Agenda
          
           retorno = fwrite (&max[cont], sizeof(contatos) ,1,arq);
           // fwrite retornara um valor int 1 para sucesso e 0 para fracasso
           if (retorno == 1) {
               printf("\n Gravacao ok! ");
           }
           cont++;
           op = AddMais();
           qtd++;//acrecenta 1 contato a mais
     }
     fclose (arq);
}

/*==============  Adicionar mais Contatos  ===============*/
char AddMais() {
   char op;
   do {
      printf("\n Deseja inserir novos dados? [S ou N]? " );
      op = getch();
      printf("\n" );
   } while (op != 's' && op != 'n');
   return op;
}

/*=====================  Apagar tudo  ====================*/
void Apagar() {
    /* w+ abre um arquivo para leitura e escrita.
    Se o arquivo não existir, o sistema operacional tentará criá-lo.
    Se o arquivo existir, todo o seu conteúdo será substituído pelo novo conteúdo.*/
    arq = fopen("agenda.txt","w+"); //recria um arquivo limpo
    printf("\n\tLista limpa!\n ");
    fclose(arq);
    getch();
}

/*=============  Organizar em ordem alfabetica  ==========*/
void Organizar(void){//algoritmo de ordenação do tipo ordenação por seleção
     contatos vet; 
     int aux,i,j,k,retorno;
     char *str, *str2, *straux;
     aux = qtd; 
     
     for (i = 0 ; i < aux ; i++){
         str = max[i].nome;
         for (j = i+1 ; j < aux ; j++){
             str2 = max[j].nome;             
             if ( strcmp ( str, str2 ) > 0 ){
                 vet = max[i];
                 max[i] = max[j];
                 max[j] = vet;
             }
         }
     }
     remove("agenda.txt");
     arq = fopen("agenda.txt", "w+");
     if (arq == NULL){
        printf (" ERRO!\n ");
        getch();
        exit(1);
     }
     for (k = 0 ; k < aux ; k++){
           retorno = fwrite (&max[k], sizeof(contatos) ,1,arq);
           if (retorno != 1) {
               printf("\n ERRO! ");
           }
     }
     fclose(arq);
     printf("\n Lista Ordenada!\n ");
     getch();
}

/*============== Pesquisar contato pelo nome =====================*/
void Pesquisar(void){
     int i=0, retorno=1, cont=0;
     char nome[50],op;

     arq = fopen("agenda.txt", "r");
     if (arq == NULL){
         printf (" Erro!\nO arquivo da lista não pode ser aberto! \n");
         getch();
         exit(1);
     }
     printf (" Digite o nome: ");
     gets(nome);
     retorno = fread(&max[i], sizeof(contatos), 1, arq);
     while (retorno == 1){
         if (strcmp(nome, max[i].nome) == 0 ){
            printf("\n Nome....: %s",max[i].nome);
            printf("\n Fone....: %s",max[i].fone);
            printf("\n E-mail..: %s\n ",max[i].email);
            cont++;
         }
     i++;
     retorno = fread(&max[i], sizeof(contatos), 1, arq);
     }
     if(cont == 0){
        printf("Nao ha contatos com este nome!\n ");
     }
     getch();
     fclose(arq);
}

/*================== Lista os contatos cadastrados ======================*/
void Visualizar(void){
    int i = 0, retorno;

    arq = fopen("agenda.txt", "r");
    if (arq == NULL){
       printf ("Erro!\nO arquivo da lista não pode ser aberto!\n");
       getch();
       exit(1);
    }
    retorno = fread(&max[i], sizeof(contatos), 1, arq);
    while (retorno == 1){ 
      printf("\n Nome....: %s",max[i].nome);
      printf("\n Fone....: %s",max[i].fone);
      printf("\n E-mail..: %s\n",max[i].email);
      i++;
      retorno = fread(&max[i], sizeof(contatos), 1, arq);
    }
    printf(" \n\n %d Contatos salvos!\n ", i);
    getch();
    fclose(arq);
}

/*=====================   Menu   =======================*/
void menu(void){
    char op;
    do{
        system("cls");
        printf("\n\n\t\tAGENDA\n");
        printf("\n 1 = Incluir\n 2 = Listar\n 3 = Organizar por ordem alfabetica\n 4 = Pesquisar por nome\n");
        printf(" 5 = Formatar lista\n 6 = Sobre\n 7 = Voltar\n\n");
        op = getch();
        switch(op){
            case '1':
                Incluir();
                break;
            case '2':
                Visualizar();
                break;
            case '3':
                Organizar();
                break;
            case '4':
                Pesquisar();
                break;
            case '5':
                Apagar();
                break;     
            case '6':
                system("cls");
               int main();
                break;
            default:
                printf("\a Digite uma opção valida\n");
                getch();
        }
    }
    while (op);
}

/*=========== Função Principal ================*/
int main (){
    int var;
    system("title AGENDA");
    setlocale(LC_ALL, "Portuguese");
    printf("\tUse os numeros para selecionar a opção desejada.\n");
    printf("\tPressione qualquer tecla para continuar ou\n\tEspaço para sair do programa agora.\n\t");
    var=getch();
    if(var == 32){ exit(0);}// 32 corresponde a espaço no teclado conforme Tabela ASCII
menu();
system("pause");
}
