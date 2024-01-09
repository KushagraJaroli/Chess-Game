#include<iostream>
#include<graphics.h>
using namespace std;
int arr[8][8]={0},moves[8][8]={0},checkvar=0,bkpos=4,wkpos=60,turn=0,castle[6]={0},garbagevar=0;
void printpawn(int x,int y){
    circle(x,y-16,8);
    line(x-13,y-3,x+13,y-3);
    line(x-13,y-3,x-13,y+3);
    line(x+13,y-3,x+13,y+3);
    line(x-13,y+3,x-8,y+3);
    line(x+13,y+3,x+9,y+3);
    line(x-8,y+3,x-16,y+16);
    line(x+9,y+3,x+16,y+16);
    line(x-16,y+16,x-16,y+24);
    line(x+16,y+16,x+16,y+24);
    line(x-16,y+24,x+16,y+24);
}
void printknight(int x,int y){
    line(x-4,y-20,x-4,y-27);
    arc(x-4,y-5,90,150,15);
    line(x-16,y-13,x-27,y+8);
    arc(x-21,y+8,180,360,6);
    line(x-15,y+8,x-4,y+3);
    arc(x-4,y+8,270,90,5);
    arc(x+4,y+24,126,184,15);
    line(x-11,y+24,x-20,y+24);
    line(x-20,y+24,x-20,y+32);
    line(x-20,y+32,x+25,y+32);
    line(x+25,y+24,x+25,y+32);
    line(x+17,y+24,x+25,y+24);
    ellipse(x-4,y+15,-24,90,23,42);
}
void printrook(int x,int y){
    line(x-5,y-27,x+5,y-27);
    line(x-22,y-27,x-12,y-27);
    line(x+12,y-27,x+22,y-27);
    line(x-22,y-27,x-22,y-15);
    line(x-12,y-27,x-12,y-18);
    line(x-5,y-27,x-5,y-18);
    line(x+5,y-27,x+5,y-18);
    line(x+12,y-27,x+12,y-18);
    line(x+22,y-27,x+22,y-15);
    line(x-12,y-18,x-5,y-18);
    line(x+5,y-18,x+12,y-18);
    line(x-22,y-15,x-13,y-6);
    line(x+22,y-15,x+13,y-6);
    line(x-13,y-6,x-13,y+10);
    line(x+13,y-6,x+13,y+10);
    line(x-13,y+10,x-22,y+18);
    line(x+13,y+10,x+22,y+18);
    line(x-22,y+18,x-22,y+30);
    line(x+22,y+18,x+22,y+30);
    line(x-22,y+30,x+22,y+30);
}
void printbishop(int x,int y){
    ellipse(x+26,y-12,152,180,25,20);
    ellipse(x+25,y-7,144,170,25,17);
    arc(x,y-28,-60,240,5);
    arc(x-5,y-12,-10,32,15);
    arc(x-5,y-12,48,60,15);
    arc(x+5,y-12,120,190,15);
    line(x-10,y-10,x-15,y-10);
    line(x+10,y-10,x+15,y-10);
    line(x-15,y-10,x-15,y-3);
    line(x+15,y-10,x+15,y-3);
    line(x-15,y-3,x-7,y-3);
    line(x+7,y-3,x+15,y-3);
    line(x-7,y-3,x-15,y+20);
    line(x+7,y-3,x+15,y+20);
    line(x-20,y+20,x-15,y+20);
    line(x+15,y+20,x+20,y+20);
    line(x-20,y+20,x-20,y+25);
    line(x+20,y+20,x+20,y+25);
    line(x-25,y+25,x-20,y+25);
    line(x+25,y+25,x+20,y+25);
    line(x-25,y+25,x-25,y+30);
    line(x+25,y+25,x+25,y+30);
    line(x-25,y+30,x+25,y+30);
}
void printqueen(int x,int y){
    arc(x-9,y-25,304,270,6);
    arc(x+7,y-25,304,270,6);
    arc(x-23,y-13,330,286,6);
    arc(x+22,y-13,290,230,6);
    line(x-23,y-7,x-20,y+20);
    line(x-19,y-10,x-13,y+3);
    line(x-11,y-21,x-13,y+3);
    line(x-6,y-21,x-1,y-2);
    line(x+5,y-21,x-1,y-2);
    line(x+9,y-21,x+11,y+3);
    line(x+18,y-9,x+11,y+3);
    line(x+23,y-8,x+20,y+20);
    line(x-20,y+20,x-30,y+20);
    line(x-30,y+20,x-30,y+30);
    line(x+20,y+20,x+30,y+20);
    line(x+30,y+20,x+30,y+30);
    line(x-30,y+30,x+30,y+30);
}
void printking(int x,int y){
    line(x-5,y,x-5,y+10);
    line(x+5,y-1,x+5,y+10);
    line(x-5,y+10,x-13,y+10);
    line(x+5,y+10,x+13,y+10);
    line(x-13,y+10,x-21,y-1);
    line(x+13,y+10,x+21,y-1);
    arc(x-13,y,0,188,8);
    arc(x+13,y,0,180,8);
    line(x+19,y+20,x+31,y+5);
    line(x-19,y+20,x-31,y+5);
    line(x+5,y-22,x+5,y-15);
    arc(x+16,y-2,-30,130,17);
    line(x-5,y-22,x-5,y-15);
    arc(x-16,y-2,48,210,17);
    line(x-15,y-22,x-5,y-22);
    line(x+5,y-22,x+15,y-22);
    line(x-15,y-22,x-15,y-28);
    line(x+15,y-22,x+15,y-28);
    line(x+5,y-28,x+15,y-28);
    line(x-15,y-28,x-5,y-28);
    line(x-5,y-28,x-5,y-35);
    line(x+5,y-28,x+5,y-35);
    line(x-5,y-35,x+5,y-35);
    line(x-25,y+20,x-19,y+20);
    line(x+19,y+20,x+25,y+20);
    line(x-25,y+20,x-25,y+30);
    line(x+25,y+20,x+25,y+30);
    line(x-25,y+30,x+25,y+30);
}
void print(int x,int y,int val){
    if(val==1 || val==11){
        printpawn(x,y);
        if(val==1){
            setfillstyle(SOLID_FILL,BLACK);
            floodfill(x,y-16,BLACK);
        }
    }else if(val==2 || val==12){
        printrook(x,y);
    }else if(val==3 || val==13){
        printknight(x,y);
    }else if(val==4 || val==14){
        printbishop(x,y);
    }else if(val==5 || val==15){
        printqueen(x,y);
    }else if(val==6 || val==16){
        printking(x,y);
    }
    if(val>0&&val<7){
        setfillstyle(SOLID_FILL,BLACK);
        floodfill(x,y,BLACK);
    }
}
int check(int,int);
int checklegalmove(int a,int b,int m[8][8]){
    int c=0;
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            if(m[i][j]>99){
                c++;
                int temp = arr[i][j];
                arr[i][j]=arr[a][b];
                arr[a][b]=0;
                if(arr[i][j]==6)
                    bkpos = (i*8) + j;
                if(arr[i][j]==16)
                    wkpos = (i*8) + j;
                if(turn%2!=0){
                    if(check(bkpos/8,bkpos%8)){
                        m[i][j]=0;
                        c--;
                    }
                }else{
                    if(check(wkpos/8,wkpos%8)){
                        m[i][j]=0;
                        c--;
                    }
                }
                arr[a][b]=arr[i][j];
                arr[i][j]=temp;
                if(arr[a][b]==6)
                    bkpos = (a*8) + b;
                if(arr[a][b]==16)
                    wkpos = (a*8) + b;
            }
        }
    }
    return c;
}
void castling(int i,int a){
    int x=0;
    if(castle[i+1]==0){
        if(arr[a][1]==0&&arr[a][2]==0&&moves[a][3]==100){
            moves[a][2]=100;
            garbagevar=checklegalmove(a,4,moves);
        }
    }
    if(castle[i+2]==0){
        if(moves[a][5]==100&&arr[a][6]==0){
            moves[a][6]=100;
            garbagevar=checklegalmove(a,4,moves);
        }
    }
}
void upgradepawn(int a, int b){
    setcolor(BLUE);
    rectangle(500+(b*80),50+(a*80),600+(b*80),150+(a*80));
    setfillstyle(SOLID_FILL,WHITE);
    floodfill(501+(b*80),51+(a*80),BLUE);
    setcolor(BLACK);
    for(int i=0;i<2;i++){
        line(500+(b*80),50+(a*80)+(i*100),600+(b*80),50+(a*80)+(i*100));
        line(500+(b*80)+(i*100),50+(a*80),500+(b*80)+(i*100),150+(a*80));
    }

    for(int i=0;i<3;i++){
        line(500+(b*80),75+(a*80)+(i*25),600+(b*80),75+(a*80)+(i*25));
    }
    setcolor(GREEN);
    char s[4][7]={"Queen","Bishop","Knight","Rook"};
    int add[4] = {20,22,15,0};
    for(int i=0;i<4;i++){
        outtextxy(570+add[i]+(b*80),75+(i*25)+(a*80),s[i]);
    }
    int x,y;
    while(1){
        if(ismouseclick(WM_MOUSEMOVE)){
            getmouseclick(WM_MOUSEMOVE,x,y);
        }
        if((x>500+(b*80)&&x<600+(b*80))&&(y>50+(a*80)&&y<150+(a*80))){
            setfillstyle(SOLID_FILL,WHITE);
            for(int i=0;i<4;i++){
                floodfill(501+(b*80),51+(i*25)+(a*80),BLACK);
                outtextxy(570+add[i]+(b*80),75+(i*25)+(a*80),s[i]);
            }
            for(int i=0;i<4;i++){
                if((x>500+(b*80)&&x<600+(b*80))&&(y>50+(i*25)+(a*80)&&y<75+(i*25)+(a*80))){
                    setbkcolor(14);
                    setfillstyle(SOLID_FILL,14);
                    floodfill(501+(b*80),51+(i*25)+(a*80),BLACK);
                    outtextxy(570+add[i]+(b*80),75+(i*25)+(a*80),s[i]);
                }
            }
            setbkcolor(WHITE);
        }
        if(ismouseclick(WM_LBUTTONDOWN)){
            getmouseclick(WM_LBUTTONDOWN,x,y);
            for(int i=0;i<4;i++){
                if((x>500+(b*80)&&x<600+(b*80))&&(y>50+(i*25)+(a*80)&&y<75+(i*25)+(a*80))){
                    int temparr[4]={4,3,2,1};
                    arr[a][b]+=temparr[i];
                    x=-1;
                }
            }
            if(x==-1)break;
        }
        delay(1);
    }
}
void kingmove(int a,int b,int m[8][8]){
    for(int i=-1;i<2;i++){
        for(int j=-1;j<2;j++){
            if(a+i>-1&&a+i<8&&b+j>-1&&b+j<8){
                if(arr[a+i][b+j]==0){
                    m[a+i][b+j]=100;
                }else if((arr[a+i][b+j]+arr[a][b]>16)&&(arr[a+i][b+j]+arr[a][b]<23)){
                    m[a+i][b+j]=101;
                }
            }
        }
    }
}
void bishopmove(int a,int b,int m[8][8]){
    int c1=0,c2=0,c3=0,c4=0;
    for(int i=1;i<8;i++){
        if((a-i)>-1&&(b-i)>-1&&c1==0){
            if(arr[a-i][b-i]==0){
                m[a-i][b-i]=100;
            }else{
                c1++;
                if(arr[a-i][b-i]+arr[a][b]>11&&arr[a-i][b-i]+arr[a][b]<22){
                    m[a-i][b-i]=101;
                }
            }
        }
        if((a-i)>-1&&(b+i)<8&&c2==0){
            if(arr[a-i][b+i]==0){
                m[a-i][b+i]=100;
            }else{
                c2++;
                if(arr[a-i][b+i]+arr[a][b]>11&&arr[a-i][b+i]+arr[a][b]<22){
                    m[a-i][b+i]=101;
                }
            }
        }
        if((a+i)<8&&(b-i)>-1&&c3==0){
            if(arr[a+i][b-i]==0){
                m[a+i][b-i]=100;
            }else{
                c3++;
                if(arr[a+i][b-i]+arr[a][b]>11&&arr[a+i][b-i]+arr[a][b]<22){
                    m[a+i][b-i]=101;
                }
            }
        }
        if((a+i)<8&&(b+i)<8&&c4==0){
            if(arr[a+i][b+i]==0){
                m[a+i][b+i]=100;
            }else{
                c4++;
                if(arr[a+i][b+i]+arr[a][b]>11&&arr[a+i][b+i]+arr[a][b]<22){
                    m[a+i][b+i]=101;
                }
            }
        }
    }
}
void knightmove(int a,int b,int m[8][8]){
    for(int i=-2;i<3;i++){
        if(i!=0){
            if(a+i>-1&&a+i<8&&b+abs(i)-3>-1&&arr[a+i][b+abs(i)-3]==0){
                m[a+i][b+abs(i)-3]=100;
            }else if(a+i>-1&&a+i<8&&b+abs(i)-3>-1&&arr[a+i][b+abs(i)-3]+arr[a][b]>11&&arr[a+i][b+abs(i)-3]+arr[a][b]<22){
                m[a+i][b+abs(i)-3]=101;
            }
            if(a+i>-1&&a+i<8&&b-abs(i)+3<8&&arr[a+i][b-abs(i)+3]==0){
                m[a+i][b-abs(i)+3]=100;
            }else if(a+i>-1&&a+i<8&&b-abs(i)+3<8&&arr[a+i][b-abs(i)+3]+arr[a][b]>11&&arr[a+i][b-abs(i)+3]+arr[a][b]<22){
                m[a+i][b-abs(i)+3]=101;
            }
        }
    }
}
void rookmove(int a,int b,int m[8][8]){
    int c1=0,c2=0,c3=0,c4=0;
    for(int i=1;i<8;i++){
        if((a-i)>-1&&c1==0){
            if(arr[a-i][b]==0){
                m[a-i][b]=100;
            }else{
                c1++;
                if(arr[a-i][b]+arr[a][b]>11&&arr[a-i][b]+arr[a][b]<22){
                    m[a-i][b]=101;
                }
            }
        }
        if((b+i)<8&&c2==0){
            if(arr[a][b+i]==0){
                m[a][b+i]=100;
            }else{
                c2++;
                if(arr[a][b+i]+arr[a][b]>11&&arr[a][b+i]+arr[a][b]<22){
                    m[a][b+i]=101;
                }
            }
        }
        if((b-i)>-1&&c3==0){
            if(arr[a][b-i]==0){
                m[a][b-i]=100;
            }else{
                c3++;
                if(arr[a][b-i]+arr[a][b]>11&&arr[a][b-i]+arr[a][b]<22){
                    m[a][b-i]=101;
                }
            }
        }
        if((a+i)<8&&c4==0){
            if(arr[a+i][b]==0){
                m[a+i][b]=100;
            }else{
                c4++;
                if(arr[a+i][b]+arr[a][b]>11&&arr[a+i][b]+arr[a][b]<22){
                    m[a+i][b]=101;
                }
            }
        }
    }
}
void pawnmove(int a,int b,int m[8][8]){
    int i=-1;
    if(arr[a][b]==1)
        i=1;
    if(arr[a+i][b]==0){
        m[a+i][b]=100;
        if(((i>0&&a==1)||(i<0&&a==6))&&arr[a+2*i][b]==0)
            m[a+2*i][b]=100;
    }
    if(arr[a][b]+arr[a+i][b+1]>11&&arr[a][b]+arr[a+i][b+1]<22&&b+1<8)
        m[a+i][b+1]=101;
    if(arr[a][b]+arr[a+i][b-1]>11&&arr[a][b]+arr[a+i][b-1]<22&&b-1>-1)
        m[a+i][b-1]=101;
}
void selected(int i,int j,int m[8][8]){
    if(arr[i][j]%10==6){
        kingmove(i,j,m);
    }else if(arr[i][j]%10==5){
        bishopmove(i,j,m);
        rookmove(i,j,m);
    }else if(arr[i][j]%10==4){
        bishopmove(i,j,m);
    }else if(arr[i][j]%10==3){
        knightmove(i,j,m);
    }else if(arr[i][j]%10==2){
        rookmove(i,j,m);
    }else if(arr[i][j]%10==1){
        pawnmove(i,j,m);
    }
}
int checkwin(){
    int n=0,temp[8][8]={0},c=0;
    if(turn%2==0)
        n=9;
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            if(n<arr[i][j]&&arr[i][j]<n+9){
                selected(i,j,temp);
                c+=checklegalmove(i,j,temp);
            }
        }
    }
    if(c==0){
        setcolor(BLUE);
        rectangle(580,260,920,450);
        setfillstyle(SOLID_FILL,WHITE);
        floodfill(601,261,BLUE);
        setcolor(BLACK);
        rectangle(580,260,920,450);
        rectangle(820,392,900,430);
        rectangle(600,392,800,430);
        setfillstyle(SOLID_FILL,3);
        floodfill(651,261,BLACK);
        setbkcolor(3);
        settextstyle(4,4,3);
        if(checkvar==1&&turn%2==0){
            outtextxy(855,315,"Game Over!!");
            outtextxy(840,370,"Black Wins");
        }else if(checkvar==1&&turn%2!=0){
            outtextxy(855,315,"Game Over!!");
            outtextxy(840,370,"White Wins");
        }else{
            outtextxy(880,315,"No Legal Moves");
            outtextxy(840,370,"It's a Draw");
        }
        setbkcolor(WHITE);
        outtextxy(890,425,"Exit");
        outtextxy(790,425,"New Game");
        int x,y,z=0;
        while(1){
            if(ismouseclick(WM_MOUSEMOVE)){
                getmouseclick(WM_MOUSEMOVE,x,y);
            }
            if((x>820&&x<900)&&(y>392&&y<430)){
                setbkcolor(14);
                setfillstyle(SOLID_FILL,14);
                floodfill(821,393,BLACK);
                outtextxy(890,425,"Exit");
                setbkcolor(WHITE);
            }else{
                setfillstyle(SOLID_FILL,15);
                floodfill(821,393,BLACK);
                outtextxy(890,425,"Exit");
            }
            if((x>600&&x<800)&&(y>392&&y<430)){
                setbkcolor(14);
                setfillstyle(SOLID_FILL,14);
                floodfill(601,393,BLACK);
                outtextxy(790,425,"New Game");
                setbkcolor(WHITE);
            }else{
                setfillstyle(SOLID_FILL,15);
                floodfill(601,393,BLACK);
                outtextxy(790,425,"New Game");
            }
            if(ismouseclick(WM_LBUTTONDOWN)){
                getmouseclick(WM_LBUTTONDOWN,x,y);
                if((x>820&&x<900)&&(y>392&&y<430))
                    exit(0);
                if((x>600&&x<800)&&(y>392&&y<430))
                    return 1;
            }
            delay(1);
        }
    }
    return 0;
}
int check(int x,int y){
    int n=0, temp[8][8]={0};
    if(arr[x][y]<8)
        n=9;
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            if(n<arr[i][j]&&arr[i][j]<n+9){
                selected(i,j,temp);
                if(temp[x][y]==101){
                    return 1;
                }
            }
        }
    }
    return 0;
}
void board(){
    cleardevice();
    setfillstyle(SOLID_FILL,WHITE);
    floodfill(100,100,WHITE);
    setcolor(BLACK);
    for(int i=0;i<9;i++){
        line(430,80+(i*80),1070,80+(i*80));
        line(430+(i*80),80,430+(i*80),720);
    }
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            print(470+(j*80),120+(i*80),arr[i][j]);
            if((i+j)%2!=0){
                setfillstyle(SOLID_FILL,2);
                floodfill(431+(j*80),81+(i*80),BLACK);
            }/*else{
                setfillstyle(SOLID_FILL,LIGHTGRAY);
                floodfill(431+(j*80),81+(i*80),BLACK);
            }*/
            if(arr[i][j]%10==6&&(i+j)%2!=0){
                setfillstyle(SOLID_FILL,GREEN);
                floodfill(463+(j*80),120+(i*80),BLACK);
                floodfill(477+(j*80),120+(i*80),BLACK);
            }
        }
    }
    setfillstyle(SOLID_FILL,RED);
    if(checkvar==1&&turn%2==0){
        floodfill(431+((wkpos%8)*80),81+((wkpos/8)*80),BLACK);
        floodfill(463+((wkpos%8)*80),120+((wkpos/8)*80),BLACK);
        floodfill(477+((wkpos%8)*80),120+((wkpos/8)*80),BLACK);
    }else if(checkvar==1&&turn%2!=0){
        floodfill(431+((bkpos%8)*80),81+((bkpos/8)*80),BLACK);
        floodfill(463+((bkpos%8)*80),120+((bkpos/8)*80),BLACK);
        floodfill(477+((bkpos%8)*80),120+((bkpos/8)*80),BLACK);
    }
    setbkcolor(WHITE);
    settextstyle(4,4,1);
    char s[] = "A       B        C       D       E        F       G        H ";
    outtextxy(1050,80,s);
    outtextxy(1050,745,s);
    char num[8][2] = {"8","7","6","5","4","3","2","1"};
    for(int i=0;i<8;i++){
        outtextxy(420,130+(i*80),num[i]);
        outtextxy(1095,130+(i*80),num[i]);
    }
}
int main(){
    initwindow(1536,864);
    start:
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            if(i==1 || i==6){
                arr[i][j]=1;
            }else if((i==0||i==7)&&(j==0||j==7)){
                arr[i][j]=2;
            }else if((i==0||i==7)&&(j==1||j==6)){
                arr[i][j]=3;
            }else if((i==0||i==7)&&(j==2||j==5)){
                arr[i][j]=4;
            }else if((i==0||i==7)&&j==3){
                arr[i][j]=5;
            }else if((i==0||i==7)&&j==4){
                arr[i][j]=6;
            }else{
                arr[i][j]=0;
            }
            if(i>5){
                arr[i][j] +=10;
            }
        }
    }
    checkvar=0;
    turn=0;
    board();
    int x,y,m=0,n=0;
    while(1){
        getmouseclick(WM_LBUTTONDOWN,x,y);
        if((x>430&&x<1070)&&(y<720&&y>80)){
            for(int i=0;i<8;i++){
                for(int j=0;j<8;j++){
                    int color=getpixel(431+(j*80),81+(i*80)),tvalue=0;
                    if(turn%2==0)
                        tvalue=9;
                    if((x>430+(j*80)&&x<510+(j*80))&&(y<160+(i*80)&&y>80+(i*80))&&tvalue<arr[i][j]&&(arr[i][j]<tvalue+9||arr[i][j]>20)){
                        for(int i=0;i<8;i++){
                            for(int j=0;j<8;j++){
                                if((i+j)%2!=0){
                                    setfillstyle(SOLID_FILL,2);
                                    floodfill(431+(j*80),81+(i*80),BLACK);
                                    if(arr[i][j]%10==6){
                                        floodfill(463+(j*80),120+(i*80),BLACK);
                                        floodfill(477+(j*80),120+(i*80),BLACK);
                                    }
                                }else{
                                    setfillstyle(SOLID_FILL,15);
                                    floodfill(431+(j*80),81+(i*80),BLACK);
                                    if(arr[i][j]%10==6){
                                        floodfill(463+(j*80),120+(i*80),BLACK);
                                        floodfill(477+(j*80),120+(i*80),BLACK);
                                    }
                                }
                            }
                        }
                        if(arr[i][j]<20){
                            if(arr[m][n]>20){
                                arr[m][n]-=20;
                                for(int a=0;a<8;a++){
                                    for(int b=0;b<8;b++){
                                        moves[a][b]=0;
                                    }
                                }
                            }
                            selected(i,j,moves);
                            garbagevar=checklegalmove(i,j,moves);
                            if(arr[i][j]==6&&castle[0]==0&&checkvar==0)
                                castling(0,0);
                            if(arr[i][j]==16&&castle[3]==0&&checkvar==0)
                                castling(3,7);
                            m=i;
                            n=j;
                            arr[i][j]+=20;
                            setfillstyle(SOLID_FILL,10);
                            floodfill(431+(j*80),81+(i*80),BLACK);
                            if(arr[i][j]%10==6){
                                floodfill(463+(j*80),120+(i*80),BLACK);
                                floodfill(477+(j*80),120+(i*80),BLACK);
                            }
                            for(int a=0;a<8;a++){
                                for(int b=0;b<8;b++){
                                    if(moves[a][b]==100){
                                        setfillstyle(SOLID_FILL,YELLOW);
                                        floodfill(431+(b*80),81+(a*80),BLACK);
                                    }else if(moves[a][b]==101){
                                        setfillstyle(SOLID_FILL,LIGHTRED);
                                        floodfill(431+(b*80),81+(a*80),BLACK);
                                    }
                                }
                            }
                        }else{
                            arr[i][j]-=20;
                            for(int a=0;a<8;a++){
                                for(int b=0;b<8;b++){
                                    moves[a][b]=0;
                                }
                            }
                        }
                        setfillstyle(SOLID_FILL,RED);
                        if(checkvar==1&&turn%2==0){
                            floodfill(431+((wkpos%8)*80),81+((wkpos/8)*80),BLACK);
                            floodfill(463+((wkpos%8)*80),120+((wkpos/8)*80),BLACK);
                            floodfill(477+((wkpos%8)*80),120+((wkpos/8)*80),BLACK);
                        }else if(checkvar==1&&turn%2!=0){
                            floodfill(431+((bkpos%8)*80),81+((bkpos/8)*80),BLACK);
                            floodfill(463+((bkpos%8)*80),120+((bkpos/8)*80),BLACK);
                            floodfill(477+((bkpos%8)*80),120+((bkpos/8)*80),BLACK);
                        }
                    }else if((x>430+(j*80)&&x<510+(j*80))&&(y<160+(i*80)&&y>80+(i*80))&&(color==12 || color==14)){
                        if(arr[m][n]>20){
                            if(arr[m][n]%10==6&&abs(n-j)==2){
                                arr[i][j]=arr[m][n]-20;
                                if(n>j){
                                    arr[i][j+1]=arr[i][j-2];
                                    arr[i][j-2]=0;
                                }else{
                                    arr[i][j-1]=arr[i][j+1];
                                    arr[i][j+1]=0;
                                }
                                arr[m][n]=0;

                            }else{
                                arr[i][j]=arr[m][n]-20;
                                arr[m][n]=0;
                            }
                            if(arr[i][j]==6){
                                bkpos = (i*8) + j;
                                castle[0]=1;
                            }
                            if(arr[i][j]==16){
                                wkpos = (i*8) + j;
                                castle[3]=1;
                            }
                            if(arr[i][j]%10==1&&(i==0||i==7))
                                upgradepawn(i,j);
                            if(n==0){
                                if(m==0)
                                    castle[1]=1;
                                if(m==7)
                                    castle[4]=1;
                            }else if(n==7){
                                if(m==0)
                                    castle[2]=1;
                                if(m==7)
                                    castle[5]=1;
                            }
                            if(turn%2==0)
                                checkvar = check(bkpos/8,bkpos%8);
                            else
                                checkvar = check(wkpos/8,wkpos%8);
                            turn++;
                            board();
                            for(int a=0;a<8;a++){
                                for(int b=0;b<8;b++){
                                    moves[a][b]=0;
                                }
                            }
                            if(checkwin())
                                goto start;
                        }
                    }
                }
            }
        }
        delay(1);
    }
    getch();
    return 0;
}
