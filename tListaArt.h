/*{
    tArtista ** lista;
    int numArtista;
    int max_size;
};

la->lista =(tArtista**) malloc(sizeof(tArtista*)*INITIAL_SIZE);
tListaArtista * la = malloc(sizeof(tListaArtista));
*/

#ifndef _TLISTAART_H_
#define _TLISTAART_H_
#include "tArtista.h"

typedef struct tListaArt tListaArt;

typedef tListaArt* tListaArt_pt;

tListaArt_pt AlocaListaArt();
void InicializaListaArt(tListaArt_pt);
void AddArtistaLista(tListaArt_pt, tArtista_pt);
void ImprimeLista(tListaArt_pt, int);
void FazRealloc(tListaArt_pt);
void LiberaListaArtista(tListaArt_pt, int);
tListaArt_pt LeECriaListaArt(FILE*, char*);
tArtista_pt RetornaArtistas(tListaArt_pt, int);
int RetornaNumArtista(tListaArt_pt);
char *RetornaIdLista(tListaArt_pt, int);

#endif