#include <algorithm>
#include <iostream>
#include <values.h>
#include <cstdlib>
#include <string>
#include <cstdio>
#include <vector>
#include <stack>
#include <queue>
#include <set>

using namespace std;

int N, L;
int V[1001];
int C[1001];

queue<int> lig;

int main()
{
    scanf("%d %d", &N, &L);

    for (int i = 1; i <= N; ++i)
        C[i] = 0;

    int l;
    for (int i = 0; i < L; ++i)
    {
        scanf("%d", &l);
        lig.push(l);
    }

    int m = MAXINT;
    for (int i = 1; i <= N; ++i)
    {
        if(lig.empty())
            break;

        V[i] = lig.front();
        lig.pop();
        m = min(m, V[i]);
        ++C[i];
    }

    while(!lig.empty())
    {
        int t = m;
        m = MAXINT;

        for (int i = 1; i <= N; ++i)
        {
            if(lig.empty())
                break;

            V[i] -= t;

            if(V[i] == 0)
            {
                V[i] = lig.front();
                lig.pop();
                ++C[i];
            }

            m = min(m, V[i]);
        }
    }

    for (int i = 1; i <= N; ++i)
        printf("%d %d\n", i, C[i]);

    return 0;
}

