#include "taxi.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

Taxi criarTaxi()
{
    system("cls");
    Taxi t;
    getchar();
    printf("Introduza a matricula do taxi (00-AA-00): ");
    fgets(t.matricula, MAX_matricula, stdin);
    fflush(stdin);
    t.matricula[strlen(t.matricula) - 1] = '\0';
    printf("Introduza o Marca (100 caracteres maximo): ");
    fgets(t.marca, MAX_nome, stdin);
    fflush(stdin);
    t.marca[strlen(t.marca) - 1] = '\0';
    printf("Introduza o Modelo (100 caracteres maximo): ");
    fgets(t.modelo, MAX_nome, stdin);
    fflush(stdin);
    t.modelo[strlen(t.modelo) - 1] = '\0';
    printf("Introduza o numero do mes do carro: ");
    scanf("%d", &t.mesInspecao);
    t.numero = qttaxi + 1;
    t.ativo = 1;
    return t;
}

void imprimeTaxiInf(Taxi t)
{
    printf("Taxi n: %d\n\t- Marca: %s\n\t- Modelo: %s\n\t- Matricula: %s\n\t- Mes do carro: %d\n", t.numero, t.marca, t.modelo, t.matricula, t.mesInspecao);
    avisarInspecao(t);
}

void avisarInspecao(Taxi t) {
    time_t tempo;
    struct tm *tempoAgora;

    time(&tempo);
    tempoAgora = localtime(&tempo);

    int mes = tempoAgora->tm_mon + 1;
    if (mes == t.mesInspecao - 1) {
        printf("\tAtencao, a inspecao do taxi esta agendada para o proximo mes.\n");
    }
      if (mes == t.mesInspecao) {
        printf("\tAtencao, a inspecao do taxi e este mes.\n");
    }
    
}