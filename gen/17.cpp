#include <cstdio>
#include <cstdlib>
#include <set>
using namespace std;

set <int> a;

int main(){
  int s = 0, i;
  freopen("s", "r", stdin); scanf("%d", &s); srand(s);
  freopen("in", "w", stdout);
  int n = rand() % 100 + 5, m = rand() % 100 + 5, k = rand() % n;
  printf("%d %d %d\n", n, m, k);
  for (i = 1; i <= n; i++) 
    printf("%d %d\n", rand() % (m - 1) + 1, rand() % (m - 1) + 1);
  for (i = 1; i <= k; i++){
    int p, l, h;
    do{l = rand() % (m + 1); h = rand() % (m + 1);} while (l + 1 >= h);
    do p = rand() % (n - 1) + 1; while (a.find(p) != a.end());
    printf("%d %d %d\n", p, l, h);
    a.insert(p);
  }
  freopen("s", "w", stdout); printf("%d", rand());
  return 0;
}
