#include <iostream>
using namespace std;
//create point structure
struct Element{
    int data;
    Element *next;
    Element *prev;//access back
};
//create head and tail structure for list
struct List{
    int n;//access element
    Element *head;
    Element *tail;
};
//create empty list
List *create_List(){
    List *ls;
    ls = new List();
    ls->n=0;
    ls->head =NULL;
    ls->tail =NULL;
    return ls;
}
//insert begin
void insert_Begin(List *ls,int newData);
//display from head
void displayHead(List *ls);
//display from tail
void displayTail(List *ls);
//insert_End
void insert_End(List *ls, int newData);
//delete begin
void delete_Begin(List *ls);
//delete end
void delete_End(List *ls);
int main(){
    List *ls;
    ls=create_List();
    insert_Begin(ls,1);
    insert_Begin(ls,2);
    insert_Begin(ls,3);
    insert_Begin(ls,5);
    insert_Begin(ls,9);
    insert_End(ls,1);
    insert_End(ls,2);
    insert_End(ls,3);
    insert_End(ls,5);
    insert_End(ls,9);
    cout<<"The result before delete\n\n";
    cout<<"Result display from head\n";
    displayHead(ls);
    cout<<"Result display from tail\n";
    displayTail(ls);
    cout<<"\nThe result after delete:\n\n";
    cout<<"Delete begin of list\n";
    delete_Begin(ls);
    delete_Begin(ls);
    displayHead(ls);
    displayTail(ls);
    cout<<"\nDelete end of list\n";
    delete_End(ls);
    delete_End(ls);
    displayHead(ls);
    displayTail(ls);
}
void insert_Begin(List *ls,int newData){
    Element *e;
    e = new Element();
    e->data = newData;
    e->prev=NULL;
    e->next = ls->head;
    
    if (ls->n==0)
    {
        ls->tail=e;
    }
    if (ls->n!=0)
    {
        ls->head->prev=e;
    } 
    ls->head=e;
    ls->n++;
}
void displayHead(List *ls){
    Element *tmp;
    tmp=ls->head;
    while (tmp!=NULL)
    {
        cout<<tmp->data<<" ";
        tmp=tmp->next;
    }
    cout<<"\n";
}
void displayTail(List *ls){
    Element *tmp;
    tmp = ls->tail;
    while (tmp!=NULL)
    {
        cout<<tmp->data<<" ";
        tmp=tmp->prev;
    }
    cout<<"\n";
}
void insert_End(List *ls, int newData){
    Element *e;
    if (ls->n==0)
    {
        insert_Begin(ls,newData);
    }
    else
    {
        e= new Element();
        e->data =newData;
        e->next = NULL;
        ls->tail->next =e;
        e->prev=ls->tail;
        ls->tail=e;
        ls->n++;
    }
}
void delete_Begin(List *ls){
    Element *tmp;
    tmp=ls->head;
    ls->head = ls->head->next;
    
    ls->head->prev=NULL;//give prev point to null
    //begin element to no value or delete
    tmp=NULL;
    if (ls->n==0)
    {
        ls->tail=NULL;
    }
    ls->n--;
}
void delete_End(List *ls){
    Element *tmp;
    if (ls->n==1)
    {
        delete_Begin(ls);
    }else{
        //head
        tmp=ls->head;
        for (int i = 1; i < ls->n-1; i++)
        {
            tmp=tmp->next;
            
        }
        ls->tail=tmp;//set head to tail
        tmp=tmp->next;//tail next point to null
        ls->tail->next =NULL;//set next to null
        ls->n--;
    }
}
