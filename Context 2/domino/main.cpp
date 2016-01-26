#include <algorithm>
#include <iostream>
#include <values.h>
#include <cstdlib>
#include <bitset>
#include <string>
#include <cstdio>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>

using namespace std;

int pecas[28][2] = {
    {0,0}, {0,1}, {0,2}, {0,3},
    {0,4}, {0,5}, {0,6}, {1,1},
    {1,2}, {1,3}, {1,4}, {1,5},
    {1,6}, {2,2}, {2,3}, {2,4},
    {2,5}, {2,6}, {3,3}, {3,4},
    {3,5}, {3,6}, {4,4}, {4,5},
    {4,6}, {5,5}, {5,6}, {6,6}
};

int N;
int m[7][8];
int x[] = {0, 1};
int y[] = {1, 0};

bool tab[7][8];
bool visit[28];

int montar(int p, int q, int u)
{
    if ( u >= 28 )
        return 1;
    if ( p >= 7 )
        return 0;
    if ( q >= 8 )
        return montar(p+1, 0, u);
    if ( tab[p][q] )
        return montar(p, q+1, u);

    int c = 0;
    for (int i = 0; i < 28; ++i)
    {
        if ( visit[i] )
            continue;
        visit[i] = true;
        for (int k = 0; k < 2; ++k)
        {
            if ( p+x[k] < 7 && q+y[k] < 8 && !tab[p+x[k]][q+y[k]] )
                if ( (m[p][q] == pecas[i][0] && m[p+x[k]][q+y[k]] == pecas[i][1]) || (m[p][q] == pecas[i][1] && m[p+x[k]][q+y[k]] == pecas[i][0]) )
                {
                    tab[p][q] = true;
                    tab[p+x[k]][q+y[k]] = true;

                    c += montar(p, q+1, u+1);

                    tab[p][q] = false;
                    tab[p+x[k]][q+y[k]] = false;
                }

        }
        visit[i] = false;
    }

    return c;
}

int main()
{
    scanf("%d", &N);

    for (int i = 0; i < N; ++i)
    {
        for (int k = 0; k < 28; ++k)
            visit[k] = false;

        for (int k = 0; k < 7; ++k)
            for (int j = 0; j < 8; ++j)
            {
                scanf("%d", &m[k][j]);
                tab[k][j] = false;
            }

        printf("Teste %d\n%d\n", i+1, montar(0,0,0));
    }

    return 0;
}

