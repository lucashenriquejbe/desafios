#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <queue>
 
using namespace std;
 
typedef struct  _estado
{
    int x, y;
    int turno;
    _estado();
    _estado(int i, int j, int t) : x(i), y(j), turno(t) {}
} Estado;
 
int lab[55][55];
bool est[55][55][10];
 
int dx[] = {0,  1, -1,  0,  0};
int dy[] = {0,  0,  0,  1, -1};
 
int n, m;
 
int percorer()
{
    Estado inicial(1,1,0);
    queue<Estado> fila;
    fila.push(inicial);
    int sx, sy;
    while(!fila.empty())
    {
        Estado e = fila.front();
        fila.pop();
 
        for (int i = 0; i < 5; ++i)
        {
            sx = e.x + dx[i];
            sy = e.y + dy[i];
 
            if( est[sx][sy][(e.turno+1)%10] )
                continue;
            if( sx>=1 && sy>=1 && sx<=n && sy<=m && ((lab[sx][sy]+e.turno)%10 <= (lab[e.x][e.y]+e.turno)%10 + 1) ) {
                est[sx][sy][(e.turno+1)%10] = true;
 
                if(sx == n && sy == m)
                    return e.turno+1;
 
                Estado ne(sx, sy, e.turno+1);
                fila.push(ne);
            }
        }
 
    }
}
 
int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            scanf("%d", &lab[i][j]);
    printf("%d\n", percorer());
    return 0;
}