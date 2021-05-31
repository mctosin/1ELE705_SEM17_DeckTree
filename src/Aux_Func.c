#include "Aux_Func.h"

extern const char Path[];

extern const char* face[];
extern const char* suit[];

size_t ReadFileOfOneFr52Deck(ListCardNodePtr* sPtr) {
	FILE* cfPtr;
	int i = 0;
	ListCardNodePtr newPtr, currentPtr;
	char myPath[100];

	// Abre o arquivo com as cartas do baralho ordenadas
	sprintf(myPath, "%s%s", Path, "Fr52Deck.dat");
	if ((cfPtr = fopen(myPath, "rb")) == NULL) {
		return 1;
	}

	// Insere o primeiro n�-carta
	newPtr = malloc(sizeof(ListCardNode));
	if (newPtr == NULL) return 2;
	// L� o conte�do do n�-carta do arquivo e 
	// coloca no primeiro n�-carta
	if (feof(cfPtr)) return 3;
	fread(newPtr, sizeof(ListCardNode), 1, cfPtr);
	// Refaz os ponteiros internos dos n�s para a posi��o
	// atual das strings de face e naipe 
	newPtr->card.face = face[newPtr->card.face_number - 1];
	newPtr->card.suit = suit[newPtr->card.suit_number - 1];
	// Refaz os ponteiros do n� e da lista
	newPtr->nextPtr = NULL;
	currentPtr = newPtr;
	*sPtr = newPtr;
	i++;

	// Insere os n�s-carta restantes
	for (; i < 52; i++) {
		newPtr = malloc(sizeof(ListCardNode));
		if (newPtr == NULL) return 2;
		if (feof(cfPtr)) return 3;
		fread(newPtr, sizeof(ListCardNode), 1, cfPtr);
		newPtr->card.face = face[newPtr->card.face_number - 1];
		newPtr->card.suit = suit[newPtr->card.suit_number - 1];
		currentPtr->nextPtr = newPtr;
		currentPtr = newPtr;
	}
	fclose(cfPtr); // Fecha o arquivo
	return 0;
}


// Retorna circularmente cada um dos 300 valores randomicos entre 1 e 100
// recuperados do arquivo RandomVallues.dat
int randomico(void) {
	// Na inicializa��o do programa, zera as vari�veis est�ticas
	static int random[300] = { 0 };
	static int i_random = 0;
	static int randomizado = 0;

	FILE* cfPtr;
	int i;
	char myPath[100];

	// Na primeira execu��o da fun��o, l� o vetor random do arquivo
	if (random[0] == 0) {
		// L� o vetor random do arquivo de
		// O vetor random recebe valores pseudo randomicos entre 1 e 100
		
		// Abre o arquivo com os n�meros pseudo rand�micos entre 1 e 100  
		sprintf(myPath, "%s%s", Path, "RandomValues.dat");
		if ((cfPtr = fopen(myPath, "rb")) == NULL) {
			//Se erro, retorna zero
			return 0;
		}
		// L� os n�meros e os atribui ao vetor random
		for (i = 0; i < 300; i++) {
			// Se erro, retorna zero
			if (feof(cfPtr)) {
				fclose(cfPtr);
				return 0;
			}
			fread(&random[i], sizeof(int), 1, cfPtr);
		}
		// Fecha o arquivo
		fclose(cfPtr);
	}

	// Devolve o randomico da vez
	randomizado = random[i_random];
	++i_random;
	if (i_random >= 300) i_random = 0;
	return randomizado;

}


// L� do arquivo ShuffledFr52Deck.dat, cria a lista ligada e
// retorna o ponteiro desta para *sPtr
size_t readFileOfShuffledFr52Deck(ListCardNodePtr* sPtr) {
	FILE* cfPtr;
	int i = 0;
	ListCardNodePtr newPtr, currentPtr;
	char myPath[100];

	// Abre o arquivo com as cartas do baralho ordenadas
	sprintf(myPath, "%s%s", Path, "ShuffledFr52Deck.dat");
	if ((cfPtr = fopen(myPath, "rb")) == NULL) {
		return 1;
	}

	// Insere o primeiro n�-carta
	newPtr = malloc(sizeof(ListCardNode));
	if (newPtr == NULL) {
		fclose(cfPtr);
		return 2;	
	}
	// L� o conte�do do n�-carta do arquivo e 
	// coloca no primeiro n�-carta
	if (feof(cfPtr)) {
		fclose(cfPtr);
		return 3;
	}
	fread(newPtr, sizeof(ListCardNode), 1, cfPtr);
	// Refaz os ponteiros internos dos n�s para a posi��o
	// atual das strings de face e naipe 
	newPtr->card.face = face[newPtr->card.face_number - 1];
	newPtr->card.suit = suit[newPtr->card.suit_number - 1];
	// Refaz os ponteiros do n� e da lista
	newPtr->nextPtr = NULL;
	currentPtr = newPtr;
	*sPtr = newPtr;
	i++;

	// Insere os n�s-carta restantes
	for (; i < 52; i++) {
		newPtr = malloc(sizeof(ListCardNode));
		if (newPtr == NULL) {
			fclose(cfPtr);
			return 2;
		}
		if (feof(cfPtr)) {
			fclose(cfPtr);
			return 3;
		}
		fread(newPtr, sizeof(ListCardNode), 1, cfPtr);
		newPtr->card.face = face[newPtr->card.face_number - 1];
		newPtr->card.suit = suit[newPtr->card.suit_number - 1];
		currentPtr->nextPtr = newPtr;
		currentPtr = newPtr;
	}
	fclose(cfPtr); // Fecha o arquivo
	return 0;
}


// Fun��es para a constru��o do exerc�cio
