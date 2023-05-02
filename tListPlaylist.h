#ifndef _TLISTPLAYLIST_
#define _TLISTPLAYLIST_
#include "tPlaylist.h"
#include "tListMsc.h"

typedef struct tListPlaylist tListPlaylist;
typedef tListPlaylist* tListPlaylist_pt;




void CriaPlaylistXnaLista(tListPlaylist_pt,int);
tListPlaylist_pt AlocaListaPlaylist();
void AddPlaylistNaLista(tListPlaylist_pt, tPlaylist_pt);
void AddMusicaNaListaPlaylist(tListPlaylist_pt,int,int);
void CriaListaPlaylist(tListPlaylist_pt);
void ImprimeListaPlaylists(tListPlaylist_pt);
void ImprimePlaylist(tListPlaylist_pt,int, tListMsc_pt);
float *CriaVetorMediaLista(tListPlaylist_pt,tListMsc_pt,int);
void GeraArquivo(FILE*, tListPlaylist_pt, tListMsc_pt);
void LiberaListaPlay(tListPlaylist_pt);

#endif