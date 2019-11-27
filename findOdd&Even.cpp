#include<iostream>

using namespace std;

int main()
{
	int i,arr1[5],arr2[5],j=0,k=0,n=5;
	int arr[5]={1,2,3,4,5};
	
	for(i=0;i<n;i++)
	{
		if(arr[i]%2==0)
			arr1[j++]=arr[i];
		else
			arr2[k++]=arr[i];
	}
	cout<<"The Even numbers are: "<<endl;
	for(i=0;i<j;i++)
	{
		cout<<arr1[i]<<endl;
	}
	cout<<"The Odd numbers are: "<<endl;
	for(i=0;i<k;i++)
	{
		cout<<arr2[i]<<endl;
	}
}
