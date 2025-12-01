#include<stdio.h>
#include<string.h>
#include<ctype.h>
int main(){
    char infix[100],postfix[100],stack[100];
    int j=0,top=-1,p1,p2;
    printf("enter expression");
    fgets(infix,sizeof(infix),stdin);
    for (int i=0;infix[i]!='\0';i++){
        char ch=infix[i];
        if( ch==' ') continue;
        if (isalpha(ch)){
            postfix[j++]=ch;
             postfix[j++] = ' ';
            
        }
        else if (isdigit(ch)){
            while (isdigit(infix[i])){
                postfix[j++]=infix[i++];
                
            }
            postfix[j++] = ' ';
            i--;
            
        }    
        else if (ch=='('){
            stack[++top]=ch;
        }
        else if (ch==')'){
            while (top!=-1 && stack[top]!='('){
                postfix[j++]=stack[top--];
                postfix[j++] = ' ';
            }
            top--;
        }
        else{
            if (ch=='+'||ch=='-') p1=1;
            else if(ch=='*'||ch=='/') p1=2;
            else if (ch =='^') p1=3;
            else p1=0;
            while (top!=-1){
                char op=stack[top];
                if (op=='+'||op=='-') p2=1;
                else if(op=='*'||op=='/') p2=2;
                else if (op =='^') p2=3;
                else p2=0;
                
                if (p2>p1||(p2==p1&&ch!='^')){
                    postfix[j++]=stack[top--];
                    postfix[j++] = ' ';
                }
                else {
                    break;
                }
            }
            stack[++top]=ch;
        }
    }
    while (top!=-1){
            postfix[j++]=stack[top--];
            postfix[j++] = ' ';
        }
        postfix[j]='\0';
        printf("%s",postfix);
        int evaluation[100],evaltop=-1;
        for (int i=0;postfix[i]!='\0';i++){
            char ch=postfix[i];
            if (ch==' ') continue;
            if (isdigit(ch)){
                int num=0;
                while (isdigit(ch)){
                    num=num*10+(ch-'0');
                    i++;
                }
                evaluation[++evaltop]=num;
                i--;
            }
            else if (isalpha(ch)) {
                printf("\nCannot evaluate expression containing alphabets (e.g., %c)\n", ch);
                return 0;
            }
            else{
                int b=evaluation[evaltop--];
                int a =evaluation[evaltop--];
                int result;
                if (ch=='+') result=a+b;
                else if (ch=='-') result = a-b;
                else if (ch=='*') result = a*b;
                else if (ch=='/') result = a/b;
                else if (ch=='^'){
                    result=1;
                    for (int k=0;k<b;k++){
                        result*=a;
                    }       
                }
                evaluation[++evaltop]=result;
            }

        }
        printf("%d",evaluation[evaltop]);
        return 0;
}    
