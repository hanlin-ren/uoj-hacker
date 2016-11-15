#include "testlib.h"
#include <stdio.h>
#include <math.h>
#include <map>
using namespace std;
typedef long long ll;
map<ll,bool> s;
int main(int argc, char * argv[])
{
    setName("UOJ 216 checker");
    registerTestlibCmd(argc, argv);
    ll A=inf.readLong(),B=inf.readLong(),C=inf.readLong();
    int qwq=ouf.readInt(),qaq=ans.readInt();
    if(qaq!=-1&&qwq==-1) quitf(_wa,"has solution, but output -1");
    if(qaq==-1&&qwq!=-1) quitf(_wa,"no solution, but output solution");
    if(qaq==-1&&qwq==-1) quitf(_ok,"ok -1");
    if(qwq<0) quitf(_wa,"step < 0");
    if(qwq>400) quitf(_wa,"step > 400");
    s[A]=1; s[B]=1;
    for(int i=1;i<=qwq;i++)
    {
    	ll q1=ouf.readLong(),q2=ouf.readLong();
    	if(q1<=q2) quitf(_wa,"step %d a<=b",i);
    	if(q1<0||q2<0) quitf(_wa,"step %d a<0 or b<0",i);
    	if(!s[q1]||!s[q2]) quitf(_wa,"step %d a or b not in set",i);
    	s[q1-q2]=1;
	}
	if(!s[C]) quitf(_wa,"C not in set");
	quitf(_ok,"%d steps",qwq);
}
