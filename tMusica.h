#ifndef TMUSICA_H_
#define TMUSICA_H_
#include "tArtista.h"
#include "tListaArt.h"
#include "tPropriedades.h"

typedef struct tMusica tMusica;
typedef tMusica* tMusica_pt;

tMusica_pt alocaMusica();
int CriaMusica(tMusica_pt, FILE *, tListaArt_pt, int);
void ImprimeMusica(tMusica_pt);
void LiberaMusica(tMusica_pt);
int RetornaQtdArtista(char*);
tArtista_pt LinkaArtista(char*, tListaArt_pt);
char *RetornaNomeMsc(tMusica_pt);
int RetornaIndiceMsc(tMusica_pt);
char *RetornaIdMsc(tMusica_pt);
void ImprimeArtistasMusica(tMusica_pt, int);
int RetornaQtdArtistasDaMsc(tMusica_pt);


#endif