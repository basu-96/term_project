//##############################################################################
//##############################################################################
//How to use this program:
//1.Suppose we are interested in calculating the number of S=0(singlet) eigen-
//states for n = 10
//  Input:
//    >>10
//    >>0.00
//  Output:
//    >>42
//2.To calculate the numbe of S = 1.5(i.e., S = 3/2) eigenstates for n = 9
//  Input:
//    >>9
//    >>1.5
//  Output:
//    >>192
//NOTE: The output comes multiplied by 'multiplicity' corresponding to S
//##############################################################################
//##############################################################################
#include<iostream>
#include<map>
#include<cmath>//fabs() - returns absolute value of floats
#include<algorithm>//count(), unique()
#include<vector>

using namespace std;

int states(int, float);//returns instances of S for n spin 1/2s

int main()
{
  int n;//no. of spins
  float S;//total spin for which the number of eigenstates has to be calculated
  cin >> n;
  cin >> S;
  cout << states(n, S) << endl;

  return 0;
}
int states(int n, float S)
{
  map<float, int> vec;//container that stores instances of S against S as a map
  vector<float> keysp;
  keysp.push_back(0.5);
  for(int i = 2; i <= n; i++)
  {
      vector<float> keys;
      vector<float> temp;

      for(int i = 0; i < keysp.size(); i++)
      {
        float j = fabs(0.5 - keysp[i]);
        while(j <= 0.5 + keysp[i])
        {
          keys.push_back(j);
          temp.push_back(j);
          j = j + 1.00;
        }
      }

      sort(temp.begin(), temp.end());
      vector<float>::iterator it;
      it = unique(temp.begin(), temp.end());
      temp.resize(distance(temp.begin(), it));
      for(int i = 0; i < temp.size(); i++)
      {
        vec[temp[i]] = count(keys.begin(), keys.end(), temp[i]);
      }
      keysp = keys;

  }
  return vec[S];
}
