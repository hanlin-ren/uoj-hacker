#include <cstdio>
#include <cstdlib>

int s = 0;
int r(){
  int p;
  do {p = rand();} while (p > 1000000000 || p == 0); return p % 20 + 1;
}
void gen(int n){
  printf("%d\n", n);
  while (n--) printf("%d %d %d\n", r(), r(), rand() & 1);
}

int T;
int main(){
  freopen("s", "r", stdin); scanf("%d", &s); srand(s);
  printf("%d\n", T = 10);
  while (T--) gen(rand() % 20 + 1);
  freopen("s", "w", stdout); printf("%d", rand());
  return 0;
}
