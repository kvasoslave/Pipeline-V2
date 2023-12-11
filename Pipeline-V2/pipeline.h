#pragma once
namespace pipeline {

// ��������, ������������ ��� ����������� ���������. ����� ��������, ������
// callable ������
// ���������� �������� ������� �� �������.
template <typename T, typename F>
inline auto operator|(T &&value, F &&func) -> decltype(func(value)) {
  return func(value);
}

// ������� ����� ������� ������� ���� ����� ���� ��������. ����� ���� � ��������
// ���������, �� � ��� �������
template <typename T> auto to_callable(T func) {
  return [func](auto &&...args) {
    return func(std::forward<decltype(args)>(args)...);
  };
}

} // namespace pipeline