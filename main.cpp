#include <iostream>
#include <cstdlib>

using namespace std;
const int MAXGEN = 10; // max # of gens.
const int n = 5; //# of rows
const int m = 5; //# of col.


void intialize(int populus[][m]){
    cout<<"please enter "<<n<<" x "<<m<<" numbers that are 0 or 1"<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>populus[i][j];
    }
}

}

/*
void intialize2(int populus[][m],int density){
    for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                    int NUM = rand()%100;
                    if (NUM <= density)
                        populus[i][j] = 1;
                    else
                        populus[i][j] = 0;
            }
    }
}


*/
int countNeighbours(int populus[][m], int x, int y){ // X ROWS, Y COLUMNS
   int countx=0;

    if (populus[x][y] == 1) // do not count the square being checked
    countx--;

   for(int i=-1;i<2;i++){  // count all squares surrounding the square
    for(int j=-1;j<2;j++){
        if(populus[(x+i+n)%n][(y+j+m)%m]==1)
            countx++;

    }

   }
   return countx;
}

bool allDead(int populus[][m]){
    int countx = 0;
    bool dead = false;
 for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
          if(populus[i][j]!= 0)
            countx++;
        }
    }
    if (countx == 0)
        dead = true;
    return dead;
}

void print(int populus[][m]){
   for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<populus[i][j]<<"  ";
    }
    cout<<endl;
}

}


void reproduce(int populus[n][m]){
int nextPop[n][m];
for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
        if(countNeighbours(populus,i,j)==3)
            nextPop[i][j] = 1;
        else if(countNeighbours(populus,i,j)>1 && countNeighbours(populus,i,j)<4 && populus[i][j]==1)
            nextPop[i][j] = 1;
            else
                nextPop[i][j] = 0;

    }
}
for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
        populus[i][j]=nextPop[i][j];
    }
    }
//print(populus);
}

int main(){
   /* int population[n][m];
    intialize(population);
    print(population);
    int dab = countNeighbours(population,0,1);
    cout<<endl<<dab<<endl;
    bool ded = allDead(population);
    cout<<ded<<endl<<endl<<endl;
    reproduce(population);
*/

  int grid[n][m];
  intialize(grid);
  cout<<"initial population = "<<endl;
  print(grid);
  int gen = 1;
  //print(grid);
  while (gen<= MAXGEN && !allDead(grid)){
    cout <<"gen = "<<gen<<endl;
    reproduce(grid);
    print(grid);
    gen++;

}
}
