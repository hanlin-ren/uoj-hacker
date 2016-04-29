#include <cstdio>
#include <cstdlib>
int s;
int f[233][233];
int main(){
  int n, m, i, j;
  freopen("s", "r", stdin); scanf("%d", &s); srand(s);
  n = rand() % 7 + 2; m = rand() % (n * (n - 1) + 1);
  printf("%d %d\n", n, m);
  while (m--){
    do {i = rand() % n + 1; j = rand() % n + 1;}
    while (f[i][j] || i == j);
    printf("%d %d\n", i, j); f[i][j] = 1;
  }
  freopen("s", "w", stdout); printf("%d", rand());
  return 0;
}
