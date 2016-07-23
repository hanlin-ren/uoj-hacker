#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
int T;
typedef long long ll;
using namespace std;
int n,hp[2333333];
bool gg[2333333];
int main(){
	int s;
	freopen("s", "r", stdin); scanf("%d", &s); srand(s);
	int n=1000000; if(rand()%5==0) n=1;
	cout<<n<<"\n";
	for(int i=1;i<=n;i++) hp[i]=rand()%1000000000; //for linux
	sort(hp+1,hp+1+n);
	if(rand()&1)
	{
		for(int j=2;j<=n;j+=2) printf("%d ",hp[j]), gg[j]=1;
		for(int j=n;j>=1;j--)
		{
			if(!gg[j]) printf("%d ",hp[j]);
		}
	}
	else if(rand()&1)
	{
		for(int j=1;j<=n;j+=2) printf("%d ",hp[j]), gg[j]=1;
		for(int j=n;j>=1;j--)
		{
			if(!gg[j]) printf("%d ",hp[j]);
		}
	}
	else
	{
		for(int j=1;j<=n;j++) printf("%d ",hp[j]);
	}
	freopen("s", "w", stdout); printf("%d", rand());
	return 0;
}
