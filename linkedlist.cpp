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
