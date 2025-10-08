#include <stdio.h>
#include <string.h>

// --- Constantes Globais ---
#define MAX_TERRITORIOS 5

// --- Definição de Estrutura (struct) ---
struct Territorio {
    char nome[30];
    char cor[10];
    int tropas;
};

// --- Função para limpar o  buffer de entrada ---
void limparBufferEntrada() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// --- Função principal (main) ---
int main() {
    struct Territorio jogo[MAX_TERRITORIOS];
    int totalTerritorios = 0;
    int opcao;
    
    // --- Laço principal do jogo ---
    do {
        // Exibe menu de opções
        printf("=================================\n");
        printf("JOGO WAR: Desafio Novato\n");
        printf("=================================\n");
        printf("1. Cadastrar novo territorio.\n");
        printf("2. Lista de territorios cadastrados.\n");
        printf("0. Sair.\n");
        printf("Escolha uma opcao: ");
        
        // Lê opção escolhida pelo usuário
        scanf("%d", &opcao);
        limparBufferEntrada(); // Limpa o '\n' deixado pelo scanf

        switch (opcao)
        {
        case 1: // Cadastro de territorio
            printf("--- Cadastro de novo territorio ---\n\n");
            if (totalTerritorios < MAX_TERRITORIOS)
            {
                printf("Digite o nome do territorio: ");
                fgets(jogo[totalTerritorios].nome, sizeof(jogo[totalTerritorios].nome), stdin);

                printf("Digite a cor do territorio: ");
                fgets(jogo[totalTerritorios].cor, sizeof(jogo[totalTerritorios].cor), stdin);

                jogo[totalTerritorios].nome[strcspn(jogo[totalTerritorios].nome, "\n")] = '\0';
                jogo[totalTerritorios].cor[strcspn(jogo[totalTerritorios].cor, "\n")] = '\0';

                printf("Digite o numero de tropas do territorio: ");
                scanf("%d", &jogo[totalTerritorios].tropas);
                limparBufferEntrada();

                totalTerritorios++;

                printf("Territorio registrado com sucesso!\n");
            } else {
                printf("Numero maximo de territorios atingido! Nao e possivel cadastrar mais territorios\n");
            }
            
            printf("Pressione Enter para continuar...");
            getchar();
            break;

        case 2: // Listar territorios cadastrados
            printf("--- Lista de territorios cadastrados ---\n\n");
            
            if (totalTerritorios == 0) {
                printf("Nenhum territorio cadastrado ainda.\n");
            } else {
                for (int i = 0; i < totalTerritorios; i++)
                {
                    printf("------------------------------\n");
                    printf("Territorio %d\n", i + 1);
                    printf("Nome: %s\n", jogo[i].nome);
                    printf("Cor: %s\n", jogo[i].cor);
                    printf("Numero de tropas: %d\n", jogo[i].tropas);
                }
                printf("-----------------------------\n");
            }
            // Pausa para o usuário ver a lista
            printf("Pressione Enter para continuar...");
            getchar();
            break;

        case 0: // Sair
            printf("\nSaindo do sistema...\n");
            break;
            
        default: // Opção inválida
            printf("\nOpcao invalida. Tente novamente.\n");
            printf("\nPressione Enter para continuar...");
            getchar();
            break;
        }
    } while (opcao != 0);
}