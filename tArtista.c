#include "tArtista.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct tArtista{
  char id[22];
  int numSeguidores; 
  char *generos;
  char *nome;
  int popularidade;
  int indice;
};

/**
 * @brief Funcao para alocar um struct artista na memoria;
 * 
 * @return tArtista_pt 
 */

tArtista_pt alocaArtista(){

  tArtista_pt artista =(tArtista_pt) malloc(sizeof(tArtista));
  
  return artista;
}

/**
 * @brief Aloca uma lista de artistas que vão estar contidas no struct musica;
 * 
 * @param numArt 
 * @return tArtista_pt* 
 */

tArtista_pt *AlocaListaArtista(int numArt){

  tArtista_pt *listaArtista = (tArtista_pt*) malloc(sizeof(tArtista)*numArt);

  return listaArtista;
}

/**
 * @brief Le as informacoes contidas contidas no arquivo e coloca no struct de artista;
 * 
 * @param artista 
 * @param linha 
 * @param indice 
 */

void criaArtista(tArtista_pt artista, char *linha, int indice){

  char *string =  strtok(linha,";");
  strcpy( artista->id ,string);
  
  artista->numSeguidores = atoi(strtok(NULL,";"));
  
  string =  strtok(NULL,";");
  artista->generos = (char*) malloc(sizeof(char)*strlen(string)+1);
  strcpy( artista->generos ,string);
  
  string = strtok(NULL,";");
  artista->nome = (char*) malloc(sizeof(char)*strlen(string)+1);
  strcpy(artista->nome ,string);
  
  artista->popularidade = atoi(strtok(NULL,";"));
  artista->indice = indice;
}

/**
 * @brief Funcao para imprimir as informacoes de um struct de artista;
 * 
 * @param artista 
 */

void imprimeArtista(tArtista_pt artista){
  printf("Artista: %s\n", artista->nome);
  //printf("NUM:%d\n", artista->indice);
  printf("ID artista: %s\n", artista->id);
  printf("No de seguidores: %d\n", artista->numSeguidores);
  printf("generos: %s\n", artista->generos);
  printf("Popularidade: %d\n", artista->popularidade);
}

/**
 * @brief Funcao para liberar o espaco de memoria de um struct de artista;
 * 
 * @param artista 
 */

void liberaArtista(tArtista_pt artista){

  if(artista != NULL){
    if(artista->indice != -1){
      free(artista->generos);
    }
    free(artista->nome);
    free(artista); 
  }

  artista = NULL;
}

/**
 * @brief funcao utilizada para salvar dados de artistas cujo nao temos informacoes pelo arquivo de artistas, mas participam de algumas musicas;
 * 
 * @param artistaDesconhecido 
 * @param id 
 */

void criaArtistaDesconhecido(tArtista_pt artistaDesconhecido, char*id){
  strcpy(artistaDesconhecido->id,id);
  artistaDesconhecido->numSeguidores = -1;
  artistaDesconhecido->generos = NULL;
  artistaDesconhecido->popularidade = -1;
  artistaDesconhecido->indice = -1;
}

void NomeiaArtistaDesconhecido(tArtista_pt artista,char*nome){
  if(artista->indice <0){
    artista->nome = (char*)malloc(sizeof(char) *strlen(nome)+3);
    strcpy(artista->nome, nome);
  }
}

void ImprimeArtistaDesconhecido(tArtista_pt artista){
  printf("Artista: %s\n", artista->nome);
  printf("ID artista: %s\n", artista->id);
}

/**
 * @brief funcao que retorna o ID de um artista;
 * 
 * @param artista 
 * @return char* 
 */

char *RetornaId(tArtista_pt artista){
  return artista->id;
}

/**
 * @brief Funcao que retorna o nome de um artista
 * 
 * @param artista 
 * @return char* 
 */

char *RetornaNomeArt(tArtista_pt artista){
  return artista->nome;
}

int RetornaIndiceArt(tArtista_pt artista){
  return artista->indice;
}