#include <stddef.h>
#include "main.h"
#define _USE_MATH_DEFINES
#include "math.h"
#include "string.h"
#include "stdio.h"
#include "stdlib.h"
#include <time.h>
#include "Aux_Func.h"

// Legacy global variables
// if used elsewere it MUST be defined as extern
const char polar[] = { "polar" };
const char cartesian[] = { "cartesian" };

// Global variables
// if used elsewere it MUST be defined as extern

const char* face[] = {	"Ace", "Deuce", "Three", "Four", "Five", 
						"Six", "Seven", "Eight", "Nine", "Ten",
						"Jack", "Queen", "King"	};

const char* suit[] = { "Hearts", "Diamonds", "Clubs", "Spades" };

// Mude a string com o caminho (PATH) do diretório do seu projeto.
// Use duas contrabarras para separar os diretórios.
const char Path[] = { "C:\\Repos\\1ELE705_SEM15_DeckLnkdLst2\\" };

//void view(ListCardNodePtr lPtr, FILE* cfPtr) {
//
//}

void shuffle(ListCardNodePtr* sPtr) {
	ListCardNodePtr trocaPtr, jumpPtr, trocaAnteriorPtr, jumpAnteriorPtr, trocaProxPtr;
	int N;

	// trocaPtr e jumpPtr apontam para o primeiro nó, se este existir.
	if (*sPtr == NULL) return;
	trocaAnteriorPtr = NULL;
	trocaPtr = *sPtr;
	jumpAnteriorPtr = NULL;
	jumpPtr = *sPtr;

	while (trocaPtr != NULL) {
		// Sorteia o nó para o qual jumPtr irá apontar
		do {
			// Sorteia N entre 1 e 100
			N = randomico(); //rand() % 100 + 1; // Descomente e veja que nunca vai funcionar.
			// jumpPtr percorre N nós-carta na lista de forma circular
			// note que jumpPtr será deslocado N posições à partir da última posição em que parou no ciclo anteiror.
			for (; N > 0; N--) {
				jumpAnteriorPtr = jumpPtr;
				jumpPtr = jumpPtr->nextPtr;
				if (jumpPtr == NULL) {
					jumpPtr = *sPtr;
				}
			}
			// Se jumpPtr e trocaPtr apontarem para o mesmo nó ou se apontarem para nós vizinhos, sorteia novo nó para jumPtr
		} while (jumpPtr == trocaPtr || jumpPtr->nextPtr == trocaPtr || trocaPtr->nextPtr == jumpPtr);

		// NÃO MODIFIQUE O CÓDIGO ACIMA

		// INSIRA SEU CÓDIGO A PARTIR DESTE PONTO





		/* RETIRE ESTA LINHA E ESTE COMANDO ANTES DE COMEÇAR A CODIFICAR SEU PROGRAMA --> */ return;


		// Algoritmo para a troca dos nós-carta
			// O mecanismo de troca é diferente sempre que um nó carta a ser trocado está na primeira posição da lista.
			// Note que há três tipos de trocas distintas dentro da estrutura Se-Senão abaixo.
			// Assim:

		// Se trocaPtr aponta para o primeiro nó

			// Troca o nó apontado por trocaPtr pelo nó apontado por jumpPtr, refazendo as ligações destes.

			// Obs: jumpPtr nunca irá apontar para o primeiro elemento nesse instante, pois jumpPtr nunca 
			//		será igual a trocaPtr, dada as condiões do sorteio

		// Senão

			// Se jumpPtr aponta para o primeiro nó

				// Troca o nó apontado por trocaPtr pelo nó apontado por jumpPtr, refazendo as ligações destes.

			// Senão

				// Troca o nó apontado por trocaPtr pelo nó apontado por jumpPtr, refazendo as ligações destes.

			// Fim Se-Senão

		// Fim Se-Senão





		// SEU CÓDIGO TERMINA ACIMA.

		// NÃO MODIFIQUE O CÓDIGO ABAIXO

		// Com as trocas dos nós, jumpPtr e trocaPtr continuam apontando para os nós agora trocados. Assim, 
		// é necessário trocar as posições apontadas, de forma que seja preservada a posição atual de 
		// jumpPtr e de trocaPtr na lista.
		// Usa trocaProxPtr como buffer
		trocaProxPtr = trocaPtr;
		trocaPtr = jumpPtr;
		jumpPtr = trocaProxPtr;

		// Agora trocaAnteriorPtr e trocaPtr podem avançar para o próximo nó a ser trocado
		trocaAnteriorPtr = trocaPtr;
		trocaPtr = trocaPtr->nextPtr;
	}
}

void createOneFr52Deck(ListCardNodePtr* sPtr) {
	// NÃO MODIFIQUE O CÓDIGO ACIMA

	// INSIRA SEU CÓDIGO A PARTIR DESTE PONTO

	// NÃO MODIFIQUE O CÓDIGO ABAIXO
}

// Este projeto implementa funções para o gerenciamento de cartas de.
// baralho, que podem ser utilizadas para a construção de um jogo.
// 
// As funções a serem construídas são: createOneFr52Deck, shuffle e view.
//
// A função createOneFr52Deck cria um monte contendo as cartas de um baralho
// padrão francês com 52 cartas. O monte de cartas é uma lista dinâmica cujos
// nós são do tipo ListCardNode e o ponteiro para seu nó inicial é do tipo
// ListCardNodePtr.
// Esta função recebe o endereço do ponteiro de uma lista ligada de cartas 
// (ponteiro para o ponteiro do monte) e realiza a inserção das 52 cartas 
// padrão do baralho francês em ordem crescente. A ordem crescente é 
// organizada pelo valor crescente dos nipes e, de forma secundária, pelo valor
// crescente das faces. Assim, os nipes vão de Hearts a Spades e ter valor de 1
// a 4, respectivamente. Estes seguem a sequencia descrita pelo vetor de strings
// constantes suit. O valor da face vai de 1 a 13, onde Ace é 1 e King é 13,
// respectivamente, seguindo a sequencia definida pelo vetor de strings constantes
// face.
// A função createOneFr52Deck recebe como parâmetro o endereço do ponteiro
// para um monte de cartas (ListCardNodePtr*) e cria os 52 nós do monte,
// seguindo a sequencia descrita e usando os vetores de strings face e suit, 
// que são strings globais com valores constantes.
//
//
// A função shuffle embaralha uma dada lista dinâmica de cartas. A função 
// recebe o endereço do ponteiro para o nó inicial de uma lista de cartas.
// A forma como a função deve embaralhar as cartas da seguinte forma:
// Um ponteiro denominado trocaPtr deve ser criado. No início da execução
// da função o ponteiro trocaPtr aponta para o primeiro elemento da lista
// de cartas. Além deste, um ponteiro denominado jumpPtr também deve ser
// criado e, inicialmente, também deve apontar para o primeiro nó da lista.
// Pelo fato da lista ser dinâmica, não há como saber a quantidade de nós
// presentes na lista, a não ser que se percorra a lista até o fim contando
// seus nós. No entanto, percorrer a lista sem realizar alguma tarefa é 
// perda de tempo de processamento útil.
// Assim, inicialmente um número denominado N entre 1 e 100 deve ser 
// sorteado. O jumpPtr deve se deslocar sequencialmente na lista por N nós.
// Caso atinja o final da lista antes de completar os N deslocamentos, 
// o ponteiro jumpPtr deve voltar a apontar para o inicio da lista e 
// continuar se deslocando, até completar os N deslocamentos.
// O nó pontado por jumpPtr deve ser trocado com o nó apontado por trocaPtr
// e o ponteiro trocaPtr deve passar a apontar o próximo elemento da lista.
// O processo se repete com um novo sorteio de N e com o ponteiro jumpPtr
// sendo deslocado circularmente pela lista à partir da última posição
// que havia parado. Assim, jumpPtr fica circulando pela lista após cada
// sorteio de N.
// O elemento apontado por jumpPtr é trocado com o elemento apontado por 
// trocaPtr e trocaPtr é apontado para o próximo nó da lista.
// O processo termina quando trocaPtr chegar ao fim da lista.
//
// A função view deve imprimir em um arquivo sequencial de texto o conteúdo 
// impresso de uma lista de cartas.
// A impressão no arquivo deve ser feita em duas colunas obedecendo o
// seguinte formato:
//    seven of diamonds   deuce of spades
// onde:
// - A palavra of deve iniciar na coluna 10 e na coluna 30, exatamente.
// - A face da carta deve terminar 1 espaço antes da palavra of.
// - O naipe deve inicial 1 espaço após a palavra of.
// - Um enter deve ser colocado sempre ao final no nipe da segunda coluna.
// - Ao final da impressão, um enter deve ser colocado ao final do
//   nipe da carta impressa.
// São parâmetros passados para a função, o endereço do início do da lista
// (do tipo ListCardNodePtr) e o endereço do arquivo de texto (FILE *) no
// qual será impressa a lista de cartas.
//
