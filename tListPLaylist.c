#include "tListPlaylist.h"
#include "tPlaylist.h"
#include <stdlib.h>
#include <string.h>

struct tListPlaylist {
  tPlaylist_pt *playlists;
  int qtdPLaylists;
  int numMax;
};

/**
 * @brief Aloca o espaco na memoria para um struct de lista de playlists
 * 
 * @return tListPlaylist_pt 
 */

tListPlaylist_pt AlocaListaPlaylist() {
  tListPlaylist_pt playlists = (tListPlaylist_pt)malloc(sizeof(tListPlaylist));
  playlists->playlists = AlocaConjuntoPlaylists();

  return playlists;
}

/**
 * @brief Inicializa os valores da lista
 * 
 * @param listaPlay 
 */

void CriaListaPlaylist(tListPlaylist_pt listaPlay) {
  listaPlay->qtdPLaylists = 0;
  listaPlay->numMax = 100;
}

/**
 * @brief Adiciona uma playlist na lista e contabiliza o numero de playlists
 * 
 * @param listaPlay 
 * @param playlist 
 */

void AddPlaylistNaLista(tListPlaylist_pt listaPlay, tPlaylist_pt playlist) {
  listaPlay->playlists[listaPlay->qtdPLaylists] = playlist;
  listaPlay->qtdPLaylists++;
}

/**
 * @brief adiciona o indice de uma musica em uma playlist contida na lista;
 * 
 * @param listaPlay 
 * @param indiceMsc 
 * @param indice 
 */

void AddMusicaNaListaPlaylist(tListPlaylist_pt listaPlay, int indiceMsc,
                              int indice) {
  AddMusicaNaPlaylist(listaPlay->playlists[indice], indiceMsc);
}

/**
 * @brief Funcao que imprime alguns dados de todas as playlists da lista;
 * 
 * @param listaPlay 
 */

void ImprimeListaPlaylists(tListPlaylist_pt listaPlay) {

  for (int i = 0; i < listaPlay->qtdPLaylists; i++) {
    ListarPlaylist(listaPlay->playlists[i]);
  }
}

/**
 * @brief Funcao que imprime os dados de uma unica playlist da lista;
 * 
 * @param listaPlay 
 * @param indice 
 * @param listaMsc 
 */

void ImprimePlaylist(tListPlaylist_pt listaPlay, int indice,
                     tListMsc_pt listaMsc) {
  ListarUmaPlaylist(listaPlay->playlists[indice], listaMsc);
}

/**
 * @brief Cria o vetor de media de propriedades de uma playlist da lista;
 * 
 * @param listaPlay 
 * @param listaMsc 
 * @param indice 
 * @return float* 
 */

float *CriaVetorMediaLista(tListPlaylist_pt listaPlay, tListMsc_pt listaMsc,
                           int indice) {

  float *medias = CriaVetorMedias(listaPlay->playlists[indice], listaMsc);

  return medias;
}

/**
 * @brief Gera dois arquivos, um contendo as musicas e outros os artistas contidos nas playlists; 
 * 
 * @param arq 
 * @param listaPlay 
 * @param listaMsc 
 */

void GeraArquivo(FILE *arq, tListPlaylist_pt listaPlay, tListMsc_pt listaMsc) {

  int numMscPlay = 0, numMscJaLidas = 0;
  arq = fopen("MusicasContidasEmPlaylist.txt", "w");

  fprintf(arq, "Essas sao as musicas contidas na sua playlist:\n\n");

  for (int i = 0; i < listaPlay->qtdPLaylists; i++) {
    numMscPlay += RetornaNumMscPlaylist(listaPlay->playlists[i]);
  }

  int *vetorMsc = (int *)calloc(numMscPlay, sizeof(int));

  for (int i = 0; i < listaPlay->qtdPLaylists; i++) {
    for (int j = 0; j < RetornaNumMscPlaylist(listaPlay->playlists[i]); j++) {
      vetorMsc[j + numMscJaLidas] =
          RetornaUmIndicerMscPlaylist(listaPlay->playlists[i], j);
    }
    numMscJaLidas += RetornaNumMscPlaylist(listaPlay->playlists[i]);
  }

  for(int i=0;i<numMscPlay;i++){
    printf("%d\n",vetorMsc[i]);
  } 
  



  fclose(arq);

  arq = fopen("ArtistasContidosEmPlaylists.txt", "w");

  fprintf(arq, "Esses sao os artistas contidos na Playlist:\n\n");

  fclose(arq);
}

/**
 * @brief Libera o espaco de memoria de cada playlist da lista e depois da lista;
 * 
 * @param listaPlay 
 */

void LiberaListaPlay(tListPlaylist_pt listaPlay) {

  if (listaPlay != NULL) {
    for (int i = 0; i < listaPlay->qtdPLaylists; i++) {
      LiberaPlaylist(listaPlay->playlists[i]);
    }
    free(listaPlay->playlists);
    free(listaPlay);
    listaPlay = NULL;
  }
}

/*void EscreveArquivoBin(tListPlaylist_pt listaPlay){
  FILE* arquivo = fopen("playlists.dat","wb");

for(int i=0;i<listaPlay->qtdPLaylists;i++){
fwrite(listaPlay->
}
}
  */
