#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum categoria{
    ENTRADA,
    PRINCIPAL,
    SOBREMESA, 
    BEBIDA
}categoria;

typedef enum status{
    PENDENTE,
    EM_PREPARO,
    PRONTO, 
    ENTREGUE
}status; 

typedef struct cliente{
    char nome[20];
    unsigned idade; 
    char endereco[150];
    char email[25];
}cliente; 

typedef struct cardapio
{
    char nome[20]; 
    char descricao [100];
    float preco; 
    enum categoria categoria1; 
}cardapio;

typedef struct pedidos
{
    char identificador[10]; //pedido: w21KAS1Cds
    struct cliente cliente1;
    struct cardapio item; 
    enum status status1; 
}pedidos;


int main(){
    return (0);
}