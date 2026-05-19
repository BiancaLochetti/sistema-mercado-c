#include <stdio.h>
#include <stdlib.h>

struct produto {
    char nome_produto[50];
    int id_produto;
    int qtd_produto;
    float preco_produto;
};

struct cliente {
    char nome_cliente[50];
    char cpf_cliente[15];
    char fidelidade_cliente;
};

int main() {

    struct produto produtos[100];
    struct cliente clientes[100];

    int continuar = 1;
    int i = 0;

    float preco_total = 0;
    float desconto = 0;

    // Matriz para armazenar:
    // [0] = ID
    // [1] = quantidade
    // [2] = preco unitario
    // [3] = subtotal
    float compras[100][4];

    // *Dados do cliente*

    printf("\nDigite o nome do cliente: ");
    scanf(" %[^\n]", clientes[0].nome_cliente);

    printf("Digite o CPF do cliente: ");
    scanf(" %[^\n]", clientes[0].cpf_cliente);

    printf("O cliente possui fidelidade? (S = sim / N = nao): ");
    scanf(" %c", &clientes[0].fidelidade_cliente);

   
    // *Cadastro dos produtos*

    while (continuar == 1) {

        printf("\nDigite o nome do produto: ");
        scanf(" %[^\n]", produtos[i].nome_produto);

        printf("Digite o codigo do produto: ");
        scanf("%d", &produtos[i].id_produto);

        printf("Digite a quantidade do produto: ");
        scanf("%d", &produtos[i].qtd_produto);

        printf("Digite o preco do produto: R$ ");
        scanf("%f", &produtos[i].preco_produto);

        // subtotal do produto
        compras[i][0] = produtos[i].id_produto;
        compras[i][1] = produtos[i].qtd_produto;
        compras[i][2] = produtos[i].preco_produto;
        compras[i][3] = produtos[i].qtd_produto * produtos[i].preco_produto;

        // soma no total
        preco_total += compras[i][3];

        printf("Produto cadastrado!\n");

        printf("\nDeseja cadastrar outro produto? (1 = sim / 0 = nao): ");
        scanf("%d", &continuar);

        i++;
    }

    // *Resumo da compra*

    printf("\n========== RESUMO DA COMPRA ==========\n");

    printf("Cliente: %s\n", clientes[0].nome_cliente);
    printf("CPF: %s\n", clientes[0].cpf_cliente);

    printf("\nTotal sem desconto: R$ %.2f\n", preco_total);

    
    // *Desconto*

    if (clientes[0].fidelidade_cliente == 'S' ||
        clientes[0].fidelidade_cliente == 's') {

        printf("Cliente possui fidelidade.\n");

        if (preco_total < 100) {
            desconto = preco_total * 0.05;
        }
        else if (preco_total >= 100 && preco_total <= 500) {
            desconto = preco_total * 0.10;
        }
        else {
            desconto = 0;
        }

        printf("Desconto aplicado: R$ %.2f\n", desconto);

    } else {

        printf("Cliente nao possui fidelidade.\n");
    }

    preco_total -= desconto;

    printf("Total final: R$ %.2f\n", preco_total);


    // *Detalhes da compra*

    printf("\n========== DETALHES DOS PRODUTOS ==========\n");

    for (int j = 0; j < i; j++) {

        printf("\nProduto %d\n", j + 1);

        printf("Nome: %s\n", produtos[j].nome_produto);

        printf("ID: %d\n", produtos[j].id_produto);

        printf("Quantidade: %.0f\n", compras[j][1]);

        printf("Preco Unitario: R$ %.2f\n", compras[j][2]);

        printf("Subtotal: R$ %.2f\n", compras[j][3]);
    }

    return 0;
}