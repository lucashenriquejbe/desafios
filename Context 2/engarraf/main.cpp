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

int g[10002][10002];
int d[10002];
int N, M;

vector<int> G[10002];

int dijkstra(int s, int t)
{
    queue<int> Q;
    Q.push(s);

    d[s] = 0;
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

    return d[t] == MAXINT ? -1 : d[t];
}

void limpar(int n)
{
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
            g[i][j] = 0;
        d[i] = MAXINT;
        G[i].clear();
    }
}

int main()
{
    while(scanf("%d %d", &N, &M) && !(N == 0 && M == 0))
    {

        limpar(N+1);

        int s, t, b;
        for (int i = 0; i < M; ++i)
        {
            scanf("%d %d %d", &s, &t, &b);
            g[s][t] = b;
            G[s].push_back(t);
        }

        scanf("%d %d", &s, &t);
        printf("%d\n", dijkstra(s, t));
    }
    return 0;
}
