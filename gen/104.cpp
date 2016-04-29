#include <cstdio>
#include <cstdlib>

int s = 0, n, k;
int main(){
  freopen("s", "r", stdin); scanf("%d", &s); srand(s);
  do {n = rand() % 1000 + 2; k = rand() % 50 + 1;} while (k > n - 1);
  printf("%d %d\n", n, k);
  while (n--) printf("%d ", rand() % 10001);
  freopen("s", "w", stdout); printf("%d", rand());
  return 0;
}
