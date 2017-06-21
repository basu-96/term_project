#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>
#include<iterator>
#include<cmath>
#include<fstream>
//#include "linked_list.cpp"


using namespace std;

vector <float> add_spin(float, float);
void display_vector(const vector<float> &);

/////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////

int main()
{
    int n;
    cout << "enter number of spins:";
    cin >> n;
    int node = 0;
    int layer;
    vector<float> test_ns_pair;
    vector<float> spin;
    spin = add_spin(0.5, 0.5);
    vector<float> buffer;// stores ns_pair for each layer
    for(int i = 0; i < spin.size(); i++)
    {
      test_ns_pair.push_back(spin[i]);
      node++;
    }
    buffer = test_ns_pair;

    for(int i = 2; i < n; i++)
    {
      int j = 0;
      layer = 0;
      while(j < buffer.size())
      {
        vector<float> temp = add_spin(0.5 , buffer[j]);
        for(int l = 0; l < temp.size(); l++)
        {
          test_ns_pair.push_back(temp[l]);
          node++;
          layer++;
        }
        j++;
      }
      buffer.resize(0);
      for(int i= node-layer; i < node; i++)
      {
        buffer.push_back(test_ns_pair[i]);
      }
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
