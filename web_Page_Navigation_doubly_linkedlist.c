#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct Node{
    char url[100];
    struct Node*prev;
    struct Node*next;
}Node;

Node*current=NULL,*newNode=NULL,*temp=NULL,*ptr=NULL;
void visit(char *url){
    newNode=malloc(sizeof(Node));
    strcpy(newNode->url,url);
    newNode->next=NULL;
    newNode->prev=current;
    if(current!=NULL){
        temp=current->next;
        while(temp!=NULL){
            ptr=temp;
            temp=temp->next;
            free(ptr);
        }
        current->next=newNode;
    }
    current =newNode;
    printf("%s",url);
}
void back(){
    if(current!=NULL &&current->prev!=NULL){
        current=current->prev;
        printf("%s",current->url);
    }
    else{
        printf("No prev page");
    }
}
void forward(){
    if(current !=NULL && current->next!=NULL){
        current=current->next;
        printf("Forward to: %s\n", current->url);
    } else {
        printf("No forward page\n");
    }
}
void show(){
    if (current!=NULL){
        printf("%s",current->url);
    }
    else{
        printf("nothing to show");
    }
}
int main(){
    char url[100];
    int choice;
    while(1){
        printf("1.visit\n2.back\n3.forward\n4.current5.exit \nenter choice");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                printf("Enter url:");
                scanf("%s",url);
                visit(url);
                break;
            case 2:
                back();
                break;
            case 3:
                forward();
                break;
            case 4 :
                show();
                break;
            case 5:
                printf("exiting...");
                return 0;
            default:
                printf("invalid");
            
        }
    }
}
