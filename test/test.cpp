#include "gtest/gtest.h"
#include <cstring>
#include "aux_functions.h"
#define _USE_MATH_DEFINES
#include "math.h"

extern "C"
{
    #include <time.h>
    #include <stdlib.h>
    #include "../src/Aux_Func.h"
}


TEST(TestCaseName, TestName) {
    EXPECT_EQ(1, 1);
    EXPECT_TRUE(true);

    // Inicializações do Projeto

    // Randomiza, eventualmente.
    srand((unsigned int) time(NULL));
}


TEST(TestcreateOneFr52Deck, TestMatchFr52Deck) {
    ListCardNodePtr expectedDeck = NULL;
    ListCardNodePtr actualDeck = NULL;

    createOneFr52Deck(&actualDeck);
    ReadFileOfOneFr52Deck(&expectedDeck);
    ASSERT_TRUE(ListMatch(actualDeck, expectedDeck));
}


TEST(TestshuffleOneFr52Deck, TestShuffleFr52DeckListMatch) {
    ListCardNodePtr expectedDeck = NULL;
    ListCardNodePtr actualDeck = NULL;

    ReadFileOfOneFr52Deck(&actualDeck);
    shuffle(&actualDeck);
    
    readFileOfShuffledFr52Deck(&expectedDeck);
    ASSERT_TRUE(ListMatch(actualDeck, expectedDeck));
}

TEST(TestshuffleOneFr52Deck, TestShuffleFr52DeckNodeAddressMismatch) {
    ListCardNodePtr expectedDeck = NULL;
    ListCardNodePtr actualDeck = NULL;

    int i;
    int actualAddressSeq[53] = { 0 };
    int expectedAddressSeq[53] = { 0 };

    for (i = 0; i < 53; i++) {
        expectedAddressSeq[i] = rand() + 1;
    }

    ListCardNodePtr actualAddressSeqPtr;
    ListCardNodePtr expectedAddressSeqPtr;

    ReadFileOfOneFr52Deck(&actualDeck);
    actualAddressSeqPtr = actualDeck;
    for (i = 0; actualAddressSeqPtr != NULL && i < 52; i++) {
        actualAddressSeq[i] = (int)actualAddressSeqPtr;
        actualAddressSeqPtr = actualAddressSeqPtr->nextPtr;
    }
    actualAddressSeq[i] = (int)actualAddressSeqPtr;

    shuffle(&actualDeck);
    expectedAddressSeqPtr = actualDeck;
    for (i = 0; expectedAddressSeqPtr != NULL && i < 52; i++) {
        expectedAddressSeq[i] = (int)expectedAddressSeqPtr;
        expectedAddressSeqPtr = expectedAddressSeqPtr->nextPtr;
    }
    expectedAddressSeq[i] = (int)expectedAddressSeqPtr;

    // Verifica se os nós foram trocados
    ASSERT_TRUE(ListNodeAddressesArrayMismatch(actualAddressSeq, expectedAddressSeq));
}

TEST(TestshuffleOneFr52Deck, TestShuffleFr52DeckEmptyDeck) {
    ListCardNodePtr expectedDeck = NULL;
    ListCardNodePtr actualDeck = NULL;

    ReadFileOfOneFr52Deck(&actualDeck);
    shuffle(&actualDeck);

    readFileOfShuffledFr52Deck(&expectedDeck);
    // Verifica se algum dos ponteiros é nulo
    ASSERT_TRUE(NullPointerTest(actualDeck, expectedDeck));
}

TEST(Test_isDeckEmpty, isDeckEmptyTestEmptyDeck) {
    ListCardNodePtr expectedDeck = NULL;

    EXPECT_TRUE(isDeckEmpty(expectedDeck));

}

TEST(Test_isDeckEmpty, isDeckEmptyTestNotEmptyDeck) {
    ListCardNodePtr expectedDeck = (ListCardNodePtr)malloc(sizeof(ListCardNode));
    expectedDeck->nextPtr = NULL;
    expectedDeck->card.face = face[0];
    expectedDeck->card.face_number = 1;
    expectedDeck->card.suit = suit[3];
    expectedDeck->card.suit_number = 4;

    EXPECT_FALSE(isDeckEmpty(expectedDeck));

}

TEST(Test_popFromDeck, popFromOneElementDeckTestEmptyDeck) {
    ListCardNodePtr rebuiltExpectedDeck = (ListCardNodePtr)malloc(sizeof(ListCardNode));
    *rebuiltExpectedDeck = { face[0], suit[3], 1, 4, NULL };
    ListCardNodePtr actualDeck = (ListCardNodePtr)malloc(sizeof(ListCardNode));
    *actualDeck = { face[0], suit[3], 1, 4, NULL };
    ListCardNodePtr expectedDeck = NULL;
    ListCardNodePtr rebuiltActualDeck = (ListCardNodePtr)malloc(sizeof(ListCardNode));
    Card actualCard = { 0 };
    *rebuiltActualDeck = { actualCard, NULL };
    popFromDeck(&actualDeck);
    ASSERT_TRUE(ListMatch(actualDeck, expectedDeck));

}

TEST(Test_popFromDeck, popFromOneElementDeckTestOneElementRebuiltDeck) {
    ListCardNodePtr rebuiltExpectedDeck = (ListCardNodePtr)malloc(sizeof(ListCardNode));
    *rebuiltExpectedDeck = { face[0], suit[3], 1, 4, NULL };
    ListCardNodePtr actualDeck = (ListCardNodePtr)malloc(sizeof(ListCardNode));
    *actualDeck = { face[0], suit[3], 1, 4, NULL };
    ListCardNodePtr expectedDeck = NULL;
    ListCardNodePtr rebuiltActualDeck = (ListCardNodePtr)malloc(sizeof(ListCardNode));
    Card actualCard = { 0 };
    *rebuiltActualDeck = { actualCard, NULL };
    actualCard = popFromDeck(&actualDeck);
    *rebuiltActualDeck = { actualCard, NULL };
    ASSERT_TRUE(ListMatch(rebuiltActualDeck, rebuiltExpectedDeck));
}

TEST(Test_popFromDeck, popFromOneFr52DeckTestRebuiltDeck) {
    ListCardNodePtr expectedDeck;
    ListCardNodePtr actualDeck;
    ReadFileOfOneFr52Deck(&actualDeck);
    ReadFileOfOneFr52Deck(&expectedDeck);
    ListCardNodePtr rebuiltActualDeck = NULL;
    Card actualCard = { 0 };
    ListCardNodePtr newNode = NULL;

    while (actualDeck != NULL) {
        newNode = (ListCardNodePtr)malloc(sizeof(ListCardNode));
        actualCard = popFromDeck(&actualDeck);
        newNode->card = actualCard;
        newNode->nextPtr = rebuiltActualDeck;
        rebuiltActualDeck = newNode;
    }

    while (rebuiltActualDeck != NULL) {
        newNode = (ListCardNodePtr)malloc(sizeof(ListCardNode));
        actualCard = popFromDeck(&rebuiltActualDeck);
        newNode->card = actualCard;
        newNode->nextPtr = actualDeck;
        actualDeck = newNode;
    }

    ASSERT_TRUE(ListMatch(actualDeck, expectedDeck));
}

