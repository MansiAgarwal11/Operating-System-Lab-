#include<iostream>

using namespace std;

/*struct process

{
	int BT, CT, WT, done;
};




int main()
{
	cout<"Enter number of processes"<<endl;
	int n;
	cin>>n;
	cout<<"Enter time slice"<<endl;
	int t;
	cin>>t;
	process A[100];
	for(int i=0;i<n;i++)
	{
		cout<<"Enter burst time for "<< i <<"th process "<<endl;
		cin>>A[i].BT;
		A[i].CT=0;
		A[i].done=0;

	}
	if(A[0].BT<=t)
	{A[0].CT +=A[0].BT; A[0].BT=0;
	}
	else
	{
		A[0].CT+=t; A[0].BT-=t;
	}

	int j =1,count1=0,L=0;
	while(1)
	{
	    if(A[j].done==1)
        {
            L++;
        }

            int b=j;
		else if(A[j].BT<=t )
		{
		    if(A[(j + n -1)%n].done !=1)
			{A[j].CT += (A[(j + n -1)%n].CT + A[j].BT); A[j].BT=0;count1++ ;A[j].done=1;}
			else
            {
                while(A[(b + n -1)%n].done !=1)
                {
                    b=(b+n-1)%n;
                }

                A[j].CT += (A[(b + n -1)%n].CT + A[j].BT); A[j].BT=0;count1++ ;A[j].done=1;
            }


		}
		else
		{
		    if(A[(j + n -1)%n].done !=1)
			{A[j].CT +=   (A[(j + n -1)%n].CT + t) ; A[j].BT-=t;}
			else
            {
                while(A[(b + n -1)%n].done !=1)
                {
                    b=(b+n-1)%n;
                }

                A[j].CT +=   (A[(b + n -1)%n].CT + t) ; A[j].BT-=t}
		}
		j= (j+1)%n;
	}*/

int BT[10];
int WT[10];
int remain_bt[10];
int t=0;

int main()
{
    cout<<"Enter number of processes"<<endl;
	int n;
	cin>>n;
	cout<<"Enter time slice"<<endl;
	int quant;
	cin>>quant;
	for(int i=0;i<n;i++)
    {
        cout<<"Enter burst time for "<< i <<"th process "<<endl;
		cin>>BT[i];
		WT[i]=0;
    }
    for(int j=0;j<n;j++)
    {

        remain_bt[j]= BT[j];
    }

    int k=0, count1=0;
    while(count1!=n)
    {

        if(remain_bt[k]==0)
        {
            count1++;
        }
        else if(remain_bt[k]<=quant)
        {
            t+= remain_bt[k];
            WT[k]=t-BT[k];
            remain_bt[k]=0;
        }
        else
        {
            t+=quant;
            remain_bt[k]-=quant;
        }
        k=(k+1)%n;
    }

	int awgwt=0;
	for(int r=0;r<n;r++)
    {
        awgwt+=WT[r];

    }

    float ans;
    ans= float(awgwt)/n;
    cout<<"Average waiting time "<< ans<< endl;
    return 0;
}



