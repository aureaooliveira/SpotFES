#include "tListaArt.h"
#include "tArtista.h"
#include<stdlib.h>

struct tListaArt{
  tArtista **lista;
    int numArtista;
    int max_size;

};

/**
 * @brief Aloca um espaco de memoria de um struct de lista de artistas;
 * 
 * @return tListaArt_pt 
 */

tListaArt_pt AlocaListaArt(){

  tListaArt_pt listaArt = (tListaArt_pt)malloc(sizeof(tListaArt));

  listaArt->lista = (tArtista_pt*)malloc(sizeof(tArtista_pt)*100);
  
   return listaArt;
}

/**
 * @brief Adiciona os valores iniciais da lista;
 * 
 * @param listaArt 
 */

void InicializaListaArt(tListaArt_pt listaArt){
  listaArt->numArtista = 0;
  listaArt->max_size = 100;
}

/**
 * @brief Adiciona um artista na lista de artistas;
 * 
 * @param listaArt 
 * @param artista 
 */

void AddArtistaLista(tListaArt_pt listaArt, tArtista_pt artista){

  if(listaArt->numArtista+1 == listaArt->max_size){
    FazRealloc(listaArt);
  }
    listaArt->lista[listaArt->numArtista] = artista;
    listaArt->numArtista++;
}

/**
 * @brief Imrpime os dados de um artista contido na lista;
 * 
 * @param listaArt 
 * @param i indice do artista;
 */

void ImprimeLista(tListaArt_pt listaArt, int i){
  imprimeArtista(listaArt->lista[i]);
  printf("\n");
}

/**
 * @brief Aumenta o espaco de memoria alocado para a lista quando ele acaba;
 * 
 * @param listaArt 
 */

void FazRealloc(tListaArt_pt listaArt){
    listaArt->max_size +=100; 
    listaArt->lista = (tArtista_pt*)realloc(listaArt->lista,sizeof(tArtista_pt)*listaArt->max_size);
  
}

/**
 * @brief libera o espaco de memoria alocado pelos artistas da lista e do struct de lista de artistas;
 * 
 * @param listaArt 
 * @param numArt 
 */

void LiberaListaArtista(tListaArt_pt listaArt, int numArt){

  for(int i=0; i < numArt; i++){
    liberaArtista(listaArt->lista[i]);
  }
  free(listaArt->lista);
  free(listaArt);
}

/**
 * @brief Le o arquivo que contem os dados dos artistas e coloca eles na lista de artistas
 * 
 * @param arquivo 
 * @param nomeArq 
 * @return tListaArt_pt 
 */

tListaArt_pt LeECriaListaArt(FILE *arquivo, char *nomeArq){
  
  int numArt=0;
  char linha[4000];
  tArtista_pt artista;
  tListaArt_pt listaArt = AlocaListaArt();
  InicializaListaArt(listaArt);

  arquivo = fopen(nomeArq, "r");

  if (arquivo == NULL) {
    printf("Arquivo nao pode ser aberto\n");
    return 0;
  }

  while (fgets(linha, 4000, arquivo) != NULL) {

    artista = alocaArtista();
    criaArtista(artista, linha, numArt);
    AddArtistaLista(listaArt, artista);
    //ImprimeLista(listaArt,numArt);

    numArt++;
  }
  
  fclose(arquivo);
  
  return listaArt;
}

/**
 * @brief Retorna um artista de lista;
 * 
 * @param listaArt 
 * @param i 
 * @return tArtista_pt 
 */

tArtista_pt RetornaArtistas(tListaArt_pt listaArt, int i){
  return listaArt->lista[i]; 
}

/**
 * @brief Retorna o numero de artista da lista;
 * 
 * @param listaArt 
 * @return int 
 */

int RetornaNumArtista(tListaArt_pt listaArt){
  return listaArt->numArtista;
}

/**
 * @brief Retorna o id de um artista da lista;
 * 
 * @param listaArt 
 * @param i 
 * @return char* 
 */

char *RetornaIdLista(tListaArt_pt listaArt, int i){
  return RetornaId(listaArt->lista[i]);
}


