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

//prototipando a função de limpar a interface 
void clear();

//prototipando as funções de alteração de pedidos 
void pedido_add(pedidos **listaPedidos, int *numPedidos, char *identificador, cliente cliente1, cardapio *item, int numitens);
void pedido_fetch(pedidos *pedidos1, int numPedidos, char *identificador, status novoStatus);
void pedido_list(pedidos *pedidos1, int numPedidos);

//prototipando as funções de crud do cardápio: inserção, remoção e atualização dos items
void cardapio_add(cardapio  **cardapio1, int *tamanho, char *nome, char *descricao, float preco, categoria tipo);
void cardapio_delete(cardapio **cardapio1, int *tamanho, char *nome);
void cardapio_fetch(cardapio *cardapio1, int tamanho, char *nome, char *novaDescricao, float novoPreco, categoria novoTipo);
void cardapio_list(cardapio *cardapio1, int tamanho);

int main(){
    //o cardápio começa zerado (boot no cardápio)
    pedidos *listadepedidos = NULL;
    int numPedidos = 0, tamanhomenu = 0, opcao; 
    cardapio *menu = NULL;

    do {
        printf("\n==== SISTEMA DE GERENCIAMENTO DE PEDIDOS ====\n");
        printf("1 - Adicionar Item ao Cardápio\n");
        printf("2 - Remover Item do Cardápio\n");
        printf("3 - Criar Pedido\n");       
        printf("4 - Alterar Status do Pedido\n");                                               
        printf("5 - Listar Pedidos\n");
        printf("6 - Listar Cardápio\n");
        printf("7 - Atualizar Item do Cardápio\n");
        printf("8 - Sair\n");
        printf("\nEscolha uma opção: ");
        scanf("%d", &opcao);
        getchar(); //limpar buffer do teclado

        switch (opcao) {
            case 1:{
                //limpando a tela
                clear();
                // Chamar função para adicionar item ao cardápio
                char nome[50], descricao[100];
                float preco; 
                int cat; //categoria

                printf("Nome do item: ");
                fgets(nome, sizeof(nome), stdin);
                nome[strcspn(nome, "\n")] = 0;

                printf("Descrição: ");
                fgets(descricao, sizeof(descricao), stdin);
                descricao[strcmp(descricao, "\n")] = 0;

                printf("Preço: ");
                scanf("%f", &preco);

                printf("Categoria: (0 = ENTRADA, 1 = PRINCIPAL, 2 = SOBREMESA, 3 = BEBIDA): ");
                scanf("%d", &cat);

                cardapio_add(&menu, &tamanhomenu,nome, descricao, preco, (categoria)cat);
                printf("Item adicionado no cardápio com sucesso!\n");
                break;}
            case 2:{
                clear();
                // Caso o cardápio esteja vazio
                if (tamanhomenu == 0){
                    printf("Erro: O cardápio está vazio!\n");
                    break; 
                }

                // Input item do cardápio à ser removido
                char nome[50];
                printf("Nome do item a remover: ");
                scanf("%s", nome);

                // Chamando a função
                cardapio_delete(&menu, &tamanhomenu, nome);
                // retorno da função ao usuário
                printf("Item removido do cardápio com sucesso!\n");
                break;}
            case 3:{
                clear();
                // Caso não haja itens no cardápio
                if (tamanhomenu == 0){
                    printf("Erro: Não há itens no cardápio!\n");
                    break;
                }

                //inputs necessários para saciar os parâmetros da função de add pedidos no cardápio
                char identificador[10];
                char nomeCliente[50], endereco[100], email[50];
                int idade, numItens; 

                printf("Identificador do pedido: ");
                scanf("%s", identificador);
                getchar();

                printf("Número do cliente: ");
                fgets(nomeCliente, sizeof(nomeCliente), stdin);
                nomeCliente[strcspn(nomeCliente, "\n")] = 0;
                
                printf("Idade do cliente: ");
                scanf("%d", &idade);
                getchar();

                printf("Endereço do cliente: ");
                fgets(endereco, sizeof(endereco), stdin);
                endereco[strcspn(endereco, "\n")] = 0;

                printf("Email do cliente: ");
                fgets(email, sizeof(email), stdin);
                email[strcspn(email, "\n")] = 0;

                printf("Número de itens no pedido: ");
                scanf("%d", &numItens);
                getchar();
                
                //Alocando espaço para os itens do pedido que serão adicionados
                cardapio *itensPedido = malloc(numItens * sizeof(cardapio));                

                // A cada iteração for, será pedido pro usuário pedir o nome dos itens e buscar no cardápio
                for (int i = 0; i < numItens; i++){
                    char nomeItem[50];
                    printf("Nome do item %d:", i+1);
                    fgets(nomeItem, sizeof(nomeItem), stdin);
                    nomeItem[strcspn(nomeItem, "\n")] = 0;

                    int encontrado = 0; // Valores não encontrado = 0 
                    for (int j = 0; j < tamanhomenu; j++){
                        if (strcmp(menu[j].nome, nomeItem) == 0){
                            itensPedido[i] = menu[j]; // Copia dados do item do cardápio
                            encontrado = 1; // Valor encontroado = 1
                            break;
                        }
                    }

                    // Caso o item buscado no cardápio não seja encontrado: encontrado = 0  
                    if(!encontrado){
                        printf("Erro: Item não encontrado no cardápio!\n");
                        //liberando espaço na memória que era para o item encontrado 
                        free(itensPedido);
                    }
                }

                //criando um registro de cliente para associá-lo ao pedido
                cliente clientenovo; 
                clientenovo.nome = strdup(nomeCliente);
                clientenovo.idade = idade; 
                clientenovo.endereco = strdup(endereco);
                clientenovo.email = strdup(email);
                
                //tendo todos os parâmetros prontos, chamar a função de add pedido
                pedido_add(&listadepedidos, &numPedidos, identificador, clientenovo, itensPedido, numItens);
                break;}
            case 4:
                clear();
                // Chamar função para alterar status - pedidofetch
                
                //tratamento caso não haja itens no cardápio
                if (numPedidos == 0) {
                    printf("Erro: Não há itens no cardápio para atualizar!\n");
                    break;
                }
                
                //input de membros necessários do registro de itens do cardápio
                char identificador[10];
                int novoStatus;

                printf("Identificador do pedido a ser atualizado: ");
                scanf("%s", identificador);

                printf("Novo status do pedido (0 = PENDENTE, 1 = EM_PREPARO, 2 = PRONTO, 3 = ENTREGUE): ");
                scanf("%d", &novoStatus);
                
                //chamando a função de pedidofetch
                pedido_fetch(listadepedidos, numPedidos, identificador, (status)novoStatus);
                //retorno ao usuário
                printf("Pedido [%s] atualizado com sucesso!\n", identificador);
                break;
            case 5:
                clear();
                // Chamar função para listar pedidos - pedidolist
                pedido_list(listadepedidos, numPedidos);
                break;
            case 6:
                clear();
                // Chamar a função para listar o cardápio - cardapiolist
                cardapio_list(menu, tamanhomenu);
                break;                
            case 7:
                clear();
                // Chamar a função de atualizar o cardápio - cardapiofetch
                
                //verificando se há itens no cardápio
                if (tamanhomenu == 0) {
                    printf("Erro: Não há itens no cardápio para atualizar!\n");
                    break;
                }

                //inputs necessários para atualizar um item do cardápio
                char nome[50], novaDescricao[100];
                float novoPreco;
                int novaCategoria;

                printf("Nome do item a ser atualizado: ");
                fgets(nome, sizeof(nome), stdin);
                nome[strcspn(nome, "\n")] = 0;

                printf("Nova descrição: ");
                fgets(novaDescricao, sizeof(novaDescricao), stdin);
                novaDescricao[strcspn(novaDescricao, "\n")] = 0;

                printf("Novo preço: ");
                scanf("%f", &novoPreco);

                printf("Nova categoria (0 = ENTRADA, 1 = PRINCIPAL, 2 = SOBREMESA, 3 = BEBIDA): ");
                scanf("%d", &novaCategoria);

                //chamando a função de atualização
                cardapio_fetch(menu, tamanhomenu, nome, novaDescricao, novoPreco, (categoria)novaCategoria);
                //retorno da função
                printf("Item do cardápio atualizado com sucesso!\n");
                break;
            case 8:
                clear();
                printf("Saindo do sistema...\n");
                break;
            default:
                clear();
                printf("Opção inválida! Digite novamente!\n");
        }
    } while (opcao != 8);

    return (0);
}   

//FUNÇÃO DE LIMPAR A TELA
void clear(){
    #ifdef _WIN32
        system("cls"); //Limpa caso seja windows
    #else
        system("clear"); //Limpa caso seja linux
    #endif
}

//FUNÇÕES DE CRUD DOS PEDIDOS

void pedido_add(pedidos **pedidos1, int *numPedidos, char *identificador, cliente cliente1, cardapio *item, int numitens){
    //realocando a memória do vetor de pedidos1, já que um novo pedido está sendo adicionado... o sistema necessita de mais memória
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
    //iterando conteúdo das strings, não os ponteiros
    for(int i = 0; i < numitens; i++){
        novoPedido->item[i].nome = strdup(item[i].nome);
        novoPedido->item[i].descricao = strdup(item[i].descricao);
        novoPedido->item[i].preco = item[i].preco;
        novoPedido->item[i].categoria1 = item[i].categoria1; 
    }

    //aumentando a quantidade de pedidos no cardápio
    (*numPedidos)++;
    
    //mensagem de saída da função
    printf("Pedido [%s] criado com sucesso!\n", identificador);
}

void pedido_fetch(pedidos *pedidos1, int numPedidos, char *identificador, status novoStatus){
    //procurando o pedido beasado no identificador 
    for (int i = 0; i < numPedidos; i++){
        //condição para achar o pedido pelo número id
        if (strcmp(pedidos1[i].identificador, identificador) == 0){
            pedidos1[i].status1 = novoStatus; //aleterando para o novo status
            printf("Pedido [%s] atualizado para STATUS: %d\n", identificador, novoStatus); //retorno da função
            return;
        }
    }
    //caso não encontre o pedido a ser atualizado
    printf("Pedido [%s] não encontrado!\n", identificador);
    return;
}

void pedido_list(pedidos *pedidos1, int numPedidos){
    // Caso não haja nenhum pedido registrado à ser listado 
    if (numPedidos == 0){
        printf("Nenhum pedido registrado!\n");
        return;
    }

    // Array de strings correspondente à enumerações de status
    const char *statusString[] = {"PENDENTE", "EM_PREPARO", "PRONTO", "ENTREGUE"};

    // Iterando por cada registro de pedido e printando-o
    printf("\n==== LISTA DE PEDIDOS ====\n");
    for (int i = 0; i < numPedidos; i++){
        printf("\nPedido: [%s]\n", pedidos1[i].identificador);
        printf("Cliente: %s\n", pedidos1[i].cliente1.nome);
        //exibindo a string correspondente à enumeração do status
        printf("Status: %s\n", statusString[pedidos1[i].status1]); 
        printf("Itens do pedido:\n");

        //iterando outro laço para printar cada item respectivo à cada pedido
        printf("Itens pedidos do cardápio:\n");
        for (int j = 0; j < pedidos1[i].numitens; j++) {
            printf(" - %s | R$%.2f\n", pedidos1[i].item[j].nome, pedidos1[i].item[j].preco);
        }
        printf("----------------------------------\n");
    }
}

//FUNÇÕES DE CRUD DO CARDÁPIO
// FUNÇÃO CARDAPIO_ADD()
void cardapio_add(cardapio **cardapio1, int *tamanho, char *nome, char *descricao, float preco, categoria tipo){
    *cardapio1 = realloc(*cardapio1, (*tamanho+1) * sizeof(cardapio));
    
    // Tratamento de erros - caso a dimensão do registro de cardápio seja nulo
    if (*cardapio1 == NULL){
        printf("Erro na alocação de memória!\n");
        exit(1);
    }

    // Alocando "nome" e "descricao" na memória utilizando os ponteiros da instância do cardápio (cardapio1) com o tamanho do cardapio. Essa alocação toma como base o comprimento das strings de "nome" e "descricao" para reservar a quantidade suficiente na memória
    (*cardapio1)[*tamanho].nome = malloc(strlen(nome) + 1);
    (*cardapio1)[*tamanho].descricao = malloc(strlen(descricao) + 1);

    // Tratamento de erros - caso alocação de memória das strings "nome" e "descrição" não ocorra
    if (!(*cardapio1)[*tamanho].nome || !(*cardapio1)[*tamanho].descricao) {
        printf("Erro na alocação de memória!\n");
        exit(1);
    }

    // Acessando cada um dos campos do item que está sendo criado e copiando o valor para dentro
    strcpy((*cardapio1)[*tamanho].nome, nome);  
    // A string em "descricao" está sendo copiada para o campo descrição o qual está sendo apontado pelo *tamanho, o qual está sendo apontado por **cardapio1
    strcpy((*cardapio1)[*tamanho].descricao, descricao);  
    // Não há necessidade de utilizar a função "strcpy()" uma vez que a atribuição será feita por valor diferentes de strings
    (*cardapio1)[*tamanho].preco = preco;
    (*cardapio1)[*tamanho].categoria1 = tipo; 

    // Ao final da adição do item, o valor de tamanho irá aumentar. Afinal, mais um item foi adicionado ao cardápio e, portanto, seu tamanho aumentou
    (*tamanho)++;
}

void cardapio_delete(cardapio **cardapio1, int *tamanho, char *nome){

    // Iterando até achar o item que será deletado
    for (int i=0; i < *tamanho; i++){
        //achando e comparando o nome que está dentro do item 'i' do cardápio
        if (strcmp((*cardapio1)[i].nome, nome) == 0){
            //liberando o espaço de memória do nome 
            free((*cardapio1)[i].nome);
            free((*cardapio1)[i].descricao);
                
            for (int j = i; j < (*tamanho)-1; j++){
                (*cardapio1)[j] = (*cardapio1)[j+1];
            }
            
            //realocando o espaço de memória, uma vez que um item do cardápio fora deletado
            cardapio *temp = realloc(*cardapio1, (*tamanho-1) * sizeof(cardapio));
            if (temp || *tamanho-1 == 0){
                *cardapio1 = temp; //valor temporário no cardápio1 
                (*tamanho) --; //diminuindo o tamanho do cardápio
            } else {
                printf("Erro na realocação de memória!\n"); //caso "realloc" não funcione
            }
            return;
        }
    }
}

void cardapio_fetch(cardapio *cardapio1, int tamanho, char *nome, char *novaDescricao, float novoPreco, categoria novoTipo){
    for(int i = 0; i < tamanho; i++){
        //achando o item a ser atualizado
        if (strcmp(cardapio1[i].nome, nome) == 0){
            //liberando o espaço da descrição
            free(cardapio1[i].descricao);
            //alterando os membros do registro 'i' do cardápio
            cardapio1[i].descricao = strdup(novaDescricao);
            cardapio1[i].preco = novoPreco;
            cardapio1[i].categoria1 = novoTipo;
            return; 
        }
    }   
}

void cardapio_list(cardapio *cardapio1, int tamanho){
    //caso o cardapio não tenha itens registrados nele   
    if (tamanho == 0){
        printf("O cardápio está vazio!\n");
        return; 
    }

    printf("\n==== ITENS DO CARDÁPIO ====\n");
    //esse laço vai iterar cada item registrado da struct cardápio e printar seu respectivo nome e preço.
    for (int i = 0; i< tamanho; i++){
        printf(" - %s | R$%.2f\n", cardapio1[i].nome, cardapio1[i].preco);
    }
}