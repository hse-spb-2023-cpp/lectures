# С чего начать
Всё по этим ссылкам знать обязательно:

* Базовый синтаксис C++ — одно из двух:
    * Переход с Python на C++ для алгоритмических задач и олимпиад: https://notes.algoprog.ru/cpp/index.html
    * Все прорешанные задачи из курса: https://stepik.org/course/363/promo
* Работа с консолью:
    * [Краткая вводная лекция](https://www.youtube.com/watch?v=G7Dgxtgj2Tw&list=PLxMpIvWUjaJuOVEWZ0-H7QaUeREmyqNl9&index=2)
    * [Курс по работе в Linux](https://stepik.org/course/73/promo) (обязательно знать от раздела 1.4 "Terminal: основы" до раздела 1.6 "Ввод / вывод" включительно)

# Как выбирать материалы
Много курсов и книг сначала учит языку Си (или его частям), а только потом рассказывает про высокоуровневые части.
Это «классическое» построение: сначала чистые массивы вроде `int a[10]`, указатели (`int*`), а только через полгода появляются шаблоны и стандартная библиотека C++ (`vector<int>`).
Мне это кажется [ненужным усложнением](https://www.youtube.com/watch?v=YnWhqhNdYyk), которое осталось со времён переучивания Си-программистов на C++.
В таком подходе сложно сразу писать простые программы, сначала учат писать сложные.

Наш курс сначала рассказывает простые вещи из C++, а их низкоуровневые аналоги из Си разбираются гораздо позже.

Не существует какого-то стандартного изложения, терминов, определений.
Всё рукомахательно, куча местечкового жаргона, много упрощений или неточностей.
В стандарте языка C++ есть некоторые термины, но они тоже могут превращаться в жаргонизмы в зависимости от контекста.
Порядок изучения тем также может разительно отличаться от курса к курсу: где-то в начале идёт арифметика указателей,
а где-то (у нас или у Яндекса) она задвинута в конец.

Проверяйте свои знания так: вы можете написать корректный код и объяснить происходящее в любом коде (в том числе некорректном).

## Запрещённые материалы
* coderoad.ru – это машинные переводы со stackoverflow.com, лучше в оригинале или переводить компьютером самостоятельно.
  Тогда вы видете весь контекст, а не только то, что сайт запомнил.
* Стандарт языка C++ – не учебник и не справочник, предназначен для разработчиков компиляторов.
  Юридически-программистский талмуд на полторы тысячи страниц.

Любые материалы, где упоминается нижеследующее, следует считать или устаревшими, или вредными, или и то и другое вместе:

* `<conio.h>` (вроде http://www.weblux.ru/cpp/91-c-dlya-nachinayushchikh) – это из компилятора Turbo C конца XX века под MS-DOS, сейчас прямого аналога нет.
* `void main()` – это нестандартный C++, но иногда встречается в специфичных компиляторах под микроконтроллеры.
* "Си - это упрощённый C++" – это разные языки: [комментарий от создателя C++](https://www.stroustrup.com/bs_faq.html#C-slash), [байки на Quora](https://www.quora.com/What-are-the-similarities-and-differences-between-C-and-C/answer/Upasana-Singh-11).
* "При сложении двух чисел результат берётся по модулю два в степени ..., получается отрицательное число, это переполнение" – это просто неверно, переполнение знаковых чисел в C++ не определено (undefined behavior).
* "Так как программа работает корректно, такая конструкция тоже корректна" – это неверно, некорректные программы на C++ имеют право работать корректно.

# Дополнительные материалы
## Справочники
* https://en.cppreference.com/w/cpp – основной источник.
  Близок к стандарту, можно читать случайные подстроки.
  Содержит сильно больше, чем надо в курсе.
  Лучше искать и читать понятные подмножества по конкретным темам вроде `std::sort` или "member functions".
* https://cplusplus.com/ – вспомогательный источник, проще изложение, могут быть неточности и ошибки
* [Справочник по C++ от Microsoft](https://learn.microsoft.com/en-us/cpp/cpp/cpp-language-reference?view=msvc-170) – сделан для Visual Studio,
  может быть написан понятным языкам, на всех страницах есть автоматический машинный перевод.
  Осторожно: не наткнитесь на Visual Studio- или Windows-специфичные вещи, или на C++/CLI для .NET (с конструкциями вида `gcnew array<String^>(10);`).
* Ответы на StackOverflow.com
    * Бывают неверные, читайте комментарии к ответам и вопросам
    * Самостоятельно задавать вопросы не рекомендую: заклюют

## Заметки
* Про зарезервированные имена в Си и C++ (нижние подчёркивания и не только): https://stackoverflow.com/questions/228783/what-are-the-rules-about-using-an-underscore-in-a-c-identifier/228797#228797
* Про отличия undefined, unspecified и implementation-defined behavior: https://stackoverflow.com/questions/2397984/undefined-unspecified-and-implementation-defined-behavior
* [UBBook](https://github.com/Nekrolm/ubbook) – сборник интересного неопределённого поведения (неисчерпывающий)

## Курсы
В этих курсах я только читал программу, детали не смотрел, но доверяю авторам.

* Специализация «Искусство разработки на современном C++» от Яндекса и МФТИ.
    * Официально была доступна только на Coursera, но [Coursera её снесла в марте 2022](https://blog.coursera.org/coursera-response-to-the-humanitarian-crisis-in-ukraine/).
      Теперь доступна на [cppcourse.ru](https://cppcourse.ru/), очень платно.
      Не требуется покупать, мы всё пройдём.
    * [Хорошо построенные пять курсов](https://habr.com/ru/company/yandex/blog/332556/), начинают сразу с C++ и не тратят силы на изучение низкоуровневых частей Си в начале.
* [«Введение в программирование (C++)»](https://stepik.org/course/363/promo) на Stepik от ФКН ВШЭ – введение в программирование, самого C++ там очень мало.
* Книга от создателя языка C++ (есть перевод на русский): [Programming – Principles and Practice Using C++ от Bjarne Stroustrup](https://www.stroustrup.com/programming.html).
  Сам не читал, содержание выглядит разумно, но наверняка изложение сильно отличается от нашего курса.

Более «классические» курсы, в начале идёт много неприятного низкоуровневого про Си или вообще предполагается, что вы уже знаете Си:

* C++ от МФТИ (целый YouTube-канал):
    * [Базовый курс C++](https://www.youtube.com/watch?v=Bym7UMqpVEY&list=PL3BR09unfgciJ1_K_E914nohpiOiHnpsK&index=1) для знающих язык Си
    * [Продвинутый C++](https://www.youtube.com/watch?v=bDWdRyt6fIY) для тех, кто уже неплохо владеет C++
    * [Сложные проблемы C++ и стандарт языка](https://www.youtube.com/watch?v=rxICf0tW7_Q&list=PL3BR09unfgcjJ2YUCgh62vgv_1maXcKuS)
* [«Программирование на языке C++»](https://stepik.org/course/7/promo) на Stepik, старая версия нашего курса.
  Есть [продолжение](https://stepik.org/course/3206/promo).
  * Осторожно: C++11 и C++14 рассказываются только в продолжении, в начале идут старые стандарты. C++17 не рассказан вообще, курс вышел в 2015 году.
* Годовой курс от Computer Science Center: [первый семестр](https://compscicenter.ru/courses/cpp-1/2018-autumn/classes/), [второй семестр](https://compscicenter.ru/courses/cpp-2/2019-spring/classes/).
