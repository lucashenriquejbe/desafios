#include <cstdio>
int p[102][102];int main(){int n,k,i,j,u;scanf("%d",&n);for(u=0;u<n;++u){for(i=0;i<102;++i)for(j=0;j<102;++j)p[i][j]=0;scanf("%d",&k);for(i=1;i<=k;++i)for(j=1;j<=i;++j)scanf("%d",&p[i][j]);for(i=k-1;i>0;--i)for(j=0;j<=k;++j)p[i][j]+=(p[i+1][j]>p[i+1][j+1]?p[i+1][j]:p[i+1][j+1]);printf("%d\n",p[1][1]);}return 0;}