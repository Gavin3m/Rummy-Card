
//██████╗░██╗░░░██╗███╗░░░███╗███╗░░░███╗██╗░░░██╗  ░█████╗░░█████╗░██████╗░██████╗░
//██╔══██╗██║░░░██║████╗░████║████╗░████║╚██╗░██╔╝  ██╔══██╗██╔══██╗██╔══██╗██╔══██╗
//██████╔╝██║░░░██║██╔████╔██║██╔████╔██║░╚████╔╝░  ██║░░╚═╝███████║██████╔╝██║░░██║
//██╔══██╗██║░░░██║██║╚██╔╝██║██║╚██╔╝██║░░╚██╔╝░░  ██║░░██╗██╔══██║██╔══██╗██║░░██║
//██║░░██║╚██████╔╝██║░╚═╝░██║██║░╚═╝░██║░░░██║░░░  ╚█████╔╝██║░░██║██║░░██║██████╔╝
//╚═╝░░╚═╝░╚═════╝░╚═╝░░░░░╚═╝╚═╝░░░░░╚═╝░░░╚═╝░░░  ░╚════╝░╚═╝░░╚═╝╚═╝░░╚═╝╚═════╝░
// 𝙬𝙧𝙞𝙩𝙩𝙚𝙣 𝙗𝙮 𝙂𝙖𝙫𝙞𝙣3𝙢

#include <stdio.h>
#include <stdlib.h>

int deck_amount = 52;
#define suit_amount 13
int hand_amount_0d = 6;
int shuffle_amount = 10000;

typedef struct{
    int number;
    char suit;
} card;

void createDeck(card* deck){
    char suit[] = {'C', 'S', 'H', 'D', 'A', 'B', 'E', 'F', 'G', 'I', 'J', 'K', 'L'};
    int suit_index = 0;

    for(int idx = 1; idx <= deck_amount; idx++){
        // set the card number to the index number
        int number = idx;
        // if its greater than the suit amount, subtract until suitable
        while(suit_amount < number){number -= suit_amount;}
        // if it is one greater than a multiple of the suit amount, use the next suit
        if((idx-1)%suit_amount == 0){suit_index++;}

        // set the card details on that index position in the deck
        deck[idx].number = number;
        deck[idx].suit = suit[suit_index];
    }
}

void shuffle(card* deck, int maxIdx, int shuffles) {
    // while shuffles can still be completed
    for (int cShuffle = 0; cShuffle < shuffles; cShuffle++) {
        // get two random index positions in the deck
        int pos1 = rand() % maxIdx + 1;
        int pos2 = rand() % maxIdx + 1;
        // swap them using a temporary card variable
        card temp = deck[pos1];
        deck[pos1] = deck[pos2];
        deck[pos2] = temp;
    }
}

void deal(card* deck, card* p1Hand, card* p2Hand, card* center, int hand_amount_0d){
    // while empty slots exist in both hands, fill them in using the back of the deck
    for(int idx = 0; idx <= hand_amount_0d; idx++){
        p1Hand[idx] = deck[deck_amount-idx-hand_amount_0d-1];
        p2Hand[idx] = deck[deck_amount-idx];
    }

    // place the first card
    int offset = (hand_amount_0d*2)-1;
    int final_count = deck_amount-offset-3;
    center[0].number = deck[final_count].number;
    center[0].suit = deck[final_count].suit;
    
    // replace all of those cards with blanks
    for(int idx = deck_amount; final_count <= idx; idx--){
        deck[idx].number = 0;
        deck[idx].suit = 'X';
    }
}

void displayDeck(card* deck, int minIdx, int maxIdx){
    // card count variable
    int counter = 0;

    // from the minimum index to the maximum index of a deck
    for(int i = minIdx; i <= maxIdx; i++){
        // print the card
        printf("%d%c\t", deck[i].number, deck[i].suit);
        // increase the counter
        counter++;
        // if the counter reaches the suit amount, create a new row for the next suit
        if(counter==suit_amount){printf("\n"); counter = 0;}
    }

    // proceed down the terminal
    printf("\n\n");
}

void MatchLoop(card* deck, card* p1, card* p2, int cardAmount){

}

int main()
{   
    card deck[52];
    card hand1[7];
    card hand2[7];
    card center[2];
    
    createDeck(deck);
    displayDeck(deck, 1, deck_amount);

    shuffle(deck, deck_amount, shuffle_amount);
    displayDeck(deck, 1, deck_amount);

    deal(deck, hand1, hand2, center, hand_amount_0d);
    displayDeck(deck, 1, deck_amount);

    int turn = 0;
    int cardIdx = deck_amount-(hand_amount_0d*2)-3;
    while(cardIdx!=0){

        printf("\n\t%d\t0\n\t%c\tX\n\n", center[0].number, center[0].suit);

        if(turn%2==1){displayDeck(hand2, 0, hand_amount_0d);}
        else{displayDeck(hand1, 0, hand_amount_0d);}
        for(int i=0;i<=hand_amount_0d;i++){printf("%d\t", i);}

        printf("\ndo you take it ([t]ake or [d]raw)?");

        

        char move = getchar();

        while(move!='t' && move!='d'){move = getchar();}

        switch(move){
            case 't':
                printf("Choose an index to swap out: ");
                int index;
                int input = scanf("%d", &index); 
                while(input < 0 && hand_amount_0d < input){input = scanf("%d", &index);}

                if(turn%2==1){
                    card temp = hand2[index];
                    hand2[index] = center[0];
                    center[0] = temp;
                }
                else{
                    card temp = hand1[index];
                    hand1[index] = center[0];
                    center[0] = temp;
                }
                if(turn%2==1){displayDeck(hand2, 0, hand_amount_0d);}
                else{displayDeck(hand1, 0, hand_amount_0d);}

                break;
            case 'd':
                // place the first card
                center[1].number = deck[cardIdx].number;
                center[1].suit = deck[cardIdx].suit;
                printf("\t\t\t%d\n\t\t\t%c\ndo you take it ([t]ake or [p]lace it down)? ", center[1].number, center[1].suit);

                char move = getchar();
                while(move!='t' && move!='p'){move = getchar();}
                
                if(move == 't'){
                    printf("Choose an index to swap out: ");
                    int index;
                    int input = scanf("%d", &index); 
                    while(input < 0 && hand_amount_0d < input){input = scanf("%d", &index);}

                    if(turn%2==1){
                        card temp = hand2[index];
                        hand2[index] = center[1];
                        center[1] = temp;
                    }
                    else{
                        card temp = hand1[index];
                        hand1[index] = center[1];
                        center[1] = temp;
                    }
                    if(turn%2==1){displayDeck(hand2, 0, hand_amount_0d);}
                    else{displayDeck(hand1, 0, hand_amount_0d);}
                }
                card temp = center[0];
                center[0] = center[1];
                center[1] = temp;
                if(turn%2==1){displayDeck(hand2, 0, hand_amount_0d);}
                else{displayDeck(hand1, 0, hand_amount_0d);}
                cardIdx--;
                break;
        }
        if(turn%2==1){checkWinCondition(hand2, hand_amount_0d+1);}
        else{checkWinCondition(hand1, hand_amount_0d+1);}
        
        printf("Turn ended: next player begins!!\n");
        turn++;
    }

    return 0;
}

int runCheck(card* hand, int handAmount){
    int winning = 0;
    int count[suit_amount+1];
    
    for(int i=0;i<=suit_amount;i++){
	    count[i]=0;
    }

    for(int i=0;i<=suit_amount;i++){
	    count[hand[i].number]++;
    }

    for(int i=0;i<=handAmount;i++){
        int index = i;
        int counter = 0;
        int run = 0;
        while(count[index]!=0){
            for(int i = 0;i<hand_amount_0d;i++){
                if(hand[i].number == index && hand[i].suit == hand[i+1].suit){
                    
                }
            }

        }

        //'0,1,2,3,4,5,6,7,8,9,10,11,12,13'
        //[0,0,3,0,1,0,1,1,1,0, 0, 0, 0, 0]
        



        if(2 < counter){
            index--;
            while(counter != 1){
                
                if (hand[index].suit == hand[index-1].suit){
                    count[hand[index].number]--;
                    index--;
                    counter--;
                    run++;
                }
                else{break;}
            }
            run++;
            if(3 <= run){return run;}
        }
    }
}

void checkWinCondition(card* hand, int handAmount){
    int winning = 0;
    int count[suit_amount+1];
    
    for(int i=0;i<=suit_amount;i++){
	    count[i]=0;
    }

    for(int i=0;i<=suit_amount;i++){
	    count[hand[i].number]++;
    }
    //'0,1,2,3,4,5,6,7,8,9,10,11,12,13'
    //[0,0,3,0,1,0,1,1,0,0, 1, 0, 0, 0]

    for(int i=0;i<=suit_amount;i++){
        int index = i;
        int counter = 0;
        while(count[index]!=0){counter++;index++;}
        if(2 < counter){
            index--;
            while(counter != 1){
                if (hand[index].suit == hand[index-1].suit){
                    index--;
                    counter--;
                }
                else{break;}
            }
        }
    }
    if(winning == handAmount+1){return 1;}
    return 0;
}