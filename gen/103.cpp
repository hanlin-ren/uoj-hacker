#include <cstdio>
#include <cstdlib>

int T = 5;
void gen(int l){while (l--) putchar(rand() % 3 + 'x'); putchar('\n');}
int main(){
  int s;
  freopen("s", "r", stdin); scanf("%d", &s); srand(s);
  freopen("in", "w", stdout);
  gen(rand() % 20 + 1);
  freopen("s", "w", stdout); printf("%d\n", rand());
  return 0;
}
