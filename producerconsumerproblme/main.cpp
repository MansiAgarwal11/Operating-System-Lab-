#include<iostream>
#include<queue>

using namespace std;

int N=100;
int S=1;
int E=100;
int F=0;
queue <int>Q;

int wait(int a)
{
	while(a<=0);
	a--;
	return a;
}
int signal(int a)
{
 a++;return a;
}

void producer(int item)
{
	S=wait(S);
	E=wait(E);
	Q.push(item);
	cout<<"item produced!"<<endl;
	F=signal(F);
	S=signal(S);
}

void consumer()
{
	S=wait(S);
	F=wait(F);
	Q.pop();
	cout<<"item consumed!"<<endl;
	S=signal(S);
	E=signal(E);

}

int main()
{
	char a;
	do
	{
		cout<<"Which process do you want to do? 1)Produce 2)Consume 3)Exit"<<endl;
		int k;
		cin>>k;
		switch(k)
		{
			case 1: if(E==0)
   				 	{
		 		   	 cout<<"buffer full!"<<endl;break;
	 	 	         }
                    else
                    {
				    cout<<"enter item number"<<endl;
				 	int x;
				 	cin>>x;
				 	producer(x);
	 				break;
	 				}
			case 2:if(F==0)
   				    { cout<<"Buffer empty!"<<endl;
  					break;
					}
			        else
					{
					 consumer();break;
					 }
		    case 3: break;
			default: cout<<"Press valid option"<<endl;
		}
		cout<<"want to do more?(y/n)"<<endl;

		cin>>a;
	}while(a!='n');
}
