#include "empresa.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

void menu();
void menuEmpresa();
void menuViagens();

int ref1 = 0;
int qttaxi = 1;

int main(int argc, char const *argv[])
{
    system("cls");
    Empresa e = read();
    Viagem viagem;
    qttaxi = e.tamanho;
    Lista *fila = NULL;
    readLista(&fila);
    menu(&e, &viagem);
}

void menu(Empresa *e, Viagem *viagem)
{
    int opcao;
    do
    {
        system("cls");
        printf("========   Gestao de Empresa   ========\n");
        printf(" \n");
        printf(" 1 - Menu taxis \n");
        printf(" 2 - Menu viagens \n");
        printf(" 0 - Sair\n");
        printf("Introduza a opcao pretendida: ");
        scanf("%d", &opcao);
        printf("\n");
        switch (opcao)
        {
        case 0:
            break;
        case 1:
            menuEmpresa(e);
            system("PAUSE");
            break;
        case 2:
            menuViagens(viagem);
            system("PAUSE");
            break;
        default:
            printf("Opcao invalida\n");
            break;
        }
    } while (opcao != 0);
}

void menuEmpresa(Empresa *e)
{
    Lista *fila = NULL;
    readLista(&fila);
    Taxi t;
    int opcao;
    do
    {
        system("cls");
        printf("========   Gestao de Taxis   ========\n");
        printf(" \n");
        printf(" 1 - Adicionar taxi \n");
        printf(" 2 - Listar todos os taxis \n");
        printf(" 3 - Procurar taxi pelo numero\n");
        printf(" 4 - Imprimir viagem/s mais cara/s de um taxi\n");
        printf(" 5 - Editar taxi\n");
        printf(" 6 - Eliminar taxi\n");
        printf(" 7 - Recuperar taxi\n");
        printf("---------------------------------------------\n");
        printf(" \n");
        printf(" 8 - Guardar\n");
        printf(" 0 - Sair / Guardar\n");
        printf("Introduza a opcao pretendida: ");
        scanf("%d", &opcao);
        printf("\n");
        switch (opcao)
        {
        case 0:
            save(*e);
            break;
        case 1:
            acrestentaTaxi(e, criarTaxi());
            system("PAUSE");
            break;
        case 2:
            imprimeEmpresa(e);
            system("PAUSE");
            break;
        case 3:
            procuraTaxi(e, fila);
            system("PAUSE");
            break;
        case 4:
            procuraTaxiViagensMaisCara(e, fila);
            system("PAUSE");
            break;
        case 5:
            alterarTaxiEmpresa(e, t);
            system("PAUSE");
            break;
        case 6:
            eliminarTaxiEmpresa(e, t);
            system("PAUSE");
            break;
        case 7:
            recuperarTaxiEmpresa(e, t);
            system("PAUSE");
            break;
        case 8:
            save(*e);
            system("PAUSE");
            break;
        default:
            printf("Opção invalida\n");
            break;
        }
    } while (opcao != 0);
}

void menuViagens(Viagem *viagem)
{
    Lista *fila = NULL;
    readLista(&fila);
    int opcao;
    do
    {
        system("cls");
        contarViagens(fila);
        printf("========   Gestao de Viagens   ========\n");
        printf(" \n");
        printf(" 1 - Adicionar viagem\n");
        printf(" 2 - Listar todas as viagens\n");
        printf(" 3 - Gestao financeira de todas as viagens\n");
        printf(" 4 - Procurar viagem pela referencia\n");
        printf(" 5 - Eliminar viagem pela referencia\n");
        printf(" 6 - Eliminar viagens feitas pelo taxi\n");
        printf(" 7 - Recuperar viagem pela referencia\n");
        printf(" 8 - Recuperar viagens feitas pelo taxi\n");
        printf("-----------------------------------------------------\n");
        printf(" \n");
        printf("========   Gestao de Viagens Locais  ========\n");
        printf(" \n");
        printf(" 9 - Listar viagens locais\n");
        printf(" 10 - Gestao financeira das viagens locais\n");
        printf("-----------------------------------------------------\n");
        printf(" \n");
        printf("========   Gestao de Viagens Nacionais  ========\n");
        printf(" \n");
        printf(" 11 - Listar viagens nacionais\n");
        printf(" 12 - Gestao financeira das viagens nacionais\n");
        printf("-----------------------------------------------------\n");
        printf(" \n");
        printf("========   Gestao de Viagens Internacionais  ========\n");
        printf(" \n");
        printf(" 13 - Listar viagens internacionais\n");
        printf(" 14 - Gestao financeira das viagens internacionais\n");
        printf("-----------------------------------------------------\n");
        printf(" \n");
        printf(" 15- Guardar\n");
        printf(" 0 - Sair / Guardar\n");
        printf("Introduza a opcao pretendida: ");
        scanf("%d", &opcao);
        printf("\n");
        switch (opcao)
        {
        case 0:
            saveLista(fila);
            break;
        case 1:
            if (qttaxi == 0)
            {
                printf("Impossivel criar viagem pois ainda nao existem taxis\n");
            }
            else
            {
                criarViagem(&fila);
            }
            system("PAUSE");
            break;
        case 2:
            imprimirListaViagens(fila);
            system("PAUSE");
            break;
        case 3:
            gestaoFinanceiraViagens(fila);
            system("PAUSE");
            break;
        case 4:
            procurarViagensRef(fila);
            system("PAUSE");
            break;
        case 5:
            eliminarViagemRef(fila);
            system("PAUSE");
            break;
        case 6:
            eliminarViagemTaxi(fila);
            system("PAUSE");
            break;
        case 7:
            recuperarViagemRef(fila);
            system("PAUSE");
            break;
        case 8:
            recuperarViagemTaxi(fila);
            system("PAUSE");
            break;
        case 9:
            imprimirListaViagensLocais(fila);
            system("PAUSE");
            break;
        case 10:
            gestaoFinanceiraViagensLocal(fila);
            system("PAUSE");
            break;
        case 11:
            imprimirListaViagensNacional(fila);
            system("PAUSE");
            break;
        case 12:
            gestaoFinanceiraViagensNacional(fila);
            system("PAUSE");
            break;
        case 13:
            imprimirListaViagensInternacionais(fila);
            system("PAUSE");
            break;
        case 14:
            gestaoFinanceiraViagensInternacional(fila);
            system("PAUSE");
            break;
        case 15:
            saveLista(fila);
            system("PAUSE");
            break;
        default:
            printf("Opcao invalida\n");
            break;
        }
    } while (opcao != 0);
}