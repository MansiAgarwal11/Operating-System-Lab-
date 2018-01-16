#include<iostream>
#include<cmath>
#define MAX 100
using namespace std;

int A[MAX];
int f, r;
int addfirst;

void initialise()
{
	f=0;r=0;
}

void insert(int add)
{
	if((r+1)%MAX== f)
	{
		
		cout<<"Queue is full ";
	}
	else
	{
		A[r]=add;
		r=(r+1)%MAX;
	}
}

int Delete()
{
	int x;
	x=A[f];
	f=(f+1)%MAX;
	return x;
}
int avgseektime()
{
	int addsec;
	addsec=Delete();
	int time;
	time=abs(addfirst- addsec);
	
	cout<<"The first head position was at"<<addfirst<<" and the final head position after this job is "<< addsec<< " and the seek time is "<<time<<endl;
	addfirst=addsec;
	return time;	
}
int main()
{
	int head;
	cout<<"Enter head position"<<endl;
	cin>>head;
	addfirst=head;
	initialise();
	int add;
	cout<<"Enter number of memory requests you want to schedule in range 0 to 1023"<<endl;
	int n;
	cin>>n;
	float t=0;
	for(int i=1;i<=n;i++)
	{
		cout<<"Enter address of job to be scheduled"<<endl;
		cin>>add;
		if(add>=0 && add<=1023          )
		{
		insert(add);
		}
		else
		{
			cout<<"Wrong entry"<<endl;
			break;
		}
		
		
	}
	for(int j=1;j<=n;j++)
	{
		t+=avgseektime();
	}
	float ans;
	ans= float(t)/n;
	cout<<"The first head position was at"<<head<< "and the average seek time is "<<ans<<endl;
	return 0;
}
