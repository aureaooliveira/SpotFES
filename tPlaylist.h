#ifndef _TPLAYLIST_H_
#define _TPLAYLIST_H_
#include "tListMsc.h"

typedef struct tPlaylist tPlaylist;
typedef tPlaylist* tPlaylist_pt;

tPlaylist_pt AlocaPlaylist();
tPlaylist_pt *AlocaConjuntoPlaylists();
void CriaPlaylist(tPlaylist_pt,int,char*);
void ListarPlaylist(tPlaylist_pt);
void AddMusicaNaPlaylist(tPlaylist_pt, int);
void ListarUmaPlaylist(tPlaylist_pt, tListMsc_pt);
float MediaDanceability(tPlaylist_pt, tListMsc_pt);
float MediaEnergy(tPlaylist_pt, tListMsc_pt);
float MediaKey(tPlaylist_pt, tListMsc_pt);
float MediaLoudness(tPlaylist_pt, tListMsc_pt);
float MediaMode(tPlaylist_pt, tListMsc_pt);
float MediaSpeechiness(tPlaylist_pt, tListMsc_pt);
float MediaAcousticness(tPlaylist_pt, tListMsc_pt);
float MediaInstrumentalness(tPlaylist_pt, tListMsc_pt);
float MediaLiveness(tPlaylist_pt, tListMsc_pt);
float MediaValence(tPlaylist_pt, tListMsc_pt);
float MediaTempo(tPlaylist_pt, tListMsc_pt);
float MediaTime_signature(tPlaylist_pt, tListMsc_pt);
float *CriaVetorMedias(tPlaylist_pt, tListMsc_pt);
void LiberaPlaylist(tPlaylist_pt);
int *RetornaVetorMscPlaylist(tPlaylist_pt);
int RetornaUmIndicerMscPlaylist(tPlaylist_pt, int);
int RetornaNumMscPlaylist(tPlaylist_pt);

#endif