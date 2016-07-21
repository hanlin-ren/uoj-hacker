#include <cstdio>
#include <cstdlib>
#include <iostream>
int T;
typedef long long ll;
ll rndll()
{
	ll ans=0;
	for(int i=1;i<=10;i++) ans=ans*32768+rand();
	if(ans<0) ans=-ans;
	ans%=1000000000000000000LL;
	++ans;
	return ans;
}
ll gcd(ll a,ll b)
{
	while(b)
	{
		ll t=a%b; a=b; b=t;
	}
	return a;
}
ll rp(ll x)
{
	if(rand()%10<3) return rndll();
	ll t=x*(rndll()%(10000000000000000LL/x*2));
	if(t>1000000000000000000LL||t<1) return rndll();
	return t;
}
ll fib[2333];
int main(){
	fib[0]=fib[1]=1;
	for(int i=2;i<=233;i++) fib[i]=fib[i-1]+fib[i-2];
	int s;
	freopen("s", "r", stdin); scanf("%d", &s); srand(s);
	//ll A=rndll(),B=rndll();
	//ll A=864691128455135230,B=3;
	//ll A=rndll(),B=rand()%2+2;
	ll A=fib[rand()%4+83]+rand(),B=rand()%2+2;
	if(rand()%4==0) B=1;
	ll g=gcd(A,B);
	std::cout<<A<<" "<<B<<" "<<rp(g)<<"\n"; 
	freopen("s", "w", stdout); printf("%d", rand());
	return 0;
}
