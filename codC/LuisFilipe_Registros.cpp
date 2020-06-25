#include <stdio.h>
#include <stdlib.h>

struct pessoa {
    char nome [50];
    int idade;
    char sexo [1];
    char email[50];
    char celular[11];
    
    
};

void limpa_linha() {
    scanf("%*[^\n]");
    scanf("%*c");
}

void ler_registros() {

    FILE *arquivo;
    struct pessoa p; // aqui estou chamando a minha struct pessoa de p, antes era pessoa

    arquivo = fopen("arquivo.bin", "rb");

    if (arquivo == NULL) {
        printf("erro ao abrir o arquivo.\n");
        exit(1);
    }
    printf("\n ========== PESSOAS CADASTRADAS ==========\n\n");

    fread(&p, sizeof(struct pessoa), 1, arquivo);
    do {
        printf("\nNOME: %s\nIDADE: %d\nSEXO: %s\nEMAIL: %s\nCELULAR: %s\n",p.nome, p.idade, p.sexo, p.email, p.celular);
        fread(&p, sizeof(struct pessoa), 1, arquivo);
    } while (!feof(arquivo));

    fclose(arquivo);
}

void gravar_registros() {

    FILE *arq;
    struct pessoa pessoa;
    int i, n_reg;

    printf("\nQuantidade de registros para incluir: ");
    scanf("%d", &n_reg);
    limpa_linha();

    arq = fopen("arquivo.bin", "ab"); // abre arquivo para gravação no final do arquivo

    if (arq == NULL) {
        perror("Erro");
        exit(1);
    }

    for (i = 0; i < n_reg; i++) {

        printf("\nDigite o nome da pessoa: ");
        scanf("%[^\n]", pessoa.nome);
        limpa_linha();
        
		printf("Digite a idade: ");
        scanf("%d", &pessoa.idade);
        limpa_linha();
        
        printf("Digite o sexo: ");
        scanf("%s", pessoa.sexo);
        limpa_linha();
        
        printf("Digite o email: ");
        scanf("%s", pessoa.sexo);
        limpa_linha();
        
        printf("Digite o celular: ");
        scanf("%s", pessoa.sexo);
        limpa_linha();

        fwrite(&pessoa, sizeof(struct pessoa), 1, arq);
    }

    fclose(arq);
}

int main(void) {

    char opcao;

    do {
        gravar_registros();

        ler_registros();

        printf("\nDeseja continuar? [s/n]: ");
        scanf("%c", &opcao);
        limpa_linha();

    } while (opcao == 's');

    return 0;
}
