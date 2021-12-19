#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_RESET   "\x1b[0m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
struct node
{
    int data;
    struct node *next;
    struct node *prev;
}*head,*tail;
int getCountList();
int Createlist();
int Display();
int DeleteFromBeg();
int DeleteFromEnd();
int DeleteFromPos();
int InsertatBeg();
int InsertatEnd();
int InsertatPos();
int ReverseList();
int main()
{
    int choice,n,c2,c3;
    while (1)
    {
        system("cls");
        printf("                  ----:DOUBLE LINKED LIST:----                 ");
        printf("\n1.CREATELIST | 2.INSERT | 3.DELETE | 4.REVERSE LIST | 5.DISPLAY | 6.QUIT");
        printf("\n\nEnter your Choice:");
        scanf("%d",&choice);
        
        switch (choice)
        {
        case 1:
            Createlist();
            break;
        case 2:
            if(head==NULL)
            {
                printf(ANSI_COLOR_RED "No List has been created.Please Create a List first!!!" ANSI_COLOR_RESET);
                getch();
            }
            else{

                printf("1.At Beginning\n2.At End\n3.Any Position\n\nWhere do you want to insert data?:");
            scanf("%d",&c2);
            switch (c2)
            {
            case 1:
                InsertatBeg();
                break;
            case 2:
                InsertatEnd();
                break;
            case 3:
                InsertatPos();
                break;
            default:
                break;
            }
            }
            break;
        case 3:
            if(head==NULL)
            {
                printf(ANSI_COLOR_RED "No List has been created.Please Create a List first!!!" ANSI_COLOR_RESET);
                getch();
            }
            else{
            printf("1.At Beginning\n2.At End\n3.Any Position\n\nFrom where do you want to delete data?:");
            scanf("%d",&c3);
            switch (c3)
            {
            case 1:
                DeleteFromBeg();
                break;
            case 2:
                DeleteFromEnd();
                break;
            case 3:
                DeleteFromPos();
                break;      
            default:
                break;
            }
            }
            break;
        case 4:
            if(head==NULL)
            {
                printf(ANSI_COLOR_RED "No List has been created.Please Create a List first!!!" ANSI_COLOR_RESET);
                getch();
            }
            else{
                ReverseList();
            }
            break;
        case 5:
            if(head==NULL)
            {
                printf(ANSI_COLOR_RED "No List has been created.Please Create a List first!!!" ANSI_COLOR_RESET);
                getch();
            }
            else{
            Display();
            }
            break;
        case 6:
            exit(0);
        default:
            break;
        }
    }
    
}

int Createlist()
{
    int n,i=1;
    struct node *newnode,*temp;
    newnode=(struct node *)malloc(sizeof(struct node));
    printf("Enter the no. of nodes you want\n");
    scanf("%d",&n);
    printf("Enter data to the node %d: ", i);
    scanf("%d",&newnode->data);
    newnode->prev=NULL;
    newnode->next=NULL;
    head=newnode;
    temp=newnode;
    for(i=2;i<=n;i++){
        newnode=(struct node *)malloc(sizeof(struct node));
        printf("Enter data to the node %d: ", i);
        scanf("%d",&newnode->data);
        newnode->next=NULL;
        newnode->prev=temp;
        temp->next=newnode;
        temp=temp->next;
    }
}
int Display()
{
    struct node *temp;
    temp=head;
    printf(ANSI_COLOR_GREEN "The List is--> " ANSI_COLOR_RESET);
    while (temp!=NULL)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("\nThe Length is-_>%d\n",getCountList());
    getch();
    
}


int getCountList()
{
    int count=0;
    struct node *temp;
    temp=head;
    while (temp!=NULL)
    {
        temp=temp->next;
        count++;
    }
    return(count);
}


//Inserting New Node

int InsertatBeg()
{
    struct node *newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("\nEnter the data you want to insert:");
    scanf("%d",&newnode->data);
    newnode->next=NULL;
    newnode->prev=NULL;
    head->prev=newnode;
    newnode->next=head;
    head=newnode; 
}

int InsertatEnd()
{
    struct node *newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("\nEnter the data you want to insert:");
    scanf("%d",&newnode->data);
    newnode->next=NULL;
    newnode->prev=NULL;
    tail->next=newnode;
    newnode->prev=tail;
    tail=newnode;
}

int InsertatPos()
{
    int pos,i;
    printf("\nEnter the position:");
    scanf("%d",&pos);
    if(pos<1 || pos>getCountList())
    {
        printf(ANSI_COLOR_RED"Invalid!This position does not exit in this list." ANSI_COLOR_RESET);
        getch();
    }
    else if(pos==1)
    {
        InsertatBeg();
    }
    else
    {
        struct node *newnode,*temp;
        temp=head;
        newnode=(struct node*)malloc(sizeof(struct node));
        printf("\nEnter the data you want to insert:");
        scanf("%d",&newnode->data);
        while(i<pos)
        {
            temp=temp->next;
            i++;
        }
        newnode->prev=temp;
        newnode->next=temp->next;
        temp->next=newnode;
        newnode->next->prev=newnode;
    }
} 

//Deletion Of Node

int DeleteFromBeg()
{
    struct node *temp=head;
    head=head->next;
    head->prev=NULL;
    free(temp);
}

int DeleteFromEnd()
{
    struct node *temp=tail;
    tail=tail->prev;
    tail->next=NULL;
    free(temp);
    
}

int DeleteFromPos()
{
    int pos,i=1;
    printf("Enter the position of the node you want to delete:");
    scanf("%d",&pos);
    if(pos<1 || pos>getCountList())
    {
        printf(ANSI_COLOR_RED"Invalid!This position does not exit in this list."ANSI_COLOR_RESET);
        getch();
    }
    else if(pos==1)
    {
        DeleteFromEnd();
    }
    else if(pos==getCountList())
    {
        DeleteFromEnd();
    }
    else
    {
        struct node *temp;
        temp=head;
        while (i<pos)
        {
            temp=temp->next;
            i++;
        }
        temp->prev->next=temp->next;
        temp->next->prev=temp->prev;
        free(temp);
               
    }
}


int ReverseList()
{
    struct node *current,*nextnode;
    current=head;
    while (current!=NULL)
    {
        nextnode=current->next;
        current->next=current->prev;
        current->prev=nextnode;
        current=nextnode;
    }
    current=head;
    head=tail;
    tail=current;
}
