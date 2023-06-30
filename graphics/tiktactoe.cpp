#include<iostream>
#include<ctime>
char p1='O';
char p2='X';
void drawboard(char*);
bool playermove(char*);
bool playermove2(char*);
bool checkwinner(char*);
int checkdraw(char *);
int main()
{
    char name[9]={' ',' ',' ',' ',' ',' ',' ',' ',' '};
    std::cout<<"--------------------TicTakToeGame-----------\n\n";
    drawboard(name);
    while(true)
    {
        if(playermove(name)==true)
        break;
        if(checkdraw(name)==9){
            std::cout<<"\n\n-----------------The Game is draw--------------";
            break;
        }
        if(playermove2(name)==true)
        break;

    }
    return 0;
}
void drawboard(char *board)
{
    std::cout<<"     "<<"|"<<"     "<<"|"<<"     "<<std::endl;
    std::cout<<"     "<<"|"<<"     "<<"|"<<"     "<<std::endl;
    std::cout<<" "<<board[0]<<"   "<<"|"<<" "<<board[1]<<"   "<<"|"<<" "<<board[2]<<"   "<<std::endl;
    std::cout<<"_____"<<"|"<<"_____"<<"|"<<"_____"<<std::endl;
    std::cout<<"     "<<"|"<<"     "<<"|"<<"     "<<std::endl;
    std::cout<<" "<<board[3]<<"   "<<"|"<<" "<<board[4]<<"   "<<"|"<<" "<<board[5]<<"   "<<std::endl;
    std::cout<<"_____"<<"|"<<"_____"<<"|"<<"_____"<<std::endl;
    std::cout<<"     "<<"|"<<"     "<<"|"<<"     "<<std::endl;
    std::cout<<" "<<board[6]<<"   "<<"|"<<" "<<board[7]<<"   "<<"|"<<" "<<board[8]<<"   "<<std::endl;
    std::cout<<"     "<<"|"<<"     "<<"|"<<"     "<<std::endl;
    std::cout<<"     "<<"|"<<"     "<<"|"<<"     "<<std::endl;
}
bool playermove(char *name)
{
    int number;
    do{
        std::cout<<"P1:::"<<"Choose number between (1-9): ";
        std::cin>>number;
        number--;
        if(name[number]==' ')
        {
            name[number]=p1;
            break;
        }
        
    }while(true);
    drawboard(name);
    if(checkwinner(name)==true)
    return true;
    else 
    return false;
}
bool playermove2(char *name)
{
    int number;
    do{
        std::cout<<"P2:::"<<"Choose number between (1-9): ";
        std::cin>>number;
        number--;
        if(name[number]==' ')
        {
            name[number]=p2;
            break;
        }

    }while(true);
    drawboard(name);
    if(checkwinner(name)==true)
    return true;
    else 
    return false;
}
bool checkwinner(char*name)
{
    if(name[0]!=' ' && name[0]==name[1] && name[1]==name[2])
    {
        name[0]==p1?std::cout<<"P1 WON ":std::cout<<"P2 won";
    }
    else if(name[3]!=' ' && name[3]==name[4] && name[4]==name[5])
    {
        name[3]==p1?std::cout<<"P1 WON ":std::cout<<"P2 won";
    }
    else if(name[6]!=' ' && name[6]==name[7] && name[7]==name[8])
    {
        name[6]==p1?std::cout<<"P1 WON ":std::cout<<"P2 won";
    }
    else if(name[0]!=' ' && name[0]==name[3] && name[3]==name[6])
    {
        name[0]==p1?std::cout<<"P1 WON ":std::cout<<"P2 won";
    }
    else if(name[1]!=' ' && name[1]==name[4] && name[4]==name[7])
    {
        name[1]==p1?std::cout<<"P1 WON ":std::cout<<"P2 won";
    }
    else if(name[2]!=' ' && name[2]==name[5] && name[5]==name[8])
    {
        name[2]==p1?std::cout<<"P1 WON ":std::cout<<"P2 won";
    }
    else if(name[0]!=' ' && name[0]==name[4] && name[4]==name[8])
    {
        name[0]==p1?std::cout<<"P1 WON ":std::cout<<"P2 won";
    }
    else if(name[2]!=' ' && name[2]==name[4] && name[4]==name[6])
    {
        name[2]==p1?std::cout<<"P1 WON ":std::cout<<"P2 won";
    }
    else 
    return false;
    return true;
}
int checkdraw(char *name)
{
    int count=0;
    for(int i=0;i<9;i++)
    {
        if(name[i]!=' ')
        {
            count++;
        }
    }
    return count;
}