#include <stdio.h>
typedef struct Polynomial{
    int coeff;
    int expo;
}Polynomial;
int main(){
    int n1,n2;
    Polynomial poly1[100],poly2[100],result[200];
    printf("Enter no of terms in first polynomial");
    scanf("%d",&n1);
    printf("Enter no of terms in second polynomial");
    scanf("%d",&n2);
    printf("ENter terms and expo of first poly");
    for (int i=0;i<n1;i++){
        scanf("%d%d",&poly1[i].coeff,&poly1[i].expo);
    }
    printf("ENter terms and expo of second poly");
    for (int i=0;i<n2;i++){
        scanf("%d%d",&poly2[i].coeff,&poly2[i].expo);
    }
    int k=0,i=0,j=0;
    while (i<n1&&j<n2){
        if (poly1[i].expo==poly2[j].expo){
            result[k].expo=poly1[i].expo;
            result[k].coeff=poly1[i].coeff+poly2[j].coeff;
            i++,j++,k++;
        }
        else if (poly1[i].expo>poly2[j].expo){
                result[k].expo=poly1[i].expo;
                result[k].coeff=poly1[i].coeff;
                i++,k++;
            }
        else {
            result[k].expo=poly2[j].expo;
            result[k].coeff=poly2[j].coeff;
            j++,k++;
        }
    }
    while(i<n1){
        result[k].expo=poly1[i].expo;
        result[k].coeff=poly1[i].coeff;
        i++,k++;
    }
    while(j<n2){
        result[k].expo=poly2[j].expo;
        result[k].coeff=poly2[j].coeff;
        j++,k++;
    }
    printf("sum :\n");
    for (int i=0;i<k;i++){

        printf("%dx^%d",result[i].coeff,result[i].expo);
        if(i!=k-1){
            printf("+");
        }
    }
    return 0;
}
