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

int g[10050][10050];
int d[10050];
int prev[10050];
int N, M;

vector<int> G[10050];

int dijkstra(int s, int t)
{
    queue<int> Q;
    Q.push(s);

    d[s] = g[s][s];
    while(!Q.empty())
    {
        int u = Q.front();
        Q.pop();

        int v;
        for (int i = 0; i < G[u].size(); ++i)
        {
            v = G[u][i];
            if(d[v] > g[u][v] + d[u])
            {
                d[v] = g[u][v] + d[u];
                Q.push(v);
                prev[v] = u;
            }
        }
    }

    int sum = 0;
    for (int i = 0; i <= t; ++i)
        if( prev[i]>=0 )
            sum += g[prev[i]][i];

    return sum;
}

void limpar(int n)
{
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
            g[i][j] = 0;
        d[i] = MAXINT;
        prev[i] = -1;
    }
}

int main()
{
    scanf("%d %d", &N, &M);

    limpar(N+2);

    int s, t, b;
    for (int i = 0; i < M; ++i)
    {
        scanf("%d %d %d", &s, &t, &b);
        g[s][t] = b;
        g[t][s] = b;
        G[s].push_back(t);
        G[t].push_back(s);
    }

    printf("%d\n", dijkstra(0, N-1));

    return 0;
}
