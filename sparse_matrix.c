#include <stdio.h>

int main(){
    int rows,cols;
    int matrix[10][10],sparse[50][3];
    printf("Enter the number of rows:");
    scanf("%d",&rows);
    printf("Enter the number of columns:");
    scanf("%d",&cols);
    
    printf("Enter matrix elements:");
    for(int i=0;i<rows;i++){
      for(int j=0;j<cols;j++){
        scanf("%d",&matrix[i][j]);
      }
    } 
    sparse[0][0]=rows;
    sparse[0][1]=cols;
    sparse[0][2]=0;    //number of non-zero elements
    int k=1;
    for(int i=0;i<rows;i++){
      for(int j=0;j<cols;j++){
          if(matrix[i][j]!=0){
            sparse[k][0]=i;
            sparse[k][1]=j;
            sparse[k][2]=matrix[i][j];
            k++;
            sparse[0][2]++;
        }
      }
    }

    for(int i=0;i<=sparse[0][2];i++){
      printf("%d %d %d",sparse[i][0],sparse[i][1],sparse[i][2]);
      printf("\n");
    }
return 0;
}
