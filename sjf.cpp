#include<bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
int main()
{
	int n;
	cout << "Number of Works: ";
	cin >> n;
	int temp = n;
	vector<pair<int,string>>q;
	for(int i = 0; i < n; i++){
		string s;
		cout << "Process: ";
		int time = 0;
		cin >> s;
		cout << "Burst Time: ";
		cin >> time;
		q.push_back(make_pair(time,s));
	}
	vector<int>wait;
	sort(q.begin(), q.end());
	int sum = 0;
	for(int i = 0; i < n; i++){
		wait.push_back(sum);
		sum += q[i].ff;
	}
	int waiting_time = 0;
	cout << "Process\t\t" << "Waitting time\n";
	for(int i = 0; i < n; i++){
		cout << q[i].ss << "\t\t" << wait[i] << "\n";
		waiting_time += wait[i];
	}
	cout << "\n\navg_waiting_time = " << (double)waiting_time/temp << "\n";
	return 0;
}
/**
5
p1 
5
p2 
10
p3 
15
p4 
12
p5 
2
**/