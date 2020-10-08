#include<iostream>
//creating a node for storing polynomials
template<class T>
class Node
{
public:
T coefficient;
T power;
Node<T> *next;
Node()
{
    next=NULL;
}
Node(T coefficient,T power)
{
    this->coefficient=coefficient;
    this->power=power;
    next=NULL;
}
};
//Linked list for group of polynomials
template<class T>
class CustomPolynomial
{
private:
Node<T> *head;
public:
CustomPolynomial()
{
    head=NULL;
}
//inserting at the end of the node
void insert(T coeff,T power)
{
    Node<T> *ptr=new Node<T>;
    ptr->coefficient=coeff;
    ptr->power=power;
    if(head==NULL)
    {
        head=ptr;
    }
    else
    {
        Node<T> *temp=head;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=ptr;
    }
}
//adding two polynomials
void add_polynomial(CustomPolynomial<T> a,CustomPolynomial<T> &result)
{
    Node<T> *ptr,*ptr1;
    ptr=this->head;
    ptr1=a.head;
    while(ptr && ptr1)
    {
        if(ptr1->power>ptr->power)
        {
            result.insert(ptr1->coefficient,ptr1->power);
            ptr1=ptr1->next;
        }
        else if(ptr->power>ptr1->power)
        {
            result.insert(ptr->coefficient,ptr->power);
            ptr=ptr->next;
        }
        else
        {
            result.insert(ptr->coefficient+ptr1->coefficient,ptr->power);
            ptr=ptr->next;
            ptr1=ptr1->next;
        }
    }
    while(ptr||ptr1)
    {
        if(ptr1)
        {
            result.insert(ptr1->coefficient,ptr1->power);
            ptr1=ptr1->next;
        }
        if(ptr)
        {
            result.insert(ptr->coefficient,ptr->power);
            ptr=ptr->next;
        }
    }
}
//displaying all the elements of the node
void display()
{
    Node<T> *temp=head;
    while(temp!=NULL)
    {
        if(temp->coefficient>0)
        {
            std::cout<<"+"<<temp->coefficient<<"x^"<<temp->power;
        }
        else
        {
            std::cout<<temp->coefficient<<"x^"<<temp->power;
        }
        temp=temp->next;
    }
    std::cout << "\n";
}
//Deallocating all the dynamically allocated memory
~CustomPolynomial()
{
    Node<T> *ptr,*ptr1;
    ptr=head;
    ptr1=ptr->next;
    while(ptr1!=NULL)
    {
        delete ptr;
        ptr=ptr1;
        ptr1=ptr->next;
    }
}
};
int main()
{
    CustomPolynomial<int> a,b,c;
    a.insert(-6,5);
    a.insert(-9,3);
    a.insert(5,2);
    a.insert(-6,1);
    a.insert(-6,0);
    std::cout<<"First polynomial:";
    a.display();
    b.insert(8,4);
    b.insert(4,3);
    b.insert(5,0);
    std::cout<<"Second polynomial:";
    b.display();
    a.add_polynomial(b,c);
    std::cout<<"Resulting polynomial:";
    c.display();
    return 0;
}
