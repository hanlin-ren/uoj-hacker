#include <cstdio>
#include <cstdlib>
int R(int x){return rand() % x;}

int main(){
  int s, x0, a, b, c, d, n, m, q, x, y;
  freopen("s", "r", stdin); scanf("%d", &s); srand(s);
  d = rand() % 100000000 + 2;
  printf("%d %d %d %d %d\n", R(d), R(301), R(d), R(d), d);
  printf("%d %d %d\n", n = rand() % 100 + 2, m = rand() % 100 + 2, q = rand() % 1000 + 1);
  while (q--) printf("%d %d\n", rand() % (n * m) + 1, rand() % (n * m) + 1);
  freopen("s", "w", stdout); printf("%d", rand());
  return 0;
}
