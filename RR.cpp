#include<bits/stdc++.h>

using namespace std;

#define bug(x) cout << #x  << " = " << x << "\n"

struct pr{
    string s;
    int burst;
    int number;
};
int main()
{
    freopen("inp2.txt","r",stdin);
    int n,t;
    queue<pr>R;
    vector<int>a(n+1,0);
    cout << "Number of Process : ";
    cin >> n;
    cout << "Quantum : ";
    cin >> t;
    string process;
    int burst_time = 0;
    double waiting_time = 0;
    for(int i = 0; i < n; i++){
        pr pro;
        cin >> process >> burst_time;
        pro.s = process;
        pro.burst = burst_time;
        pro.number = i+1;
        a[i+1] = a[i] + min(t,burst_time);
        waiting_time += a[i];
        //bug(waiting_time);
        R.push(pro);

    }
    cout << "Process \t\t Execution Time\n";

    int sum = 0;

    while(!R.empty()){
        //bug(R.front().number);
        //bug(a[R.front().number]);
        int cur = R.front().burst;
        sum += min(R.front().burst,t);
        cout << R.front().s<< "\t\t\t\t" << sum << "\n";
        cur -= t;
        waiting_time += (sum - a[R.front().number]);
        //bug(waiting_time);
        //bug(sum);
        a[R.front().number] = sum;
        if(cur > 0){
            R.push({R.front().s, cur,R.front().number});
        }
        R.pop();
    }
    cout << "Waiting Time : ";
    cout << waiting_time << "\n";

    return 0;
}
/**
5
2
p1 6
p2 3
p3 5
p4 1
p5 4


**/
