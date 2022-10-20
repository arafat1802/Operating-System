#include <bits/stdc++.h>
using namespace std;
 
int main()
{
	priority_queue< pair< int , pair<int,int> > > q;
	int n,wait_time=0,total_wait=0;
	cout<<"Enter number of processes : ";
	cin>>n;
 
	for(int i = 0 ; i < n ; i++)
	{
    	int priority , process_num , burst_time ;
    	cout<<"Enter  value (process number,burst time,priority) : ";
        cin>>process_num>>burst_time>>priority;
        q.push(make_pair(-1*priority,make_pair(process_num,burst_time)));
	}
 
	cout<<"\n\n";
	cout<<"Process number \t\t Burst time \t\t Priority \t\t Waiting time \n";
	while(!q.empty())
	{
        cout<<q.top().second.first<<"\t\t\t "<<q.top().second.second<<"\t\t\t "<<-1*q.top().first<<"\t\t\t "<<wait_time<<'\n';
    	if(q.size()>1)
    	{
        	wait_time += q.top().second.second;
        	total_wait += wait_time;
    	}
    	q.pop();
	}
 
	cout<<"\nTotal wait time : "<<total_wait<<"\n";
	cout<<"\nAverage wait time : "<<total_wait/(float)n<<"\n";
	return 0;
}
