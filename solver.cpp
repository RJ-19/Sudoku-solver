#include <iostream>
#include <cmath>
using namespace std;

bool canplace(int mat[][9],int i,int j,int n,int num){
    //check row & col
    for(int x =0;x<n;x++){
        if(mat[x][j]==num || mat[i][x]==num){
            return false;
        }
    }
    
    int sx = (i/3)*3;
    int sy = (j/3)*3;
    for (int x = sx;x<sx+3;x++){
        for (int y = sy;y<sy+3;y++){
        if(mat[x][y]==num){
            return false;
        }
     }
    }
    return true;
    

}

bool solvesudoku(int mat[][9],int i,int j,int n){
    //base case
    if(i==n){
        //print matrix 
        for(int i =0;i<n;i++){
            for(int j =0;j<n;j++){
                cout<<mat[i][j]<<" ";
            }    
            cout<<endl;
        }
        return true;
    }
    //col end
    if(j==n){
        return solvesudoku(mat,i+1,0,n);

    }
    //skip pre-filled cells
    if(mat[i][j] != 0){
        return solvesudoku(mat,i,j+1,n);
    }
    for(int num =1;num<=n;num++){
        if(canplace(mat,i,j,n,num)){
            //assume
            mat[i][j]=num;
            bool couldwesolve = solvesudoku(mat,i,j+1,n);
            if(couldwesolve == true){
                return true ;
            }
        }
    }
    //backtracking
    mat[i][j]= 0;
    return false;
}

int main(){
    int mat[9][9];
     
    for(int i =0;i<9;i++){
        for(int j =0;j<9;j++){
                cin>>mat[i][j];
        }    
           
    }
    solvesudoku(mat,0,0,9);
    return 0;
}
