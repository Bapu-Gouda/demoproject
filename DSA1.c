#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct Book{
    int bookID;
    char title[50],author[50];
    float price;
    char status[10];//"Available"or "issued"
};
struct Book*books;
int n;
void create(){
    printf("Enter number of books:");
    scanf("%d",&n);
    books =(struct Book*) malloc(n*sizeof(struct Book));
    for(int i=0;i<n;i++){
        printf("\nBook %d\n",i+1);
        printf("Book ID:");
        scanf("%d",&books[i].bookID);
        printf("Title:");
        scanf("%s",books[i].title);
        printf("Author:");
        scanf("%s",books[i].author);
        printf("price:");
        scanf("%f",&books[i].price);
        strcpy(books[i].status,"Available");
    }
}
void display(){
    printf("\n%-8s%-15s%-15s%-10s%-10s\n","ID","Title","Author","Price","status");
    for(int i=0;i<n;i++)
    printf("%-8d%-15s%-15s%-10.2f%-10s\n",books[i].bookID,books[i].title,books[i].author,books[i].price,books[i].status);    
}
int search(int id){
    for(int i=0;i<n;i++)
    if(books[i].bookID==id)return i;
    return -1;
}
void issueBook(){
    int id;
    printf("Enter Book ID to issue:");
    scanf("%d",&id);
    int idx=search(id);
    if (idx==-1){printf("Book not found.\n");return;}
    if(strcmp (books[idx].status,"Issued")==0)
    printf("Book already issued.\n");
    else {
        strcpy(books[idx].status,"Issued");
        printf("Book issued successfully.\n");
    }
}
void returnBook(){
    int id;
    printf("Enter Book ID  to return:");
    scanf( "%d",&id);
    int idx=search(id);
    if(idx==-1){printf("Book not found.\n");return;}
    if(strcmp(books[idx].status,"Available")==0)
    printf("Book was not issued.\n");
    else{
        strcpy(books[idx].status,"Available");
        printf("Book returned successfully.\n");
    }
}
int main(){
    int choice,id,idx;
    create();
    do{
        printf("\n 1.Display All 2.search by ID 3.Issued 4.Return Book 5.Exit\n");
        printf("Enter choice:");
        scanf("%d",& choice);
        switch (choice){
            case 1:
            display();
            break;
            case 2:
            printf("Enter Book ID:");
            scanf("%d",&id);
            idx=search(id);
            if(idx==-1)
            printf("Book not found.\n");
            else 
            
printf("Found:%s by %s,status:%s\n",books[idx].title,books[idx].author,books[idx].status);
            break;
            case 3:issueBook();break;
            case 4:returnBook();break;
            case 5:printf("Exiting...\n");break;
            default:printf("Invalid choice.\n");
        }
    }while(choice!=5);
    free(books);
    return 0;
}