#include <iostream>
#include <string>

#include "pipeline.h"

int mul_by_2(int x) { return x * 2; } // пример обычной функции

int main() {
  using namespace pipeline;         // подключаем namespace
  std::string str = "Hello World!"; // строка из примера
  str | std::size<std::string> | to_callable(mul_by_2) | [](auto x) {
    return x * 2;
  } | [](auto x) { std::cout << x; }; // пример использования пайплайна

  std::cout << std::endl
            << mul_by_2(7 | to_callable(mul_by_2)) << std::endl; // ещё пример

}