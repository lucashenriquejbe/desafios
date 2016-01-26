#include <iostream>
#include <values.h>
#include <cstdlib>
#include <cstdio>
#include <queue>

#define MAX MAXINT/2;

short v[12][12];
bool visit[12][12];
short dist[12][12];
short mi = MAXSHORT;

short i, j;

const short a[4] = {0,  0,  1, -1};
const short b[4] = {1, -1,  0,  0};

using namespace std;

void bfs(short x, short y)
{
	for (i = 0; i < 12; ++i)
		for (j = 0; j < 12; ++j)
			dist[i][j] = MAXSHORT;

	queue<short> Q;
	Q.push(x);
	Q.push(y);

	dist[y][x] = 0;

	short r, s, ia, ib;
	while(!Q.empty()) 
	{
		r = Q.front();
		Q.pop();
		s = Q.front();
		Q.pop();

		for (i = 0; i < 4; ++i)
		{
			ia = r+a[i];
			ib = s+b[i];
			if( !visit[ib][ia] && v[ib][ia] != 2 ) 
			{
				Q.push(ia);
				Q.push(ib);
				dist[ib][ia] = dist[s][r] + 1;
				visit[ib][ia] = true;
			}
		}
	}

}


int main() 
{

	short n, m;
	short ix, iy;

	scanf("%hd %hd", &n, &m);

	n+=2;
	m+=2;

	for (i = 0; i < n; ++i)
	{
		for (j = 0; j < m; ++j)
		{
			if ( i==0 || i==n-1 || j==0 || j==m-1 )
				v[i][j] = 2;
			else
				scanf("%hd", &v[i][j]);

			if(v[i][j] == 3)
			{
				ix = j;
				iy = i;
			}
		}
	}

	bfs(ix, iy);

	for (i = 1; i < n-1; ++i)
		for (j = 0; j < m-1; ++j)
			if( v[i][j]==0 && dist[i][j]<mi )
				mi = dist[i][j];

	cout << mi << endl;

	return 0;
}