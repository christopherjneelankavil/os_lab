#include<stdio.h>
#include<stdbool.h>

int main(){
    
    //reference string
    int n,i;
    int pageHit=0,pageFault=0;
    printf("Enter the no.of elements in reference string: ");
    scanf("%d",&n);
    int ref[n];
    printf("Enter the elements of the reference string : ");
    for(i=0;i<n;i++){
        scanf("%d",&ref[i]);
    }
    
    //frames 
    int f,j;
    printf("Enter the no.of frames: ");
    scanf("%d",&f);
    int fr[f];
    for(int j=0;j<f;j++){
        fr[j]=-1;
    }
    
    //fifo page replacement process 
    printf("The page replacement process is : \n");
    int count=0;
    for(i=0;i<n;i++){
        int found=0;
        
        for(j=0;j<f;j++){
            if(fr[j]==ref[i]){
                found=1;
                pageHit++;
                break;
            }
        }
        if(!found){
            fr[count]=ref[i];
            count=(count+1)%f;
            pageFault++;
        }
        for(int k=0;k<f;k++){
            if(fr[k]==-1){
                printf("\t-");
            }
            else{
                printf("\t%d",fr[k]);
            }
        }
        if(found){
            printf("\tPage hit : %d\n",ref[i]);
        }
        else{
            printf("\tPage fault : %d\n",ref[i]);
        }
    }

    //printing results
    printf("\nPage hit: %d\n",pageHit);
    printf("\nPage fault: %d\n",pageFault);
    return(0);
    
}
