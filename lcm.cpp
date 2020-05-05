#include <iostream>

long long lcm_naive(int a, int b) {
  for (long l = 1; l <= (long long) a * b; ++l)
    if (l % a == 0 && l % b == 0)
      return l;

  return (long long) a * b;
}
long long gcd(long long a, long long b){
  if(b == 0) return a;
  return gcd(b, a % b);
}
long long lcm_fast(long long a, long long b){
  long long l = a / gcd(a, b);
  l *= b;
  return l;
}
int main() {
  int a, b;
  std::cin >> a >> b;
  //std::cout << lcm_naive(a, b) << std::endl;
  std::cout << lcm_fast(a, b) << std::endl;
  return 0;
}
