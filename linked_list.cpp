#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>
#include<iterator>
#include<cmath>
#include<fstream>

using namespace std;

struct node
{
  int data;
  node *next;
};
/*
class my_list
{
private:
  node *head, *tail;
public:
  my_list();
  void createnode(float);
  void display();
  void insert_start(int);
  void insert_position(int, float );
  void delete_first();
  void delete_last();
  void delete_position(int);
};
*/
int main()
{
  vector<node *> my_node;
  my_node.resize(0);
  for(int i = 0; i < 5; i++)
  {
    node *temp = new node;
    temp->data = i;
    if(i == 0)
    {
      temp->next = NULL;
    }
    else if(i > 0)
    {
      temp->next = my_node[i-1];
    }
    my_node.push_back(temp);
  }

  for(int i = 0; i < 5; i++)
  {
    cout << my_node[i]->next << endl;
  }
  node *temp = new node;
  temp = my_node[my_node.size() - 1];
  while(temp!=NULL)
  {
    cout << temp->data << endl;
    temp = temp->next;
  }

  return 0;
}
/*
my_list::my_list()
{
  head = NULL;
  tail = NULL;
}
void my_list::createnode(int value)
{
  node *temp=new node;
	temp->data=value;
	temp->next=NULL;
	if(head==NULL)
	{
		head=temp;
		tail=temp;
		temp=NULL;
	}
	else
	{
		tail->next=temp;
		tail=temp;
  }
}
void my_list::display()
{
  node *temp = new node;
  temp = head;
  while(temp!=NULL)
  {
    cout << temp->data << "\t";
    temp = temp->next;
  }
}
void my_list::insert_start(float value)
{
  node *temp = new node;
  temp->data = value;
  temp->next = head;
  head = temp;
}
void my_list::insert_position(int pos, float value)
{
  node *pre = new node;
  node *cur = new node;
  node *temp = new node;
  cur = head;
  for(int i = 1; i < pos; i++)
  {
    pre = cur;
    cur = cur -> next;
  }
  temp -> data = value;
  pre -> next = temp;
  temp -> next = cur;
}
void my_list::delete_first()
{
  node *temp = new node;
  temp = head;
  head = head -> next;
  delete temp;
}
void my_list::delete_last()
{
  node *current = new node;
  node *previous = new node;
  current = head;
  while(current -> next != NULL)
  {
    previous = current;
    current = current -> next;
  }
}
void my_list::delete_position(int pos)
{
  node *current = new node;
  node *previous = new node;
  current = head;
  for(int i = 1; i < pos; i++)
  {
    previous = current;
    current = current -> next;
  }
  previous ->next = current -> next;
}
*/
