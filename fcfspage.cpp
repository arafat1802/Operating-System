#include<bits/stdc++.h>
using namespace std;
int main()
{
    int l, s[50], frame[10], n, available, count = 0, i, j, position=0;
    cout << "Enter the length of the string: ";
    cin >> l;
    cout << "Enter the string: ";
    for(i=0; i<l; i++)
        cin >> s[i];
    cout << "Enter the number of frames: ";
    cin >> n;
    for(int i=0; i<n; i++)
        frame[i]= -1;
    cout << "String\t\t Page Frames\n";

    for(int i=0; i<l; i++){
        cout << s[i] << "\t\t";
        available = 0;
        for(j=0; j<n; j++){
            if(frame[j] == s[i]){
                available = 1;
                break;
            }
        }
        if(available == 0){
            frame[position] = s[i];
            position = (position+1) % n;
            count++;
        }
        for(j=0; j<n; j++){
            if(frame[j] != -1)
                cout << frame[j] << "\t";
        }
        cout << endl;
    }

    cout << "Page Fault is = " << count << "\n";

    return 0;

}

