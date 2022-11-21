#include <bits/stdc++.h>
#include <iostream>
typedef long long ll;
using namespace std;
// ASCII of 'a'-97,'z'-123,'A'-65,'Z'-90,'0'-48,'9'-57
bool sortby(const pair<ll, ll> &a, const pair<ll, ll> &b)
{
    return a.second < b.second;
}
void LamportLogicalClock(int e1, int e2, int m[5][3])
{
    int p1[e1];
    int p2[e2];
    for (int i = 0; i < e1; i++)
    {
        p1[i] = i + 1;
    }
    for (int i = 0; i < e2; i++)
    {
        p2[i] = i + 1;
    }
    for (int i = 0; i < e1; i++)
    {
        for (int j = 0; j < e2; j++)
        {
            if (m[i][j] == 1)
            {
                p2[j] = max(p2[j], p1[i] + 1);
                for (int k = j + 1; k < e2; k++)
                {
                    p2[k] = p2[k - 1] + 1;
                }
            }
            if (m[i][j] == -1)
            {
                p1[i] = max(p1[i], p2[j] + 1);
                for (int k = i + 1; k < e1; k++)
                {
                    p1[k] = p2[k - 1] + 1;
                }
            }
        }
    }
    cout << "Time Stamp for Proecess P1 : " << endl;
    for (int i = 0; i < e1; i++)
    {
        cout << p1[i] << " ";
    }
    cout << "\n\nTime Stamp for Proecess P1 : " << endl;
    for (int i = 0; i < e2; i++)
    {
        cout << p2[i] << " ";
    }
}
int main()
{
    int e1 = 5, e2 = 3, m[5][3];
    m[0][0] = 0;
	m[0][1] = 0;
	m[0][2] = 0;
	m[1][0] = 0;
	m[1][1] = 0;
	m[1][2] = 1;
	m[2][0] = 0;
	m[2][1] = 0;
	m[2][2] = 0;
	m[3][0] = 0;
	m[3][1] = 0;
	m[3][2] = 0;
	m[4][0] = 0;
	m[4][1] = -1;
	m[4][2] = 0;

	// Function Call
	LamportLogicalClock(e1, e2, m);
    return 0;
}