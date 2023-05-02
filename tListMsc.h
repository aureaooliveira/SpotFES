#ifndef _TLISTMSC_H_
#define _TLISTMSC_H_
#include "tMusica.h"

typedef struct tListMsc tListMsc;
typedef tListMsc* tListMsc_pt;

tListMsc_pt AlocaListaMusica();
void InicializaListaMusica(tListMsc_pt);
void AddMusicaLista(tListMsc_pt,tMusica_pt);
tListMsc_pt FazReallocMsc(tListMsc_pt);
void ImprimeListaMusica(tListMsc_pt, int);
void LiberaListaMusica(tListMsc_pt, int);
void BuscarMusica(char[100], tListMsc_pt);
void ListaMsc(tListMsc_pt, int);
void ExecutarMsc(tListMsc_pt, int);
void PoeMusicaXnaPosicaoY(tListMsc_pt,tMusica_pt,int);
float *CalculaDistanciaEuclidiana(float*, tListMsc_pt);
void RecomendaMsc(float*, tListMsc_pt, int);
tListMsc_pt LeECriaListaMsc(FILE*, char*, tListaArt_pt);
tMusica_pt RetornaMusicaLista(tListMsc_pt, int);
char *RetornaNomeMscLista(tListMsc_pt, int);
int RetornaNumMscLista(tListMsc_pt);




#endif