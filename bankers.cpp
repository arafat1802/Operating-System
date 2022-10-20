#include <bits/stdc++.h>
using namespace std;
int alloc[5][5], mx[5][5], need[10][10], avail[5];
int allocion[5] = {0, 0, 0, 0, 0};
int inst[5], running[5];
int counter = 0, j, m, n, k;
int main()
{
    cout << "\nEnter number of Process: ";

    cin >> n;
    for (int i = 0; i < n; i++) {
        running[i] = 1;
        counter++;
    }
    cout << "\nEnter number of Resouces: ";
    cin >> m;
    cout << "\nEnter instance: ";
    for (int i = 0; i < m; i++) {
        cin >> inst[i];
    }
    cout << "\nEnter alloced Table:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> alloc[i][j];
        }
    }
    cout << "\nEnter mx Table:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> mx[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            allocion[j] += alloc[i][j];
        }
    }
    for (int i = 0; i < m; i++) {
        avail[i] = inst[i] - allocion[i];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            need[i][j] = mx[i][j] - alloc[i][j];
        }
    }
    cout << "\nThe Need Table:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << " " << need[i][j];
        }
        cout << endl;
    }
    cout << endl;
    int f[n], ans[n], ind = 0;
    memset(f, false, sizeof f);

    int need[n][m];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            need[i][j] = mx[i][j] - alloc[i][j];
    }
    int y = 0;
    for (int k = 0; k < 5; k++) {
        for (int i = 0; i < n; i++) {
            if (f[i] == 0) {
                int flag = 0;
                for (j = 0; j < m; j++) {
                    if (need[i][j] > avail[j]) {
                        flag = 1;
                        break;
                    }
                }
                if (flag == 0) {
                    ans[ind++] = i;
                    for (int y = 0; y < m; y++)
                        avail[y] += alloc[i][y];
                    f[i] = 1;
                }
            }

        }
    }
    int flag = 1;
    for (int i = 0; i < n; i++) {
        if (f[i] == 0) {
            flag = 0;
            cout << "The following system is not safe\n";
            break;
        }
    }
    if (flag == 1) {
        cout << "\nThe Safe Sequence: ";
        for (int i = 0; i < n - 1; i++)
            cout << " P" << ans[i] << " ->";
        cout << " P" << ans[n - 1];
    }
    cout << endl << endl;;
    return 0;
}