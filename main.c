#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//enumeração da categoria
typedef enum categoria{
    ENTRADA,  
    PRINCIPAL, 
    SOBREMESA,  
    BEBIDA
}categoria;

//enumeração de status
typedef enum status{
    PENDENTE,
    EM_PREPARO,
    PRONTO, 
    ENTREGUE
}status; 

//struct para registros dos clientes
typedef struct cliente{ 
    char *nome;
    unsigned idade; 
    char *endereco;
    char *email;
}cliente; 

//struct para registros dos itens do cardápio
typedef struct cardapio{    
    char *nome; 
    char *descricao;
    float preco; 
    enum categoria categoria1; 
}cardapio;

//struct para registros dos pedidos
typedef struct pedidos{
    char identificador[10]; 
    struct cliente cliente1;
    struct cardapio *item;
    int numitens; 
    enum status status1; 
}pedidos;

//prototipando as funções de alteração de status 
void pedido_add(pedidos **listaPedidos, int *numPedidos, char *identificador, cliente cliente1, cardapio *item, int numitens);
void pedido_delete(pedidos **pedidos1, int *numPedidos, char *identificador);
void pedido_fetch(pedidos *pedidos1, int numPedidos, char *identificador, status novoStatus);
void pedido_list(pedidos *pedidos1, int numPedidos);

//prototipando as funções de crud do cardápio: inserção, remoção e atualização dos items
void cardapio_add(cardapio  **cardapio1, int *tamanho, char *nome, char *descricao, float preco, categoria tipo);
void cardapio_delete(cardapio **cardapio1, int *tamanho, char *nome);
void cardapio_fetch(cardapio *cardapio1, int tamanho, char *nome, char *novaDescricao, float novoPreco, categoria novoTipo);

int main(){
    int opcao;
    do {
        printf("\n==== SISTEMA DE PEDIDOS ====\n");
        printf("1 - Adicionar Item ao Cardápio\n");
        printf("2 - Remover Item do Cardápio\n");
        printf("3 - Criar Pedido\n");
        printf("4 - Alterar Status do Pedido\n");
        printf("5 - Listar Pedidos\n");
        printf("6 - Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                // Chamar função para adicionar item ao cardápio
                break;
            case 2:
                // Chamar função para remover item do cardápio
                break;
            case 3:
                // Chamar função para criar pedido
                break;
            case 4:
                // Chamar função para alterar status
                break;
            case 5:
                // Chamar função para listar pedidos
                break;
            case 6:
                printf("Saindo do sistema...\n");
                break;
            default:
                printf("Opção inválida!\n");
        }
    } while (opcao != 6);

    //o cardápio começa zerado (boot no cardápio)
    cardapio *menu = NULL;
    int tamanhomenu = 0;

    //adicionando items no cardápio
    cardapio_add(&menu, &tamanhomenu, "Pizza", "Queijo com Calabreza", 30.00, PRINCIPAL);
    cardapio_add(&menu, &tamanhomenu, "Coca Cola", "Refrigerante de Cola", 9.00, BEBIDA);

    //deletando items do cardápio
    cardapio_delete(&menu, &tamanhomenu, "Pizza");

    //para cada iteração, liberar a memória dos items que compõe o cardápio
    for (int i = 0; i < tamanhomenu; i++) {
        free(menu[i].nome);
        free(menu[i].descricao);
    }
    free(menu);

    return (0);
}

//FUNÇÕES DE CRUD DOS PEDIDOS

void pedido_add(pedidos **pedidos1, int *numPedidos, char *identificador, cliente cliente1, cardapio *item, int numitens){
    //realocando vetor de pedidos
    *pedidos1 = realloc(*pedidos1, (*numPedidos+1) * sizeof(pedidos));

    //tratamento de erro de alocação de memória
    if (*pedidos1 == NULL){
        printf("Erro na alocação de memória para pedidos!\n");
        exit(1);
    }
    
    //criando um novo registro para adicionar o novo pedido  
    pedidos *novoPedido = &(*pedidos1)[*numPedidos];

    strcpy(novoPedido->identificador, identificador);
    novoPedido->cliente1 = cliente1; 
    novoPedido->numitens = numitens;
    novoPedido->status1 = PENDENTE; 

    //Alocando espaço para os itens do cardápio selecionados para o pedido 
    novoPedido->item = malloc(numitens * sizeof(cardapio));

    //tratamento de erro caso a alocação de memória para os itens do novo pedido dê errado
    if (novoPedido->item == NULL){
        printf("Erro na alocação de memória para itens do pedido!\n");
    }

    //copiando os itens/registros do cardápio para adicionar no pedido
    for(int i = 0; i < numitens; i++){
        novoPedido->item[i] = item[i]; 
    }

    //aumentando a quantidade de pedidos no cardápio
    (*numPedidos)++;
    
    //mensagem de saída da função
    printf("Pedido [%s] criado com sucesso!\n", identificador);
}

void pedido_delete(pedidos **pedidos1, int *numPedidos, char *identificador){
    //implementar o laço for para achar o pedido
    for (int i = 0; i < *numPedidos; i++){
        if(strcmp((*pedidos1)[i].identificador, identificador) == 0 ){
            //pedido achado, espaço liberado
            free((*pedidos1)[i].item);
                //movendo os pedidos restantes na memória para preencher o espaço vazio 
            int i;
            for (int j = i; j < (*numPedidos)-1; j++){
                (*pedidos1)[j] = (*pedidos1)[j+1];
            }

            //reduzindo o tamanho do vetor
            *pedidos1 = realloc(*pedidos1, (*numPedidos-1) * sizeof(pedidos));
            (*numPedidos)--;

            //saída da função delete
            printf("Pedido [%s] removido com sucesso!\n", identificador);
        }
    }
    //caso o pedido não seja achado
    printf("Pedido [%s] não encontrado!\n", identificador);
}

void pedido_fetch(pedidos *pedidos1, int numPedidos, char *identificador, status novoStatus){
    //procurando o pedido beasado no identificador 
    for (int i = 0; i < numPedidos; i++){
        //condição para achar o número id
        if (strcmp(pedidos1[i].identificador, identificador) == 0){
            pedidos1[i].status1 = novoStatus;
            printf("Pedido [%s] atualizado para STATUS: %d\n", identificador, novoStatus);
            return;
        }
    }
    //caso não encontre o pedido
    printf("Pedido [%s] não encontrado!\n", identificador);
}

void pedido_list(pedidos *pedidos1, int numPedidos){
    //caso não haja nenhum pedido registrado 
    if (numPedidos == 0){
        printf("Nenhum pedido registrado!\n");
    }

    //iterando por cada registro de pedido e printando-o
    for (int i = 0; i < numPedidos; i++){
        printf("\nPedido: [%s] | Cliente: %s | Status: %d\n", pedidos1[i].identificador, pedidos1[i].cliente1.nome, pedidos1[i].status1);
        //iterando outro laço para printar cada item respectivo à cada pedido
        printf("Itens pedidos do cardápio");
        for (int j = 0; j < pedidos1[i].numitens; j++){
            printf(" - %s | %.2f\n", pedidos1[i].item[j].nome, pedidos1[i].item[j].preco);
        }
    }
}

//FUNÇÕES DE CRUD DO CARDÁPIO
void cardapio_add(cardapio **cardapio1, int *tamanho, char *nome, char *descricao, float preco, categoria tipo){
    *cardapio1 = realloc(*cardapio1, (*tamanho+1) * sizeof(cardapio));
    if (*cardapio1 == NULL){
        printf("Erro na alocação de memória!\n");
        exit(1);
    }

    strcpy((*cardapio1)[*tamanho].nome, nome);  
    strcpy((*cardapio1)[*tamanho].descricao, descricao);  
    (*cardapio1)[*tamanho].preco = preco;
    (*cardapio1)[*tamanho].categoria1 = tipo; 

    (*tamanho)++;
}

void cardapio_delete(cardapio **cardapio1, int *tamanho, char *nome){
    for (int i=0; i < *tamanho; i++){
        if (strcmp((*cardapio1)[i].nome, nome) == 0){
            free((*cardapio1)[i].nome);
            free((*cardapio1)[i].descricao);
                
            for (int j = i; j < (*tamanho)-1; j++){
                (*cardapio1)[j] = (*cardapio1)[j+1];
            }
            
            *cardapio1 = realloc(*cardapio1, (*tamanho-1) * sizeof(cardapio));
            (*tamanho)--;
            
            return;
        }
    }
}

void cardapio_fetch(cardapio *cardapio1, int tamanho, char *nome, char *novaDescricao, float novoPreco, categoria novoTipo){
    for(int i = 0; i < tamanho; i++){
        if (strcmp(cardapio1[i].nome, nome) == 0){
            free(cardapio1[i].descricao);
            cardapio1[i].descricao = strdup(novaDescricao);
            cardapio1[i].preco = novoPreco;
            cardapio1[i].categoria1 = novoTipo;
            return; 
        }
    }
}