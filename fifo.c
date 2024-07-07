#include<stdio.h>
#include<stdlib.h>

int main(){

    //reference string 
    int n,i;
    printf("Enter the total length : ");
    scanf("%d",&n);
    int ref[n];
    printf("Enter the reference string : ");
    for(i=0;i<n;i++){
        scanf("%d",&ref[i]);
    }

    //frames
    int fr,j;
    printf("Enter the no.of frames : ");
    scanf("%d",&fr);
    int frames[fr];
    for(j=0;j<fr;j++){
        frames[j]= -1;
    }

    //page replacement
    printf("The fifo page replacement process is : \n");
    int count=0,pageHit=0,pageFault=0;
    for(i=0;i<n;i++){

        int found=0;
        
        for(j=0;j<fr;j++){
            
            if(frames[j]==ref[i]){
                found=1;
                pageHit++;
                break;
            }

        }
        if(!found){
            pageFault++;
            frames[count]=ref[i];
            count=(count+1)%fr;
        }

        for(int k=0;k<fr;k++){
            if(frames[k]==-1){
                printf("\t-");
            }
            else{
                printf("\t%d",frames[k]);
            }
        }
        if(found){
            printf("\tHIT: %d\n",ref[i]);
        }
        else{
            printf("\tFAULT: %d\n",ref[i]);
        }
        printf("\n");
    }
    printf("Total page hit : %d\n",pageHit);
    printf("Total page fault : %d\n",pageFault);
    return EXIT_SUCCESS;
}

