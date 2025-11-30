#include<stdio.h>
#include<stdlib.h>
typedef struct Block{
    int size;
    int isfree;
    int pid;
    struct Block *next,*prev;
}Block;
Block*head=NULL;
Block *createblock(int size){
    Block*b=malloc(sizeof(Block));
    b->size=size;
    b->isfree=1;
    b->pid=-1;
    b->prev=NULL;
    b->next=NULL;
    return b;
}
Block* insertblock(int size){
    Block *newblock=createblock(size);
    if (head==NULL){
        head=newblock;
        return head;
    }
    Block*ptr=head;
    while(ptr->next!=NULL){
            ptr=ptr->next;
    }
    ptr->next=newblock;
    newblock->prev=ptr;
    return head;
    
}
void merge(){
    Block*ptr=head;
    while(ptr!=NULL&&ptr->next!=NULL){
        if (ptr->isfree==1&&ptr->next->isfree==1){
            ptr->size+=ptr->next->size;
            Block*del=ptr->next;
            ptr->next=del->next;
            if(del->next!=NULL){
                del->next->prev=ptr;
            }
            free(del);
        }
        else{
            ptr=ptr->next;
        }
    }
}
void freeprocess(int pid){
    Block*ptr=head;
    int found=0;
    while(ptr!=NULL){
        if (ptr->pid==pid &&ptr->isfree==0){
            ptr->pid=-1;
            ptr->isfree=1;
            printf("freed pid%d",pid);
            merge();
            found=1;
            break;
        }
        ptr=ptr->next;
    }
    if(found=0) printf("not found");
}



void display(){
    Block*ptr=head;
    while(ptr!=NULL){
        if (ptr->isfree==1){
            printf("[Free :%d]",ptr->size);
            ptr=ptr->next;
        }
        else{
            printf("[pid%d : %d]",ptr->pid,ptr->size);
            ptr=ptr->next;
        }
    }
    printf("\n");
}

void allocate(int pid,int req){
    Block*ptr=head;
    int allocated=0;
    while(ptr!=NULL){
        if (ptr->isfree==1 &&ptr->size>=req){
            if (ptr->size>req){
                Block*newblock=createblock(ptr->size-req);
                newblock->next=ptr->next;
                if(ptr->next!=NULL){
                    ptr->next->prev=newblock;
                }
                ptr->next=newblock;
                newblock->prev=ptr;
                ptr->size=req;
            }
            ptr->pid=pid;
            ptr->isfree=0;
            printf("allocated pid%d",pid);
            allocated=1;
            break;
        }
        ptr=ptr->next;
    }
    if(allocated==0)printf("not allocated");
}
int main(){
    int n,size,choice,pid=1,id;

    printf("No of blocks:");
    scanf("%d",&n);

    for(int i=0;i<n;i++){
        printf("Block %d size:",i+1);
        scanf("%d",&size);
        insertblock(size);
    }

    while(1){
        printf("\n1.Allocate  2.Free  3.Display  4.Exit\n");
        scanf("%d",&choice);

        switch(choice){
            case 1:
                printf("Enter process size:");
                scanf("%d",&size);
                allocate(pid++,size);
                break;

            case 2:
                printf("Enter pid:");
                scanf("%d",&id);
                freeprocess(id);
                break;

            case 3:
                display();
                break;

            case 4:
                return 0;
        }
    }
}
