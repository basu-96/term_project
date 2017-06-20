#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>
#include<iterator>
#include<cmath>
#include<fstream>
#include "linked_list.cpp"


using namespace std;

vector <float> add_spin(float, float);
void display_vector(const vector<float> &);
/////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////

int main()
{
  for(int q = 3; q < 11; q++)
  {
    int n;
    n = q;
    //cout << "enter number of spins:";
    //cin >> n;
    int node = 0;
    int layer;
    vector<float> fata;
    vector<float> test_ns_pair;
    //Graph graph(11);//this is only for n = 4
    vector<float> spin;
    spin = add_spin(0.5, 0.5);
    //display_vector(spin);
    //cout << endl;
    vector<pair<int, float> > ns_pair;//vector of 'node-spin' pairs
    vector<pair<int, float> > buffer;// stores ns_pair for each layer
    for(int i = 0; i < spin.size(); i++)
    {
      fata.push_back(spin[i]);
      ns_pair.push_back(make_pair(node, spin[i]));
      test_ns_pair.push_back(spin[i]);
      node++;
    }
    buffer = ns_pair;
    /*for(int i = 0; i < ns_pair.size(); i++)
    {
      cout << ns_pair[i].first << "\t" << ns_pair[i].second << endl;
    }
    */

    for(int i = 2; i < n; i++)
    {
      int j = 0;
      layer = 0;
      //cout << spin.size() << endl;
      while(j < buffer.size())
      {
        vector<float> temp = add_spin(0.5 , buffer[j].second);
        for(int l = 0; l < temp.size(); l++)
        {
          //graph.add_edge(node, buffer[j].first);
          //cout << node << "\t" << buffer[j].first << endl;
          fata.push_back(temp[l]);
          ns_pair.push_back(make_pair(node, temp[l]));
          test_ns_pair.push_back(temp[l]);
          node++;
          layer++;
        }
        j++;
      }
      buffer.resize(0);
      for(int i= node-layer; i < node; i++)
      {
        buffer.push_back(make_pair(ns_pair[i].first, ns_pair[i].second));
      }
    }
    /*
    for(int i = 0; i < ns_pair.size(); i++)
    {
      cout << ns_pair[i].first << "\t" << ns_pair[i].second << endl;
    }
    */
    //display_vector(fata);
    cout << n << "\t" << test_ns_pair.size() << endl;
    //cout << layer << endl;

  }
  return 0;
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
