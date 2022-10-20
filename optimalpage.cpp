#include<bits/stdc++.h>
using namespace std;

int optimal(int s[], int frame[], int l, int n, int idx)
{
    int ans = 0, farthest = idx, i, j;
    for (i = 0; i < n; i++) {
        for (j = idx; j < l; j++) {
            if (frame[i] == s[j]) {
                if (j > farthest) {
                    farthest = j;
                    ans = i;
                }
                break;
            }
        }
        if (j == l)
            return i;
    }
    return ans;
}

int main()
{
    int l, s[50], frame[10], n, avail, count = 0, i, j, pos = 0, full = 0;
    cout << "Enter the length of the string: ";
    cin >> l;
    cout << "Enter the string: ";
    for (i = 0; i < l; i++)
        cin >> s[i];
    cout << "Enter the number of frames: ";
    cin >> n;
    for (int i = 0; i < n; i++)
        frame[i] = -1;
    cout << "String\t\t Page Frames\n";

    for (int i = 0; i < l; i++)
    {
        cout << s[i] << "\t\t";
        avail = 0;
        for (j = 0; j < n; j++)
        {
            if (frame[j] == s[i])
            {
                avail = 1;
                break;
            }
        }
        if (avail == 0) {
            if (full < n) {
                frame[pos] = s[i];
                pos++;
                full++;
            }
            else {
                pos = LRU(s, frame, l, n, i + 1);
                frame[pos] = s[i];
            }
            count++;
        }
        for (j = 0; j < n; j++)
        {
            if (frame[j] != -1)
                cout << frame[j] << "\t";
        }
        cout << endl;
    }

    cout << "Page Fault is = " << count << "\n";

    return 0;

}

