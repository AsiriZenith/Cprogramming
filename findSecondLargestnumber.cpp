#include<iostream>

using namespace std;

int main()
{
	int arr[10]={4,7,3,2,5,8,9,11,6};
	int max=0,secondMax=0,i,Smax;
	for(i=0;i<10;i++)
	{
		if(arr[i]>max)
			max=arr[i];
	}
	for(i=0;i<10;i++)
	{
		if(arr[i]>secondMax){
			secondMax=arr[i];
			if(max!=secondMax)
				Smax=secondMax;
		}
	}
	cout<<"Second Largest Number is: "<<Smax<<endl;
}
