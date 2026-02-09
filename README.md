# C++ Calculator Project

Небольшое консольное приложение на C++ с меню, арифметическими операциями и задачами на массивы.
Сборка проекта выполняется через **CMake** и упрощена с помощью **Makefile**.

---

## Требования

Перед началом убедись, что установлены:

- `cmake` (версия 3.10+)
- `g++` или `clang++`
- `make`

Проверка:

```bash
cmake --version
g++ --version
make --version
```

---

## Структура проекта

```
cpp/
├─ CMakeLists.txt
├─ Makefile
├─ include/
│  ├─ arrays.h
│  ├─ math.h
│  └─ menu.h
├─ src/
│  ├─ main.cpp
│  ├─ arrays.cpp
│  └─ menu.cpp
└─ utils/
   ├─ reader.cpp
   └─ reader.h
```

---

## Команды Makefile

В проекте есть три основные команды:

### 1. Инициализация сборки

Создаёт папку `build`, генерирует файлы сборки через CMake и компилирует проект.

```bash
make initBuild
```

Эквивалентно:

```bash
mkdir -p build
cd build
cmake ..
cmake --build .
```

---

### 2. Пересборка проекта

Используется, когда уже есть папка `build`.

```bash
make build
```

---

### 3. Запуск приложения

```bash
make run
```

---

## Быстрый старт

```bash
make initBuild
make run
```

---

## Очистка сборки (опционально)

Если нужно начать с нуля:

```bash
rm -rf build
```

После этого снова:

```bash
make initBuild
```

---

## Назначение Makefile

Makefile упрощает работу с CMake:

- `initBuild` — первая сборка проекта
- `build` — быстрая пересборка
- `run` — запуск приложения
