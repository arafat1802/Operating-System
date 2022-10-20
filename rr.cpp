#include<bits/stdc++.h>
using namespace std;
 
int main()
{
int count, j, n, time, remain, flag=0, time_quantum;
    int wait_time=0, turnaround_time=0, arrival_time[10], burst_time[10], remaining_time[10];
    cout << "Enter total process: ";
    cin >> n;
 
    remain=n;
    cout<<"Enter Arrival Time and Bust Time for \n";
    for(count=0; count<n; count++)
    {
        cout<<"Process Number "<<count+1<<" : ";
        cin>>arrival_time[count];
        cin>>burst_time[count];
        remaining_time[count]=burst_time[count];
    }
 
    cout<<"Enter  Time Quantum:\t";
    cin>>time_quantum;
    cout<<"\n\nProcess\t Turnaround Time    Waiting Time\n\n";
 
    for (time=0, count=0; remain!=0;)
    {
 
        if(remaining_time[count]<= time_quantum && remaining_time[count]>0)
        {
            time= time+ remaining_time[count];
            remaining_time[count]=0;
            flag=1;
        }
        else if(remaining_time[count]>0)
        {
            remaining_time[count]=remaining_time[count]- time_quantum;
            time=time+ time_quantum;
        }
 
        if(remaining_time[count]==0 && flag==1)
        {
            remain--;
            cout<<"p["<<count+1<<"] "<<time- arrival_time[count]<<"    "<<time- arrival_time[count]- burst_time[count]<<"\n";
            wait_time= wait_time+time- arrival_time[count]- burst_time[count];
            turnaround_time=turnaround_time+time- arrival_time[count];
            flag=0;     }
 
        if(count== n-1) count=0;
        else if(arrival_time[count+1]<=time) count++;
        else count=0;
 
    }
 
    cout<<"\nAverage Waiting Time= "<<wait_time*1.0/n<<"\n";
    cout<<"\nAverage Turnaround Time= "<<turnaround_time*1.0/n<<"\n";
 
    return 0;
}
