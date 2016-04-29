#include <cstdio>
#include <cstdlib>

int T = 5;
void gen(int l){while (l--) putchar(rand() % 3 + 'x'); putchar('\n');}
int main(){
  int s, t, x, y, m, n;
  freopen("s", "r", stdin); scanf("%d", &s); srand(s);
  freopen("in", "w", stdout);
  printf("%d %d\n", n = rand() % 30 + 2, m = rand() % 100 + 1);
  do {s = rand() % n + 1; t = rand() % n + 1;} while (s == t);
  while (m--){
    do {x = rand() % n + 1; y = rand() % n + 1;}
    while (x == t);
    printf("%d %d\n", x, y);
  }
  printf("%d %d\n", s, t);
  freopen("s", "w", stdout); printf("%d\n", rand());
  return 0;
}
