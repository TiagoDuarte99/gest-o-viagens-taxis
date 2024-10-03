#include "taxi.h"

#define MAX_taxi 20
typedef struct sEmpresa
{
    Taxi taxi [MAX_taxi];
    int tamanho;
}Empresa;

Empresa criarEmpresa();

void acrestentaTaxi( Empresa *e, Taxi t);

void alterarTaxiEmpresa(Empresa *e, Taxi t);

void imprimeEmpresa(Empresa *e);

void procuraTaxi(Empresa *e, Lista *fila);

void procuraTaxiViagensMaisCara(Empresa *e, Lista *head);

void eliminarTaxiEmpresa(Empresa *e, Taxi t);

void recuperarTaxiEmpresa(Empresa *e, Taxi t);

void save (Empresa e);

Empresa read();