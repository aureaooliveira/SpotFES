#ifndef _TPROPRIEDADES_H_
#define _TPROPRIEDADES_H_
#include "tMusica.h"

typedef struct tPropriedades tPropriedades;
typedef tPropriedades* tPropriedades_pt;

tPropriedades_pt alocaPropriedades();
void ImprimePropriedades(tPropriedades_pt);
tPropriedades_pt CriaPropriedades(FILE*);
float RetornaDancabilidade(tPropriedades_pt);
float RetornaEnergia(tPropriedades_pt);
int RetornaKey(tPropriedades_pt);
float RetornaLoudness(tPropriedades_pt);
int RetornaMode(tPropriedades_pt);
float RetornaSpeechiness(tPropriedades_pt);
float RetornaAcousticness(tPropriedades_pt);
float RetornaInstrumentalness(tPropriedades_pt);
float RetornaLiveness(tPropriedades_pt);
float RetornaValence(tPropriedades_pt );
float RetornaTempo(tPropriedades_pt);
int RetornaTime_signature(tPropriedades_pt);

#endif
