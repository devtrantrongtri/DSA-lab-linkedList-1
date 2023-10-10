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