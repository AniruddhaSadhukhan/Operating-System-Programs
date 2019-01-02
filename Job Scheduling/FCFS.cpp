//Program to implement FCFS cpu scheduling
//	by Aniruddha

#include<iostream>
#include<algorithm>
using namespace std;


class Process
{
	public: int AT,PID,BT,WT,TAT,CT;
	
};

bool comp(Process a,Process b)
	{
		return a.AT<b.AT;
	}

int main()
{
	int n,i,pt=0;
	float aTAT=0,aWT=0;
	
	cout<<"Enter no of process: ";
	cin>>n;
	
	Process *p = new Process[n];
	
	cout<<"Enter PID,Arival time & Burst time "<<n<<" process :\n";
	for(i=0;i<n;i++)
		cin>>p[i].PID>>p[i].AT>>p[i].BT;
	
	sort(p,p+n,comp);
	
	cout<<"Gantt Chart:\n";
	for(i=0;i<n;i++)
	{
		if(p[i].AT > pt)
			pt = p[i].AT;
		pt = p[i].CT = pt + p[i].BT;
		
		p[i].TAT = p[i].CT - p[i].AT;
		p[i].WT = p[i].TAT - p[i].BT;
		
		aTAT += p[i].TAT;
		aWT += p[i].WT;
		
		cout<<"| "<<p[i].CT-p[i].BT<<"=>(P"<<p[i].PID<<")<="<<p[i].CT<<" |";
	}
	
	aTAT /= n;
	aWT /= n;
	
	cout<<"\nPID\tAT\tBT\tCT\tTAT\tWT\n";
	for(i=0;i<6*8;i++) cout<<"-";cout<<"\n";
	for(i=0;i<n;i++)
		cout<<p[i].PID<<"\t"<<p[i].AT<<"\t"<<p[i].BT<<"\t"<<p[i].CT<<"\t"<<p[i].TAT<<"\t"<<p[i].WT<<"\n";
	for(i=0;i<6*8;i++) cout<<"-";cout<<"\n";
	cout<<"\nAverage Turn-around Time: "<<aTAT;
	cout<<"\nAverage Waiting Time: "<<aWT;
	
	return 0;
}

/*Sample Output:
Enter no of process: 3
Enter PID,Arival time & Burst time 3 process :
1 4 2
2 1 2
3 4 1
Gantt Chart:
| 1=>(P2)<=3 || 4=>(P1)<=6 || 6=>(P3)<=7 |
PID	AT	BT	CT	TAT	WT
------------------------------------------------
2	1	2	3	2	0
1	4	2	6	2	0
3	4	1	7	3	2
------------------------------------------------

Average Turn-around Time: 2.33333
Average Waiting Time: 0.666667

*/
