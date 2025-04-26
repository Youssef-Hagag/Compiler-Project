#include <stdio.h>
int main(){
    switch(2){
        case 1:
            printf("case 1\n");
            break;
        case 2:
            switch(2){
                case 1:
                    printf("case 1\n");
                    break;
                case 2:
                    printf("case x\n");
                    break;
                case 3:
                    printf("case 3\n");
                    break;
                default:
                    printf("default\n");
            }
            break;
        case 3:
            printf("case 3\n");
            break;
        default:
            printf("default\n");
    }
}