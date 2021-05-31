#pragma once
#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>

//Legacy definitions

typedef struct {
	double a;
	double b;
} Cart;

typedef struct {
	double r;
	double g;
} Pol;

typedef union {
	Cart	cart;
	Pol		pol;
} Cplx;

typedef struct {
	Cplx s;
	char* mode;
} CplxNum;

//Program definitions

typedef struct {
	const char* face; // define pointer face   
	const char* suit; // define pointer suit
	unsigned int face_number; // Define o n�mero da face da carta
	unsigned int suit_number; // Define o n�mero do naipe
} Card; // end struct card    

struct listCardNode {
	Card card; /* Cada n� cont�m uma carta */
	struct listCardNode* nextPtr; /* Ponteiro para a pr�xima carta-n� */
}; /* end structure listCard */

typedef struct listCardNode ListCardNode; /* synonym for struct listNode */
typedef ListCardNode* ListCardNodePtr; /* synonym for ListNode* */

// Prot�tipos das fun��es
// void view(ListCardNodePtr lPtr, FILE* cfPtr);
void shuffle(ListCardNodePtr* sPtr);
void createOneFr52Deck(ListCardNodePtr* sPtr);

#endif
