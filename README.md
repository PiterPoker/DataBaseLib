# Лабораторная работа: Хранение данных в документах формата .txt


## Дисциплина: Конструирование программ и языки программирования


---


**Задание:**


Написать библиотеку для работы с файлами. Проект должен удовлетворять следующим условиям:


1. Создание, удаление, изменение файла;
2. Добавление, обновление, поиск данных в файле;
3. Создание уникального идентификатора для каждой строки.


Дополнительные требования:


1. Язык программирования: C++;
2. Использовать сторонние библиотеки не желательно.


**Среда разработки и язык программирования:**


Лабораторная работа выполнена в среде разработке Visual Studio 2017. С использованием языка программирования C++. 


**Описание**


Скачать проект и включить его в свое решение. Для полноценной работы с библиотекой, необходимо вызвать функцию __CreateDataBase__, которая создаст паку для хранения файлов и config файл. После чего можно использовать остальные функции библиотеки.


Описание разрабонных функций:


1. Создание папки и config файла:


``` C++
static int CreateDataBase(const char* nameDir);
```


где __nameDir__ - название папки.


Возвращает 0, при успешном выполнении и -1, если произошла ошибка.


2. Удаление папки и ее содержимого:


``` C++
static int DropDataBase();
```


Возвращает 0, при успешном выполнении и -1, если произошла ошибка.


3. Создание .txt файла для хранения данных:


``` C++
static int CreateTable(const char* nameFile);
```

где __nameFile__ - имя файла.


Возвращает 0, при успешном выполнении и -1, если произошла ошибка.

4. Удаление .txt файла для хранения данных:


``` C++
static int DropTable(const char* nameFile);
```


Возвращает 0, при успешном выполнении и -1, если произошла ошибка.


5. Вывести список файлов:


``` C++
static std::vector<std::string> ListTable();
```


При успешном выполнение возвращает вектор имен файлов в каталоге и NULL при ошибке.


6. Чтение строки из файла:



``` C++
std::vector<T> ReadRwos(C *name);
```


где __name__ - имя файла для чтения.


Возвращает вектор строк файла.


7. Обновление ветора строк в файле:



``` C++
unsigned int WriteRwos(vector<T> listData, C *name);
```


где __listData__ - вектор данных; __name__ - имя файла.


8. Запись ветора строк в файл:



``` C++
unsigned int AddNewRwos(vector<T> listData, C *name);
```


где __listData__ - вектор данных; __name__ - имя файла.


9. Запись ветора строк в файл:



``` C++
std::vector<T> Search(const C* nameSearch,const C* nameTable);
```


где __nameSearch__ - ключ для поиска в файле; __name__ - имя файла.


Возвращает вектор результатов.
