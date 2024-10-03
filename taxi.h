#include "viagem.h"

extern int qttaxi;

#define MAX_matricula 10
#define MAX_nome 100

typedef struct sTaxi
{
    int numero;
    char matricula[MAX_matricula];
    char marca[MAX_nome];
    char modelo[MAX_nome];
    int mesInspecao;
    int ativo;
} Taxi;

Taxi criarTaxi();

void imprimeTaxiInf(Taxi t);

void avisarInspecao(Taxi t);