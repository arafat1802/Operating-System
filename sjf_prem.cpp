#include<bits/stdc++.h>
using namespace std;
bool cmp(pair<int,int>a, pair<int,int>b){
	return a.second <= b.second;
}
int main()
{
	int n;
	cin >> n;
	priority_queue<pair<int,int>,vector<pair<int,int>>, cmp> pq;
	while(n--){
		int x,y;
		cin >> x >> y;
		pq.push({x,y});
	}
	while(!pq.empty())
	{

	}
	return 0;
}