#include <iostream>
using namespace std;
// struct element
struct Element{
    int data;
    Element *next;
    Element *prev;
};
//struct list
struct List{
    int n;
    Element *head;
    Element *tail;

};
//create empty list
List *createList();
//create insert begin
void insert_Begin(List *ls, int dataNew);
//create Display
void displayList(List *ls);
//Display from back to head
void displayList1(List *ls);
//insert_end
void insert_End(List *ls,int newData);
//create Menu
void menuProgram();
int main(){   
    menuProgram();
}
void menuProgram(){
    int choice,number;
    List *ls;
    ls= createList(); 
    insert_Begin(ls,12);
    insert_Begin(ls,11);
    insert_Begin(ls,13);
    insert_End(ls,14);
    insert_End(ls,15);
    insert_End(ls,16);
    insert_Begin(ls,12);
    insert_Begin(ls,11);
    insert_Begin(ls,13);
    displayList(ls);
    displayList1(ls);
    while (1)
    {
        cout<<"\t\t==================================\n";
        cout<<"\t\t+Welcome to Link List Program -_-+\n";
        cout<<"\t\t==================================\n\n";
        cout<<"1.Insert Begin of List.\n\n";
        cout<<"2.Insert End of List.\n\n";
        cout<<"3.Display from head.\n\n";
        cout<<"4.Display from tail.\n\n";
        cout<<"5.Exit Program.\n\n";
        cout<<"Choice:";
        cin>>choice;
        if (choice ==1)
        {
            system("clear||cls");
            cout<<"Input Number:";
            cin>>number;
            insert_Begin(ls,number);
        }else if (choice==2)
        {
            system("clear||cls");
            cout<<"Input Number:";
            cin>>number;
            insert_End(ls,number);
        }else if (choice==3)
        {
            displayList(ls);
        }else if (choice ==4)
        {
            displayList1(ls);
        }else if (choice==5)
        {
            system("clear||cls");
            cout<<"Exit Program.\n\n";
            break;
        }
    }
}

void displayList1(List *ls){
    Element *tmp;
    tmp = ls->tail;
    while (tmp!=NULL)
    {
        cout<<tmp->data<<" ";
        tmp=tmp->prev;
    }
    cout<<"\n";
}
void insert_End(List *ls,int newData){
    Element *e;
    e= new Element();
    if (ls->n==0)
    {
        insert_Begin(ls,newData);    
           
    }else
    {
        e->data =newData;
        e->next = NULL;
        
        ls->tail->next =e;
        //link tail <-prev
        e->prev=ls->tail; 
        
        ls->tail=e;
        ls->n++;
    }
}

void displayList(List *ls){
    Element *tmp;
    tmp =ls->head;
    while (tmp!=NULL)
    {
        cout<<tmp->data<<" ";
        tmp=tmp->next;
    }
    cout<<"\n";

}
void insert_Begin(List *ls, int dataNew){
    Element *e;
    e = new Element();
    e->data = dataNew;
    e->prev =NULL;
    e->next=ls->head;
    //update tail
    if (ls->n==0)
    {
        ls->tail=e;

    }
    //update head next-> <-prev
    if (ls->n!=0)
    {
        ls->head->prev =e;
    }
    ls->head = e;
    ls->n++;
}
List *createList(){
    List *ls;
    ls = new List();
    ls->n=0;
    ls->head =NULL;
    ls->tail=NULL;
    return ls;
}
