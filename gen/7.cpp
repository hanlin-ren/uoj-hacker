#include <cstdio>
#include <cstdlib>
#define R (((long long)rand()) << 31 + (long long) rand())
int i, s, n = 200000;
void put(int x){
  long long L, S;
  L = rand() % 200000000000ll + 1; S = rand() % 2000000ll + 1;
  if (L < S) L ^= S, S ^= L, L ^= S;
  printf("%d ", x <= 5 ? 1 : x - 5);
  printf("%lld ", S);
  printf("%d ", rand() % 1000001);
  long long Q = R % 1000000000001ll; if (Q < 0) Q = -Q;
  printf("%lld ", Q);
  printf("%lld\n", L);
}
int main(){
  freopen("seed", "r", stdin); scanf("%d", &s); srand(s);
  printf("%d 0\n", n = rand() % 10 + 1);
  for (i = 2; i <= n; i++) put(i);
  freopen("seed", "w", stdout); printf("%d", rand());
  return 0;
}
