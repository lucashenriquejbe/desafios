#include <set>
#include <map>
#include <cstdio>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <values.h>
#include <iostream>
#include <algorithm>

using namespace std;

typedef struct tupla
{
	int x;
	int y;
	int d;
	tupla(int _x, int _y, int _d) : x(_x), y(_y), d(_d) {}
} tripla;

tripla euclides_estendido(int a, int b)
{
	if(b == 0) return tupla(1, 0, a);
	tupla t = euclides_estendido(b, a%b);
	return tupla(t.y, t.x - (a/b)*t.y, t.d);
}

int main()
{
	int a, b;
	while(scanf("%d %d", &a, &b) && a && b)
	{
		tupla t = euclides_estendido(a, b);
		if(t.y < 0)
			printf("%d*%d - %d*%d = %d\n", t.x, a, -1*t.y, b, t.d);
		else
			printf("%d*%d + %d*%d = %d\n", t.x, a, t.y, b, t.d);
	}
	return 0;
}