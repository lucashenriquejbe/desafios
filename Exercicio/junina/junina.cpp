#include <iostream>
#include <values.h>
#include <cstdlib>
#include <cstdio>
#include <vector>

short n, i, j, k, lim;
short set[21];
bool E[21][21];

using namespace std;


void junina(short u, short nset)
{	
	if( u > n )
	{
		if( lim < nset )
			lim = nset;
		return;
	}
	if( (nset+n-u+1) <= lim )
		return;

	bool is = true;
	for(i = 0; i < nset; ++i)
		if( E[u][set[i]] )
		{
			is = false;
			break;
		}

	if(is)
	{
		set[nset] = u;
		junina( u+1, nset+1 );
	}
	junina( u+1, nset );

}

int main() {
	n = 1;
	short a = 1;

	for(int u=1; ; ++u)
	{
		lim = 0;

		scanf("%hd", &n);

		if(n == 0)
			break;

		for (i = 0; i <= n; ++i)
			for(j = 0; j <= n; ++j)
				E[i][j] = false;

		for (i = 1; i <= n; ++i)
		{
			for (j = 0; a!=0; ++j)
			{
				scanf("%hd", &a);

				if( a!=0 )
				{
					E[i][a] = true;
					E[a][i] = true;
				}
			}
			a = 1;
		}

		junina( 1, 0 );

		cout << "Teste " << u << endl;
		cout << lim << endl << endl;

	}

	return 0;
}