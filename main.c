/*Miguel Gewehr de Oliveira 2020100875 Aurea Santos de Oliveira2021101303*/

#include "tListMsc.h"
#include "tListPlaylist.h"
#include "tListaArt.h"
#include "tMusica.h"
#include "tPlaylist.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {

  int numArt = 0;
  FILE *arquivo;

  tListaArt_pt listaArt = LeECriaListaArt(arquivo, argv[1]);
  numArt = RetornaNumArtista(listaArt);

  int numMusica = 0;
  FILE *arquivoMsc;

  tListMsc_pt listaMsc = LeECriaListaMsc(arquivoMsc, argv[2], listaArt);

  numMusica = RetornaNumMscLista(listaMsc);

  printf("-----------------------------------------------------");
  printf("\nEscolha uma opcao do Menu\n");
  printf("Buscar musica: 1\n");
  printf("Listar musica: 2\n");
  printf("Criar playlist: 3\n");
  printf("Listar playlists: 4\n");
  printf("Listar playlist: 5\n");
  printf("Adicionar uma musica na playlist: 6\n");
  printf("Recomendar musicas parecidas com uma playlist: 7\n");
  printf("Gerar relatorio: 8\n");
  printf("-----------------------------------------------------\n");

  int opcao = 0, indiceMsc = 0, numMscRecomendada = 0;
  char nomeMsc[100], nomePlaylist[100];
  tPlaylist_pt playlist;
  int qtdPlaylist = 0;
  int indicePlaylist = 0;
  float *mediasPlay, *mediaListaMsc;
  FILE *arqSaida;


   tListPlaylist_pt listaPlaylists = AlocaListaPlaylist();

   CriaListaPlaylist(listaPlaylists);
  

  while(scanf("%d", &opcao)){
    getchar();
    
    switch (opcao) {
    case 1:
      printf("Escreva o trecho da musica que deseja proucurar:\n");
      fgets(nomeMsc, 100, stdin);
      BuscarMusica(nomeMsc, listaMsc);
      break;

    case 2:
      scanf("%d", &indiceMsc);
      ListaMsc(listaMsc, indiceMsc);
      break;


    case 3:
      printf("Digite o nome da playlist:\n");
      fgets(nomePlaylist, 100, stdin);
      playlist = AlocaPlaylist();
      CriaPlaylist(playlist, qtdPlaylist, nomePlaylist);
      AddPlaylistNaLista(listaPlaylists, playlist);
      qtdPlaylist++;
  
      break;
      
    


    case 4:
        ImprimeListaPlaylists(listaPlaylists);
      break;

    case 5:
      printf("Escreva o indice da Playlist\n");
      scanf("%d", &indicePlaylist);
      ImprimePlaylist(listaPlaylists, indicePlaylist, listaMsc);
      break;

    case 6:
      printf("Escreva o indice da Playlist e o indice da Musica, repectivamente:\n"); scanf("%d %d ", &indicePlaylist, &indiceMsc);
      AddMusicaNaListaPlaylist(listaPlaylists, indiceMsc, indicePlaylist);
      break;

    case 7:
      printf("Escreva o indice da playlist e o numero de muiscas que vao ser recomendadas\n"); scanf("%d %d", &indicePlaylist, &numMscRecomendada);
      mediasPlay = CriaVetorMediaLista(listaPlaylists, listaMsc,
  indicePlaylist); mediaListaMsc = CalculaDistanciaEuclidiana(mediasPlay,
  listaMsc); RecomendaMsc(mediaListaMsc, listaMsc,numMscRecomendada); break;

      case 8:
        GeraArquivo(arqSaida, listaPlaylists, listaMsc);
        break;
    
        
    break;
    }
  }
  LiberaListaArtista(listaArt, numArt);
  LiberaListaMusica(listaMsc, numMusica);
  LiberaListaPlay(listaPlaylists);
  

  return 0;
}
