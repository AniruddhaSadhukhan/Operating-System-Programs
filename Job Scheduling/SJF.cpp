//Program to implement SJF cpu scheduling
//	by Aniruddha

#include<iostream>
#include<algorithm>
using namespace std;


class Process
{
	public: int AT,PID,BT,WT,TAT,CT;
	bool sts;
	Process(): sts(0) {} //1:completed 0:not completed
};

int main()
{
	int n,i,j,pt=0,min,pp;
	float aTAT=0,aWT=0;
	
	cout<<"Enter no of process: ";
	cin>>n;
	
	Process *p = new Process[n];
	
	cout<<"Enter PID,Arival time & Burst time "<<n<<" process :\n";
	for(i=0;i<n;i++)
		cin>>p[i].PID>>p[i].AT>>p[i].BT;
	
	cout<<"Gantt Chart:\n";
	for(i=0;i<n;i++)
	{
		min = 9999;
		pp=-1;	//present process
		
		//first search among those incompleted process which have already arrived
		//search for uncompleted proccess having minimum burst time
		for(j=0;j<n;j++)
			if(!p[j].sts && p[j].AT<=pt && min>p[j].BT)
			{
				min = p[j].BT;
				pp = j;
			}	
		
		//if no imcompleted processes have arrived, search among process which will
		//come immediately next and in case multiple process arrive simultaneously
		//consider the process having least BT
		if(pp<0)
		{
			for(j=0;j<n;j++)
				if(!p[j].sts && min>=p[j].AT)
				{
					if(pp>-1 && p[pp].AT==p[j].AT && p[pp].BT < p[j].BT)
						continue;
					min = p[j].AT;
					pp = j;	
				}	
		}
		
		//mark the present proccess as completed
		p[pp].sts = 1;
	
		if(p[pp].AT > pt)
			pt = p[pp].AT;
		pt = p[pp].CT = pt + p[pp].BT;
		
		p[pp].TAT = p[pp].CT - p[pp].AT;
		p[pp].WT = p[pp].TAT - p[pp].BT;
		
		aTAT += p[pp].TAT;
		aWT += p[pp].WT;
		
		cout<<"| "<<p[pp].CT-p[pp].BT<<"=>(P"<<p[pp].PID<<")<="<<p[pp].CT<<" |";
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

Enter no of process: 4
Enter PID,Arival time & Burst time 4 process :
1 4 2
2 1 2
3 4 1
4 4 3
Gantt Chart:
| 1=>(P2)<=3 || 4=>(P3)<=5 || 5=>(P1)<=7 || 7=>(P4)<=10 |
PID	AT	BT	CT	TAT	WT
------------------------------------------------
1	4	2	7	3	1
2	1	2	3	2	0
3	4	1	5	1	0
4	4	3	10	6	3
------------------------------------------------

Average Turn-around Time: 3
Average Waiting Time: 1

*/
