#include "tListMsc.h"
#include "math.h"
#include "tMusica.h"
#include "tPropriedades.h"
#include <stdlib.h>
#include <string.h>

struct tListMsc {
  tMusica_pt *listaMusica;
  int numMusica;
  int maxMusica;
};

/**
 * @brief Funcao para ler o arquivo fornecido e retornar uma lista que armazene os dados de todas as musicas contidas nele;
 * 
 * @param arquivo 
 * @param nomeArq 
 * @param listaArt 
 * @return tListMsc_pt 
 */

tListMsc_pt LeECriaListaMsc(FILE *arquivo, char *nomeArq,
                            tListaArt_pt listaArt) {

  tMusica_pt musica;
  int numMusica = 0;
  tListMsc_pt listaMsc = AlocaListaMusica();
  InicializaListaMusica(listaMsc);

  arquivo = fopen(nomeArq, "r");

  if (arquivo == NULL) {
    printf("Arquivo nao pode ser aberto\n");
    return 0;
  }

  while (!feof(arquivo)) {

    musica = alocaMusica(musica);

    CriaMusica(musica, arquivo, listaArt, numMusica);
    
    
    
    AddMusicaLista(listaMsc, musica);
    

    numMusica++;
  }

  fclose(arquivo);

  return listaMsc;
}

/**
 * @brief Aloca o espaco de memoria de um struct de  lista de musica;
 * 
 * @return tListMsc_pt 
 */

tListMsc_pt AlocaListaMusica() {

  tListMsc_pt listaMusica = (tListMsc_pt)malloc(sizeof(tListMsc));
  listaMusica->listaMusica = (tMusica_pt *)malloc(sizeof(tMusica_pt) * 100);

  return listaMusica;
}

/**
 * @brief Inicializa os dados da lista de musica;
 * 
 * @param listaMsc 
 */

void InicializaListaMusica(tListMsc_pt listaMsc) {
  listaMsc->numMusica = 0;
  listaMsc->maxMusica = 100;
}

/**
 * @brief Adiciona uma musica a lista e se nao houver mais espaco de memoria ela aloca mais; 
 * 
 * @param listaMsc 
 * @param musica 
 */

void AddMusicaLista(tListMsc_pt listaMsc, tMusica_pt musica) {

  if (listaMsc->numMusica + 1 == listaMsc->maxMusica) {
    listaMsc = FazReallocMsc(listaMsc);
  }
  listaMsc->listaMusica[listaMsc->numMusica] = musica;
  listaMsc->numMusica++;
}

/**
 * @brief Funcao responsavel por aumentar o espaco de memoria alocado pela lista de musicas;
 * 
 * @param listaMsc 
 */

tListMsc_pt FazReallocMsc(tListMsc_pt listaMsc) {
  listaMsc->maxMusica += 100;
  listaMsc->listaMusica = (tMusica_pt *)realloc(
      listaMsc->listaMusica, sizeof(tMusica_pt) * listaMsc->maxMusica);

  return listaMsc;
}

/**
 * @brief Imprime uma musica contida na lista;
 * 
 * @param listaMsc 
 * @param i indice da musica;
 */

void ImprimeListaMusica(tListMsc_pt listaMsc, int i) {
  ImprimeMusica(listaMsc->listaMusica[i]);
}

/**
 * @brief Libera o espaco de memoria alocado pelas musicas da lista e pelo struct de lista de musicas;
 * 
 * @param listaMsc 
 * @param numMsc 
 */

void LiberaListaMusica(tListMsc_pt listaMsc, int numMsc) {

  for (int i = 0; i < numMsc; i++) {
    if(listaMsc->listaMusica[i] != NULL)
      LiberaMusica(listaMsc->listaMusica[i]);
  }
  free(listaMsc->listaMusica);
  free(listaMsc);
}

/**
 * @brief Imprime os nomes das musicas que contem uma string digitada pelo usuario;
 * 
 * @param nomeMsc 
 * @param listaMsc 
 */

void BuscarMusica(char nomeMsc[100], tListMsc_pt listaMsc) {

  int numMsc = listaMsc->numMusica;
  int tamanho = strlen(nomeMsc);
  nomeMsc[tamanho-1] = '\0';

  printf("\nMusicas encontradas:\n\n");
  
  for (int i = 0; i < numMsc; i++) {
    if (strcasestr(RetornaNomeMsc(listaMsc->listaMusica[i]), nomeMsc) != NULL) {
      printf("%s\n", RetornaNomeMsc(listaMsc->listaMusica[i]));
    }
  }
}

void ListaMsc(tListMsc_pt listaMsc, int i) {

  // int numMsc = listaMsc->numMusica;

  // for(int j=0; j < numMsc; j++){
  // if(RetornaIndice(listaMsc->listaMusica[j]) == i){
  printf("Nome: %s\n", RetornaNomeMsc(listaMsc->listaMusica[i]));
  printf("ID musica: %s\n", RetornaIdMsc(listaMsc->listaMusica[i]));
  ImprimeArtistasMusica(listaMsc->listaMusica[i],
                        RetornaQtdArtistasDaMsc(listaMsc->listaMusica[i]));

  // Imprimir os artistas da musica tbm
  ExecutarMsc(listaMsc, i);
}

void ExecutarMsc(tListMsc_pt listaMsc, int indice) {

  int i = 0;
  char comando[100] = ("firefox https://open.spotify.com/track/");
  strcat(comando, RetornaIdMsc(listaMsc->listaMusica[indice]));
  printf("Digite 1 se deseja executar a musica, ou qualquer tecla caso "
         "contrario\n");
  scanf("%d", &i);
  printf("%s",comando);
  if (i == 1) {
    system(comando);
  }
}

void PoeMusicaXnaPosicaoY(tListMsc_pt lista, tMusica_pt musica, int posicao) {
  lista->listaMusica[posicao] = musica;
}

float *CalculaDistanciaEuclidiana(float *mediaPlay, tListMsc_pt listaMsc) {

  float *distanciaLista = (float *)malloc(sizeof(float) * listaMsc->numMusica);

  for (int i = 0; i < listaMsc->numMusica; i++) {
    for (int j = 0; j < 12; j++) {
      if (j == 0) {
        distanciaLista[i] += pow(RetornaDancabilidade(RetornaPropriedades(
                                     listaMsc->listaMusica[i])) -
                                     mediaPlay[j],
                                 2);
      }
      if (j == 1) {
        distanciaLista[i] +=
            pow(RetornaEnergia(RetornaPropriedades(listaMsc->listaMusica[i])) -
                    mediaPlay[j],
                2);
      }
      if (j == 2) {
        distanciaLista[i] +=
            pow(RetornaKey(RetornaPropriedades(listaMsc->listaMusica[i])) -
                    mediaPlay[j],
                2);
      }
      if (j == 3) {
        distanciaLista[i] +=
            pow(RetornaLoudness(RetornaPropriedades(listaMsc->listaMusica[i])) -
                    mediaPlay[j],
                2);
      }
      if (j == 4) {
        distanciaLista[i] +=
            pow(RetornaMode(RetornaPropriedades(listaMsc->listaMusica[i])) -
                    mediaPlay[j],
                2);
      }
      if (j == 5) {
        distanciaLista[i] += pow(
            RetornaSpeechiness(RetornaPropriedades(listaMsc->listaMusica[i])) -
                mediaPlay[j],
            2);
      }
      if (j == 6) {
        distanciaLista[i] += pow(
            RetornaAcousticness(RetornaPropriedades(listaMsc->listaMusica[i])) -
                mediaPlay[j],
            2);
      }
      if (j == 7) {
        distanciaLista[i] += pow(RetornaInstrumentalness(RetornaPropriedades(
                                     listaMsc->listaMusica[i])) -
                                     mediaPlay[j],
                                 2);
      }
      if (j == 8) {
        distanciaLista[i] +=
            pow(RetornaLiveness(RetornaPropriedades(listaMsc->listaMusica[i])) -
                    mediaPlay[j],
                2);
      }
      if (j == 9) {
        distanciaLista[i] +=
            pow(RetornaValence(RetornaPropriedades(listaMsc->listaMusica[i])) -
                    mediaPlay[j],
                2);
      }
      if (j == 10) {
        distanciaLista[i] +=
            pow(RetornaTempo(RetornaPropriedades(listaMsc->listaMusica[i])) -
                    mediaPlay[j],
                2);
      }
      if (j == 11) {
        distanciaLista[i] += pow(RetornaTime_signature(RetornaPropriedades(
                                     listaMsc->listaMusica[i])) -
                                     mediaPlay[j],
                                 2);
      }
    }
  }

  return distanciaLista;
}

void RecomendaMsc(float *distanciaLista, tListMsc_pt listaMsc,
                  int numMscRecomendadas) {

  float aux = 0.0;
  int indiceMsc[listaMsc->numMusica], auxInt = 0;

  for (int i = 0; i < listaMsc->numMusica; i++) {
    indiceMsc[i] = i;
  }

  for (int i = 0; i < listaMsc->numMusica; i++) {
    for (int j = 0; j < listaMsc->numMusica; j++) {
      if (distanciaLista[i] < distanciaLista[j]) {
        aux = distanciaLista[i];
        distanciaLista[i] = distanciaLista[j];
        distanciaLista[j] = aux;
        auxInt = indiceMsc[i];
        indiceMsc[i] = indiceMsc[j];
        indiceMsc[j] = auxInt;
      }
    }
  }

  printf("Essas sao as %d musicas mais parecidas com sua playlist:\n\n",
         numMscRecomendadas);

  for (int i = 0; i < numMscRecomendadas; i++) {
    printf("%s\n", RetornaNomeMsc(RetornaMusicaLista(listaMsc, indiceMsc[i])));
  }
}

tMusica_pt RetornaMusicaLista(tListMsc_pt listaMsc, int i) {
  return listaMsc->listaMusica[i];
}

char *RetornaNomeMscLista(tListMsc_pt listaMsc, int indice) {
  return RetornaNomeMsc(listaMsc->listaMusica[indice]);
}

int RetornaNumMscLista(tListMsc_pt listaMsc) { return listaMsc->numMusica; }