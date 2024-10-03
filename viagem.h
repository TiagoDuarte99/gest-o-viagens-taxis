extern int ref1;
extern int qttaxi;

typedef enum eTipoviagem
{
    Tipoviagem_Local = 1,
    Tipoviagem_Nacional = 2,
    Tipoviagem_Internacional = 3
} Tviagem;

typedef struct sViagem
{
    int ref;
    float precoViagem;
    float precoKm;
    int taxi;
    float kms;
    int ativo;
    Tviagem tipViagem;
}Viagem;

typedef struct lista{
    Viagem viagem;
    struct lista * proximo;
}Lista;

Viagem criarViagem();

void contarViagens(Lista *fila);

void imprimeViagem(Viagem viagem);

void inserirViagemnaLista(Lista **fila, Viagem via);

void imprimirListaViagens(Lista *fila);

void gestaoFinanceiraViagens(Lista *head);

void procurarViagensRef(Lista *fila);

void imprimirListaViagensLocais(Lista *fila);

void gestaoFinanceiraViagensLocal(Lista *head);

void imprimirListaViagensNacional(Lista *fila);

void gestaoFinanceiraViagensNacional(Lista *head);

void imprimirListaViagensInternacionais(Lista *fila);

void gestaoFinanceiraViagensInternacional(Lista *head);

void eliminarViagemRef(Lista *fila);

void eliminarViagemTaxi(Lista *fila);

void recuperarViagemRef(Lista *fila);

void recuperarViagemTaxi(Lista *fila);

void saveLista(Lista * fila);

void readLista(Lista ** fila);
