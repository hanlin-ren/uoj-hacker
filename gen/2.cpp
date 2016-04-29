#include <cstdio>
#include <cstdlib>

int s = 0, n = 1000, m = 1000000000;
int main(){
  freopen("s", "r", stdin); scanf("%d", &s); srand(s);
  freopen("in", "w", stdout);
  printf("%d %d\n", n = rand() % n + 1, rand() % m);
  while (n--){
    if (rand() % 3 == 0) printf("AND");
    else if (rand() % 2 == 0) printf("OR"); else printf("XOR");
    printf(" %d\n", rand() % m);
  }
  freopen("s", "w", stdout); printf("%d", rand());
  return 0;
}
