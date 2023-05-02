#include "tPropriedades.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct tPropriedades {
  float danceability;
  float energy;
  int key;
  float loudness;
  int mode;
  float speechiness;
  float acousticness;
  float instrumentalness;
  float liveness;
  float valence;
  float tempo;
  int time_signature;
};

/**
 * @brief Funcao para armazenar as informacoes do arquivo musica no struct propriedades;
 * 
 * @param arquivo 
 * @return tPropriedades_pt 
 */

tPropriedades_pt CriaPropriedades(FILE *arquivo){

  tPropriedades_pt propriedades = alocaPropriedades();

  fscanf(arquivo, "%f;", &propriedades->danceability);
  fscanf(arquivo, "%f;", &propriedades->energy);
  fscanf(arquivo, "%d;", &propriedades->key);
  fscanf(arquivo, "%f;", &propriedades->loudness);
  fscanf(arquivo, "%d;", &propriedades->mode);
  fscanf(arquivo, "%f;", &propriedades->speechiness);
  fscanf(arquivo, "%f;", &propriedades->acousticness);
  fscanf(arquivo, "%f;", &propriedades->instrumentalness);
  fscanf(arquivo, "%f;", &propriedades->liveness);
  fscanf(arquivo, "%f;", &propriedades->valence);
  fscanf(arquivo, "%f;", &propriedades->tempo);
  fscanf(arquivo, "%d\n", &propriedades->time_signature);

  return propriedades;
}

/**
 * @brief Funcao para alocar o espaco de memoria para um struct de propriedades 
 * 
 * @return tPropriedades_pt 
 */

tPropriedades_pt alocaPropriedades() {

  tPropriedades_pt propriedades =
      (tPropriedades *)malloc(sizeof(tPropriedades));

  return propriedades;
}

/**
 * @brief Funcao para imprimir as informacoes de um struct de propriedades;
 * 
 * @param propriedades 
 */

void ImprimePropriedades(tPropriedades_pt propriedades) {
  
  printf("%f\n", propriedades->danceability);
  printf("%f\n", propriedades->energy);
  printf("%d\n", propriedades->key);
  printf("%f\n", propriedades->loudness);
  printf("%d\n", propriedades->mode);
  printf("%f\n", propriedades->speechiness);
  printf("%f\n", propriedades->acousticness);
  printf("%f\n", propriedades->instrumentalness);
  printf("%f\n", propriedades->liveness);
  printf("%f\n", propriedades->valence);
  printf("%f\n", propriedades->tempo);
  printf("%d", propriedades->time_signature);
}

/**
 * @brief Funcao para retornar a 'danceability' de um struct de propriedades;
 * 
 * @param propriedade 
 * @return float 
 */

float RetornaDancabilidade(tPropriedades_pt propriedade){
  return propriedade->danceability;
}

/**
 * @brief Funcao para retornar a 'energy' de um struct de propriedades;
 * 
 * @param propriedade 
 * @return float 
 */

float RetornaEnergia(tPropriedades_pt propriedade){
  return propriedade->energy;
}

/**
 * @brief Funcao para retornar a 'key' de um struct de propriedades;
 * 
 * @param propriedade 
 * @return int 
 */

int RetornaKey(tPropriedades_pt propriedade){
  return propriedade->key;
}

/**
 * @brief Funcao para retornar o 'loudness' de um struct de propriedades;
 * 
 * @param propriedade 
 * @return float 
 */

float RetornaLoudness(tPropriedades_pt propriedade){
  return propriedade->loudness;
}

/**
 * @brief Funcao para retornar o 'mode' de um struct de propriedades;
 * 
 * @param propriedade 
 * @return int 
 */

int RetornaMode(tPropriedades_pt propriedade){
  return propriedade->mode;
}

/**
 * @brief Funcao para retornar a 'speechiness' de um struct de propriedades;
 * 
 * @param propriedade 
 * @return float 
 */

float RetornaSpeechiness(tPropriedades_pt propriedade){
  return propriedade->speechiness;
}

/**
 * @brief Funcao para retornar a 'acousticness' de um struct de propriedades;
 * 
 * @param propriedade 
 * @return float 
 */

float RetornaAcousticness(tPropriedades_pt propriedade){
  return propriedade->acousticness;
}

/**
 * @brief Funcao para retornar  'instrumentalness' de um struct de propriedades;
 * 
 * @param propriedade 
 * @return float 
 */

float RetornaInstrumentalness(tPropriedades_pt propriedade){
  return propriedade->instrumentalness;
}

/**
 * @brief Funcao para retornar o 'liveness' de um struct de propriedades;
 * 
 * @param propriedade 
 * @return float 
 */

float RetornaLiveness(tPropriedades_pt propriedade){
  return propriedade->liveness;
}

/**
 * @brief Funcao para retornar o 'valence' de um struct de propriedades;
 * 
 * @param propriedade 
 * @return float 
 */

float RetornaValence(tPropriedades_pt propriedade){
  return propriedade->valence;
}

/**
 * @brief Funcao para retornar o 'tempo' de um struct de propriedades;
 * 
 * @param propriedade 
 * @return float 
 */

float RetornaTempo(tPropriedades_pt propriedade){
  return propriedade->tempo;
}

/**
 * @brief Funcao para retornar o 'time_signature' de um struct de propriedades;
 * 
 * @param propriedade 
 * @return int 
 */

int RetornaTime_signature(tPropriedades_pt propriedade){
  return propriedade->time_signature;
}


