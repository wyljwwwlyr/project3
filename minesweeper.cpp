#include <iostream>
#include <ctime>
using namespace std;

const int areaLen=12;
const int num=10;

void food(int [][areaLen]);
void initHide(int [][areaLen]);
void initArea(int [][areaLen]);
void refresh(int [][areaLen]);
bool end(int, int, int [][areaLen]);
bool win(int [][areaLen], int [][areaLen]);

int main()
{
    int area[areaLen][areaLen];
    int hide[areaLen][areaLen];
    int x,y;
    initArea(area);
    initHide(hide);
    food(hide);
    refresh(area);
    cin>>x>>y;
    while(x<1 || x>10 || y<1 || y>10){
        cout<<"Please input correctly"<<endl;
        cin>>x>>y;
    }
    while(end(x,y,hide)){
        if(win(area,hide)){
            cout<<"\n you win!"<<endl;
            return 0;
        }
        area[x][y]=hide[x][y];
        refresh(area);
        cin>>x>>y;
    }
    return 0;
}


void initArea(int area[areaLen][areaLen])
{
    int i,j;
    for(i=0; i<areaLen; ++i)
    area[i][0]=area[i][areaLen-1]=0;
    for(j=1; j<areaLen-1; ++j)
    area[0][j]=area[areaLen-1][j]=0;
    for(i=1; i<areaLen-1; ++i)
    for(j=1; j<areaLen-1; ++j)
    area[i][j]=9;
}


void initHide(int hide[areaLen][areaLen])
{
    for(int i=0; i<areaLen; ++i)
    for(int j=0; j<areaLen; ++j)
    hide[i][j]=0;
}


//generate mine
void food(int hide[areaLen][areaLen])
{
    int x=4,y=4,count=0,i=0;
    srand(time(0));
    while(x!=0 && x!=areaLen-1 && y!=0 && y!=areaLen-1 && i<num)
    {
        x=rand()%10+1;
        y=rand()%10+1;
        if(hide[x][y]!=-1){
            hide[x][y]=-1;
            ++i;
        }
    }
    
    
    
    for(i=1; i<areaLen-1; ++i){
        for(int j=1; j<areaLen-1; ++j){
            count=0;
            if(hide[i][j]==-1)
            continue;
            if(hide[i-1][j-1]==-1)
            ++count;
            if(hide[i-1][j]==-1)
            ++count;
            if(hide[i-1][j+1]==-1)
            ++count;
            if(hide[i][j-1]==-1)
            ++count;
            if(hide[i][j+1]==-1)
            ++count;
            if(hide[i+1][j-1]==-1)
            ++count;
            if(hide[i+1][j]==-1)
            ++count;
            if(hide[i+1][j+1]==-1)
            ++count;
            hide[i][j]=count;
        }
    }
}

void refresh(int area[areaLen][areaLen])
{
    system("cls");
    int i,j;
    for(i=0; i<areaLen; ++i){
        for(j=0; j<areaLen; ++j){
            if(area[i][j]==9)
            cout<<'-'<<' ';
            else
            cout<<area[i][j]<<' ';
        }
        cout<<endl;
    }
    cout<<"\n please input x and y"<<endl;
}

//
bool end(int x, int y, int hide[areaLen][areaLen])
{
    if(hide[x][y]==-1){
        cout<<"\n Game Over"<<endl;
        system("pause");
        return 0;
    }
    return 1;
}

bool win(int area[areaLen][areaLen], int hide[areaLen][areaLen])
{
    int i,j,count=0;
    for(i=1; i<areaLen-1; ++i){
        for(j=1; j<areaLen-1; ++j){
            if(hide[i][j]==-1 && area[i][j]==hide[i][j])
            ++count;
        }
    }
    if(count==10)
    return 1;
    else return 0;
}
