#include<bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
int main()
{
	int n;
	cout << "Number of Works: ";
	cin >> n;
	int sum = 0;
	int temp = n;
	queue<pair<string,int> >q;

	for(int i = 0; i < n; i++){
		string s;
		cout << "Process: ";
		int time = 0;
		cin >> s;
		cout << "Burst Time: ";
		cin >> time;
		q.push(make_pair(s,sum));
		sum += (q.front().ss+time);
	}
	int waiting_time = 0;
	cout << "Process\t\t" << "Waitting time\n";
	while(!q.empty()){
		cout << q.front().ff << "\t\t" << q.front().ss << "\n";
		waiting_time += q.front().ss;
		q.pop();
	}
	cout << "\n\navg_waiting_time = " << (double)waiting_time/temp << "\n";
	return 0;
}