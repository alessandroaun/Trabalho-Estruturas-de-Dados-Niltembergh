#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int dado;
    struct No* prox;
} No;

//criar//
No* criarLista() {
    return NULL;
}

//verificar//
int verificarVazia(No* lista) {
    return (lista == NULL);
}

//inserir//
void inserirOrdenado(No** lista, int valor) {
    No* novoNo = (No*)malloc(sizeof(No));
    if (novoNo == NULL) {
        printf("Erro ao alocar memória.\n");
        return;
    }
    novoNo->dado = valor;
    novoNo->prox = NULL;

    if (*lista == NULL || (*lista)->dado >= valor) {
        novoNo->prox = *lista;
        *lista = novoNo;
    } else {
        No* atual = *lista;
        while (atual->prox != NULL && atual->prox->dado < valor) {
            atual = atual->prox;
        }
        novoNo->prox = atual->prox;
        atual->prox = novoNo;
    }
}

//exibir//
void exibirLista(No* lista) {
    No* atual = lista;
    while (atual != NULL) {
        printf("%d - ", atual->dado);
        atual = atual->prox;
    }
    printf("Sem elementos na lista.\n");
}

//buscar//
No* buscarLista(No* lista, int valor) {
    No* atual = lista;
    while (atual != NULL && atual->dado != valor) {
        atual = atual->prox;
    }
    return atual;
}

//excluir//
void excluirLista(No** lista, int valor) {
    No* atual = *lista;
    No* anterior = NULL;
    while (atual != NULL && atual->dado != valor) {
        anterior = atual;
        atual = atual->prox;
    }
    if (atual == NULL) {
        printf("Elemento não encontrado.\n");
        return;
    }
    if (anterior == NULL) {
        *lista = atual->prox;
    } else {
        anterior->prox = atual->prox;
    }
    free(atual);
}

//liberar//
void liberarLista(No** lista) {
    No* atual = *lista;
    No* proxNo;
    while (atual != NULL) {
        proxNo = atual->prox;
        free(atual);
        atual = proxNo;
    }
    *lista = NULL;
}

void menu() {
    No* lista = criarLista();
    int opcao, valor;

    do {
        printf("\n-------- Menu:---------\n");
        printf("1. Criar Lista\n");
        printf("2. Inserir Elemento\n");
        printf("3. Exibir Lista\n");
        printf("4. Verificar Elemento\n");
        printf("5. Buscar Elemento\n");
        printf("6. Excluir Elemento\n");
        printf("7. Liberar Lista\n");
        printf("8. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        printf("\n\n");
         
        switch (opcao) {
            case 1:
                printf("Lista criada.\n");
                break;
            case 2:
                printf("Digite o valor a ser inserido: ");
                scanf("%d", &valor);
                inserirOrdenado(&lista, valor);
                break;
            case 3:
                printf("Lista: ");
                exibirLista(lista);
                break;
            case 4:
                printf("Digite o valor para verificar: ");
                scanf("%d", &valor);
                if (buscarLista(lista, valor) != NULL) {
                    printf("O elemento %d está presente na lista.\n", valor);
                } else {
                    printf("O elemento %d não está presente na lista.\n", valor);
                }
                break;
            case 5:
                printf("Digite o valor para buscar: ");
                scanf("%d", &valor);
                if (buscarLista(lista, valor) != NULL) {
                    printf("O elemento %d foi encontrado na lista.\n", valor);
                } else {
                    printf("O elemento %d não foi encontrado na lista.\n", valor);
                }
                break;
            case 6:
                printf("Digite o valor para excluir: ");
                scanf("%d", &valor);
                excluirLista(&lista, valor);
                break;
            case 7:
                liberarLista(&lista);
                printf("Lista liberada.\n");
                break;
            case 8:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
        }
    } while (opcao != 8);
}

int main() {
    menu();
    return 0;
}
