#include <FEHLCD.h>
#include <FEHImages.h>
#include <FEHUtility.h>
#include <iostream> 
#include <iterator>
#include <map>
#include <string.h>
#include <cstring>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <FEHRandom.h>

//declare classes
class Pics //class for pictures
{
public:
void OpenPics();
void ClosePics();
FEHImage MBackground, MInstructions, CardBG, CredBG;
FEHImage C2, C3, C4, C5, C6, C7, C8, C9, C10, CJ, CQ, CK, CA;
FEHImage S2, S3, S4, S5, S6, S7, S8, S9, S10, SJ, SQ, SK, SA;
FEHImage D2, D3, D4, D5, D6, D7, D8, D9, D10, DJ, DQ, DK, DA;
FEHImage H2, H3, H4, H5, H6, H7, H8, H9, H10, HJ, HQ, HK, HA;
FEHImage Chip, BOC;
private:
};




class Card //class for some card variables.
{
    int id;
    public:
    char name[4];
    bool check;
    Card()
    {
        id = 0;
        strcpy(name,"hi");
    }
    Card(int num, char n[4])
    {
        id = num;
        strcpy(name,n);
        check = true;
    }
};

class Deck  //class with deck informations.
{
    
    public:
    Card names[52];
    void display(Deck d);
    int draw();
    Deck()
    {
    names[0] = Card(1,"as");
    names[1]=Card(2,"2s");
    names[2]=Card(3,"3s");
    names[3]=Card(4,"4s");
    names[4]=Card(5,"5s");
    names[5]=Card(6,"6s");
    names[6]=Card(7,"7s");
    names[7]=Card(8,"8s");
    names[8]=Card(9,"9s");
    names[9]=Card(10,"10s");
    names[10]=Card(11,"js");
    names[11]=Card(12,"qs");
    names[12]=Card(13,"ks");
    names[13]=Card(14,"ah");
    names[14]=Card(15,"2h");
    names[15]=Card(16,"3h");
    names[16]=Card(17,"4h");
    names[17]=Card(18,"5h");
    names[18]=Card(19,"6h");
    names[19]=Card(20,"7h");
    names[20]=Card(21,"8h");
    names[21]=Card(22,"9h");
    names[22]=Card(23,"10h");
    names[23]=Card(24,"jh");
    names[24]=Card(25,"qh");
    names[25]=Card(26,"kh");
    names[26]=Card(27,"ac");
    names[27]=Card(28,"2c");
    names[28]=Card(29,"3c");
    names[29]=Card(30,"4c");
    names[30]=Card(31,"5c");
    names[31]=Card(32,"6c");
    names[32]=Card(33,"7c");
    names[33]=Card(34,"8c");
    names[34]=Card(35,"9c");
    names[35]=Card(36,"10c");
    names[36]=Card(37,"jc");
    names[37]=Card(38,"qc");
    names[38]=Card(39,"kc");
    names[39]=Card(40,"ad");
    names[40]=Card(41,"2d");
    names[41]=Card(42,"3d");
    names[42]=Card(43,"4d");
    names[43]=Card(44,"5d");
    names[44]=Card(45,"6d");
    names[45]=Card(46,"7d");
    names[46]=Card(47,"8d");
    names[47]=Card(48,"9d");
    names[48]=Card(49,"10d");
    names[49]=Card(50,"jd");
    names[50]=Card(51,"qd");
    names[51]=Card(52,"kd");
    }
};
//declare functions
//function declarations
int chooseplayers();
int choosechips();
int choosebet(int n,int y);
int cardcount(int array[], int ccard);


int main()
{
    Pics Pic;
    Deck deck = Deck();
    //declare needed variables and classes/
    float xplay_button, yplay_button;
    float x_trash, y_trash;
    int DealerWon=0, NetChips=0, RoundsPlayed=0, count21=0, countBust=0;//all tracked stats
    int playernum, chipnum, quitvar=0, turn=1; //variables used in loops
    Pic.OpenPics();//opens all pictures
    FEHImage picarray[52]={Pic.SA, Pic.S2, Pic.S3, Pic.S4, Pic.S5, Pic.S6, Pic.S7, Pic.S8, Pic.S9, Pic.S10, Pic.SJ, Pic.SQ, Pic.SK, Pic.HA, Pic.H2, Pic.H3, Pic.H4, Pic.H5, Pic.H6, Pic.H7, Pic.H8, Pic.H9, Pic.H10, Pic.HJ, Pic.HQ, Pic.HK, Pic.CA, Pic.C2, Pic.C3, Pic.C4, Pic.C5, Pic.C6, Pic.C7, Pic.C8, Pic.C9, Pic.C10, Pic.CJ, Pic.CQ, Pic.CK, Pic.DA, Pic.D2, Pic.D3, Pic.D4, Pic.D5, Pic.D6, Pic.D7, Pic.D8, Pic.D9, Pic.D10, Pic.DJ, Pic.DQ, Pic.DK};//array with card picture pointers.
    LCD.SetFontColor(WHITE); //Draw Background
    Pic.MBackground.Draw(0,0);
    LCD.SetFontColor(WHITE);
    LCD.DrawRectangle(35,12,100,65);
    LCD.DrawRectangle(35,80,100,40);
    LCD.DrawRectangle(5,120,160,40);
    LCD.DrawRectangle(25,165,120,40);
    int cardvalue[52]={11, 2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10, 11, 2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10, 11, 2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10, 11, 2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10}; //array with values for cards
while(1)
{
    
    while(!LCD.Touch(&xplay_button,&yplay_button))
    {
       
    }
    while(LCD.Touch(&xplay_button,&yplay_button))
    {
    //LCD.Clear(BLACK);
    //LCD.WriteAt("Quit",0,200);
    }
    //*********************
    //main game code
    //*********************
    if(((xplay_button>35)&&(xplay_button<140))&&(yplay_button<70))
    {
        //declare variables used in game code.
        quitvar=1;
        LCD.Clear(BLACK);
        LCD.SetFontColor(WHITE);
        LCD.WriteAt("Quit",0,200);
        playernum=chooseplayers(); //choose number of players
        chipnum=choosechips(); //choose starting chip values
        int n, quitvar2=1, pturn;
        int playerbet;
        int playerbet2[4];
        int pfirstcard[4]={0, 0, 0, 0};
        int playerin[4]={0, 0, 0, 0};
        int player1s, player2s, player3s, player4s;
        int cardnum;
        int dc[10]={0};
        int p1[10]={0};
        int p2[10]={0};
        int p3[10]={0};
        int p4[10]={0};
        int shufstop=1;
        int shuffle[26];
        int checkcards[52];
        int ka, ja, la,sa, ha, oa, shufanim;
        int fix[5]; //fix variables used to solve problems in code with data storage issues. 
        int fix2[10];
        int fix3[4]; 
        int fix4; // has dealer points stored in it.
        int fix5a, fix5b;
        int netchips1, netchips2; //has net chips for each round, used for stats and for displaying chips lost/won.
        int ccard; //keeps track of current card in simulated deck (current card)
        int count; //used in function for card counting.
        int p1h, p2h, p3h, p4h;
        float xclickpos2, yclickpos2;  //track click positions
        int turn;  //used in loops for turns
        int hcardpos; //used in calculating changing locations
        int acecount; //used to track if you have an ace for point calculations
        int playerpoint[4]={0, 0, 0, 0};  //tracks player points
        int playerchip[4]; //tracks player chips
        int precalc[4]; //tracks chips before dealer hand calculated.
        int dealerhit; //track how many times dealer had to hit.
        for (int f=0;f<4;f++)
        {
            playerchip[f]=chipnum;//sets each players chips to chosen chip value
        }
        //creates array which states whether player is in or not
        for (int p=0;p<playernum;p++)
        {
            playerin[p]=1;
        }
        player1s=playerin[0]; //sets players status to in depending on if 1 or 2 player chosen.
        player2s=playerin[1];

        //begin game


        while (quitvar2==1)
        {
    //set variables to necessary start values.
        ccard=2;
        p1h=0;
        acecount=0;
        count=0;
        LCD.Clear(BLACK);
        LCD.WriteAt("Shuffling the Deck...", 30, 30); //animation for shuffling the deck
        for (shufanim=0;shufanim<=250;shufanim++)
        {
            LCD.WriteAt("Shuffling the Deck...", 30, 30);
            Pic.BOC.Draw(10*shufanim, 5*shufanim);
            Pic.BOC.Draw(10*shufanim+100, 5*shufanim);
            Pic.BOC.Draw(-10*shufanim+20, -5*shufanim);
            Pic.BOC.Draw(5*shufanim, -5*shufanim);
            LCD.Update();
            Sleep(1);
            LCD.Clear(BLACK);
        }
        
        
        //Start Shuffle, generates random deck each round.
        for (ja=0;ja<=51;ja++)//sets the deck checking array all to zero
        {
            checkcards[ja]=0;
        }
        for (ka=0;ka<=25;ka++)//generates a deck with random values 0-51
            {
                shuffle[ka]=deck.draw();
            }
        for (la=0;la<=25;la++)//checks previous array to see if it is repeated, if it isn't it updates the check array.
        {
            if(checkcards[shuffle[la]-1]==1)
            {
            shuffle[la]=deck.draw();
            la--;
            }
            else
            {
            checkcards[shuffle[la]-1]=1;
            }
        }
        //End Shuffle
        printf("PostShuffle:");
        printf("%d, %d",cardvalue[shuffle[0]], cardvalue[shuffle[1]]);
        fix3[0]=cardvalue[shuffle[0]]; //set certain fix values
        fix3[1]=cardvalue[shuffle[1]];
        fix3[2]=shuffle[0];
        fix3[3]=shuffle[1];
        printf("\nShuffle0: %d, %d", fix3[2], shuffle[0]); //values printed to command window for troubleshooting reasons
        printf("\nShuffle1: %d, %d", fix3[3], shuffle[1]);
        printf("\nDealerStartingValue: %d", fix3[0]+fix3[1]);


        //each player chooses their bet for the round
        LCD.Clear(BLACK);
        if (player1s==1)
        {
        playerbet2[0]=choosebet(playerchip[0], 1);
        }
        if (player2s==1)
        {
        LCD.Clear(BLACK);
        playerbet2[1]=choosebet(playerchip[1], 2);
        }
        //begin player 1 turn
        if (player1s==1)
        {
        playerbet=playerbet2[0];
        pturn=1;
        LCD.Update();//display background
        LCD.Clear(BLACK);
        LCD.SetFontColor(WHITE);
        Pic.CardBG.Draw(0,0);
        Pic.BOC.Draw(200,25);//place dealers original cards here
        picarray[shuffle[1]].Draw(250,25);
        playerchip[pturn-1]=playerchip[pturn-1]-playerbet;
        LCD.WriteAt("Dealer:",200,5);
        LCD.WriteAt("Turn: Player ",15,5);
        LCD.WriteAt(pturn, 165, 5);
        LCD.WriteAt("Quit",0,200);
        LCD.WriteAt("Chips:", 0, 35);
        LCD.WriteAt("Bet:", 0, 60);
        LCD.WriteAt("Hit", 15, 90);
        LCD.WriteAt("Stand", 65, 90);
        LCD.WriteAt(playerbet,50, 60);
        LCD.WriteAt("Card Count:", 170, 130);
        LCD.WriteAt(count, 200, 145);
        LCD.WriteAt(playerchip[pturn-1],70,35);
        pfirstcard[0]=ccard;
        picarray[shuffle[pfirstcard[0]]].Draw(15,120);
        picarray[shuffle[pfirstcard[0]+1]].Draw(65,120);
        //count if there are any aces
        acecount=0;
        if ((shuffle[pfirstcard[0]])==0||(shuffle[pfirstcard[0]]==13)||(shuffle[pfirstcard[0]]==26)||(shuffle[pfirstcard[0]]==39))
        {
        acecount=acecount+1;
        }
        if ((shuffle[pfirstcard[0]+1]==0)||(shuffle[pfirstcard[0]+1]==13)||(shuffle[pfirstcard[0]+1]==26)||(shuffle[pfirstcard[0]+1]==39))
        {
        acecount=acecount+1;
        }
        ccard+=2;
        count=cardcount(shuffle,ccard);
        //LCD.WriteAt("Dealer Total:", 180, 130);
        //LCD.WriteAt("Player Total:", 180, 155);
        LCD.WriteAt("Dealer Total:", 120, 190);
        LCD.WriteAt("Player Total:", 120, 215);
        turn=0;
        hcardpos=115;
        playerpoint[pturn]=(cardvalue[shuffle[2]])+(cardvalue[shuffle[3]]);
        playerpoint[0]=cardvalue[shuffle[0]]+cardvalue[shuffle[1]];
        if (acecount==2) //if 2 aces off the start, subtract 10 from score.
        {
            playerpoint[pturn]=playerpoint[pturn]-10;
            acecount=acecount-1;

        }
        do
        {
            LCD.Clear(BLACK);  //display game screen each loop.
            LCD.SetFontColor(WHITE);
            Pic.CardBG.Draw(0,0);
            Pic.BOC.Draw(200,25);   
            picarray[shuffle[1]].Draw(250,25);
            LCD.WriteAt("Dealer:",200,5);
            LCD.WriteAt("Turn: Player ",15,5);
            LCD.WriteAt(pturn, 165, 5);
            LCD.WriteAt("Quit",0,200);
            LCD.WriteAt("Chips:", 0, 35);
            LCD.WriteAt("Bet:", 0, 60);
            LCD.WriteAt("Hit", 15, 90);
            LCD.WriteAt("Stand", 65, 90);
            LCD.WriteAt(playerbet,50, 60);
            LCD.WriteAt(playerchip[pturn-1],75,35);
            picarray[shuffle[pfirstcard[0]]].Draw(15,120);
            LCD.WriteAt("Card Count", 200, 120);
            LCD.WriteAt(count, 240, 145);
            picarray[shuffle[pfirstcard[0]+1]].Draw(65,120);
            //LCD.WriteAt("Dealer Total:", 180, 130);
            //LCD.WriteAt("Player Total:", 180, 155);
            LCD.WriteAt("Dealer Total:", 120, 190);
            LCD.WriteAt("Player Total:", 120, 215);
            LCD.WriteAt(playerpoint[pturn],280, 215);
            LCD.WriteAt("?",280, 190);
            hcardpos=115;
            for (oa=pfirstcard[0]+2; oa < ccard; oa++)  //displays cards if player hit
            {
                picarray[shuffle[oa]].Draw(hcardpos,120);
                hcardpos+=15;
            }
            if (playerpoint[pturn]==21) //screen if player reaches 21
                {
                    LCD.WriteAt("21 Reached!",175, 95);
                    fix[0]=playerpoint[1];
                    Sleep(3000);
                    count21+=1;
                    break;
                }
            if (playerpoint[pturn]>=22) //screen if player busted
                {
                    LCD.WriteAt("You Busted!", 185, 95);
                    fix[0]=playerpoint[1];
                    Sleep(3000);
                    countBust+=1;
                    break;
                }
            while(!LCD.Touch(&xclickpos2,&yclickpos2)) //wait for player action
            {
            
            }
            while(LCD.Touch(&xclickpos2,&yclickpos2))

            {
    
            }
            if (((xclickpos2>10)&&(xclickpos2<55))&&(((yclickpos2<110))&&(yclickpos2>80)))//if player hits
                {

                if (playerpoint[pturn]<=20)
                {
                    if ((shuffle[ccard]==0)||(shuffle[ccard]==13)||(shuffle[ccard]==26)||(shuffle[ccard]==39))
                    {
                    acecount=acecount+1;
                    }

                playerpoint[pturn]=playerpoint[pturn]+cardvalue[shuffle[ccard]];

                    if ((playerpoint[pturn]>21)&&(acecount>0))
                    {
                    playerpoint[pturn]= playerpoint[pturn] - 10;
                    acecount=acecount-1;
                    }
                
                ccard+=1;
                count=cardcount(shuffle,ccard);
                p1h=1+p1h;
                }



    
                }
            else if(((xclickpos2>65)&&(xclickpos2<130))&&(((yclickpos2<110))&&(yclickpos2>80))) //if player stands
                {
                
                fix[0]=playerpoint[1];
                turn=0;
                break;

                }
            else if(((xclickpos2>5)&&(xclickpos2<40))&&(((yclickpos2<230))&&(yclickpos2>185))) //if player quits
                {

                quitvar2=0;
                turn=0;
                break;


        
                }
            }while (turn==0);
        if (quitvar2==0)
        {
            break;
        }
        
        }
        //End Player 1 Turn


        //Start Player 2 Turn
        if (player2s==1) //checks if player 2 is in.
        {
        playerbet=playerbet2[1]; //player 2 game screen
        pturn=2;
        LCD.Update();
        LCD.Clear(BLACK);
        LCD.SetFontColor(WHITE);
        Pic.CardBG.Draw(0,0);
        Pic.BOC.Draw(200,25);//place dealers original cards here
        picarray[shuffle[1]].Draw(250,25);
        //LCD.WriteAt(dc[0], 60, 60);
        //LCD.WriteAt(dc[1], 60, 90);
        playerchip[pturn-1]=playerchip[pturn-1]-playerbet;
        LCD.WriteAt("Dealer:",200,5);
        LCD.WriteAt("Turn: Player ",15,5);
        LCD.WriteAt(pturn, 165, 5);
        LCD.WriteAt("Quit",0,200);
        LCD.WriteAt("Chips:", 0, 35);
        LCD.WriteAt("Bet:", 0, 60);
        LCD.WriteAt("Hit", 15, 90);
        LCD.WriteAt("Stand", 65, 90);
        LCD.WriteAt("Card Count:", 175, 150);
        LCD.WriteAt(count, 200, 165);
        LCD.WriteAt(playerbet,50, 60);
        LCD.WriteAt(playerchip[pturn-1],70,35);
        pfirstcard[1]=ccard;
        picarray[shuffle[pfirstcard[1]]].Draw(15,120);
        picarray[shuffle[pfirstcard[1]+1]].Draw(65,120);
        acecount=0;
        //checks for initial aces
        if ((shuffle[pfirstcard[1]])==0||(shuffle[pfirstcard[1]]==13)||(shuffle[pfirstcard[1]]==26)||(shuffle[pfirstcard[1]]==39))
        {
        acecount=acecount+1;
        }
        if ((shuffle[pfirstcard[1]+1]==0)||(shuffle[pfirstcard[1]+1]==13)||(shuffle[pfirstcard[1]+1]==26)||(shuffle[pfirstcard[1]+1]==39))
        {
        acecount=acecount+1;
        }
        ccard+=2;
        count=cardcount(shuffle,ccard);
        LCD.WriteAt("Dealer Total:", 120, 190); 
        LCD.WriteAt("Player Total:", 120, 215);
        turn=0;
        hcardpos=115;
        playerpoint[pturn]=cardvalue[shuffle[ccard-2]]+cardvalue[shuffle[ccard-1]];
        if (acecount==2) //checks for 2 aces off initial deal.
        {
            playerpoint[pturn]=playerpoint[pturn]-10;
            acecount=acecount-1;

        }
        do
        {
            LCD.Clear(BLACK); //display game screen
            LCD.SetFontColor(WHITE);
            Pic.CardBG.Draw(0,0);
            Pic.BOC.Draw(200,25);//place dealers original cards here
            picarray[shuffle[1]].Draw(250,25);
            LCD.WriteAt("Dealer:",200,5);
            LCD.WriteAt("Turn: Player ",15,5);
            LCD.WriteAt(pturn, 165, 5);
            LCD.WriteAt("Quit",0,200);
            LCD.WriteAt("Chips:", 0, 35);
            LCD.WriteAt("Bet:", 0, 60);
            LCD.WriteAt("Hit", 15, 90);
            LCD.WriteAt("Stand", 65, 90);
            LCD.WriteAt(playerbet,50, 60);
            LCD.WriteAt("Card Count", 200, 120);
            LCD.WriteAt(count, 240, 145);
            LCD.WriteAt(playerchip[pturn-1],75,35);
            picarray[shuffle[pfirstcard[1]]].Draw(15,120);
            picarray[shuffle[pfirstcard[1]+1]].Draw(65,120);
            //LCD.WriteAt("Dealer Total:", 180, 130);
            //LCD.WriteAt("Player Total:", 180, 155);
            LCD.WriteAt("Dealer Total:", 120, 190);
            LCD.WriteAt("Player Total:", 120, 215);
            LCD.WriteAt(playerpoint[pturn],280, 215);
            LCD.WriteAt("?",280, 190);
            hcardpos=115;
            for (oa=pfirstcard[1]+2; oa < ccard; oa++)
            {
                picarray[shuffle[oa]].Draw(hcardpos,120);
                hcardpos+=15;
            }
            if (playerpoint[pturn]==21) //if player reaches 21
                {
                    LCD.WriteAt("21 Reached!",175, 95);
                    Sleep(3000);
                    count21+=1;
                    fix[1]=playerpoint[2];
                    playerpoint[pturn]=fix[1];
                    break;
                }
            if (playerpoint[pturn]>=22) //if player busts
                {
                    LCD.WriteAt("You Busted!", 185, 95);
                    fix[1]=playerpoint[2];
                    countBust+=1;
                    Sleep(3000);
                    break;
                }
            while(!LCD.Touch(&xclickpos2,&yclickpos2)) //wait for player action
            {
            
            }
            while(LCD.Touch(&xclickpos2,&yclickpos2))

            {
    
            }
            if (((xclickpos2>10)&&(xclickpos2<55))&&(((yclickpos2<110))&&(yclickpos2>80))) //if player hits
                {

                if (playerpoint[pturn]<=20)
                {
                    if ((shuffle[ccard]==0)||(shuffle[ccard]==13)||(shuffle[ccard]==26)||(shuffle[ccard]==39))
                    {
                    acecount=acecount+1;
                    }

                playerpoint[pturn]=playerpoint[pturn]+cardvalue[shuffle[ccard]];

                    if ((playerpoint[pturn]>21)&&(acecount>0))
                    {
                    playerpoint[pturn]= playerpoint[pturn] - 10;
                    acecount=acecount-1;
                    }
                
                ccard+=1;
                count=cardcount(shuffle,ccard);
                p1h=1+p1h;
                }



    
                }
            else if(((xclickpos2>65)&&(xclickpos2<130))&&(((yclickpos2<110))&&(yclickpos2>80))) //if player stands
                {
                //LCD.Write("Stand");
                fix[1]=playerpoint[2];
                turn=0;
                break;

                }
            else if(((xclickpos2>5)&&(xclickpos2<40))&&(((yclickpos2<230))&&(yclickpos2>185)))
                {

                quitvar2=0;
                turn=0;
                break;


        
                }
            }while (turn==0);
        if (quitvar2==0)
        {
            break;
        }
        
        }
        //End Player 2 turn



//begin point calculations

        fix5a=cardvalue[(fix3[2])];
        fix5b=cardvalue[(fix3[3])];
        fix4=fix5a+fix5b;
        printf("\nBegin Point Calculations:");
        printf("\nDealer Points: %d", fix4);
        printf("\nDealer Card Values: %d, %d", cardvalue[(fix3[2])], cardvalue[(fix3[3])]);
        printf("\nDealer Card Values: %d, %d", fix5a, fix5b);
        dealerhit=0;
        ccard=ccard+2;

        for (int y=0;y<=1;y++) //records player points before dealer hand calculated.
        {
            precalc[y]=playerchip[y]+playerbet2[y];
        }
        if ((fix4>=17)&&(fix4<=21)) //if dealer has reached 17
        {
            for (int a=1;a<=2;a++)
            {
                if ((fix[a-1]>=(fix4+1))&&(fix[a-1]<=21)) //player hand beats dealer hand, they get double their bet back
                {
                    playerchip[a-1]=playerchip[a-1]+(playerbet2[a-1]*2);
                }
                else if (fix[a-1]<=(fix4-1)) //player hand loses to dealer hand, they don't get any chips
                {
                    playerchip[a-1]=playerchip[a-1];
                }
                else if (fix[a-1]==fix4) //player hand ties dealer hand, player gets their initial bet back.
                {
                    playerchip[a-1]=playerchip[a-1]+playerbet2[a-1];
                }

            }
        }
        else if(fix4<=16)  //if dealer hasn't reached 21
        {
            printf("\nDealer Under 17\n");
            Sleep(1000);
            acecount=0;
            dealerhit=0;
            if ((shuffle[0])==0||(shuffle[0]==13)||(shuffle[0]==26)||(shuffle[0]==39)) //checks dealer hand for aces
                {
                acecount=acecount+1;
                }
            if ((shuffle[1]==0)||(shuffle[1]==13)||(shuffle[1]==26)||(shuffle[1]==39))
                {
                acecount=acecount+1;
                }
            while(fix4<=16)//adds cards until dealer reaches 17 or higher
            {
                if ((shuffle[ccard])==0||(shuffle[ccard]==13)||(shuffle[ccard]==26)||(shuffle[ccard]==39)) //checks dealt card for aces
                    {
                        acecount=acecount+1;
                    }
                    printf("\nPreAdd: %d", playerpoint[0]);
                    fix4=(fix4)+(cardvalue[shuffle[ccard]]);
                    printf("\nCardValueAdded: %d", cardvalue[shuffle[ccard]]);
                    printf("\nCardNumAdded: %d", shuffle[ccard]);
                    printf("\nPostAdd: %d", fix4);
                if ((fix4>=22)&&(acecount>=1)) //if there are aces in the hand, and it went over 21, it subtracts 10 from dealer score
                    {
                    fix4=fix4-10;
                    acecount=acecount-1;
                    printf("\n10 Subtracted");
                    }
                ccard=ccard+1;
                dealerhit=dealerhit+1;
            }
            printf("\ndealer threshold reached");
            if (fix4>=22)//dealer busted
                {
                    printf("\nDealer Busted!!!\n");
                    for (int q=0;q<=1;q++)
                    {
                        if (fix[q]<=21)
                        {
                        
                        playerchip[q]=playerchip[q]+(2*playerbet2[q]); //awards chips to all players under 21.
                        }
                    }
                }
            else if(fix4<=21)//dealer between 17 and 21
                {
                    for (int a=1;a<=2;a++)
                    {
                        if ((fix[a-1]>fix4)&&(fix[a-1]<=21)) //players who beat dealer hand get their chip back
                            {
                                playerchip[a-1]=playerchip[a-1]+(playerbet2[a-1]*2);
                            }
                        else if (fix[a-1]<fix4) //players who lose to dealer hand get no chips back
                            {
                                playerchip[a-1]=playerchip[a-1];
                            }
                        else if (fix[a-1]==fix4) //players who tie dealer hand get their initial bet back
                            {
                            playerchip[a-1]=playerchip[a-1]+playerbet2[a-1];
                            }

                    }
                }
        
        }
        LCD.Clear(BLACK);
        Pic.CardBG.Draw(0,0);
        printf("\nShuffle0: %d, %d", fix3[2], shuffle[0]);
        printf("\nShuffle1: %d, %d", fix3[3], shuffle[1]);
        picarray[(fix3[2])].Draw(10, 170);
        picarray[(fix3[3])].Draw(60,170);
        hcardpos=60;
        oa=0;
        ccard=ccard-dealerhit;
        
        netchips1=playerchip[0]-precalc[0]; //find net chips for each player.
        netchips2=playerchip[1]-precalc[1];
        if (player1s==0)//if player is out, sets their net chips to 0
        {
            netchips1=0;
        }
        if(player2s==0)
        {
            netchips2=0;
        }
        LCD.Update();
        for (oa=dealerhit;oa>=1;oa--) //will print all cards that the dealer hit for.
        {
            picarray[shuffle[ccard]].Draw(oa*50+60, 170);
            ccard=ccard+1;
        }
        LCD.WriteAt("Dealer: ", 0, 5); //print all dealer cards, as well as player points, dealer points, and chips gained/lost
        LCD.WriteAt("Dealer Cards:", 10, 150);
        LCD.WriteAt(fix4, 90, 5);
        //prints screen, with certain screen based on if player lost, gained, or got pushed. 
        if (player1s==1)
        {
            LCD.WriteAt("\nPlayer 1:", 0, 40); 
            LCD.WriteAt(fix[0], 130, 40);
        }
        
        if (player2s==1)
        {
            LCD.WriteAt("\nPlayer 2:", 0, 75);
            LCD.WriteAt(fix[1], 130, 75);
        }
        if ((player1s==1)&&(netchips1>=1))
        {
            LCD.WriteAt("+   Chips",180, 40);
            LCD.WriteAt(netchips1, 200, 40);
        }
        else if((player1s==1)&&(netchips1<=-1))
        {
            LCD.WriteAt(" Chips",220, 40);
            LCD.WriteAt(netchips1, 190, 40);
        }
        else if((player1s==1)&&(netchips1==0))
        {
            LCD.WriteAt("Push",210, 40);
        }
        if ((player2s==1)&&(netchips2>=1))
        {
            LCD.WriteAt("+   Chips",180, 75);
            LCD.WriteAt(netchips2, 200, 75);
        }
        else if((player2s==1)&&(netchips2<=-1))
        {
            LCD.WriteAt(" Chips",220, 75);
            LCD.WriteAt(netchips2, 190, 75);
        }
        else if((player2s==1)&&(netchips2==0))
        {
            LCD.WriteAt("Push",210, 75);
        }
        Sleep(7000);
        printf("\nplayer1chips:");
        printf("%d",playerchip[0]);
        if (playerchip[0]<=0) //if player 1 is out of chips, takes them out of game
        {
            printf("chip check p1");
            player1s=0;
            LCD.Clear(BLACK);
            Pic.CredBG.Draw(0,0);
            LCD.SetFontColor(WHITE);
            LCD.WriteAt("Player 1 Ran Out of Chips.", 10, 20);
            LCD.WriteAt("Player 1 is Out!", 20, 70);
            Sleep(4000);
        }
        if (playerchip[1]<=0) //if player 2 is out of chips, takes them out of game
        {
            player2s=0;
            LCD.Clear(BLACK);
            Pic.CredBG.Draw(0,0);
            LCD.SetFontColor(WHITE);
            LCD.WriteAt("Player 2 Ran Out of Chips.", 10, 20);
            LCD.WriteAt("Player 2 is Out!", 20, 70);
            Sleep(4000);
        }
        printf("\nBothOutCheck");
        printf("\n%d %d\n", player1s, player2s);
        if ((player1s==0)&&(player2s==0)) //checks if both players are out, if so, ends the game
        {
            printf("\nboth out check");
            quitvar2==0;
            LCD.Clear(BLACK);
            LCD.SetFontColor(WHITE);
            Pic.CredBG.Draw(0,0);
            LCD.SetFontColor(WHITE);
            LCD.WriteAt("All Players Are Out", 60, 50);
            LCD.WriteAt("\nGame Over!", 60, 80);
            Sleep(3000);
            LCD.WriteAt("Quit",0,200);
            break;
        }

    //track statistics at end of round
        NetChips=netchips1+netchips2; //calculates net chips for stats page
        if (NetChips>=-1)
        {
            DealerWon+=1; //check if dealer won hand (if net chips is negative for players combined.)
        }
        RoundsPlayed+=1; //records rounds for stats
        printf("\n\nEnd of Game:");
        printf("\nplayer1:");
        printf("%d", player1s);
        printf("\nplayer2:");
        printf("%d", player2s);
        }//End of "Round"
        
        

        //LCD.Write("Reached");
        //LCD.Clear(BLACK);

    
    } //end of a "Round", loops again if game isn't over.
    //*********************
    //End Main Game Code
    //*********************
    //stats code
    else if(((xplay_button>5)&&(xplay_button<140))&&((yplay_button>80)&&(yplay_button<120)))
    {
        //display stats screen
        quitvar=1;
        LCD.Clear(BLACK);
        Pic.CredBG.Draw(0,0);
        LCD.SetFontColor(WHITE);
        LCD.WriteAt("Rounds Played:", 10, 10);
        LCD.WriteAt(RoundsPlayed, 180, 10);
        LCD.WriteAt("Net Chips:", 10, 40);
        LCD.WriteAt(NetChips, 135, 40);
        LCD.WriteAt("Rounds Dealer Won:", 10, 70);
        LCD.WriteAt(DealerWon, 230, 70);
        LCD.WriteAt("21s:", 10, 100);
        LCD.WriteAt(count21, 60, 100);
        LCD.WriteAt("Busts:", 10, 130);
        LCD.WriteAt(countBust, 80, 130);
        LCD.WriteAt("Quit",0,200);
    }
    //instructions code
    else if(((xplay_button>5)&&(xplay_button<180))&&((yplay_button>120)&&(yplay_button<160)))
    {
        //display instructions
        quitvar=1;
        LCD.Clear(BLACK);
        LCD.Write("Instructions Selected");
        Pic.MInstructions.Draw(0,0);
        LCD.SetFontColor(WHITE);
        LCD.WriteAt("Quit",0,200);
        
    }
    //credits code
    else if(((xplay_button>5)&&(xplay_button<150))&&((yplay_button>160)&&(yplay_button<210)))
    {
        //LCD.Write("Credits Selected");
        quitvar=1;
        LCD.Clear(BLACK);
        Pic.CredBG.Draw(0,0);
        LCD.SetFontColor(WHITE);
        LCD.WriteAt("Producers:", 85, 40);
        LCD.WriteAt("Ryan de Beer", 85, 70);
        LCD.WriteAt("Josh Mulyadi", 85, 100);
        LCD.WriteAt("Quit",0,200);
    }
    //quit code
    if (quitvar==1){
    LCD.WriteAt("Quit",0,200);
    while(1)
    {
        while(!LCD.Touch(&xplay_button,&yplay_button))
        {

        }
        while(LCD.Touch(&xplay_button,&yplay_button))
        {

        }
        if(((xplay_button>0)&&(xplay_button<60))&&(yplay_button>190))
        {
        LCD.Clear(BLACK);
        Pic.MBackground.Draw(0,0);
        LCD.SetFontColor(WHITE);
        LCD.DrawRectangle(35,12,100,65);
        LCD.DrawRectangle(35,80,100,40);
        LCD.DrawRectangle(5,120,160,40);
        LCD.DrawRectangle(25,165,120,40);
        quitvar=0;
        break;
        }
    }
    }
}
    
    LCD.Update();    
    return 0;
Pic.ClosePics(); //function to close all pictures.
}
//
//End Main Function
//



//Choose # Players
int chooseplayers() //function that lets user choose a game with one or two players
{
    Pics Pic;
    LCD.Clear(BLACK);
    LCD.SetFontColor(WHITE);
    LCD.DrawRectangle(15,10,300,150);
    LCD.WriteAt("        1    2     ", 20, 100);
    LCD.WriteAt("Choose Amount of Players",20,20);
    float xclickpos, yclickpos;
    int plyn, loopv=1;
    do
    {
     while(!LCD.Touch(&xclickpos,&yclickpos))
    {
    
    }
    while(LCD.Touch(&xclickpos,&yclickpos))
    {
    
    }
    if(((xclickpos>115)&&(xclickpos<135))&&((yclickpos<120))&&(yclickpos>95)) //one player 
    {
        
        plyn=1;
        break;


    }
    else if(((xclickpos>170)&&(xclickpos<195))&&((yclickpos<120))&&(yclickpos>95)) //two player
    {
        
        plyn=2;
        break;
        
    }
    }while (loopv==1);
    LCD.Clear(BLACK);
    return plyn; //return # players
}



//Open all pictures
void Pics::OpenPics()
{
    
    MBackground.Open("menFEH.pic");
    MInstructions.Open("MnBKRDFEH.pic");
    CardBG.Open("CardBackgroundFEH.pic");
    C2.Open("2_of_clubsFEH.pic");
    C3.Open("3_of_clubsFEH.pic");
    C4.Open("4_of_clubsFEH.pic");
    C5.Open("5_of_clubsFEH.pic");
    C6.Open("6_of_clubsFEH.pic");
    C7.Open("7_of_clubsFEH.pic");
    C8.Open("8_of_clubsFEH.pic");
    C9.Open("9_of_clubsFEH.pic");
    C10.Open("10_of_clubsFEH.pic");
    CJ.Open("jack_of_clubsFEH.pic");
    CQ.Open("queen_of_clubsFEH.pic");
    CK.Open("king_of_clubsFEH.pic");
    CA.Open("ace_of_clubsFEH.pic");
    S2.Open("2_of_spadesFEH.pic");
    S3.Open("3_of_spadesFEH.pic");
    S4.Open("4_of_spadesFEH.pic");
    S5.Open("5_of_spadesFEH.pic");
    S6.Open("6_of_spadesFEH.pic");
    S7.Open("7_of_spadesFEH.pic");
    S8.Open("8_of_spadesFEH.pic");
    S9.Open("9_of_spadesFEH.pic");
    S10.Open("10_of_spadesFEH.pic");
    SJ.Open("jack_of_spadesFEH.pic");
    SQ.Open("queen_of_spadesFEH.pic");
    SK.Open("king_of_spadesFEH.pic");
    SA.Open("ace_of_spadesFEH.pic");
    D2.Open("2_of_diamondsFEH.pic");
    D3.Open("3_of_diamondsFEH.pic");
    D4.Open("4_of_diamondsFEH.pic");
    D5.Open("5_of_diamondsFEH.pic");
    D6.Open("6_of_diamondsFEH.pic");
    D7.Open("7_of_diamondsFEH.pic");
    D8.Open("8_of_diamondsFEH.pic");
    D9.Open("9_of_diamondsFEH.pic");
    D10.Open("10_of_diamondsFEH.pic");
    DJ.Open("jack_of_diamondsFEH.pic");
    DQ.Open("queen_of_diamondsFEH.pic");
    DK.Open("king_of_diamondsFEH.pic");
    DA.Open("ace_of_diamondsFEH.pic");
    H2.Open("2_of_heartsFEH.pic");
    H3.Open("3_of_heartsFEH.pic");
    H4.Open("4_of_heartsFEH.pic");
    H5.Open("5_of_heartsFEH.pic");
    H6.Open("6_of_heartsFEH.pic");
    H7.Open("7_of_heartsFEH.pic");
    H8.Open("8_of_heartsFEH.pic");
    H9.Open("9_of_heartsFEH.pic");
    H10.Open("10_of_heartsFEH.pic");
    HJ.Open("jack_of_heartsFEH.pic");
    HQ.Open("queen_of_heartsFEH.pic");
    HK.Open("king_of_heartsFEH.pic");
    HA.Open("ace_of_heartsFEH.pic");
    Chip.Open("ChipsFEH.pic");
    BOC.Open("BackOfCardFEH.pic");
    CredBG.Open("CredBGFEH.pic");
    return;
}



//close all pictures
void Pics::ClosePics()
{
    MBackground.Close();
    MInstructions.Close();
    CardBG.Close();
    C2.Close();
    D2.Close();
    H2.Close();
    S2.Close();
    C3.Close();
    D3.Close();
    H3.Close();
    S3.Close();
    C4.Close();
    D4.Close();
    H4.Close();
    S4.Close();
    C5.Close();
    D5.Close();
    H5.Close();
    S5.Close();
    C6.Close();
    D6.Close();
    H6.Close();
    S6.Close();
    C7.Close();
    D7.Close();
    H7.Close();
    S7.Close();
    C8.Close();
    D8.Close();
    H8.Close();
    S8.Close();
    C9.Close();
    D9.Close();
    H9.Close();
    S9.Close();
    C10.Close();
    D10.Close();
    H10.Close();
    S10.Close();
    CJ.Close();
    DJ.Close();
    HJ.Close();
    SJ.Close();
    CQ.Close();
    DQ.Close();
    HQ.Close();
    SQ.Close();
    CK.Close();
    DK.Close();
    HK.Close();
    SK.Close();
    CA.Close();
    DA.Close();
    HA.Close();
    SA.Close();
}



//choose starting # of chips
int choosechips()
{
    Pics Pic;
    LCD.Clear(BLACK);
    Pic.CredBG.Draw(0,0);
    LCD.WriteAt("Choose Amount of Chips",20,20);
    LCD.WriteAt("+", 190, 100);
    LCD.WriteAt("-", 125, 100);
    LCD.WriteAt("Done", 145, 130);
    LCD.DrawRectangle(15,10,300,150);
    float xclickpos, yclickpos;
    int loopv=1, nchips=10;
    do
    {
    LCD.WriteAt(nchips, 150, 100);
     while(!LCD.Touch(&xclickpos,&yclickpos))
        {
    
        }
    while(LCD.Touch(&xclickpos,&yclickpos))
        {
    
        }

    if (((xclickpos>120)&&(xclickpos<140))&&(((yclickpos<120))&&(yclickpos>95)))
    {
        if (nchips>=2) //allows for minimum of a one chip 
        {
        nchips=nchips-1;
        LCD.Clear(BLACK);
        Pic.CredBG.Draw(0,0);
        LCD.WriteAt("Choose Amount of Chips",20,20);
        LCD.WriteAt("+", 190, 100);
        LCD.WriteAt("-", 125, 100);
        LCD.WriteAt("Done", 145, 130);
        LCD.DrawRectangle(15,10,300,150);
        
        }
        
    
    }
    else if(((xclickpos>185)&&(xclickpos<210))&&(((yclickpos<120))&&(yclickpos>95)))
    {
      
        nchips=nchips+1;
        LCD.Clear(BLACK);
        Pic.CredBG.Draw(0,0);
        LCD.WriteAt("Choose Amount of Chips",20,20);
        LCD.WriteAt("+", 190, 100);
        LCD.WriteAt("-", 125, 100);
        LCD.WriteAt("Done", 145, 130); 
        LCD.DrawRectangle(15,10,300,150);
       

    }
    else if(((xclickpos>140)&&(xclickpos<200))&&(((yclickpos<155))&&(yclickpos>123)))
    {
        //LCD.Write("Click3");
    
        break;
        
    }
    
    }while (loopv==1);
    LCD.Clear(BLACK);
    return nchips;

}



void Deck::display(Deck d)
{
    for(int i = 0; i< sizeof(d)/8; i++){
        printf("%s",d.names[i].name);
    }
}


//generate random card (number 0->51)
int Deck::draw()
{
    int r = Random.RandInt();
    int n=(r%51);
    return n;
}


void deal(Deck d, int num){
    int n;
    for(int i = num; i>0; i--)
    {
        n=d.draw();
    }
}

//choose # of chips for bet
int choosebet(int playerchips, int playerturn)
{
//display screen
int done=0, s=2;
float xclickpos, yclickpos;
LCD.SetFontColor(WHITE);
LCD.WriteAt("Choose Bet:",20,60);
LCD.WriteAt("+", 190, 100);
LCD.WriteAt("-", 125, 100);
LCD.WriteAt("Done", 145, 130);
LCD.WriteAt("Chips:", 15, 35);
LCD.WriteAt(playerturn, 165, 5);
LCD.WriteAt("Turn: Player ",15,5);
LCD.WriteAt(playerchips,90,35);


do
{

LCD.WriteAt(s, 150, 100);
while(!LCD.Touch(&xclickpos,&yclickpos))
    {

    }
while(LCD.Touch(&xclickpos,&yclickpos))

    {
    
    }
if (((xclickpos>120)&&(xclickpos<140))&&(((yclickpos<120))&&(yclickpos>95)))
    {
        if (s>=2) //subtract a chip 
        {
        s=s-1;
        LCD.Clear(BLACK);
        LCD.WriteAt("Choose Bet:",20,60);
        LCD.WriteAt("+", 190, 100);
        LCD.WriteAt("-", 125, 100);
        LCD.WriteAt("Done", 145, 130);
        LCD.WriteAt("Chips:", 15, 35);
        LCD.WriteAt(playerturn, 165, 5);
        LCD.WriteAt("Turn: Player ",15,5);
        LCD.WriteAt(playerchips,90,35);
        
        }
        //break;
    
    }
    else if(((xclickpos>185)&&(xclickpos<210))&&(((yclickpos<120))&&(yclickpos>95)))
    {
      if (s<playerchips) //add a chip
      {
        s=s+1;
        LCD.Clear(BLACK);
        LCD.WriteAt("Choose Bet:",20,60);
        LCD.WriteAt("+", 190, 100);
        LCD.WriteAt("-", 125, 100);
        LCD.WriteAt("Done", 145, 130);
        LCD.WriteAt("Chips:", 15, 35);
        LCD.WriteAt(playerturn, 165, 5);
        LCD.WriteAt("Turn: Player ",15,5);
        LCD.WriteAt(playerchips,90,35);
        
      }
       

    }
    else if(((xclickpos>140)&&(xclickpos<200))&&(((yclickpos<155))&&(yclickpos>123)))
    {
        //selected done.
    
        break;
        
    }
}while (done==0);

return s;
}

//function used to calculate the card counting value
int cardcount(int array[], int ccard)
{
    int cnt = 0;
for (int i=0; i<ccard; i++)
{
    if(array[i] % 13 >= 1 && array[i] % 13 <= 5)
    {
        cnt++;
    }
    else if(array[i] % 13 >= 6 && array[i] % 13 <= 8)
    {

    }
    else
    {
        cnt--;
    }
}
return cnt;
}
