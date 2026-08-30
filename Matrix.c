#include <stdio.h>

int main(void) {

    int mat_arr[2][2]= {{2,2},{2,2}};

    for(int i=0;i<2;i++) {
        for(int j=0;j<2;j++) {
            printf("%d ",mat_arr[i][j]);
        }
        printf("\n");
    }



    return 0;
}