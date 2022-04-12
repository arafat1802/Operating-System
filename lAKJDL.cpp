#include<bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
int main()
{
	int n = 5;
	int sum = 0;
	int temp = n;
	queue<pair<string,int>>q;
	while(n--){
		string s;
		int time = 0;
		cin >> s >> time;
		q.push(make_pair(s,sum));
		sum += (q.front().ss+time);
	}
	int waiting_time = 0;
	while(!q.empty()){
		cout << q.front().ff << " = " << q.front().ss << "\n";
		waiting_time += q.front().ss;
		q.pop();
	}
	cout << "avg_time = " << (double)waiting_time/temp << "\n";
	return 0;
}
/**
p1 5
p2 10
p3 15
p4 12
p5 2
**/
