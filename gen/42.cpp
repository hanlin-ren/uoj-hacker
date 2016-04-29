#include <cstdio>
#include <cstdlib>
int T = 10000, n = 1000000, r = 100, s;
int main(){
  freopen("s", "r", stdin); scanf("%d", &s); srand(s);
  printf("%d\n", T);
  while (T--) printf("%d %d\n", rand() % n + 1, rand() % r + 1);
  freopen("s", "w", stdout); printf("%d", rand());
  return 0;
}
