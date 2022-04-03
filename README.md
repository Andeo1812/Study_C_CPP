#  Углубленное программирование на языке С/С++

## Индивидуальное задание №2
### Вариант 38
Вы разрабатываете специализированную БД сотрудников для корпорации, в которой работает около 10к человек. 
По ряду причин все данные необходимо хранить в оперативной памяти. Предложите такую эффективную упаковку 
данных о сотруднике (его имени, фамилии, поле, возрасте, заработной плате, должности и стаже работы), 
при которой эти данные занимали бы наименьший объем. Используя её, реализуйте однопоточную и многопоточную 
программу построения отчётов о средней заработной плате для каждой должности в зависимости от стажа работы.
### Критерии
Корректно реализован последовательный алгоритм, ревьюер одобрил весь код, при этом есть хотя бы одна настройка 
от CI и хотя бы один тест, которые автоматически запускаются для всех новых изменений и проходят на итоговой версии –  3

Последовательная реализация полностью покрыта юнит-тестами –  1

Для последовательной реализации настроен и проходит CI: автоматическая сборка, статический анализ,
линтеры, valgrind, code coverage, запуск тестов –  1

Корректно реализован параллельный алгоритм, ревьюер одобрил весь код, при этом есть хотя бы одна
настройка от CI и хотя бы один тест, которые автоматически запускаются для всех новых изменений и 
проходят на итоговой версии –  5

Эффективная работа с памятью (выравнивание структур/работа с кеш-памятью/эффективные структуры
данных для хранения и обмена данными между потоками/процессами) –  2

Оформление кода в виде статической и динамической библиотек с одним интерфейсом –  2

Рабочие на CI стресс-тесты для сравнения последовательной и параллельной реализаций –  1

Первым аргументом программе подается путь к файлу письма (.blk).

## Формат ввода:

`name[32] surname[64] gender[8] age[4] salaty[16] position[64] experience[4]`

## Формат вывода:

В работе создает директорию report* в зависимости
от метода и там же создаются файлы отвечающие за распределение по должностям:

Actor.txt
```
exp 4 - 379648
exp 5 - 49136
exp 6 - 217894
exp 7 - 104281
exp 8 - 64867
exp 9 - 111761
exp 10 - 34688
```

## Устройство структуры:

Массив пользовательского типа.

## Работа программы:

На вход принимает первым аргументом требование к сортировке, путь к базе
данных, путь к отсортированной базе данных (для вывода), тип работы 
императивный или многопоточный.

### Примеры запуска:
```
./build/HW-2 1 generated_database.txt sorted_database.txt 1
```
- для последовательного алгоритма.

```
./build/HW-2 1 generated_database.txt sorted_database.txt 2
```
- для многопоточного

## Проверки:
1. Стические анализаторы cppcheck, clang-tidy, cpplint.
2. Сборка на cmake.
3. Тестирование на gtest общего функционала для обоих библиотек.
4. Провекрка покрытия gtest. Если менее чем 60% (опционально в make) выдаст ошибку для также для общего функционала и обоих библиотек.
5. Запуск тестов на valgring также для общего функционала и обоих библиотек.

При наличии замечаний или неудаче выдаст ошибку.