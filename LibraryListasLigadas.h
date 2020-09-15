#include<stdio.h>
#include<stdlib.h>
struct node {
    int data;
    struct node *next;
    //struct node *first;
};

struct node *newList(struct node *lista){
    lista = NULL;
    return lista;
}
struct node *addback(struct node *head, int data);
void display(struct node *head);
int NumberElements (struct node *head);
//struct node *find(struct node *head, int data);
//struct node *delnode (struct node *head, struct node *pelement);
    //struct node *freelist (struct node *head);
//void freelist(struct node **head);



struct node *addback(struct node *head, int data){
    struct node *temp, *aux;
    temp = malloc(sizeof(struct node));
    temp->data = data;
    temp->next = NULL;
    if(head==NULL)
        head = temp;
    else{
        aux = head;
        while(aux->next != NULL){
            aux=aux->next;
        }
        aux->next = temp;
    }
    return head;
}

void display(struct node *head){
    struct node *temp;
    int i=0;
    for (temp = head; temp != NULL; temp = temp->next){
         printf("position: %d \t Data: %d \n",i,temp->data);
        i++;
}
}

int NumberElements (struct node *head){
    struct node *temp;
    int i=0;
    for (temp = head; temp != NULL; temp = temp->next){
        i++;
    }
    return i;
}



struct node *find (struct node *head, int data){
    struct node *temp;
    for (temp = head; temp != NULL; temp = temp->next){
        if (temp->data == data)
            return temp;
    }
    return NULL;
}

struct node *delnode (struct node *head, struct node *pelement){
    struct node *temp, *first, *back;
    first=head;
    if(pelement != first){
        for (temp = first; temp != NULL; temp = temp->next){
            if (temp==pelement){
                back->next=temp->next;
                free(temp);
                break;
            }
            back=temp;
        }
    }else{
        temp = first;
        back=temp;
        temp = temp->next;
        free(back);
        head = temp;
    }
    return head;
}
void freelist(struct node **head)
{
    struct node *now;

    while (*head != NULL && head != NULL)
    {
        now = *head;
        *head = (*head)->next;
        free(now);
    }
}
