#include <iostream>
#include <string>

#include "pipeline.h"

int mul_by_2(int x) { return x * 2; } // ������ ������� �������

int main() {
  using namespace pipeline;         // ���������� namespace
  std::string str = "Hello World!"; // ������ �� �������
  str | std::size<std::string> | to_callable(mul_by_2) | [](auto x) {
    return x * 2;
  } | [](auto x) { std::cout << x; }; // ������ ������������� ���������

  std::cout << std::endl
            << mul_by_2(7 | to_callable(mul_by_2)) << std::endl; // ��� ������

}