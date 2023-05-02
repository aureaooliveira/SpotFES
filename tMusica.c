#include "tMusica.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct tMusica {
  int indice;
  char id[22];
  char *nome;
  int popularidade;
  float duracao;
  int explicito;
  tArtista_pt *listaArtMsc;
  char data[10];
  tPropriedades_pt propriedades;
  int qtdArtistas;
};

tMusica_pt alocaMusica() {

  tMusica_pt musica = (tMusica *)malloc(sizeof(tMusica));

  return musica;
}

int CriaMusica(tMusica_pt musica, FILE *arquivo, tListaArt_pt listaArt,
               int indice) {

  char *nomeArtistas;
  char *idArtistas;
  char *nomeMsc = (char *)malloc(sizeof(char) * 10000);
  char *temp2 = (char *)malloc(sizeof(char) * 10000);

  musica->indice = indice;

  fscanf(arquivo, "%[^;];", musica->id);

  fscanf(arquivo, "%[^;];", nomeMsc);
  musica->nome = (char *)malloc(sizeof(char) * strlen(nomeMsc) + 3);
  strcpy(musica->nome, nomeMsc);
  fscanf(arquivo, "%d;", &musica->popularidade);
  fscanf(arquivo, "%f;", &musica->duracao);
  fscanf(arquivo, "%d;", &musica->explicito);

  fscanf(arquivo, "%[^;];", temp2);
  nomeArtistas = (char *)malloc(sizeof(char) * strlen(temp2) + 3);
  strcpy(nomeArtistas, temp2);

  fscanf(arquivo, "%[^;];", temp2);
  idArtistas = (char *)malloc(sizeof(char) * strlen(temp2) + 3);
  strcpy(idArtistas, temp2);

  fscanf(arquivo, "%[^;];", musica->data);

  musica->propriedades = CriaPropriedades(arquivo);

  int qtd = RetornaQtdArtista(idArtistas);
  musica->qtdArtistas = qtd;

  musica->listaArtMsc = AlocaListaArtista(qtd);
  char *temp;
  char *tempNome;
  for (int i = 0; i < qtd; i++) {
    if (i == 0) {
      temp = strtok(idArtistas, "|");

    } else {
      temp = strtok(NULL, "|");
    }
    //printf("IDARTISTA %d: %s\n", i, temp);
    musica->listaArtMsc[i] = LinkaArtista(temp, listaArt);
  }
  for (int i = 0; i < qtd; i++) {
    if (i == 0) {
      tempNome = strtok(nomeArtistas, "|");

    } else {
      tempNome = strtok(NULL, "|");
    }
    NomeiaArtistaDesconhecido(musica->listaArtMsc[i], tempNome);
  }
  // ImprimeMusica(musica);
  free(nomeArtistas);
  free(idArtistas);
  free(nomeMsc);
  free(temp2);
  return 0;
}

int RetornaQtdArtista(char *id) {
  int i = 0;
  int contArt = 1;

  while (id[i] != '\0') {

    if (id[i] == '|') {
      contArt++;
    }

    i++;
  }
  return contArt;
}

tArtista_pt LinkaArtista(char *id, tListaArt_pt listaArt) {

  int numArt = RetornaNumArtista(listaArt);

  for (int i = 0; i < numArt; i++) {
    if (strcmp(id, RetornaIdLista(listaArt, i)) == 0) {
      return RetornaArtistas(listaArt, i);
    }
  }
  tArtista_pt artistaDesconhecido = alocaArtista();
  criaArtistaDesconhecido(artistaDesconhecido, id);

  return artistaDesconhecido;
}

void ImprimeMusica(tMusica_pt musica) {

  printf("NUM:%d ", musica->indice);
  printf("%s\n", musica->id);
  printf("%s\n", musica->nome);
  printf("%d\n", musica->popularidade);
  printf("%f\n", musica->duracao);
  printf("%d\n", musica->explicito);
  printf("%s\n", musica->data);
  ImprimePropriedades(musica->propriedades);
  printf("\n\n");
}

void LiberaMusica(tMusica_pt musica) {
  if (musica != NULL) {
    free(musica->nome);
    free(musica->propriedades);
    for(int i=0; i < musica->qtdArtistas; i++){
      if(musica->listaArtMsc[i] != NULL){
        if(RetornaIndiceArt(musica->listaArtMsc[i]) == -1)
          liberaArtista(musica->listaArtMsc[i]);
        }   
      }
    free(musica->listaArtMsc);
    
    free(musica);
  }
  musica = NULL;
}

char *RetornaNomeMsc(tMusica_pt musica) { return musica->nome; }

int RetornaIndiceMsc(tMusica_pt musica) { return musica->indice; }

char *RetornaIdMsc(tMusica_pt musica) { return musica->id; }

int RetornaQtdArtistasDaMsc(tMusica_pt m) { return m->qtdArtistas; }

void ImprimeArtistasMusica(tMusica_pt musica, int qtd) {
  for (int i = 0; i < qtd; i++) {
    imprimeArtista(musica->listaArtMsc[i]);
    // IMPRIMIR ARTISTA DESCONHECIDO DE UM JEITO DIFERENTE
    // APENAS NOME E ID
  }
}

tPropriedades_pt RetornaPropriedades(tMusica_pt musica) {
  return musica->propriedades;
}