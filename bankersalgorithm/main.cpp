#include<iostream>

using namespace std;

int avail[10];
int max1[10][10];
int alloc[10][10];
int need[10][10];
int work[10];
int finish[10];
int safe[10];

 int main()
 {
 	int n,m;
 	cout<<"enter the number of processes"<<endl;
 	cin>>n;
 	cout<<"enter the number of resources"<<endl;
 	cin>>m;

 	for(int l=0; l<m;l++)
 		{
 			cout<<"enter the number of instances for each resource type"<<endl;
 			cin>>avail[l];
 		}


 	for(int i=0;i<n;i++)
 	{
 		for(int j=0; j<m;j++)
 		{
 			int k;
 			cout<<"Enter the maximum need of  resource type "<< j+1 <<"for process "<< i+1 <<endl;
 			cin>>k;
 			if(k<=avail[j])
 			{
			max1[i][j]=k;}

			else
			{cout<<"process can't request for resources more than that available in the system"<<endl;
			break;
			}

		 }
	 }

	 for(int k=0;k<n;k++)
 	{
 		for(int f=0; f<m;f++)
 		{
	 		alloc[k][f]=0;}}

	for(int a=0;a<n;a++)
	{
		for(int b=0;b<m;b++)
		{
			need[a][b]= max1[a][b]- alloc[a][b];

		}
	}

	for(int u=0;u<m;u++)
	{
		work[u]= avail[u];
	}

 	for(int v=0;v<n;v++)
 	{
 		finish[v]=0;
	 }


	 int count=0;
	 int r=0;
	 while(count!=n)
	 {
        int h=0;
	 	if(finish[r]==0 )
	 	{
	 			for(int e=0;e<m;e++)
	 			{
	 				if(need[r][e]<=work[e])
	 				{
	 					h++;
					 }
				 }
				 if(h==m)
				 {
				     for(int v=0;v<m;v++)
				     {work[v] += alloc[r][v];}
						 finish[r]=1;
						 safe[count]= r;
						 count++;}
		 }

		 r=(r+1)%n;

	 }
	 cout<<"the safe sequence is"<<endl;
	 for(int g=0; g<n;g++)
	 {
	 	cout<<safe[g];
	 }
	return 0;
 }
