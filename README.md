# Лабораторные работы ОАиП
## Лабораторная работа №1
- Цель: освоить механизм структур языка С, научиться работать с массивами пользовательских типов данных.
- Задача: написать программу для работы с массивом структур.
- Уловия: выбрать любой подходящий объект для описания его с помощью структуры. В ней должно быть не менее трех полей, желательно, разных типов.
## Лабораторная работа №2
- Цель: освоить принципы работы с текстовыми файлами в языке С.
- Задача: написать программу, реализующую простой алгоритм сжатия текста.
- Уловия: написать программу сжатия текстового файла по алгоритму: 
  - 1.Подсчет частоты встречи каждого слова в файле.
  - 2.Поиск самого популярного среди длинных слов (А).
  - 3.Поиск самого непопулярного среди коротких слов (В).
  - 4.Замена всех слов А и В друг на друга.
  - 5.Повтор пунктов 2-4 до тех пор, пока это имеет смысл.
## Лабораторная работа №3
- Цель: освоить принципы работы с бинарными файлами в языке С.
- Задача: написать программу, реализующую простую обработку изображения.
- Уловия: Написать программу обработки для bmp-изображений с сохранением результата в отдельный bmp файл. 
## Лабораторная работа №4
- Цель: освоить принципы работы с бинарными деревьями.
- Задача: написать программу-аналог Акинатора.
- Уловия: программа должна определять загаданный пользователем объект. Для этого она должна управлять двоичным деревом, в котором хранится информация о загадываемых объектах. Работа проходит по следующему сценарию:
  - 1.Пользователь загадывает объект.
  - 2.Программа задает вопросы, на которые пользователь отвечает да/нет.
  - 3.Каждый ответ приводит к очередному вопросу из дерева. Так до тех пор, пока не будет достигнут конец (лист) с ответом.
  - 4.Если ответ неверный, программа должна предложить ввести данные о загаданном объекте (отличительный вопрос) и запомнить новый объект.
## Лабораторная работа №5
- Цель: освоить принципы работы с хеш-таблицами и двусвязными списками.
- Задача: написать программу поиска с кэшем.
- Уловия: программа должна выполнять поиск IP адреса по доменному имени в файле, содержащем DNS таблицу. Поиск необходимо реализовать через кэш с алгоритмом LRU:
  - 1.Пользователь задает доменное имя.
  - 2.Программа проверяет наличие данных в кэше:
    - 2.1.Если HIT (присутствует в кэше) – возвращает IP адрес пользователю.
    - 2.2.Если MISS (отсутствует в кэше) – программа производит поиск по файлу, помещает запись в кэш и возвращает IP адрес. 
  - 3.Кэш должен содержать значения <key, value>, где k – это доменное имя, а v – IP адрес. Данные в кэш помещаются по алгоритму LRU.
  
