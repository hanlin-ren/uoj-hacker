#include <cstdio>
#include <cstdlib>
int s, n, m;

int main(){
  freopen("s", "r", stdin); scanf("%d", &s); srand(s);
  printf("%d %d\n", n = rand() % 20 + 3, m = rand() % 100 + 12);
  for (int i = 1; i <= n; i++){
    for (int j = 1; j <= m; j++) printf("%d ", rand() % 401 - 200);
    printf("\n");
  }
  freopen("s", "w", stdout); printf("%d", rand());
}
