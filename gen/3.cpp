#include <cstdio>
#include <cstdlib>
#define R(x) rand() % (x) + 1

int s = 0;
int n = 2000, m = 40000;
int main(){
  freopen("s", "r", stdin); scanf("%d", &s); srand(s);
  printf("%d %d\n", n = rand() % n + 2, m = rand() % m + 1);
  while (m--) printf("%d %d %d %d\n", R(n), R(n), R(50000), R(50000));
  freopen("s", "w", stdout); printf("%d", rand());
  return 0;
}
