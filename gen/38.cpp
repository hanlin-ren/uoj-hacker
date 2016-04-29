#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;

int prime[70] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 193, 197, 199, 211, 223, 227, 229, 233, 239, 241, 251, 257, 263, 269, 271, 277, 281};
int p2[120];

pair <int, int> C[102020];

#define Q(x, y) if (((p / x) * y) < 1000000 && p % x == 0) p = (p / x) * y;
int main(){
  int s;
  freopen("s", "r", stdin); scanf("%d", &s); srand(s);
  int x = 100000, i, k = 20000, p, j;
  for (i = 1; i <= 100000; i++) C[i] = make_pair(-__builtin_popcount(i), i);
  sort(C + 1, C + 100001);
  freopen("in", "w", stdout);
  printf("%d\n", x);
  for (i = 0; i < 60; i++){
    p = 1;
    for (j = i; j >= 0; j--){
      while (p < 1000000) p *= prime[j];
      p /= prime[j];
    }
    for (j = 0; j < 60; j++) for (int k = j + 1; k < 60; k++)
			       Q(prime[j], prime[k]);
    p2[i] = p;
  }
  for (i = 1; i <= 60; i++) printf("1 %d %d\n", C[i].second, p2[i - 1]);
  for (i = 61; i <= k; i++) printf("1 %d %d\n", C[i].second, p2[rand() % 60]);
  x -= k;
  while (x--) printf("0 %d %d\n", 32767, 98303);
  freopen("s", "w", stdout); printf("%d", rand());
  return 0;
}
