#include<stdio.h>
int mergesteps=0;
void merge(int C[],int lb,int mid,int ub){
    int i=lb;
    int k=lb;
    int j=mid+1;
    int D[100];
    while(i<=mid&&j<=ub){
        mergesteps++;
        if(C[i]<=C[j]){
            D[k++]=C[i++];
        }
        else{
            D[k++]=C[j++]; 
        }
    }
    while(i<=mid){
        D[k++]=C[i++];
    }
    while(j<=ub){
        D[k++]=C[j++];
    }
    for(int i=lb;i<=ub;i++){
        C[i]=D[i];
    }
}
void mergesort(int C[],int lb,int ub){
    if (lb<ub){
        int mid=(lb+ub)/2;
        mergesort(C,lb,mid);
        mergesort(C,mid+1,ub);
        merge(C,lb,mid,ub);
    }
}
int quick_steps=0;
int partition(int E[],int low,int high){
    int i=low;
    int pivot=E[high];
    for (int j=low;j<high;j++){
        if (E[j]<=pivot){
            int temp=E[i];
            E[i]=E[j];
            E[j]=temp;
            quick_steps++; 
            i++;
        }
    }
    int temp=E[i];
    E[i]=E[high];
    E[high]=temp;
    quick_steps++; 
    return i;
}
void quicksort(int E[],int low,int high){
    if(low<high){
        int p=partition(E,low,high);
        quicksort(E,low,p-1);
        quicksort(E,p+1,high);
    }
}
int main(){
    int A[100],B[100],C[100],D[100],E[100],n;
    printf("Enter number of elements ");
    scanf("%d",&n);
    printf("Enter elements");
    for (int i=0;i<n;i++){
        scanf("%d",&A[i]);
        B[i]=C[i]=D[i]=E[i]=A[i];
    }
    printf("Bubble Sort:");
    int bubblesteps=0;
    for (int i=0;i<n;i++){
        for(int j=0;j<n-i-1;j++){
            if (A[j]>A[j+1]){
                int temp=A[j];
                A[j]=A[j+1];
                A[j+1]=temp;
            }
            bubblesteps+=1;
        } 
    }
    for(int i=0;i<n;i++){
        printf("%d\t",A[i]);
    }
    printf("\nNo of bubble steps:%d\t",bubblesteps);
    
    printf("\nInsertion: ");
    int insertionsteps=0;
    for (int i=1;i<n;i++){
        int j=i-1;
        int key=B[i];
        while(j>=0&&B[j]>key){
            B[j+1]=B[j];
            j--;
            insertionsteps++;
        }
        B[j+1]=key;
    }
    for(int i=0;i<n;i++){
        printf("%d\t",B[i]);
    }
    printf("\nNo of insertion steps:%d",insertionsteps);
    mergesort(C,0,n-1);
    printf("\nMerge");
    for(int i=0;i<n;i++){
        printf("%d\t",C[i]);
    }
    printf("\nNo of merge steps:%d",mergesteps);
    printf("\nQuick :");
    quicksort(E,0,n-1);
    for(int i=0;i<n;i++){
        printf("%d\t",E[i]);
    }
    printf("\nNo of quick steps:%d",quick_steps);
    return 0;
}
