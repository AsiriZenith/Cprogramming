#include<iostream>

using namespace std;

int main()
{
	int n,i,j,arr[20][20];
	cout<<"Enter the number here: ";
	cin>>n;
	
	for(i=1;i<=n;i++)
	{
		int line1=i;
		for(j=n;j>0;j--)
		{
			if(line1==0)
				arr[i][j]=0;
			else
				arr[i][j]=line1--;		
		}
		int line2=i-1;	
		int  l=n+1; 
		for(j=n-1;j>0;j--)
		{
			if(line2==0)
				arr[i][l]=0;
			else
				arr[i][l]=line2--;
			l++;
		}
	} 
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=2*n-1;j++)
			cout<<arr[i][j]<<" "; 
		cout<<endl;
	} 
	
	for(i=n-1;i>0;i--)
	{
		for(j=1;j<=2*n-1;j++)
			cout<<arr[i][j]<<" ";
		cout<<endl;
	}
}
