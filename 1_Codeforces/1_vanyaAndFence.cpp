#include <iostream>

int main (int argc, char *argv[]) {
 int n, h, fh, w{0};
 std::cin >> n >> h;
 for (size_t i = 0; i < n; i++) {
  std::cin >> fh;
  if (fh>h) w += 2;
  else w += 1;
 }
 std::cout << w << std::endl;
  return 0;
}

