#pragma once
namespace pipeline {

// оператор, используемый для организации пайплайна. Слева значение, справа
// callable объект
// возвращает значение функции от объекта.
template <typename T, typename F>
inline auto operator|(T &&value, F &&func) -> decltype(func(value)) {
  return func(value);
}

// функция чтобы обычные функции тоже можно было запихать. Можно было и оператор
// подобрать, но и так неплохо
template <typename T> auto to_callable(T func) {
  return [func](auto &&...args) {
    return func(std::forward<decltype(args)>(args)...);
  };
}

} // namespace pipeline