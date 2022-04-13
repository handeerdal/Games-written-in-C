//
//  Memory Game
//
//  Created by Hande Erdal on 16.01.2022.
//

#include <stdio.h>
#include <unistd.h>

int main(int argc, const char * argv[]) {
    char A[2][3]={'-','?','#','#','-','?'}, B[2][3]={'*','*','*','*','*','*'};
    int temp1=0,temp2=0;
    do{
    int line=0,column=0,line2=0,column2=0;
    goback:
    for(int i=0;i<2;i++){
        for(int j=0;j<3;j++){
            printf("%c",B[i][j]);
            printf("\t");
           }
        printf("\n");
           }
        do{
    printf("Which star do you want to open from which line? Write as line-column.\n");
    scanf("%d%d",&line,&column);
        }while(line <0 || line>4 || column<0 || column>4);
    line-=1;
    column-=1;
        temp1=B[line][column];
    B[line][column]=A[line][column];
    for(int i=0;i<2;i++){
        for(int j=0;j<3;j++){
            printf("%c",B[i][j]);
            printf("\t");
           }
        printf("\n");
           }
    sameEnterance:
        do{
    printf("Now which star do you want to open from which line? Write as line-column.\n");
    scanf("%d%d",&line2,&column2);
        }while(line2 <0 || line2>4 || column2<0 || column2>4);
    line2-=1;
    column2-=1;
        if(line2==line && column==column2)
        {
            printf("You typed the same combination.Try again.\n");
            goto sameEnterance;
        }
        temp2=B[line2][column2];
    B[line2][column2]=A[line2][column2];
    for(int i=0;i<2;i++){
        for(int j=0;j<3;j++){
            printf("%c",B[i][j]);
            printf("\t");
           }
        printf("\n");
           }
        if(B[line][column]==B[line2][column2]){
        printf("Congrats\n");
            if(A[2][3]==B[2][3])
                break;
        }
        
    else{
        printf("Wrong guess. Try again.\n");
        
        B[line][column]=temp1;
        B[line2][column2]=temp2;
        goto goback;
    }
    
    }while (A[2][3]!=B[2][3]);
    return 0;
}
