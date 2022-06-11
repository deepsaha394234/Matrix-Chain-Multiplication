#include<stdio.h>

int matrixchainmultiplication(int arr[], int size){
    int minmul[size][size];
    int j,q;
    for (int i = 0; i < size; i++)
    {
        minmul[i][i]=0;
    }

    for (int L = 2; L < size; L++)
    {
        for (int i = 1; i < size-L+1; i++)
        {
            j=i+L-1;
            minmul[i][j]=99999999;
            for (int k = i; k <=j-1;  k++){
                q=minmul[i][k]+minmul[k+1][j]+arr[i-1]*arr[j]*arr[k];
                if (q<minmul[i][j])
                {
                    minmul[i][j]=q;
                }
                
            }
            
        }
        
        
    }
    
    return minmul[1][size-1];
} 
int main()
{   int size;
    scanf("%d",&size);
    int arr[size+1],rows[size],cols[size],i;
    for(i=0;i<size;i++){
            scanf("%d",&rows[i]);
            scanf("%d",&cols[i]);
            arr[i]=rows[i];
    }
    
    arr[size]=cols[i-1];
    printf("%d",matrixchainmultiplication(arr,size+1));
    return 0;
}