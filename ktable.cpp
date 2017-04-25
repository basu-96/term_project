#include<iostream>
#include<cmath>
#include<fstream>

using namespace std;

int k_coupled(int);

int main()
{
	fstream myfile;
	myfile.open("sample.txt", ios::out);
	for(int i = 2; i < 11; i++)
	{
		
		myfile << i << "\t" << k_coupled(i) << endl;
	}
	myfile.close();
	return 0;
}

int k_coupled(int n)
{
	int result;
	int temp = n;
	
	result = 0;//# of intermediate tensor ranks('kbar')
	while(temp != 0 && temp > 2)
	{
		result = result + temp/2;
		if(temp > 3)
		{
			result = result + temp % 2;	
		}	
		temp = temp/2;
	}
	return result;

}



