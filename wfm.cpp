#include<bits/stdc++.h>
using namespace std;
int main()
{
    int blockNo, processNo, blockSize[10], processSize[10], flags[10], alloc[10], temp, highest = -
            9999, id = 9, i, j;
    cout << "Enter the number of blocks: ";
    cin >> blockNo;
    cout << "Enter size of each block: ";
    for (i = 0; i < blockNo; i++)
        cin >> blockSize[i];
    printf("Enter the number of processes: ");
    cin >> processNo;
    cout << "Enter size of each process: ";
    for (i = 0; i < processNo; i++)
        cin >> processSize[i];
    for (i = 0; i < blockNo; i++) {
        flags[i] = 0;
        alloc[i] = -1;
    }
    for (i = 0; i < processNo; i++) {
        for (j = 0; j < blockNo; j++) {
            if (flags[j] == 0) {
                temp = blockSize[j] - processSize[i];
                if (temp >= 0 && temp > highest) {
                    highest = temp;
                    id = j;
                }
            }
        }
        alloc[id] = i;
        flags[id] = 1;
        highest = -9999;
        id = 9;
    }
    cout << "Block no.\tBlock Size\tProcess no.\tProcess Size\tUnused Space";
    for (i = 0; i < blockNo; i++) {
        cout << "\n" << i + 1 << "\t\t" << blockSize[i] << "\t\t";
        if (flags[i] == 1)
            cout << alloc[i] + 1 << " \t\t" << processSize[alloc[i]] << "\t\t" << blockSize[i] -
                 processSize[alloc[i]];
        else
            cout << "NULL\t\tNULL\t\t" << blockSize[i];
    }
    cout << endl;
    return 0;
}