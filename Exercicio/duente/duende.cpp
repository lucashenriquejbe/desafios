#include <iostream>
#include <values.h>
#include <cstdlib>
#include <cstdio>

#define MAX MAXINT/2;

short v[12][12];
bool visit[12][12];

const short a[4] = {0,  0,  1, -1};
const short b[4] = {1, -1,  0,  0};
const short w = 64;

using namespace std;

int min_caminho(short x, short y)
{
	if( v[y][x]==0 )
		return 0;

	visit[y][x] = true;

	int min = MAX;

	for (int i = 0; i < 4; ++i)
	{
		if( !visit[y+b[i]][x+a[i]] && v[y+b[i]][x+a[i]] != 2 ) {
			int aux = 1 + min_caminho(x+a[i], y+b[i]);				

			if( min>aux )
				min = aux;
		}
	
	}

	visit[y][x] = false;

	return min;
}


int main() 
{

	short n, m;
	short ix, iy;
	register short i, j;

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

	cout << min_caminho(ix, iy) << endl;

	return 0;
}