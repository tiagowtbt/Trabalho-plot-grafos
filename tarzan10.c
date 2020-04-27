#include <stdlib.h>
#include <stdio.h>
#include "tarzan.h"


void cria_grafo(Grafo **g, int num_vert){
    int i;
	*g = (Grafo*)malloc(sizeof(Grafo));

	//aloca um vetor de ponteiros
	(*g)->matriz_Adj = (int**)malloc(num_vert * sizeof(int*));

	for(i = 0; i < num_vert; i++){
		
		(*g)->matriz_Adj[i] = (int*)malloc(num_vert * sizeof(int));
		for(int j = 0; j < num_vert; j++){
			(*g)->matriz_Adj[i][j] = 0;
		}
	}

	(*g)->vert = num_vert;
	(*g)->arst = 0;
}


void tempestade(Grafo *g){

    int i;

	for (i = 1; i < g->vert; i++){
		free(g->matriz_Adj[i]);
	}

  	free(g->matriz_Adj);
  	free(g);

}


void adiciona_aresta(Grafo *g, int v1, int v2){



	if((v1 != v2) && (v1 >= 0 ) && (v1 < g->vert) && (v2 >= 0) && (v2 < g->vert)&& (g->matriz_Adj[v1][v2] == 0)){
		

		g->arst++;
		g->matriz_Adj[v1][v2] = 1;
		g->matriz_Adj[v2][v1] = 1;

	}
}




void raio(Grafo *g, int v1, int v2){
	if((v1 != v2) && (v1 >=0) && (v1 < g->vert)&& (v2 >=0) && (v2 < g->vert)){

		if(g->matriz_Adj[v1][v2]!= 0){
			//decrementa o numero de arestas
			g->arst++;
		}
		g->matriz_Adj[v1][v2] = 0;
		g->matriz_Adj[v2][v1] = 0;
	}
}


void imprime_grafo(Grafo *g){
    int i, j;
	for(i = 0; i < g->vert; i++){
		printf("Arestas do vertice %d \n",i);
		for(j = 0; j < g->vert; j++){
			if(g->matriz_Adj[i][j]!= 0){
				printf("%d(%d) ",j, g->matriz_Adj[i][j]);
			}

		}
		printf("\n");
	}
	printf("\n");
}


void matriz(Grafo *g){
    int i, j;
	for(i = 0; i < g->vert; i++){
		for(j = 0; j < g->vert; j++){
				printf("  %d", g->matriz_Adj[i][j]);
		}
		printf("\n");
	}
}

//busca

int busca_caminhos(Grafo *g) {

	int i, j, r;

	for(i = 0; i < g->vert; i++){
		for(r = 0, j = 0; j < g->vert; j++){
			if (g->matriz_Adj[i][j] == 0) {
			r++;

			}
			if (r == g->vert) {
				r = 0;
				return r;
			}
		}
	}
	r = 1;
	return r;
}


void gera_file(Grafo *g) {
		int i, j;
		FILE *arq;
	    arq = fopen("grafo.txt", "w");
	    //if (arq == NULL) {
			for(i = 0; i < g->vert; i++){
				for(j = 0; j < g->vert; j++){
	    			fprintf(arq, "%d ", g->matriz_Adj[i][j]);
	    		}
	    		
				fprintf(arq, "\n");
	    	}
	    	
		fclose(arq);
}
//gera arquivo com matriz

int main(){
	Grafo *g;

	//Cria grafo com 5
	//vertices
	cria_grafo(&g,10);

	//Adiciona as arestas
	adiciona_aresta(g,0,1);
    adiciona_aresta(g,0,2);
	adiciona_aresta(g,0,3);
	adiciona_aresta(g,0,4);
	adiciona_aresta(g,0,5);
    adiciona_aresta(g,0,6);
	adiciona_aresta(g,0,7);
	adiciona_aresta(g,0,8);
	adiciona_aresta(g,0,9);
	adiciona_aresta(g,1,2);
	adiciona_aresta(g,1,3);
	adiciona_aresta(g,1,4);
    adiciona_aresta(g,1,5);
	adiciona_aresta(g,1,6);
	adiciona_aresta(g,1,7);
   	adiciona_aresta(g,1,8);
	adiciona_aresta(g,1,9);
	adiciona_aresta(g,2,3);
	adiciona_aresta(g,2,4);
   	adiciona_aresta(g,2,5);
	adiciona_aresta(g,2,6);
	adiciona_aresta(g,2,7);
   	adiciona_aresta(g,2,8);
	adiciona_aresta(g,2,9);
	adiciona_aresta(g,3,4);
   	adiciona_aresta(g,3,5);
	adiciona_aresta(g,3,6);
	adiciona_aresta(g,3,7);
   	adiciona_aresta(g,3,8);
	adiciona_aresta(g,3,9);
   	adiciona_aresta(g,4,5);
	adiciona_aresta(g,4,6);
	adiciona_aresta(g,4,7);
   	adiciona_aresta(g,4,8);
	adiciona_aresta(g,4,9);
	adiciona_aresta(g,5,6);
	adiciona_aresta(g,5,7);
   	adiciona_aresta(g,5,8);
	adiciona_aresta(g,5,9);
	adiciona_aresta(g,6,7);
   	adiciona_aresta(g,6,8);
	adiciona_aresta(g,6,9);
	adiciona_aresta(g,7,8);
	adiciona_aresta(g,7,9);				
	adiciona_aresta(g,8,9);


	//mostra o grafo
	imprime_grafo(g);
	matriz(g);

	printf("\n");

	int r = busca_caminhos(g);
	if(r == 1)
		printf("Dá para percorrer a floresta inteira\n");
	else{
		printf("Não dá para percorrer a floresta inteira\n");
	}

	gera_file(g);
	//libera a memoria
	tempestade(g);

	return 0;
}
