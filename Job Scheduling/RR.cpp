//Program to implement RR CPU Scheduling
//		by Aniruddha

#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;

class Process
{
	public: int AT,PID,BT,WT,TAT,CT,RT;
	bool arrived; 
	Process(): arrived(false) {}
	
};

bool comp(Process a,Process b)
{
	return a.AT<b.AT;
}

int push_arrived_process(Process *&p, queue<int> &q, int pt, int n, int &a_count)
{
	for(int i=0;i<n;i++)
	{
		if(pt < p[i].AT) break;
		if (!p[i].arrived)
		{
			q.push(i);
			p[i].arrived = true;
			a_count++;
		}	
	}
	return a_count;
}


int main()
{
	int n,TQ,i,pt=0,rt,pp,count = 0,a_count = 0;
	float aTAT=0,aWT=0;
	queue <int> q;
	
	//Getting Details
	cout<<"Enter no of process: ";
	cin>>n;
	
	Process *p = new Process[n];
	
	cout<<"Enter PID,Arival time & Burst time "<<n<<" process :\n";
	for(i=0;i<n;i++)
	{
		cin>>p[i].PID>>p[i].AT>>p[i].BT;
		p[i].RT = p[i].BT;
	}
	
	cout<<"\nEnter Time Quantum: ";
	cin>>TQ;
	
	//Sorted according to arrival time
	sort(p,p+n,comp);
	
	//Initialization
	pt=p[0].AT;
	a_count = push_arrived_process(p,q,pt,n,a_count);

	//Making Gnatt chart and calculating
	cout<<"\nGantt Chart:\n";
	while (true)
	{
		//if there is gap in Gnatt chart
		if(q.empty()) 
		{
			pt++;
			a_count = push_arrived_process(p,q,pt,n,a_count);
			continue;
		}
		
		pp = q.front();	//present process
		q.pop();
		
		rt = min(p[pp].RT, TQ);	//running time
		
		pt = p[pp].CT = pt + rt;
		p[pp].RT -= rt;		//updating remaining time
		
		//Check for other arrived process
		a_count = push_arrived_process(p,q,pt,n,a_count);
		
		//mark the present proccess as completed or add to queue as required
		if (p[pp].RT == 0)
			count++;
		else 
			q.push(pp);
		
		//Printing 
		cout<<"| "<<p[pp].CT-rt<<"=>(P"<<p[pp].PID<<")<="<<p[pp].CT<<" |";
		
		//Break if all are completed
		if(count==n) break;
		
	}
	
	//Calculating other details
	for(pp=0;pp<n;pp++)
	{
	
		p[pp].TAT = p[pp].CT - p[pp].AT;
		p[pp].WT = p[pp].TAT - p[pp].BT;
		aTAT += p[pp].TAT;
		aWT += p[pp].WT;
	}
	aTAT /= n;
	aWT /= n;
	
	//Printing Table
	cout<<"\n\nPID\tAT\tBT\tCT\tTAT\tWT\n";
	for(i=0;i<6*8;i++) cout<<"-";cout<<"\n";
	for(i=0;i<n;i++)
		cout<<p[i].PID<<"\t"<<p[i].AT<<"\t"<<p[i].BT<<"\t"<<p[i].CT<<"\t"<<p[i].TAT<<"\t"<<p[i].WT<<"\n";
	for(i=0;i<6*8;i++) cout<<"-";cout<<"\n";
	cout<<"\nAverage Turn-around Time: "<<aTAT;
	cout<<"\nAverage Waiting Time: "<<aWT<<"\n";
	
	return 0;
}	

/*Sample Output:

Enter no of process: 7
Enter PID,Arival time & Burst time 7 process :
1 5 250
2 50 170
3 130 75
4 190 100
5 210 130
6 350 50
7 800 125

Enter Time Quantum: 100

Gantt Chart:
| 5=>(P1)<=105 || 105=>(P2)<=205 || 205=>(P1)<=305 || 305=>(P3)<=380 || 380=>(P4)<=480 || 480=>(P2)<=550 || 550=>(P5)<=650 || 650=>(P1)<=700 || 700=>(P6)<=750 || 750=>(P5)<=780 || 800=>(P7)<=900 || 900=>(P7)<=925 |

PID	AT	BT	CT	TAT	WT
------------------------------------------------
1	5	250	700	695	445
2	50	170	550	500	330
3	130	75	380	250	175
4	190	100	480	290	190
5	210	130	780	570	440
6	350	50	750	400	350
7	800	125	925	125	0
------------------------------------------------

Average Turn-around Time: 404.286
Average Waiting Time: 275.714

*/
