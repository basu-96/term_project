#include<iostream>

#include<vector>
#include<utility>
#include<algorithm>
#include<cmath>
#include<fstream>

using namespace std;



int main()
{

  vector<int> test;
  for(int i = 0; i<5; i++)
  {
    test.push_back(i);
  }
  cout << test.size() << endl;
  test.resize(0);
  cout << test.size() << endl;


  return 0;
}
