
//██████╗░██╗░░░██╗███╗░░░███╗███╗░░░███╗██╗░░░██╗  ░█████╗░░█████╗░██████╗░██████╗░
//██╔══██╗██║░░░██║████╗░████║████╗░████║╚██╗░██╔╝  ██╔══██╗██╔══██╗██╔══██╗██╔══██╗
//██████╔╝██║░░░██║██╔████╔██║██╔████╔██║░╚████╔╝░  ██║░░╚═╝███████║██████╔╝██║░░██║
//██╔══██╗██║░░░██║██║╚██╔╝██║██║╚██╔╝██║░░╚██╔╝░░  ██║░░██╗██╔══██║██╔══██╗██║░░██║
//██║░░██║╚██████╔╝██║░╚═╝░██║██║░╚═╝░██║░░░██║░░░  ╚█████╔╝██║░░██║██║░░██║██████╔╝
//╚═╝░░╚═╝░╚═════╝░╚═╝░░░░░╚═╝╚═╝░░░░░╚═╝░░░╚═╝░░░  ░╚════╝░╚═╝░░╚═╝╚═╝░░╚═╝╚═════╝░
// 𝙬𝙧𝙞𝙩𝙩𝙚𝙣 𝙗𝙮 𝙂𝙖𝙫𝙞𝙣3𝙢

#include <stdio.h>
#include <stdlib.h>

int CardMin = 1;
int CardMax = 52;

typedef struct{
    int number;
    char suit;
} card;

void createDeck(card* deck){
    char suit[] = {'C', 'S', 'H', 'D'};
    int suit_count = 0;

    for(int i = 1; i <= 52; i++){
        int j = i;
        while(13 < j){j -= 13;}
        if(i==14 || i==27 || i==40){suit_count++;}
        deck[i].number = j;
        deck[i].suit = suit[suit_count];
    }
}

void shuffle(card* deck, int min, int max, int count) {
    printf("Random numbers between %d and %d: ", min, max);

    for (int i = 0; i < count; i++) {
        int pos1 = rand() % (max - min + 1) + min;
        int pos2 = rand() % (max - min + 1) + min;
        card temp = deck[pos1];
        deck[pos1] = deck[pos2];
        deck[pos2] = temp;
        printf("%d %d\n", pos1, pos2);
    }
}

void displayDeck(card* deck, int min, int max){
    int counter = 0;
    printf("Displaying Set:\n");
    for(int i = min; i <= max; i++){
        printf("%d%c\t", deck[i].number, deck[i].suit);
        counter++;
        if(counter==13){printf("\n"); counter = 0;}
    }
    printf("\n\n\n\n");
}

void deal(card* deck, card* h1, card* h2, int amount){
    for(int i = 0; i <= amount; i++){
        h1[i] = deck[52-i-amount];
        h2[i] = deck[52-i];
    }
    for(int i = 52; 52-(amount*2) <= i; i--){
        deck[i].number = 0;
        deck[i].suit = 'X';
    }
}

void PlayTurn(card* deck, card* hand, int turn){
    displayDeck(hand, 0, 7);
    card temp;
    temp.number = deck[turn].number;
    temp.suit = deck[turn].suit;
    printf("%d of %c: do you take it?", temp.number, temp.suit);
    char input = getchar();
    getchar();
    return;
}


int main()
{   
    card deck[52];
    createDeck(deck);
    shuffle(deck, CardMin, CardMax, 10000);
    displayDeck(deck, 1, 52);

    card hand1[7];
    card hand2[7];

    deal(deck, hand1, hand2, 7);
    displayDeck(deck, 1, 52);

    int count = 0;
    while(1){
    count++;
    PlayTurn(deck, hand1, count);
    count++;
    PlayTurn(deck, hand2, count);
    }


    return 0;
}