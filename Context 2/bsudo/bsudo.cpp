#include <iostream>
#include <values.h>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <vector>
#include <bitset>
 
using namespace std;
 
char res[91];
bool resolveu;
 
void clearM(bitset<9> values[9][9])
{
	register int i, j;
 
	for (i = 0; i < 9; ++i)
		for (j = 0; j < 9; ++j){
			values[i][j] = values[i][j].set();
		}
}
 
int eval(bitset<9> b)
{
	register int i = 0;
	while(!b[i]) ++i;
	return i+1;
}
 
void converte(bitset<9> b[9][9], char v[])
{
	int i, j;
	for (i = 0; i < 9; ++i){
		for (j = 0; j < 9; ++j){
			v[i*10+j] = '0'+eval(b[i][j]);
		}
		v[i*10+9] = '\n';
	}
	v[90] = '\0';
}
 
void erase(bitset<9> &b, int v)
{
	b[v-1] = 0;
}
 
bool eliminate(bitset<9> values[9][9], int i, int j, int v)
{
	if(!values[i][j][v-1])
		return true;
	for (register int p = 0, a, b; p < 9; ++p)
	{
		a = (i/3)*3 + p/3;
		b = (j/3)*3 + p%3;
		if(values[i][p][v-1] && p!=j){
			erase(values[i][p], v);
			if(values[i][p].none())
				return false;
			if(values[i][p].count() == 1)
				if(!eliminate(values, i, p, eval(values[i][p])))
					return false;
		}
		if(values[p][j][v-1] && p!=i){
			erase(values[p][j], v);
			if(values[p][j].none())
				return false;
			if(values[p][j].count() == 1)
				if(!eliminate(values, p, j, eval(values[p][j])))
					return false;
		}
		if(values[a][b][v-1] && !(a==i && b==j) ){
			erase(values[a][b], v);
			if(values[a][b].none())
				return false;
			if(values[a][b].count() == 1)
				if(!eliminate(values, a, b, eval(values[a][b])))
					return false;
		}
	}
 
	return true;
}
 
bool assign(bitset<9> values[9][9], int i, int j, int a)
{
	values[i][j] = values[i][j].reset();
	values[i][j] = values[i][j].set(a-1);
	return eliminate(values, i, j, a);
}
 
void copy(bitset<9> b1[9][9], bitset<9> b2[9][9])
{
	int i, j;
	for (i = 0; i < 9; ++i)
		for (j = 0; j < 9; ++j)
			b2[i][j] = b1[i][j];
}
 
void solve(bitset<9> values[9][9])
{
 
	if(resolveu)
		return;
 
	register int i, j, p, q, len, min = MAXINT;
	resolveu = true;
 
	for (i = 0; i < 9; ++i)
		for (j = 0; j < 9; ++j)
		{
			len = values[i][j].count();
			if( len > 1 && min > len){
				min = len;
				p = i;
				q = j;
				resolveu = false;
			}
		}
 
	if (resolveu)
	{
		converte(values, res);
		return;
	}
 
	for(i = 0; i < 9; ++i)
	{
		if(resolveu)
			return;
		while(i < 9 && !values[p][q][i])
			++i;
		if(i < 9 && values[p][q][i])
		{
			bitset<9> cop[9][9];
			copy(values, cop);
			if(assign(cop, p, q, i+1))
				solve(cop);
		}
	}
		
}
 
int main()
{
	register int n, i, j, k, a;
	bitset<9> values[9][9];
 
	scanf("%d", &n);
 
	for (k = 0; k < n; ++k)
	{
		clearM(values);
		resolveu = false;
 
		for ( i = 0; i < 9; ++i)
		{
			for (j = 0; j < 9; ++j)
			{
				scanf("%1d", &a);
				if(a != 0)
					assign(values, i, j, a);
			}
		}
 
		solve(values);
 
		printf("%s", res);
 
	}
 
 
	return 0;
} 