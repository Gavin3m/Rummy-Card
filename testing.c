int runCheck(card* hand, int handAmount){
    int winning = 0;
    int count[suit_amount+1];
    
    for(int i=0;i<=suit_amount;i++){
	    count[i]=0;
    }

    for(int i=0;i<=suit_amount;i++){
	    count[hand[i].number]++;
    }

    for(int i=0;i<=suit_amount;i++){
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