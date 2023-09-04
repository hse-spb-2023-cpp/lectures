# Проверка компилятора
Скомпилируйте и запустите программы: из вашей IDE со всеми компиляторами, руками из консоли со всеми компиляторами...

## Поддержка C++17
Скомпилируйте и запустите программу `has-cpp17.cpp`.
Она должна вывести в точности содержимое файла `has-cpp17.expected.txt`.

## Точные версии
Под Ubuntu должно вывести в точности как в файлах `*-ubuntu-*.txt`.

Под Windows Visual Studio должно вывести в точности как в файле `10-windows-vs2022-x64.txt` (64-битная версия) и `11-windows-vs2022-x86.txt` (32-битная версия).

* `C++ 199711` даже при включённом C++17 (потому что нужна совместимость со старым кодом, но [это можно настроить](https://docs.microsoft.com/en-us/cpp/build/reference/zc-cplusplus?view=msvc-160&viewFallbackFrom=vs-2019), нам не потребуется).
* Будьте осторожны с битностью, выберите правильный тип проекта.

Под macOS должно вывести в точности как в файле `20-macos-appleclang.txt`.