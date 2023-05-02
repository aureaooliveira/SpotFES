#ifndef _TARTISTA_H_
#define _TARTISTA_H_
#include <stdio.h>

typedef struct tArtista tArtista;
typedef tArtista* tArtista_pt;

tArtista_pt alocaArtista();
tArtista_pt *AlocaListaArtista(int);
void criaArtista(tArtista_pt, char*, int);
void imprimeArtista(tArtista_pt);
void liberaArtista(tArtista_pt);
void criaArtistaDesconhecido(tArtista_pt, char*);
void NomeiaArtistaDesconhecido(tArtista_pt,char*);
void ImprimeArtistaDesconhecido(tArtista_pt);
char *RetornaId(tArtista_pt);
char *RetornaNomeArt(tArtista_pt);
int RetornaIndiceArt(tArtista_pt);

#endif