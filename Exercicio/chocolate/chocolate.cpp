#include <iostream>
#include <values.h>
#include <cstdlib>
#include <cstdio>

int n, m;

using namespace std;

void vencedor()
{
	int a = m+1;
	if( n%a == 0 )
		cout << "Carlos" << endl;
	else
		cout << "Paula" << endl;
}

int main() {

	scanf("%d %d", &n, &m);

	vencedor();

	return 0;
}