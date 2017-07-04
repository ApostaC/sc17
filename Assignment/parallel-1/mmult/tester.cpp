#include <iostream>
#include <stdio.h>
#include <fstream>
#include <cstdlib>
using namespace std;

ifstream fin1("output");
ifstream fin2("output2");

const int MAXI=(1<<31)-1;
int main()
{
	int sum1=0,sum2=0;
	float b;
	while(fin1>>b)
	{
		int temp=b*MAXI;
		srand(temp);
		sum1+=rand();
	}
	while(fin2>>b)
	{
		int temp=b*MAXI;
		srand(temp);
		sum2+=rand();
	}
	cout<<sum1<<" "<<sum2<<endl;
	return 0;
}

