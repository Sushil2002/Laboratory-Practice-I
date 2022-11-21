#include <bits/stdc++.h>
#include <iostream>
typedef long long ll;
using namespace std;
// ASCII of 'a'-97,'z'-123,'A'-65,'Z'-90,'0'-48,'9'-57
bool sortby(const pair<ll, ll> &a, const pair<ll, ll> &b)
{
    return a.second < b.second;
}
void First(int Blocksize[], int m, int ProcessSize[], int n)
{
    int allocation[n];
    for (int i = 0; i < n; i++)
    {
        allocation[i] = -1;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (Blocksize[j] >= ProcessSize[i])
            {
                allocation[i] = j;
                Blocksize[j] -= ProcessSize[i];
                break;
            }
        }
    }
    cout << "\nProcess No.\tProcess Size\tBlock no.\n";
    for (int i = 0; i < n; i++)
    {
        cout << " " << i + 1 << "\t\t"
             << ProcessSize[i] << "\t\t";
        if (allocation[i] != -1)
            cout << allocation[i] + 1;
        else
            cout << "Not Allocated";
        cout << endl;
    }
}
void Next(int Blocksize[], int m, int ProcessSize[], int n)
{
    int allocation[n];
    for (int i = 0; i < n; i++)
    {
        allocation[i] = -1;
    }
    int j = 0;
    for (int i = 0; i < n; i++)
    {
        while (j < m)
        {
            if (Blocksize[j] >= ProcessSize[i])
            {
                allocation[i] = j;
                Blocksize[j] -= ProcessSize[i];
                break;
            }
            j = (j + 1) % m;
        }
    }
    cout << "\nProcess No.\tProcess Size\tBlock no.\n";
    for (int i = 0; i < n; i++)
    {
        cout << " " << i + 1 << "\t\t"
             << ProcessSize[i] << "\t\t";
        if (allocation[i] != -1)
            cout << allocation[i] + 1;
        else
            cout << "Not Allocated";
        cout << endl;
    }
}
void Best(int Blocksize[], int m, int ProcessSize[], int n)
{
    int allocation[n];
    for (int i = 0; i < n; i++)
    {
        allocation[i] = -1;
    }
    for (int i = 0; i < n; i++)
    {
        int k = -1;
        for (int j = 0; j < m; j++)
        {
            if (Blocksize[j] > ProcessSize[i])
            {
                if (k == -1)
                {
                    k = j;
                }
                else if (Blocksize[k] > Blocksize[j])
                {
                    k = j;
                }
            }
        }
        if (k != -1)
        {
            allocation[i] = k;
            Blocksize[k] -= ProcessSize[i];
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << "   " << i+1 << "\t\t" << ProcessSize[i] << "\t\t";
        if (allocation[i] != -1)
            cout << allocation[i] + 1;
        else
            cout << "Not Allocated";
        cout << endl;
    }
}
int main()
{

    int blockSize[] = {100, 500, 200, 300, 600};
    int processSize[] = {212, 417, 112, 426};
    int m = sizeof(blockSize)/sizeof(blockSize[0]);
    int n = sizeof(processSize)/sizeof(processSize[0]);

    Best(blockSize, m, processSize, n);
    return 0;
}