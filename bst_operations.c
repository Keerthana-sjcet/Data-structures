#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct Node{
    int data;
    struct Node*left;
    struct Node*right;
}Node;
Node*createnode(int value){
    Node*newnode=malloc(sizeof(Node));
    newnode->data=value;
    newnode->right=NULL;
    newnode->left=NULL;
    return newnode;
}
Node *insertnode(Node *root,int value){
    if (root==NULL){
        return createnode(value);
    }
    else if(value<root->data){
        root->left=insertnode(root->left,value);
    }
    else if(value>root->data){
        root->right=insertnode(root->right,value);
    }
    return root;
}
Node * searchnode(Node *root,int value){
    if (root==NULL||root->data==value){
        return root;
    }
    else if (root->data>value){
        return searchnode(root->left,value);
    }
    else{
        return searchnode(root->right,value);
    }
    return root;
}
Node* findmin(Node*node){
    while (node->left!=NULL){
        node=node->left;
    }
    return node;
}
Node *deletenode(Node*root,int value){
    if (root==NULL){
        return root;
    }
    else if(value<root->data){
        root->left=deletenode(root->left,value);
    }
    else if(value>root->data){
        root->right=deletenode(root->right,value);
    }
    else{
        if (root->left==NULL){
            Node*temp=root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            Node* temp = root->left;
            free(root);
            return temp;
        }
        else{
            Node*temp=findmin(root->right);
            root->data=temp->data;
            root->right=deletenode(root->right,temp->data);
        }
    }
    return root;
}
void inorder(Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}
void printTree(Node* root, char* prefix, int isLeft)
{
    if (root == NULL)
        return;
    if (prefix[0] == '\0') {
        printf("%d\n", root->data);
    }
    else{
        printf("%s", prefix);

        if (isLeft)
            printf("|--");
        else
            printf("\\--");

        printf("%d\n", root->data);
    }
    char newPrefix[1000];
    strcpy(newPrefix, prefix);

    if (isLeft)
        strcat(newPrefix, "|   ");
    else
        strcat(newPrefix, "    ");

    printTree(root->left, newPrefix, 1);
    printTree(root->right, newPrefix, 0);
}

int main()
{
    Node* root = NULL;
    int choice, value;

    while (1)
    {
        printf("\n1.Insert  2.Delete  3.Search  4.inorder  5. display tree  6.exit\n");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                root = insertnode(root, value);
                break;

            case 2:
                printf("Enter value: ");
                scanf("%d", &value);
                if (searchnode(root, value) == NULL){
                    printf("Not found\n");
                }
                else {
                    root = deletenode(root, value);
                    printf("Deleted\n");
                }
                break;

            case 3:
                printf("Enter value: ");
                scanf("%d", &value);
                if (searchnode(root, value) != NULL) printf("Found\n");
                else printf("Not found\n");
                break;

            case 4:
                inorder(root);
                break;

            case 5:
                printTree(root, "", 0);
                break;
            case 6:
                return 0;

        }
    }
}

