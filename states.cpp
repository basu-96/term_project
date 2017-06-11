#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>
#include<list>
#include<iterator>
#include<cmath>
#include<fstream>


using namespace std;

vector <float> add_spin(float, float);
void display_vector(const vector<float> &);
/////////////////////////////////////////////////////////////////////////
class Graph
{
private:
  int V;
  list<int> *adj;
public:
  Graph(int V)
  {
    this->V = V;
    adj = new list<int>[V];
  }
  void add_edge(int , int );
};
void Graph::add_edge(int v, int w)
{
  adj[v].push_back(w);
  adj[w].push_back(v);
}
////////////////////////////////////////////////////////////////////////

int main()
{
  int n;
  cout << "enter number of spins:";
  cin >> n;
  int node = 0;
  vector<float> spin;
  spin = add_spin(0.5, 0.5);
  vector<pair<int, float> > graph;
  graph.push_back(make_pair(node, spin[0]));
  node++;
  graph.push_back(make_pair(node, spin[1]));
  node++;
  for(int i = 2; i < n; i++)
  {
    int layer = 0;
    for(int j = 0; j < spin.size(); j++)
    {
      vector<float> temp = add_spin(0.5 ,spin[j]);
      for(int l = 0; l < temp.size(); l++)
      {

        graph.push_back(make_pair(node, temp[l]));
        node++;
        layer++;
      }
    }
    spin.resize(0);
    for(int i= node-layer; i < node; i++)
    {
      spin.push_back(graph[i].second);
    }
  }
  for(int i = 0; i < graph.size(); i++)
  {
    cout << graph[i].first << "\t" << graph[i].second << endl;
  }
  display_vector(spin);
  cout << endl;
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
}
////////////////////////////////////////////////////////////////////////////////
