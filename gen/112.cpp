#include <bits/stdc++.h>
int main(){
  int s, n;
  freopen("s", "r", stdin); scanf("%d", &s); srand(s);
  printf("%d %d\n", rand() % 2 + 1, n = rand() % 100 + 1);
  while (n--) printf("%c %d %c %d\n", "AB"[rand() & 1], rand() % 1000000000, "AB"[rand() & 1], rand() % 1000000000);
  freopen("s", "w", stdout); printf("%d", rand());
  return 0;
}
