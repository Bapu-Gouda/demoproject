#include<stdio.h>
#define MAX 5
int stack[MAX],top=-1;
void push(){
    int val;
    if (top==MAX-1){printf("stack overflow!\n");return;}
    printf("Enter value to push:");
    scanf("%d",&val);
    stack[++top]=val;
    printf("%d pushed onto stack.\n",val);
}
void pop(){
    if (top==-1){printf("stack underflow!\n");return;}
    printf("%d popped from stack.\n",stack[top--]);
}
void display (){
    if (top==-1){printf("stack is empty!\n");return;}
        printf(" stack elements are:\n");
        for(int i=top;i>=0;i--)
        printf("%d\n",stack[i]);
        printf("\n");
    }
    void checkPalindrome(){
        int n,num[MAX],ispalin=1;
        printf("Enter number of elements:");
        scanf("%d",&n);
        if(n>MAX){printf("Exceeds stack size .\n ");return;}
        for(int i=0;i<n;i++)
        scanf("%d",&num[i]);
        int localTop=-1,temp[MAX];
        for(int i=0;i<n;i++)
        temp[++localTop]=num[i];
        for(int i=0;i<n;i++)
    
        if(num[i]!=temp[localTop--]){ispalin=0;break;}
        printf(ispalin ?"The sequence IS a palindrome.\n":"The sequence is NOT a palindrome.\n");
    }
            int main(){
            int choice;
            do{
           printf("\n1.Push 2.Pop 3.Check Palindrome 4.Display 5.Exit): ");
           scanf("%d",&choice);
           switch(choice){
               case 1: push();break;
               case 2: pop();break;
               case 3: checkPalindrome();break;
               case 4: display();break;
               case 5: printf("Exiting...\n");break;
               default: printf("Invalid choice.\n");
           }
            }while(choice!=5);
            return 0;
        }