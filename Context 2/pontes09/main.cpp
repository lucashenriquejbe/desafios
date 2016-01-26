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

int g[1002][1002];
int d[1002];
int N, M;

vector<int> G[1002];

int dijkstra()
{
    queue<int> Q;
    Q.push(0);

    d[0] = 0;
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
            }
        }
    }

    return d[N+1];
}

void limpar(int n)
{
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
            g[i][j] = 0;
        d[i] = MAXINT;
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

    printf("%d\n", dijkstra());
    return 0;
}

