tại sao bị loi segmentation fault(core dumped) trong doan code nay 
#include "element.h"

element::element()
{
    this->data = 0;
    this ->pointer = nullptr;
}
element::element(int data)
{
    this ->data = data;
    this->pointer = nullptr;
}
element::~element()
{
    //dtor
}
#ifndef ELEMENT_H
#define ELEMENT_H
class element
{
    private:
        int data;
        element *pointer;
    public:
        element();
        element(int);
        virtual ~element();
        int Getdata() {return data;}
        void Setdata(int val) {this->data = val;}
        element* Getpointer() {return pointer;}
        void Setpointer(element* val) {pointer = val;}
    protected:        
};
#endif //ELEMENT_H
#include "linkedlist.h"
#include <iostream>
using namespace std;
linkedlist::linkedlist()
{
    this->head = nullptr;
    this->tail = nullptr;
    this->nNum = 0;
}
linkedlist::~linkedlist(){}

void linkedlist::InsertFirst(element*e) {
    if(this->head == nullptr)
        this->head=this->tail = e;
    else{
        e->Setpointer(this->head); // set pointer of element e by head
        this->head = e; // set head of linkedlist = e; ???
    }
    this->nNum++;    
}
void linkedlist::InsertTail(element *e)
{
    if(this->head = nullptr){
        this->head = this->tail = e; // khi head tro vao e thi e tro vao null ; do da thiet lap contructor element.
    }else{
        this->tail->Setpointer(e); // defalt value of tail is null; cause tail is a member of element ;so it can using setpointer from element . setpointer to set poiter of "this" being point to it.
        this->tail = e;
    }
    this->nNum++;
}
void linkedlist::Travel(){
    element *p =  this->head;// p.data = head.data ; p.pointer = head.pointer
    while (p!=nullptr) //
    {
        cout<<p->Getdata()<<"\t"; //return p.data;
        p=p->Getpointer(); // make p store address of next node.
    }
}
bool linkedlist::DeleteFirst(){
    if(this->head == nullptr)
        return false;
    else{
        element*p = this->head;
        this->head = this->head->Getpointer(); // set new head = the second node.
        delete p; // delete head before
        return true;
    }    
}
#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include "element.h"

class linkedlist
{
    private:
        element* head;
        element* tail;
        int nNum;
    public:
        linkedlist();
        virtual ~linkedlist();
        element* Gethead() {return head;}
        void Sethead(element* val) {head = val;}
        element *Gettail() {return tail;}
        void Settail(element *val) {tail = val;}
        void InsertFirst(element*);
        void InsertTail(element*);
        bool DeleteFirst();
        void Travel();
    protected:    
};
#endif //LINKEDLIST_H
#include <iostream>
#include "linkedlist.h"
using namespace std;
int main()
{
    linkedlist *list_ = new linkedlist() ;
    element *e;
    e=new element(9);
    list_->InsertTail(e);
    e = new element(10);
    list_->InsertTail(e);
    e = new element(8);
    list_->InsertTail(e);

    list_->Travel();
    list_->DeleteFirst();
    cout<<"\n";
    list_->Travel();
    return 0;
}
