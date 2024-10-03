#include "viagem.h"
#include <stdio.h>
#include <stdlib.h>

Viagem criarViagem(Lista **fila)
{
    system("cls");
    Viagem viagem;
    do
    {
        printf("Introduza o numero do taxi sabendo que existem %d taxi/s: ", qttaxi);
        scanf("%d", &viagem.taxi);
    } while (viagem.taxi > qttaxi || viagem.taxi == 0);
    viagem.ref = ref1 + 1;
    printf("A viagem vai ter a referencia numero: %d\n", viagem.ref);
    do
    {
        printf("1 - Tipo viagem Local, 2 - Tipo viagem Nacional, 3 - Tipo viagem Internacional: \n");
        printf("Introduza Tipo de Viagem: ");
        scanf(" %d", &viagem.tipViagem);
        fflush(NULL);
    } while (viagem.tipViagem != 1 && viagem.tipViagem != 2 && viagem.tipViagem != 3);

    switch (viagem.tipViagem)
    {
    case Tipoviagem_Local:
        viagem.precoKm = 0.47;
        printf("o preco km viagem local e: 0,47 euros \n");
        printf("Introduzir numero de kms: ");
        scanf("%f", &viagem.kms);
        viagem.precoViagem = viagem.kms * viagem.precoKm;
        printf("Preco da viagem: %.2f euros\n", viagem.precoViagem);
        viagem.ativo = 1;
        break;
    case Tipoviagem_Nacional:
        viagem.precoKm = 0.97;
        printf("o preco km viagem local e: 0,97 euros \n");
        printf("Introduzir numero de kms: ");
        scanf("%f", &viagem.kms);
        viagem.precoViagem = viagem.kms * viagem.precoKm;
        printf("Preco da viagem: %.2f euros\n", viagem.precoViagem);
        viagem.ativo = 1;
        break;
    case Tipoviagem_Internacional:
        viagem.precoKm = 1.47;
        printf("o preco km viagem local e: 1,47 euros \n");
        printf("Introduzir numero de kms: ");
        scanf("%f", &viagem.kms);
        viagem.precoViagem = viagem.kms * viagem.precoKm;
        printf("Preco da viagem: %.2f euros\n", viagem.precoViagem);
        viagem.ativo = 1;
        break;
    }
    inserirViagemnaLista(fila, viagem);
}

void contarViagens(Lista *fila)
{
    int qtviagens = 0;
    while (fila != NULL)
    {
        if (fila)
        {
            qtviagens++;
            ref1 = qtviagens;
        }
        fila = fila->proximo;
    }
}

void imprimeViagem(Viagem viagem)
{
    printf("Viagem: \n\t- Referencia: %d\n\t- preco km: %.2f euros\n\t- Preco da viagem: %.2f euros\n\t- Taxi numero: %d\n\t- Kms feitos na viagem: %.2fkms\n\t- Tipo viagem: %d", viagem.ref, viagem.precoKm, viagem.precoViagem, viagem.taxi, viagem.kms, viagem.tipViagem);
}

void inserirViagemnaLista(Lista **fila, Viagem via)
{
    Lista *aux, *novo = malloc(sizeof(Lista));

    if (novo)
    {
        novo->viagem = via;
        novo->proximo = NULL;
        if (*fila == NULL)
        {
            *fila = novo;
        }
        else
        {
            aux = *fila;
            while (aux->proximo)
                aux = aux->proximo;
            aux->proximo = novo;
        }
    }
    else
    {
        printf("\nErro ao alocar memoria.\n");
    }
}

void imprimirListaViagens(Lista *fila)
{
    system("cls");
    if (fila == NULL)
    {
        printf("Ainda nao existem viagens. \n");
    }
    else
    {
        printf("\t-------Lista Viagens-------\n\t");
        while (fila)
        {
            if (fila->viagem.ativo != 0)
            {
                imprimeViagem(fila->viagem);
                printf("\n\t------------------------------\n\t");
            }
            fila = fila->proximo;
        }
        printf("\n\t-------Fim da Lista-------\n\t");
    }
}

void gestaoFinanceiraViagens(Lista *head)
{
    system("cls");
    int opcao;
    float somaViagens = 0;
    float ivaViagens = 0;
    float mediaViagens = 0;
    int qtViagens = 0;
    Lista *fila = head;
    while (fila != NULL)
    {
        if (fila)
        {
            if (fila->viagem.ativo != 0)
            {
                somaViagens += fila->viagem.precoViagem;
                qtViagens++;
                ivaViagens = somaViagens * 0.23;
            }
        }
        mediaViagens = somaViagens / qtViagens;
        fila = fila->proximo;
    }
    do
    {
        system("cls");
        printf(" \n");
        printf("============  Gestao financeita Viagens  ============\n");
        printf(" \n");
        printf("1 - Valor total ganho em viagens\n");
        printf("2 - Quantidade de viagens efectuadas ate ao momento\n");
        printf("3 - Preco medio das viagens\n");
        printf("4 - O total do IVA a pagar ao Estado\n");
        printf("5 - Viagens com o preco abaixo da media\n");
        printf("6 - Viagens com o preco acima da media\n");
        printf("0 - Sair\n");
        printf("Introduza a opcao pretendida: ");
        scanf("%d", &opcao);
        printf("\n");
        switch (opcao)
        {
        case 0:
            break;
        case 1:
            printf("Valor total ganho em viagens: %.2feuros\n", somaViagens);
            system("PAUSE");
            break;
        case 2:
            printf("Quantidade de viagens efectuadas ate ao momento: %d\n", qtViagens);
            system("PAUSE");
            break;
        case 3:
            printf("Preco medio das viagens: %.2f euros\n", mediaViagens);
            system("PAUSE");
            break;
        case 4:
            printf("O total do IVA a pagar ao Estado: %.2f euros\n", ivaViagens);
            system("PAUSE");
            break;
        case 5:
            system("cls");
            fila = head;
            int qtViagensBaratas = 0;
            printf("\t-------Lista viagens mais baratas-------\n\t");
            while (fila)
            {
                if (mediaViagens > fila->viagem.precoViagem)
                {
                    if (fila->viagem.ativo != 0)
                    {
                        imprimeViagem(fila->viagem);
                        qtViagensBaratas++;
                        printf("\n\t------------------------------\n\t");
                    }
                }
                fila = fila->proximo;
            }
            printf("\n\tPreco medio de viagens: %.2f \n\t", mediaViagens);
            printf("\n\tNumero de viagens com o preco abaixo da medias: %d\n\t", qtViagensBaratas);
            printf("\n\t-------Fim da Lista-------\n\t");
            system("PAUSE");
            break;
        case 6:
            system("cls");
            fila = head;
            int qtViagensCaras = 0;
            printf("\t-------Lista viagens mais caras-------\n\t");
            while (fila)
            {
                if (mediaViagens < fila->viagem.precoViagem)
                {
                    if (fila->viagem.ativo != 0)
                    {
                        imprimeViagem(fila->viagem);
                        qtViagensCaras++;
                        printf("\n\t------------------------------\n\t");
                    }
                }
                fila = fila->proximo;
            }
            printf("\n\tPreco medio de viagens: %.2f \n\t", mediaViagens);
            printf("\n\tNumero de viagens com o preco acima da media: %d\n\t", qtViagensCaras);
            printf("\n\t-------Fim da Lista-------\n\t");
            system("PAUSE");
            break;
        default:
            printf("Opção invalida\n");
            break;
        }
    } while (opcao != 0);
}

void procurarViagensRef(Lista *fila)
{
    system("cls");
    int n;
    int indice = 0;
    printf("Insira a referencia da viagem que pretende encontrar: ");
    scanf("%d", &n);
    printf("\t---------- Viagem ----------\n\t");
    while (fila)
    {
        if (n == fila->viagem.ref)
        {
            if (fila->viagem.ativo != 0)
            {
                imprimeViagem(fila->viagem);
                printf("\n\t------------------------------\n\t");
                indice += 1;
            }
        }
        fila = fila->proximo;
    }
    if (indice == 0)
    {
        printf("Viagem nao encontrada.\n");
    }
}

void imprimirListaViagensLocais(Lista *fila)
{
    system("cls");
    printf("\t-------Lista viagens Locais-------\n\t");
    while (fila)
    {
        if (fila->viagem.tipViagem == 1)
        {
            if (fila->viagem.ativo != 0)
            {
                imprimeViagem(fila->viagem);
                printf("\n\t------------------------------\n\t");
            }
        }
        fila = fila->proximo;
    }
    printf("\n\t-------Fim da Lista-------\n\t");
}

void gestaoFinanceiraViagensLocal(Lista *head)
{
    system("cls");
    Lista *fila = head;
    int opcao;
    int qtViagensL = 0;
    float somaViagensL = 0;
    float mediaViagensL = 0;
    float ivaViagensL = 0;
    while (fila != NULL)
    {
        if (fila->viagem.tipViagem == 1)
        {
            if (fila->viagem.ativo != 0)
            {
                somaViagensL += fila->viagem.precoViagem;
                qtViagensL++;
                mediaViagensL = somaViagensL / qtViagensL;
                ivaViagensL = somaViagensL * 0.23;
            }
        }
        fila = fila->proximo;
    }
    do
    {
        system("cls");
        printf(" \n");
        printf("============  Gestao financeita Viagens Locais  ============\n");
        printf(" \n");
        printf("1 - Valor total ganho em viagens\n");
        printf("2 - Quantidade de viagens efectuadas ate ao momento\n");
        printf("3 - Preco medio das viagens\n");
        printf("4 - O total do IVA a pagar ao Estado\n");
        printf("5 - Viagens com o preco abaixo da media\n");
        printf("6 - Viagens com o preco acima da media\n");
        printf("0 - Sair\n");
        printf("Introduza a opcao pretendida: ");
        scanf("%d", &opcao);
        printf("\n");
        switch (opcao)
        {
        case 0:
            break;
        case 1:
            printf("Valor total ganho em viagens: %.2feuros\n", somaViagensL);
            system("PAUSE");
            break;
        case 2:
            printf("Quantidade de viagens efectuadas ate ao momento: %d\n", qtViagensL);
            system("PAUSE");
            break;
        case 3:
            printf("Preco medio das viagens: %.2f euros\n", mediaViagensL);
            system("PAUSE");
            break;
        case 4:
            printf("O total do IVA a pagar ao Estado: %.2f euros\n", ivaViagensL);
            system("PAUSE");
            break;
        case 5:
            system("cls");
            fila = head;
            int qtViagensBaratas = 0;
            printf("\t-------Lista viagens mais baratas-------\n\t");

            while (fila)
            {
                if (mediaViagensL > fila->viagem.precoViagem)
                {
                    if (fila->viagem.tipViagem == 1)
                    {
                        if (fila->viagem.ativo != 0)
                        {
                            imprimeViagem(fila->viagem);
                            qtViagensBaratas++;
                            printf("\n\t------------------------------\n\t");
                        }
                    }
                }
                fila = fila->proximo;
            }

            printf("\n\tPreco medio de viagens: %.2f \n\t", mediaViagensL);
            printf("\n\tNumero de viagens com o preco abaixo da media: %d\n\t", qtViagensBaratas);
            printf("\n\t-------Fim da Lista-------\n\t");
            system("PAUSE");
            break;
        case 6:
            system("cls");
            fila = head;
            int qtViagensCaras = 0;
            printf("\t-------Lista viagens mais caras-------\n\t");
            while (fila)
            {
                if (mediaViagensL < fila->viagem.precoViagem)
                {
                    if (fila->viagem.tipViagem == 1)
                    {
                        if (fila->viagem.ativo != 0)
                        {
                            imprimeViagem(fila->viagem);
                            qtViagensCaras++;
                            printf("\n\t------------------------------\n\t");
                        }
                    }
                }
                fila = fila->proximo;
            }
            printf("\n\tPreco medio de viagens: %.2f \n\t", mediaViagensL);
            printf("\n\tNumero de viagens com o preco acima da media: %d\n\t", qtViagensCaras);
            printf("\n\t-------Fim da Lista-------\n\t");
            system("PAUSE");
            break;
        default:
            printf("Opção invalida\n");
            break;
        }
    } while (opcao != 0);
}

void imprimirListaViagensNacional(Lista *fila)
{
    system("cls");
    printf("\t-------Lista viagens Nacionais-------\n\t");
    while (fila)
    {
        if (fila->viagem.tipViagem == 2)
        {
            if (fila->viagem.ativo != 0)
            {
                imprimeViagem(fila->viagem);
                printf("\n\t------------------------------\n\t");
            }
        }
        fila = fila->proximo;
    }
    printf("\n\t-------Fim da Lista-------\n\t");
}

void gestaoFinanceiraViagensNacional(Lista *head)
{
    system("cls");
    Lista *fila = head;
    int opcao;
    int qtViagensN = 0;
    float somaViagensN = 0;
    float mediaViagensN = 0;
    float ivaViagensN = 0;
    while (fila != NULL)
    {
        if (fila->viagem.tipViagem == 2)
        {
            if (fila->viagem.ativo != 0)
            {
                somaViagensN += fila->viagem.precoViagem;
                qtViagensN++;
                mediaViagensN = somaViagensN / qtViagensN;
                ivaViagensN = somaViagensN * 0.23;
            }
        }
        fila = fila->proximo;
    }
    do
    {
        system("cls");
        printf(" \n");
        printf("============  Gestao financeita Viagens Nacionais  ============\n");
        printf(" \n");
        printf("1 - Valor total ganho em viagens\n");
        printf("2 - Quantidade de viagens efectuadas ate ao momento\n");
        printf("3 - Preco medio das viagens\n");
        printf("4 - O total do IVA a pagar ao Estado\n");
        printf("5 - Viagens com o preco abaixo da media\n");
        printf("6 - Viagens com o preco acima da media\n");
        printf("0 - Sair\n");
        printf("Introduza a opcao pretendida: ");
        scanf("%d", &opcao);
        printf("\n");
        switch (opcao)
        {
        case 0:
            break;
        case 1:
            printf("Valor total ganho em viagens: %.2feuros\n", somaViagensN);
            system("PAUSE");
            break;
        case 2:
            printf("Quantidade de viagens efectuadas ate ao momento: %d\n", qtViagensN);
            system("PAUSE");
            break;
        case 3:
            printf("Preco medio das viagens: %.2f euros\n", mediaViagensN);
            system("PAUSE");
            break;
        case 4:
            printf("O total do IVA a pagar ao Estado: %.2f euros\n", ivaViagensN);
            system("PAUSE");
            break;
        case 5:
            system("cls");
            fila = head;
            int qtViagensBaratas = 0;
            printf("\t-------Lista viagens mais baratas-------\n\t");

            while (fila)
            {
                if (fila->viagem.tipViagem == 2)
                {
                    if (mediaViagensN > fila->viagem.precoViagem)
                    {
                        if (fila->viagem.ativo != 0)
                        {
                            imprimeViagem(fila->viagem);
                            qtViagensBaratas++;
                            printf("\n\t------------------------------\n\t");
                        }
                    }
                }
                fila = fila->proximo;
            }
            printf("\n\tPreço medio de viagens: %.2f \n\t", mediaViagensN);
            printf("\n\tNumero de viagens com o preco abaixo da media: %d\n\t", qtViagensBaratas);
            printf("\n\t-------Fim da Lista-------\n\t");
            system("PAUSE");
            break;
        case 6:
            system("cls");
            fila = head;
            int qtViagensCaras = 0;
            printf("\t-------Lista viagens mais caras-------\n\t");

            while (fila)
            {
                if (fila->viagem.tipViagem == 2)
                {
                    if (mediaViagensN < fila->viagem.precoViagem)
                    {
                        if (fila->viagem.ativo != 0)
                        {
                            imprimeViagem(fila->viagem);
                            qtViagensCaras++;
                            printf("\n\t------------------------------\n\t");
                        }
                    }
                }
                fila = fila->proximo;
            }
            printf("\n\tPreço medio de viagens: %.2f \n\t", mediaViagensN);
            printf("\n\tNumero de viagens com o preco acima da media: %d\n\t", qtViagensCaras);
            printf("\n\t-------Fim da Lista-------\n\t");
            system("PAUSE");
            break;
        default:
            printf("Opção invalida\n");
            break;
        }
    } while (opcao != 0);
}

void imprimirListaViagensInternacionais(Lista *fila)
{
    system("cls");
    printf("\t-------Lista viagens Internacionais-------\n\t");
    while (fila)
    {
        if (fila->viagem.tipViagem == 3)
        {
            if (fila->viagem.ativo != 0)
            {
                imprimeViagem(fila->viagem);
                printf("\n\t------------------------------\n\t");
            }
        }
        fila = fila->proximo;
    }
    printf("\n\t-------Fim da Lista-------\n\t");
}

void gestaoFinanceiraViagensInternacional(Lista *head)
{
    system("cls");
    Lista *fila = head;
    int opcao;
    int qtViagensI = 0;
    float somaViagensI = 0;
    float mediaViagensI = 0;
    float ivaViagensI = 0;
    while (fila != NULL)
    {
        if (fila->viagem.tipViagem == 3)
        {
            if (fila->viagem.ativo != 0)
            {
                somaViagensI += fila->viagem.precoViagem;
                qtViagensI++;
                mediaViagensI = somaViagensI / qtViagensI;
                ivaViagensI = somaViagensI * 0.23;
            }
        }
        fila = fila->proximo;
    }
    do
    {
        system("cls");
        printf(" \n");
        printf("============  Gestao financeita Viagens Internacionais  ============\n");
        printf(" \n");
        printf("1 - Valor total ganho em viagens\n");
        printf("2 - Quantidade de viagens efectuadas ate ao momento\n");
        printf("3 - Preco medio das viagens\n");
        printf("4 - O total do IVA a pagar ao Estado\n");
        printf("5 - Viagens com o preco abaixo da media\n");
        printf("6 - Viagens com o preco acima da media\n");
        printf("0 - Sair\n");
        printf("Introduza a opcao pretendida: ");
        scanf("%d", &opcao);
        printf("\n");
        switch (opcao)
        {
        case 0:
            break;
        case 1:
            printf("Valor total ganho em viagens: %.2feuros\n", somaViagensI);
            system("PAUSE");
            break;
        case 2:
            printf("Quantidade de viagens efectuadas ate ao momento: %d\n", qtViagensI);
            system("PAUSE");
            break;
        case 3:
            printf("Preco medio das viagens: %.2f euros\n", mediaViagensI);
            system("PAUSE");
            break;
        case 4:
            printf("O total do IVA a pagar ao Estado: %.2f euros\n", ivaViagensI);
            system("PAUSE");
            break;
        case 5:
            system("cls");
            fila = head;
            int qtViagensBaratas = 0;
            printf("\t-------Lista viagens mais baratas-------\n\t");

            while (fila)
            {
                if (fila->viagem.tipViagem == 3)
                {
                    if (mediaViagensI > fila->viagem.precoViagem)
                    {
                        if (fila->viagem.ativo != 0)
                        {
                            imprimeViagem(fila->viagem);
                            qtViagensBaratas++;
                            printf("\n\t------------------------------\n\t");
                        }
                    }
                }
                fila = fila->proximo;
            }
            printf("\n\tPreco medio de viagens: %.2f \n\t", mediaViagensI);
            printf("\n\tNumero de viagens com o preco abaixo da media: %d\n\t", qtViagensBaratas);
            printf("\n\t-------Fim da Lista-------\n\t");
            system("PAUSE");
            break;
        case 6:
            system("cls");
            fila = head;
            int qtViagensCaras = 0;
            printf("\t-------Lista viagens mais caras-------\n\t");

            while (fila)
            {
                if (fila->viagem.tipViagem == 3)
                {
                    if (mediaViagensI < fila->viagem.precoViagem)
                    {
                        if (fila->viagem.ativo != 0)
                        {
                            imprimeViagem(fila->viagem);
                            qtViagensCaras++;
                            printf("\n\t------------------------------\n\t");
                        }
                    }
                }
                fila = fila->proximo;
            }
            printf("\n\tPreco medio de viagens: %.2f \n\t", mediaViagensI);
            printf("\n\tNumero de viagens com o preco acima da media: %d\n\t", qtViagensCaras);
            printf("\n\t-------Fim da Lista-------\n\t");
            system("PAUSE");
            break;
        default:
            printf("Opção invalida\n");
            break;
        }
    } while (opcao != 0);
}

void eliminarViagemRef(Lista *fila)
{
    system("cls");
    int n;
    int indice = 0;
    printf("Insira a referencia da viagem que pretende eliminar: ");
    scanf("%d", &n);
    while (fila)
    {
        if (n == fila->viagem.ref)
        {
            if (fila->viagem.ativo == 1)
            {
                fila->viagem.ativo = 0;
                indice += 1;
                printf("Viagem eliminada com sucesso.\n");
            }
        }
        fila = fila->proximo;
    }
    if (indice == 0)
    {
        printf("Viagem nao encontrada.\n");
    }
}

void eliminarViagemTaxi(Lista *fila)
{
    system("cls");
    int n;
    int indice = 0;
    printf("Insira o numero do taxi que pretende eliminar viagens: ");
    scanf("%d", &n);
    if (n > qttaxi || n == 0)
    {
        printf("Taxi nao encontrado.\n");
    }
    else
    {
        while (fila)
        {
            if (n == fila->viagem.taxi)
            {
                if (fila->viagem.ativo == 1)
                {
                    fila->viagem.ativo = 0;
                    indice += 1;
                }
            }
            fila = fila->proximo;
        }

        if (indice == 0)
        {
            printf("O Taxi com o numero %d nao tem viagens.\n", n);
        }
        else
        {
            printf("Viagens do taxi numero %d eliminadas com sucesso.\n", n);
        }
    }
}

void recuperarViagemRef(Lista *fila)
{
    system("cls");
    int n;
    int indice = 0;

    printf("Insira a referencia da viagem que pretende recuperar: ");
    scanf("%d", &n);
    if (n > ref1)
    {
        printf("A viagem com essa referencia nao existe.\n");
    }
    else
    {
        while (fila)
        {
            if (n == fila->viagem.ref)
            {
                if (fila->viagem.ativo == 0)
                {
                    fila->viagem.ativo = 1;
                    indice += 1;
                    printf("Viagem recuperada com sucesso.\n");
                }
            }
            fila = fila->proximo;
        }
        if (indice == 0)
        {
            printf("A viagem ja esta ativa.\n");
        }
    }
}

void recuperarViagemTaxi(Lista *fila)
{
    system("cls");
    int n;
    int indice = 0;
    printf("Insira o numero do taxi que pretende recuperar as viagens: ");
    scanf("%d", &n);
    if (n > qttaxi || n == 0)
    {
        printf("Taxi nao encontrado.\n");
    }
    else
    {
        while (fila)
        {
            if (n == fila->viagem.taxi)
            {
                if (fila->viagem.ativo == 0)
                {
                    fila->viagem.ativo = 1;
                    indice += 1;
                }
            }
            fila = fila->proximo;
        }
        if (indice == 0)
        {
            printf("O Taxi com o numero %d nao tem viagens.\n", n);
        }
        else
        {
            printf("Viagens do taxi numero %d recuperadas com sucesso.\n", n);
        }
    }
}

void saveLista(Lista *fila)
{
    Lista *tmp = fila;
    FILE *f = fopen("viagens.dat", "wb+");
    while (tmp != NULL)
    {
        fwrite(&tmp->viagem, sizeof(Viagem), 1, f);
        tmp = tmp->proximo;
    }
    fclose(f);
}

void readLista(Lista **fila)
{
    FILE *f = fopen("viagens.dat", "rb");
    Viagem viagem;
    while (fread(&viagem, sizeof(Viagem), 1, f) > 0)
    {
        inserirViagemnaLista(fila, viagem);
    }
    fclose(f);
}