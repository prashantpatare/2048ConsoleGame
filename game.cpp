# include <cstdlib>
# include <iostream>
# include <iomanip>
# include <ctime>
# include <cstdio>
# include <conio.h>

using namespace std;

//Structure for 2048
int  N=5;
int  m[10][10];
char dir;
int  di,dj;
int  nFilled=0;

//auxiliary functions
bool isEnd(int i, int j){
  return ( i<0 || j < 0 || i>N || j>N);
}

void initMatrix()
{
  for(int i=0;i<N;i++)
     for(int j=0;j<N;j++)
        m[i][j]=0;
}

void generateInitial(){
  initMatrix();
  int i,j,i2,j2;
  i=rand()%N;
  j=rand()%N;

  do{
       i2=rand()%N;
       j2=rand()%N;
    }while(i==i2 && j==j2);

   m[i][j]=2;
   m[i2][j2]=2;
   nFilled=2;
}

void display()
{
   cout<<endl;
   for(int i=0;i<N;i++){
      cout <<endl<<" ";
      for(int j=0;j<N;j++)
           if(m[i][j])
              cout<<setw(2)<<m[i][j]<<"  ";
           else cout<<"--  ";
   }
}

void fillRandom()
{
    int temp= (rand()%(N*N-nFilled)) + 1; //no of empty cells
    nFilled++;
    for(int i=0;i< N;i++)
         for(int j=0;j<N;j++)
            if(!m[i][j])
               if((--temp)==0){
                   m[i][j]=2;
                   return;
               }
}

//traverse line from one end to another adding same tiles if there
void processline(int i, int j) //i=1,2,3,4
{
   int p=i,q=j;
   int a[N],c=0;
   bool valid=false;

   while(!isEnd(i,j))
        {
            if(m[i][j])
            {
               if(valid && a[c-1] == m[i][j])
                 {a[c-1] *=2;nFilled--;valid=false;}
              else
                 {a[c++]=m[i][j];valid=true;}
            }

            i+=di;j+=dj;
        }

      //write back the array
      for(i=0;i<N;i++){
        m[p][q]=i<c? a[i] : 0;
        p+=di,q+=dj;
      }
}

void process()
{
    for(int i=0;i<N;i++){
        if (dir == 'L')
           //00 10 20
           processline(i,0);
        if (dir == 'R')
           //03 13 23
           processline(i,N-1);
        if (dir == 'U')
           //00 01 02
           processline(0,i);
        if (dir == 'D')
           //30 31 32
           processline(N-1,i);
    }
}


int main ( int argc, char *argv[] )
{
    cout << "**************************"<<endl;
    cout << "******** 2048 Game *******"<<endl;;
    cout << "**************************"<<endl;

    generateInitial();
    display();


    while(true)
    {
        cout <<endl<<endl<< "Enter direction of move(w/a/s/d): ";
        int in = getch();

        switch(in){
        case 'd':di = 0; dj=-1; dir='R';break;
        case 'w':di = 1; dj= 0; dir='U';break;
        case 'a':di = 0; dj= 1; dir='L';break;
        case 's':di =-1; dj= 0; dir='D';break;
        default: continue;
        }

        process();

        if(nFilled==N*N) //no space to fill
           {cout<<" Game Over!"<<endl; break;}

        fillRandom();# include <cstdlib>
# include <iostream>
# include <iomanip>
# include <ctime>
# include <cstdio>
# include <conio.h>

using namespace std;

//Structure for 2048
int  N=4;
int  m[10][10];
char dir;
int  di,dj;
int  nFilled=0;

//auxiliary functions
bool isEnd(int i, int j){
  return ( i<0 || j < 0 || i>N || j>N);
}

void initMatrix()
{
  for(int i=0;i<N;i++)
     for(int j=0;j<N;j++)
        m[i][j]=0;
}

void generateInitial(){
  initMatrix();
  int i,j,i2,j2;
  i=rand()%N;
  j=rand()%N;

  do{
       i2=rand()%N;
       j2=rand()%N;
    }while(i==i2 && j==j2);

   m[i][j]=2;
   m[i2][j2]=2;
   nFilled=2;
}

void display()
{
   cout<<endl;
   for(int i=0;i<N;i++){
      cout <<endl<<" ";
      for(int j=0;j<N;j++)
           if(m[i][j])
              cout<<setw(2)<<m[i][j]<<"  ";
           else cout<<"--  ";
   }
}

void fillRandom()
{
    int temp= (rand()%(N*N-nFilled)) + 1; //no of empty cells
    nFilled++;
    for(int i=0;i< N;i++)
         for(int j=0;j<N;j++)
            if(!m[i][j])
               if((--temp)==0){
                   m[i][j]=2;
                   return;
               }
}

//traverse line from one end to another adding same tiles if there
void processline(int i, int j) //i=1,2,3,4
{
   int p=i,q=j;
   int a[N],c=0;
   bool valid=false;

   while(!isEnd(i,j))
        {
            if(m[i][j])
            {
               if(valid && a[c-1] == m[i][j])
                 {a[c-1] *=2;nFilled--;valid=false;}
              else
                 {a[c++]=m[i][j];valid=true;}
            }

            i+=di;j+=dj;
        }

      //write back the array
      for(i=0;i<N;i++){
        m[p][q]=i<c? a[i] : 0;
        p+=di,q+=dj;
      }
}

void process()
{
    for(int i=0;i<N;i++){
        if (dir == 'L')
           //00 10 20
           processline(i,0);
        if (dir == 'R')
           //03 13 23
           processline(i,N-1);
        if (dir == 'U')
           //00 01 02
           processline(0,i);
        if (dir == 'D')
           //30 31 32
           processline(N-1,i);
    }
}


int main ( int argc, char *argv[] )
{
    cout << "**************************"<<endl;
    cout << "******** 2048 Game *******"<<endl;;
    cout << "**************************"<<endl;

    generateInitial();
    display();


    while(true)
    {
        cout <<endl<<endl<< "Enter direction of move(w/a/s/d): ";
        int in = getch();

        switch(in){
        case 'd':di = 0; dj=-1; dir='R';break;
        case 'w':di = 1; dj= 0; dir='U';break;
        case 'a':di = 0; dj= 1; dir='L';break;
        case 's':di =-1; dj= 0; dir='D';break;
        default: continue;
        }

        process();

        if(nFilled==N*N) //no space to fill
           {cout<<" Game Over!"<<endl; break;}

        fillRandom();

        display();
    };

    return 0;
}


        display();
    };

    return 0;
}
