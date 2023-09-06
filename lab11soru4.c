
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/*
Bir ba�l� do�rusal listelerde listenin sonundaki d���m ile ba��ndaki d���m�n yerini de�i�tiren
changeFirstAndLast isimli bir fonksiyon yaz�n�z. Fonksiyon parametre olarak bir liste al�p
g�ncellenen listeyi geri d�nd�recektir.
*/




struct node{
    int data;
    struct node* next;
};

typedef struct node node;

node* changeFirstAndLast(node* head)
{
    if(head==NULL || head->next==NULL)
    {
        return head;
    }

        node* p=head;
        node* sonraki=NULL;
        while(p->next!=NULL)
        {
            sonraki=p;
            p=p->next;
        }
        p->next=head->next;
        head->next=NULL;
        sonraki->next=head;
        return(p);



}

void bastir(node* head)
{
    node* p=head;
    while(p!=NULL)
    {
        printf("%d ",p->data);
        p=p->next;
    }
    printf(" ");
}




int main()
{


   int n,sayi;
   printf("kac dugum olcak:  ");
   scanf("%d",&n);
   int i;
   node* head=NULL;
   for(i=0;i<n;i++)
   {
       printf("%d. sayiyi giriniz:  ",i+1);
       scanf("%d",&sayi);
       node* newnode=(node*)malloc(sizeof(node));
       newnode->data=sayi;
       newnode->next=NULL;
       if(head==NULL)
       {
           head=newnode;
       }
       else
       {
           node* p=head;
           while(p->next!=NULL)
           {
               p=p->next;
           }
           p->next=newnode;

       }
   }
   printf("orijinal liste:  ");
   bastir(head);

   head=changeFirstAndLast(head);
   printf("guncellenmis:  ");
   bastir(head);

    return 0;
}

