#include <iostream>

using namespace std;

const int NUMNODES = 10;
int avail = 0;

//creating a node
struct Node
{
	int data;
	int next;
} node[NUMNODES];

//creating a static list
class List
{
private:
	int start;

public:
	List()  {start=-1;}
//checking if list is empty or not
	bool isEmpty()
	{
		return start == -1;
	}
//getiing index of node
	int getnode()
	{
		if (avail == -1)
		{
			cout << "Overflow" << endl;
			exit(1);
		}
		int p = avail;
		avail = node[avail].next;
		return p;
	}
//Free the deleted node
	void freenode(int p)
	{
		node[p].next = avail;
		avail = p;
	}
//inserting at front of list
	void insert_front(int item)
	{
		int q = getnode();
		node[q].data = item;
		node[q].next = start;
		start = q;
	}
//inserting at last of the list
	void insert_back(int item)
	{
		int q = getnode();
		node[q].data = item;
		node[q].next = -1;

		int ptr = start;
		if (isEmpty())
			start = q;
		else
		{
			while (node[ptr].next != -1) // traverse to end of list
				ptr = node[ptr].next;
			node[ptr].next = q;
		}
	}
//removing from the front of list
	void remove_front() {
		if (isEmpty()) {
			cout << "Underflow" << endl;
			exit(1);
		}

		int ptr = start;
		start = node[start].next;
		node[ptr].data =0;
		freenode(ptr);
	}
	//displaying all the element of list
	void display()
	{
		int ptr = start;
		while (ptr != -1)
		{
			std::cout << node[ptr].data << "->";
			ptr = node[ptr].next;
		}
		std::cout<<std::endl;
	}
};

//Creating a class queue implementing static list
class Queue
{
private:
	List l;
public:
	Queue()
	{
		for (int i = 0; i < NUMNODES - 1; i++)
			node[i].next = i + 1;
		node[NUMNODES - 1].next = -1;
	}
	//inserting items at end of list
	void enqueue(int data)
	{
		l.insert_back(data);
	}
	//deleting items from the front of the list
	void dequeue()
	{
		l.remove_front();
	}
	void display()
	{
		l.display();
	}
};
//main function to insert and delete item from the list
// int main()
// {
// 	for (int i = 0; i < NUMNODES - 1; i++)
// 		node[i].next = i + 1;
// 	node[NUMNODES - 1].next = -1;
// 	List l1;
// 	l1.insert_front(100);
// 	l1.insert_front(300);
// 	l1.insert_front(200);
// 	l1.insert_back(400);
// 	l1.insert_back(500);
// 	l1.remove_front();
// 	l1.insert_back(600);
// 	l1.display();
// 	return 0;
// }

//main function to implement queue
int main()
{
	Queue q;
	q.enqueue(5);
	q.enqueue(6);
	q.display();
	q.dequeue();
	q.display();
	q.enqueue(7);
	q.enqueue(8);
	q.display();
	q.dequeue();
	q.display();
	return 0;
}
