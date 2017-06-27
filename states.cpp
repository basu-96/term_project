#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>
#include<iterator>
#include<cmath>
#include<fstream>
//#include "linked_list.cpp"


using namespace std;

struct node
{
  float data;
  node *next;
};

vector <float> add_spin(float, float);
void display_node(node *);
void display_vector(const vector<float> &);

/////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////

int main()
{
    int n;
    cout << "enter number of spins:";
    cin >> n;
    float total_spin;

    int layer;
    vector<node *> my_node;
    //vector<float> test_ns_pair;
    vector<float> spin;
    spin = add_spin(0.5, 0.5);
    vector<node *> buffer;// stores ns_pair for each layer
    for(int i = 0; i < spin.size(); i++)
    {
      node *temp = new node;
      temp->data = spin[i];
      temp->next = NULL;
      my_node.push_back(temp);

      //test_ns_pair.push_back(spin[i]);

    }
    buffer = my_node;


    for(int i = 2; i < n; i++)
    {
      int j = 0;
      layer = 0;
      while(j < buffer.size())
      {
        vector<float> temp = add_spin(0.5 , buffer[j]->data);
        for(int l = 0; l < temp.size(); l++)
        {
          node *tempn = new node;
          tempn->data = temp[l];
          tempn->next = buffer[j];
          my_node.push_back(tempn);
          //test_ns_pair.push_back(temp[l]);
          layer++;
        }
        j++;
      }


      buffer.resize(0);
      for(int i= my_node.size()-layer; i < my_node.size(); i++)
      {
        buffer.push_back(my_node[i]);
      }
    }
    cout << "enter total spin value : ";
    cin >> total_spin;
    for(int i = my_node.size() - 1; i >= my_node.size() - layer; i--)
    {
      if(my_node[i]->data == total_spin)
      {
        display_node(my_node[i]);
        cout << endl;
      }
      else continue;
    }


}
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
vector <float> add_spin(float s1, float s2)
{
  vector<float> temp;
  float s = abs(s1 - s2);
  while(s <= s1 + s2)
  {
    temp.push_back(s);
    s = s + 1;
  }
  return temp;
}
////////////////////////////////////////////////////////////////////////////////
void display_vector(const vector<float> &v)
{
	copy(v.begin(), v.end(), ostream_iterator<float>(cout, " "));
  cout << endl;
}
////////////////////////////////////////////////////////////////////////////////
void display_node(node *elem)
{
  node *temp = new node;
  temp = elem;
  while(temp!=NULL)
  {
    cout << temp->data << endl;
    temp = temp->next;
  }
}
////////////////////////////////////////////////////////////////////////////////
