#include "tPlaylist.h"
#include "tMusica.h"
#include "tListMsc.h"
#include<stdlib.h>
#include<stdio.h>
#include<string.h>


struct tPlaylist{
  int indice;
  char *nome;
  int numMax;
  int qtdMsc;
  int *musicas;
};

/**
 * @brief Funcao que aloca um struct de playlist no espaco de memoria;
 * 
 * @return tPlaylist_pt 
 */

tPlaylist_pt AlocaPlaylist(){

  tPlaylist_pt playlist = (tPlaylist_pt)malloc(sizeof(tPlaylist));
  playlist->musicas = (int*) malloc(sizeof(int)*100);
  playlist->nome = (char*)malloc(sizeof(char)*100);

  return playlist;
  
}

tPlaylist_pt *AlocaConjuntoPlaylists(){

  tPlaylist_pt *listaPlay =(tPlaylist_pt*) malloc(sizeof(tPlaylist)*100);
  
  return listaPlay;
}

/**
 * @brief 
 * 
 * @param playlist Funcao para criar uma playlist e inicializar seus atributos; 
 * @param indice 
 * @param nome 
 */

void CriaPlaylist(tPlaylist_pt playlist,int indice,char* nome){
  playlist->indice = indice;
  strcpy(playlist->nome,nome);
  playlist->numMax=100;
  playlist->qtdMsc=0;
}

/**
 * @brief Adiciona um inteiro, que representa o indice de uma musica, no vetor de musicas da playlist;
 * 
 * @param playlist 
 * @param indiceMsc 
 */

void AddMusicaNaPlaylist(tPlaylist_pt playlist, int indiceMsc){
  playlist->musicas[playlist->qtdMsc] = indiceMsc;
  playlist->qtdMsc++;
}

/**
 * @brief Funcao que imprime alguns dados de todas as playlists;
 * 
 * @param playlist 
 */

void ListarPlaylist(tPlaylist_pt playlist){

  printf("nome: %s",playlist->nome);
  printf("indice: %d\n", playlist->indice);
  printf("Quantidade de musicas: %d\n", playlist->qtdMsc);

  printf("\n");  
}

/**
 * @brief Funcao que imprime os dados de uma unica playlist;
 * 
 * @param playlist 
 * @param listaMsc 
 */

void ListarUmaPlaylist(tPlaylist_pt playlist, tListMsc_pt listaMsc){
  
   printf("\n");
  printf("O nome da playlist e: %s\n",playlist->nome);
  printf("Nome das musicas contidas nela:\n\n");
  for(int i=0; i < playlist->qtdMsc; i++){
    printf("%s\n", RetornaNomeMscLista(listaMsc, playlist->musicas[i]));
  }
  printf("\n");  
}

/**
 * @brief Funcao que retorna a media de 'danceability' de todas as musicas da playlist;
 * 
 * @param playlist 
 * @param listaMsc 
 * @return float 
 */

float MediaDanceability(tPlaylist_pt playlist, tListMsc_pt listaMsc){

  float mediaDanceability = 0.0;
  
  for(int i=0; i < playlist->qtdMsc; i++){
    mediaDanceability += RetornaDancabilidade(RetornaPropriedades(RetornaMusicaLista(listaMsc, playlist->musicas[i])));
  }

  mediaDanceability /= playlist->qtdMsc;
  
  return mediaDanceability;
}

/**
 * @brief Funcao que retorna a media de 'energy' de todas as musicas da playlist;
 * 
 * @param playlist 
 * @param listMsc 
 * @return float 
 */

float MediaEnergy(tPlaylist_pt playlist, tListMsc_pt listMsc){

  float mediaEnergy=0.0;
  
  for(int i=0; i < playlist->qtdMsc; i++){
    mediaEnergy += RetornaEnergia(RetornaPropriedades(RetornaMusicaLista(listMsc, playlist->musicas[i])));
  }

  mediaEnergy /= playlist->qtdMsc; 
  
  return mediaEnergy;
}

/**
 * @brief Funcao que retorna a media de 'key' de todas as musicas da playlist;
 * 
 * @param playlist 
 * @param listaMsc 
 * @return float 
 */

float MediaKey(tPlaylist_pt playlist, tListMsc_pt listaMsc){

  float mediaKey = 0.0;

  for(int i=0; i < playlist->qtdMsc; i++){
    mediaKey += RetornaKey(RetornaPropriedades(RetornaMusicaLista(listaMsc, playlist->musicas[i])));
  }
  
  mediaKey /= playlist->qtdMsc;
  
  return mediaKey;
}

/**
 * @brief Funcao que retorna a media de 'loudness' de todas as musicas da playlist;
 * 
 * @param playlist 
 * @param listaMsc 
 * @return float 
 */

float MediaLoudness(tPlaylist_pt playlist, tListMsc_pt listaMsc){

  float mediaLoudness =0.0;

  for(int i=0; i < playlist->qtdMsc; i++){
    mediaLoudness += RetornaLoudness(RetornaPropriedades(RetornaMusicaLista(listaMsc, playlist->musicas[i])));
  }
  
  mediaLoudness /= playlist->qtdMsc;
  
  return mediaLoudness;
};

/**
 * @brief Funcao que retorna a media de 'mode' de todas as musicas da playlist;
 * 
 * @param playlist 
 * @param listaMsc 
 * @return float 
 */

float MediaMode(tPlaylist_pt playlist, tListMsc_pt listaMsc){

  float mediaMode = 0.0;

  for(int i=0; i < playlist->qtdMsc; i++){
    mediaMode += RetornaMode(RetornaPropriedades(RetornaMusicaLista(listaMsc, playlist->musicas[i])));
  }
  
  mediaMode /= playlist->qtdMsc;
  
  return mediaMode;
}

/**
 * @brief Funcao que retorna a media de 'speechiness' de todas as musicas da playlist;
 * 
 * @param playlist 
 * @param listaMsc 
 * @return float 
 */

float MediaSpeechiness(tPlaylist_pt playlist, tListMsc_pt listaMsc){

  float mediaSpeechiness = 0.0;

  for(int i=0; i < playlist->qtdMsc; i++){
    mediaSpeechiness += RetornaSpeechiness(RetornaPropriedades(RetornaMusicaLista(listaMsc, playlist->musicas[i])));
  }
  
  mediaSpeechiness /= playlist->qtdMsc;
  
  return mediaSpeechiness;
}

/**
 * @brief Funcao que retorna a media de 'acousticness' de todas as musicas da playlist;
 * 
 * @param playlist 
 * @param listaMsc 
 * @return float 
 */

float MediaAcousticness(tPlaylist_pt playlist, tListMsc_pt listaMsc){

  float mediaAcousticness =0.0;

  for(int i=0; i < playlist->qtdMsc; i++){
    mediaAcousticness += RetornaAcousticness(RetornaPropriedades(RetornaMusicaLista(listaMsc, playlist->musicas[i])));
  }
  mediaAcousticness /= playlist->qtdMsc;
  
  return mediaAcousticness;
}

/**
 * @brief Funcao que retorna a media de 'instrumentalness' de todas as musicas da playlist;
 * 
 * @param playlist 
 * @param listaMsc 
 * @return float 
 */

float MediaInstrumentalness(tPlaylist_pt playlist, tListMsc_pt listaMsc){

  float mediaInstrumentalness=0.0;

  for(int i=0; i < playlist->qtdMsc; i++){
    mediaInstrumentalness += RetornaInstrumentalness(RetornaPropriedades(RetornaMusicaLista(listaMsc, playlist->musicas[i])));
  }
  mediaInstrumentalness /= playlist->qtdMsc;
  
  return mediaInstrumentalness;
}

/**
 * @brief Funcao que retorna a media de 'liveness' de todas as musicas da playlist;
 * 
 * @param playlist 
 * @param listaMsc 
 * @return float 
 */

float MediaLiveness(tPlaylist_pt playlist, tListMsc_pt listaMsc){

  float mediaLiveness = 0.0;

  for(int i=0; i < playlist->qtdMsc; i++){
    mediaLiveness += RetornaLiveness(RetornaPropriedades(RetornaMusicaLista(listaMsc, playlist->musicas[i])));
  }
  
  mediaLiveness /= playlist->qtdMsc;
  
  return mediaLiveness;
}

/**
 * @brief Funcao que retorna a media de 'valence' de todas as musicas da playlist;
 * 
 * @param playlist 
 * @param listaMsc 
 * @return float 
 */

float MediaValence(tPlaylist_pt playlist, tListMsc_pt listaMsc){

  float mediaValence = 0.0;

  for(int i=0; i < playlist->qtdMsc; i++){
    mediaValence += RetornaValence(RetornaPropriedades(RetornaMusicaLista(listaMsc, playlist->musicas[i])));
  }
  
  mediaValence /= playlist->qtdMsc;
  
  return mediaValence;
}

/**
 * @brief Funcao que retorna a media de 'tempo' de todas as musicas da playlist;
 * 
 * @param playlist 
 * @param listaMsc 
 * @return float 
 */

float MediaTempo(tPlaylist_pt playlist, tListMsc_pt listaMsc){
  float mediaTempo = 0.0;

  for(int i=0; i < playlist->qtdMsc; i++){
    mediaTempo += RetornaTempo(RetornaPropriedades(RetornaMusicaLista(listaMsc, playlist->musicas[i])));
  }
  
  mediaTempo /= playlist->qtdMsc;
  
  return mediaTempo;
}

/**
 * @brief Funcao que retorna a media de 'time_signature' de todas as musicas da playlist;
 * 
 * @param playlist 
 * @param listaMsc 
 * @return float 
 */

float MediaTime_signature(tPlaylist_pt playlist, tListMsc_pt listaMsc){
  
  float mediaTime_signature=0.0;

  for(int i=0; i < playlist->qtdMsc; i++){
    mediaTime_signature += RetornaTime_signature(RetornaPropriedades(RetornaMusicaLista(listaMsc, playlist->musicas[i])));
  }
  mediaTime_signature /= playlist->qtdMsc;
  
  return mediaTime_signature;
}

/**
 * @brief Une todas as medias anteriores e coloca em um unico vetor;
 * 
 * @param playlist 
 * @param listaMsc 
 * @return float* 
 */

float *CriaVetorMedias(tPlaylist_pt playlist, tListMsc_pt listaMsc){

  float *medias =(float*)malloc(sizeof(float)*12);

  medias[0] = MediaDanceability(playlist, listaMsc);
  medias[1] = MediaEnergy(playlist, listaMsc);
  medias[2] = MediaKey(playlist, listaMsc);
  medias[3] = MediaLoudness(playlist, listaMsc);
  medias[4] = MediaMode(playlist, listaMsc);
  medias[5] = MediaSpeechiness(playlist, listaMsc);
  medias[6] = MediaAcousticness(playlist, listaMsc);
  medias[7] = MediaInstrumentalness(playlist, listaMsc);
  medias[8] = MediaLiveness(playlist, listaMsc);
  medias[9] = MediaValence(playlist, listaMsc);
  medias[10] = MediaTempo(playlist, listaMsc);
  medias[11] = MediaTime_signature(playlist, listaMsc);
 
  return medias;
}

/**
 * @brief Libera o espaco de memoria alocado por uma playlist
 * 
 * @param playlist 
 */

void LiberaPlaylist(tPlaylist_pt playlist){

  if(playlist != NULL){
    free(playlist->nome);
    free(playlist->musicas);
    free(playlist);
    playlist = NULL;
  }
}

/**
 * @brief Retorna o vetor com os idices das musicas contidas em uma playlist;
 * 
 * @param playlist 
 * @return int* 
 */

int *RetornaVetorMscPlaylist(tPlaylist_pt playlist){
  return playlist->musicas;
}

/**
 * @brief Retorna o numeros de musicas contidas em uma playlist;
 * 
 * @param playlist 
 * @return int 
 */

int RetornaNumMscPlaylist(tPlaylist_pt playlist){
  return playlist->qtdMsc;
}

void ImprimePlaylistBinario(tPlaylist_pt play,FILE* arquivo){

  fwrite(play->nome,sizeof(char),strlen(play->nome),arquivo);
  fwrite(&play->indice,sizeof(int),1,arquivo);
  fwrite(play->musicas,sizeof(tMusica_pt),play->qtdMsc,arquivo);
  fwrite(&play->numMax, sizeof(int),1,arquivo);
  fwrite(&play->qtdMsc,sizeof(int),1,arquivo);
  

}

int RetornaUmIndicerMscPlaylist(tPlaylist_pt playlist, int i){
  return playlist->musicas[i];
}


