#include "linkedlist.h"
#include <iostream>
using namespace std;
linkedlist::linkedlist()
{
 //ctor
 this->head=nullptr;
 this->tail=nullptr;
}
linkedlist::~linkedlist()
{
 //dtor
}
void linkedlist::InsertFirst(element* e){
 if(this->head==nullptr)
 this->head=this->tail=e;
 else{
 e->Setpointer(this->head);
 this->head=e;
 }
}
void linkedlist::InsertTail(element*e){
 if(this->head==nullptr)
 this->head=this->tail=e;
 else{
 this->tail->Setpointer(e);
 this->tail=e;
 }
}
void linkedlist::Travel(){
 element* p=this->head;
 while(p!=nullptr){
 cout<<p->Getdata()<<"\t";
 p=p->Getpointer();
 }
}
 void linkedlist::DeleteFirst(){
 element*p=this->head;
 this->head=this->head->Getpointer();
 delete p;
 }