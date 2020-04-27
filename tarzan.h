//tarzan.h
#ifndef TARZAN
#define TARZAN

//matriz de adj

typedef int pond;

typedef struct grafo{
	int vert; //guarda o numero de vertices em um grafo
	int arst;  //guarda o numero de arestas de um grafo
	int **matriz_Adj;
	int estado; // 0-nao passou
				// 1-ja passou
				// 2-passou por ele e pelos adjacentes
	
}Grafo;


void cria_grafo(Grafo **g, int num_vert);
//cria grafo
//entra endereço de ponteiro para grafo e numero de vertices
//retorna void



void tempestade(Grafo *g);
//tempestade - destroi grafos
//entra ponteiro para grafo
//retorna void




void adiciona_aresta(Grafo *g, int v1, int v2);
//adiciona arestas
//entra ponteiro para grafo, vertice 1 e 2 da aresta
//retorna void





void imprime_grafo(Grafo *g);
//imprime grafo
//entra ponteiro para grafo
//retorna void



#endif 