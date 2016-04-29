#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;
int f(int x){return rand() % (x - 1) + 1;}

int s = 0, n;
int p[233333], q[233333];
int main(){
  freopen("s", "r", stdin); scanf("%d", &s); srand(s);
  freopen("in", "w", stdout);
  printf("%d\n", n = rand() % 1000 + 1);
  for (int i = 1; i <= n; i++) p[i] = q[i] = i;
  random_shuffle(p + 1, p + n + 1);
  random_shuffle(q + 2, q + n + 1);
  for (int i = 2; i <= n; i++){
    if (rand() & 1) printf("%d %d ", p[q[i]], p[f(q[i])]);
    else printf("%d %d ", p[f(q[i])], p[q[i]]);
    printf("%d\n", rand() % 10000 + 1);
  }
  freopen("s", "w", stdout); printf("%d", rand());
  return 0;
}
