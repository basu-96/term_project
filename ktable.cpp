#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>
#include<iterator>
#include<cmath>
#include<fstream>

using namespace std;

pair <int, vector<int> > k_coupled(int);
void display_vector(const vector<int> &);
void display_ranks(int, vector<int> &, vector<int> &);

int main()
{
	pair <int, vector<int> > p2;
	vector<int> blocs;
	int n;//number of spins
	//int i, j;
	//int ptr1 = 0;
	//int ptr2 = 0;
	//////////////////////////////////////////////////////////////////
	//variable declaration end
	//////////////////////////////////////////////////////////////////
	cout << "Number of spins :";
	cin >>n;
	p2 = k_coupled(n);
	vector<int> ranks(n + p2.first);
	//fill(ranks.begin(), ranks.end(), 0);
	//cout << ranks.size() << endl;
	//blocs = p2.second;
	//cout << "Blocs:\n";
	display_vector(blocs);
	//cout << endl;
	/*cout << "Enter hamiltonian term:";
	cin >> i >> j;

	ranks[i-1] = 1;
	ranks[j-1] = 1;

	for(int i = 1; i < blocs.size(); i++)
	{
		ptr2 = ptr2 + blocs[i-1];
		for(int j = ptr2; j < ptr2 + blocs[i]; j++)
		{
			ranks[j] = max(ranks[ptr1], ranks[ptr1+1]) - ranks[ptr1]*ranks[ptr1+1];
			ptr1 = ptr1 + 2;
		}
		ptr1 = blocs[i-1];
	}*/

	//display_vector(ranks);
	cout << endl;
	display_ranks(n, ranks, blocs);
	return 0;
}
////////////////////////////////////////////////////////////////////////////////

pair <int, vector<int> > k_coupled(int n)
{
	vector<int> blocs;
	int result;
	//pair <int, vector<int> > p1(result, blocs);
	int temp = n;

	blocs.push_back(temp);
	result = 0;//# of intermediate tensor ranks('kbar')
	while(temp != 0 && temp > 2)
	{
		result = result + temp / 2;
		blocs.push_back(temp / 2);
		temp = temp / 2 + temp % 2;
	}

	return make_pair(result, blocs);

}
////////////////////////////////////////////////////////////////////////////////
void display_vector(const vector<int> &v)
{
	copy(v.begin(), v.end(), ostream_iterator<int>(cout, " "));
}
////////////////////////////////////////////////////////////////////////////////
void display_ranks(int n, vector<int> &ranks, vector<int> &blocs)
{
	int it = 1;
	ofstream outf;
	outf.open("ranks.txt");
	for(int i = 0; i < blocs[0]; i++)
	{
		outf <<"k"<< i+1 << "\t";
	}
	for(int i = 1; i < blocs.size(); i++)
	{
		for (int j = 0; j < blocs[i]; j++)
		{
			outf <<"c"<< it << "\t";
			it++;
		}
	}
	outf << endl;
	for (int i = 1; i <= n; i++)
	{
		fill(ranks.begin(), ranks.end(), 0);
		int ptr1 = 0;
		int ptr2 = 0;

		ranks[i-1] = ranks[i%n] = 1;

		for(int i = 1; i < blocs.size(); i++)
		{
			ptr2 = ptr2 + blocs[i-1];
			for(int j = ptr2; j < ptr2 + blocs[i]; j++)
			{
				ranks[j] = max(ranks[ptr1], ranks[ptr1+1]) - ranks[ptr1]*ranks[ptr1+1];
				ptr1 = ptr1 + 2;
			}
			ptr1 = blocs[i-1];
		}

		display_vector(ranks);
		for (int i = 0; i < ranks.size(); i++)
		{
			outf << ranks[i] << "\t";
		}
		outf << endl;
		cout << endl;
	}
	outf.close();
}
