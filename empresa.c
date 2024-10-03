#include "empresa.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Empresa criarEmpresa()
{
    Empresa e;
    e.tamanho = 0;
    return e;
}

void acrestentaTaxi(Empresa *e, Taxi t)
{
    if (e->tamanho > MAX_taxi - 1)
    {
        printf("Impossivel acrescentar taxi, maximo de taxis atingidos.\n");
    }
    else
    {
        e->taxi[e->tamanho++] = t;
        qttaxi = e->tamanho;
    }

    printf("Numero de taxis da empresa: %d \n", e->tamanho);
}

void alterarTaxiEmpresa(Empresa *e, Taxi t)
{
    system("cls");
    int numero;
    printf("Insira o numero do taxi que pretende alterar: ");
    scanf("%d", &numero);
    int indice = -1;
    for (int i = 0; i < e->tamanho; i++)
    {
        if (e->taxi[i].numero == numero)
        {
            indice = i;
            break;
        }
    }
    if (indice == -1)
    {
        printf("Taxi com esse numero nao encontrado.\n");
        return;
    }
    char novaMatricula[MAX_matricula];
    char novaMarca[MAX_nome];
    char novoModelo[MAX_nome];
    getchar();
    printf("Introduza a nova matricula do taxi (00-AA-00): ");
    fgets(novaMatricula, MAX_matricula, stdin);
    fflush(stdin);
    novaMatricula[strlen(novaMatricula) - 1] = '\0';
    printf("Introduza a nova Marca: ");
    fgets(novaMarca, MAX_nome, stdin);
    fflush(stdin);
    novaMarca[strlen(novaMarca) - 1] = '\0';
    printf("Insira o novo modelo para o taxi: ");
    fgets(novoModelo, MAX_nome, stdin);
    fflush(stdin);
    novoModelo[strlen(novoModelo) - 1] = '\0';

    strcpy(e->taxi[indice].matricula, novaMatricula);
    strcpy(e->taxi[indice].marca, novaMarca);
    strcpy(e->taxi[indice].modelo, novoModelo);

    printf("Taxi com numero %d foi alterado.\n", numero);
}

void imprimeEmpresa(Empresa *e)
{
    system("cls");
    if (e->tamanho == 0)
    {
        printf("Ainda nao existem taxis.\n");
    }
    else
    {
        for (int i = 0; i < e->tamanho; i++)
        {
            if (e->taxi[i].ativo != 0)
            {
                imprimeTaxiInf(e->taxi[i]);
            }
        }
    }
}

void procuraTaxi(Empresa *e, Lista *head)
{
    system("cls");
    Lista *fila = head;
    int numero;
    int indice = -1;
    int qtViagensTaxi = 0;
    float kmViagensTaxi = 0;
    float preçoTotalViagens = 0;
    printf("Insira o numero do taxi que pretende encontrar: ");
    scanf("%d", &numero);
    for (int i = 0; i <= e->tamanho; i++)
    {
        if (e->taxi[i].numero == numero)
        {
            if (e->taxi[i].ativo != 0)
            {
                imprimeTaxiInf(e->taxi[i]);
                indice = i;
            }
        }
    }
    if (indice == -1)
    {
        printf("Taxi com esse numero nao encontrado.\n");
    }
    if (indice != -1)
    {
        while (fila != NULL)
        {
            if (fila->viagem.taxi == numero)
            {
                if (fila->viagem.ativo == 1)
                {
                    qtViagensTaxi++;
                    kmViagensTaxi += fila->viagem.kms;
                    preçoTotalViagens += fila->viagem.precoViagem;
                }
            }
            fila = fila->proximo;
        }
        if (qtViagensTaxi != 0)
        {
            fila = head;
            printf("\n\t------- Lista -------\n\t");
            while (fila != NULL)
            {
                if (fila->viagem.taxi == numero)
                {
                    if (fila->viagem.ativo == 1)
                    {
                        imprimeViagem(fila->viagem);
                        printf("\n\t------------------------------\n\t");
                    }
                }
                fila = fila->proximo;
            }
            printf("\n\t------- Fim da Lista -------\n\t");
            printf("\n\tQuantidade de viagens feita ate ao momento pelo taxi: %d\n\t", qtViagensTaxi);
            printf("Quilometros efetuados ate ao momento pelo taxi em viagens: %.2f kms\n\t", kmViagensTaxi);
            printf("Valor total ganho em viagens ate ao momento pelo taxi: %.2f euros\n\t",preçoTotalViagens);
            
        }
    }
    if (qtViagensTaxi == 0)
    {
        printf("\n\tO taxi ainda nao efetuou viagens.\n\t");
    }
}

void procuraTaxiViagensMaisCara(Empresa *e, Lista *head)
{
    system("cls");
    Lista *fila = head;
    int numero = 0;
    int indice = -1;
    float precoElevado = 0;
    printf("Insira o numero do taxi que pretende encontrar: ");
    scanf("%d", &numero);
    for (int i = 0; i <= e->tamanho; i++)
    {
        if (e->taxi[i].numero == numero)
        {
            if (e->taxi[i].ativo != 0)
            {
                imprimeTaxiInf(e->taxi[i]);
                printf("\n\t------------------------------\n\t");
                indice = i;
            }
        }
    }
    if (indice == -1)
    {
        printf("Taxi com esse numero nao encontrado.\n");
    }
    if (indice != -1)
    {
        while (fila != NULL)
        {
            if (fila->viagem.taxi == numero)
            {
                if (precoElevado < fila->viagem.precoViagem)
                {
                    precoElevado = fila->viagem.precoViagem;
                }
            }
            fila = fila->proximo;
        }

        if (indice != -1)
        {
            fila = head;
            while (fila != NULL)
            {
                if (fila->viagem.taxi == numero)
                {
                    if (fila->viagem.precoViagem == precoElevado)
                    {
                        imprimeViagem(fila->viagem);
                        printf("\n\t------------------------------\n\t");
                    }
                }
                fila = fila->proximo;
            }
        }
        if (precoElevado == 0)
        {
            printf("Taxi com esse numero ainda nao tem viagens.\n");
        }
    }
}

void eliminarTaxiEmpresa(Empresa *e, Taxi t)
{
    system("cls");
    int numero;
    printf("Insira o numero do taxi que pretende eliminar: ");
    scanf("%d", &numero);
    int indice = -1;
    for (int i = 0; i < e->tamanho; i++)
    {
        if (e->taxi[i].numero == numero)
        {
            indice = i;
            e->taxi[i].ativo = 0;
            printf("Taxi com esse numero eliminado.\n");
            break;
        }
    }
    if (indice == -1)
    {
        printf("Taxi com esse numero nao encontrado.\n");
        return;
    }
}

void recuperarTaxiEmpresa(Empresa *e, Taxi t)
{
    system("cls");
    int numero;
    printf("Insira o numero do taxi que pretende eliminar: ");
    scanf("%d", &numero);
    int indice = -1;
    for (int i = 0; i < e->tamanho; i++)
    {
        if (e->taxi[i].numero == numero)
        {
            indice = i;
            e->taxi[i].ativo = 1;
            printf("Taxi com esse numero recuperado.\n");
            break;
        }
    }
    if (indice == -1)
    {
        printf("Taxi com esse numero nao encontrado.\n");
        return;
    }
}

void save(Empresa e)
{
    FILE *f;
    f = fopen("dados.dat", "wb");
    fwrite(&e, sizeof(Empresa), 1, f);
    fclose(f);
}

Empresa read()
{
    Empresa e;
    e = criarEmpresa();
    Taxi t;
    FILE *f;
    f = fopen("dados.dat", "rb");
    fread(&e, sizeof(Empresa), 1, f);
    fclose(f);
    return e;
}