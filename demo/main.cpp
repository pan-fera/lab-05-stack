#include <Stack.hpp>

int main() {
  Stack<int> a;
  a.push(5);
  a.push(10);
  int x =0;
  a.push(x);

  std::cout << std::is_move_constructible<Stack<int>>::value << std::endl;
  std::cout << std::is_move_assignable<Stack<int>>::value << std::endl;
  std::cout << std::is_copy_constructible<Stack<int>>::value << std::endl;
  std::cout << std::is_copy_assignable<Stack<int>>::value << std::endl;
  std::cout << a.head() << std::endl;
  a.pop();
  std::cout << a.head() << std::endl;
  a.pop();
  std::cout << a.head() << std::endl;
}