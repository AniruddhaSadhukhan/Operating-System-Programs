//Program to implement SRTF CPU Scheduling
//		by Aniruddha

#include<iostream>
#include<algorithm>
using namespace std;


class Process
{
	public: int AT,PID,BT,WT,TAT,CT,RT;
	bool sts;
	Process(): sts(0) {}
	
};

int main()
{
	int n,i,pt=0,min,pp,j,count = 0;
	float aTAT=0,aWT=0;
	
	cout<<"Enter no of process: ";
	cin>>n;
	
	Process *p = new Process[n];
	
	cout<<"Enter PID,Arival time & Burst time "<<n<<" process :\n";
	for(i=0;i<n;i++)
	{
		cin>>p[i].PID>>p[i].AT>>p[i].BT;
		p[i].RT = p[i].BT;
	}
	
	cout<<"\nGantt Chart:\n";
	while (true)
	{
		min = 9999;
		pp=-1;	//present process
		
		//first search among those incompleted process which have already arrived
		//search for uncompleted proccess having minimum remaining time
		for(j=0;j<n;j++)
			if(!p[j].sts && p[j].AT<=pt && min>p[j].RT)
			{
				min = p[j].RT;
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
					if(pp>-1 && p[pp].AT==p[j].AT && p[pp].RT < p[j].BT)
						continue;
					min = p[j].AT;
					pp = j;	
				}	
		}
		
		//mark the present proccess as completed
		if (p[pp].RT == 1)
			p[pp].sts = 1,count++;
	
		if(p[pp].AT > pt)
			pt = p[pp].AT;
		pt = p[pp].CT = pt + 1;
		p[pp].RT--;
		
		
		cout<<"| "<<p[pp].CT-1<<"=>(P"<<p[pp].PID<<")<="<<p[pp].CT<<" |";
		if(count==n) break;
	}
	for(pp=0;pp<n;pp++)
	{
	
		p[pp].TAT = p[pp].CT - p[pp].AT;
		p[pp].WT = p[pp].TAT - p[pp].BT;
		aTAT += p[pp].TAT;
		aWT += p[pp].WT;
	}
	aTAT /= n;
	aWT /= n;
	
	cout<<"\n\nPID\tAT\tBT\tCT\tTAT\tWT\n";
	for(i=0;i<6*8;i++) cout<<"-";cout<<"\n";
	for(i=0;i<n;i++)
		cout<<p[i].PID<<"\t"<<p[i].AT<<"\t"<<p[i].BT<<"\t"<<p[i].CT<<"\t"<<p[i].TAT<<"\t"<<p[i].WT<<"\n";
	for(i=0;i<6*8;i++) cout<<"-";cout<<"\n";
	cout<<"\nAverage Turn-around Time: "<<aTAT;
	cout<<"\nAverage Waiting Time: "<<aWT;
	
	return 0;
}	

/*Sample Output:
Enter no of process: 6
Enter PID,Arival time & Burst time 6 process :
1 0 7
2 1 5
3 2 3
4 3 1
5 4 2
6 5 1

Gantt Chart:
| 0=>(P1)<=1 || 1=>(P2)<=2 || 2=>(P3)<=3 || 3=>(P4)<=4 || 4=>(P3)<=5 || 5=>(P3)<=6 || 6=>(P6)<=7 || 7=>(P5)<=8 || 8=>(P5)<=9 || 9=>(P2)<=10 || 10=>(P2)<=11 || 11=>(P2)<=12 || 12=>(P2)<=13 || 13=>(P1)<=14 || 14=>(P1)<=15 || 15=>(P1)<=16 || 16=>(P1)<=17 || 17=>(P1)<=18 || 18=>(P1)<=19 |

PID	AT	BT	CT	TAT	WT
------------------------------------------------
1	0	7	19	19	12
2	1	5	13	12	7
3	2	3	6	4	1
4	3	1	4	1	0
5	4	2	9	5	3
6	5	1	7	2	1
------------------------------------------------

Average Turn-around Time: 7.16667
Average Waiting Time: 4
*/		
			
	
