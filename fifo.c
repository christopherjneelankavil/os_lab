#include <stdio.h>

int main(){

    //reading reference string
    int sizeOfRefString;
    printf("Enter the size of reference string : ");
    scanf("%d",&sizeOfRefString);
    char refString[20];
    printf("Enter the reference string: ");
    for(int i=0;i<sizeOfRefString;i++){
        scanf("%d",&refString[i]);
    }

    //reading frames
    int frames;
    printf("Enter the no.of frames: ");
    scanf("%d",&frames);
    int memory[10];
    for(int i=0;i<frames;i++){
        memory[i]=-1;
    }

    //page replacement process
    printf("\nThe page replacement process is: \n");
    
}