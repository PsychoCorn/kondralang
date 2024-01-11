# kondralang

Язык, который компилируется в C++

Идеи:

Типы:

Целые числа: int8, uint8, int16, uint16, int32, uint32, int64, uint64, int(DynamicInteger)

Действительные числа:

Числа с плавающей точкой: float32, float64, float80

Числа с фиксированной точкой: decimal(пока под вопросом)

Логический тип данных: bool

Символьные типы данных: char и string(String)

Динамический тип: var(Variable - может хранить int, float64, string, bool, None(тип не инициализированной переменной))

Указатели(В том числе на функции)

Обьекты

Поведение ключевого слова var:

1) Если var объявлен с ключевым словом const, то var действует, как ключевое слово auto из C++. При этом в случае с целым числом, компилятор подбирает наименьшее возможное по памяти.
2) Если var объявлен для переменной, но тип значения, которое лежит в переменной не меняется, то var действует, как auto из c++. Для целого при этом, если не происходит арифметических операций, то компилятор подбирает наименьшее возможное по памяти значение, иначе int
3) Если var объявлен для переменной и тип значения, которое лежит в переменной меняется, то создается новый объект класса Variable.
4) При использовании операции приведения var(), всегда создаётся объект класса Variable.
5) При объявлении функции типа var, функция всегда возвращает Variable.

Ключевое слово func:
 Используется при создании функции. Действует так же, как auto в C++.

Поведение операции free:

Является аналогом delete в C++.

При использовании операции new, компилятор отслеживает жизненный путь области памяти, и сам вставляет операцию delete в C++ код.

Если используется операция free, то операция delete, вставляется в соответствующее место в C++ коде. 

Ключевое слово unique: Используется при создании указателей. Говорит о том, только один указатель, может иметь ссылку на конкретную область памяти. Компилятор не считает количество ссылок, на область памяти, а анализирует жизненный путь указателя. 

f-строки:
являются аналогом f-строк из python. 

Синтаксис:
f"String value: {stringVar}. Integer value: {intVar:*^5}. Float value {floatVar:.5f}" Скомпилируется в std::format("String value: {}. Integer value: {:*^5}. Float value {:.5f}", stringVar, intVar, floatVar) 