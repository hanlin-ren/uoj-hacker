#include <cstdio>
#include <cstdlib>

int T = 5;
void gen(int l){while (l--) putchar(rand() % 3 + 'x'); putchar('\n');}
int main(){
  int s;
  freopen("s", "r", stdin); scanf("%d", &s); srand(s);
  freopen("in", "w", stdout); printf("%d\n", T);
  while (T--) gen(rand() % 10 + 1);
  freopen("s", "w", stdout); printf("%d\n", rand());
  return 0;
}
