# Logger

Консольное приложение для записи сообщений в журнал с указанием важности (DEBUG, ERROR, EMERGENCY).


### Установка
Клонирование репозитория

```git clone https://github.com/Danila-gi/logger.git```

Переход в папку с проектом

```cd logger```

Запуск скрипта со сборкой проекта

```./run_sh -h # для динамической библиотеки
./run_sh -t # для статистической библиотеки
```

Исполняемый файл *logger* для запуска после этого находится в директории *build/logger_app/*
```./logger```

### Исполняемая программа

```Usage

  ./logger
  ./logger <file name> <default severity level(0: DEBUG, 1: ERROR, 2: EMERGENCY)>
```

### Тестирование

Исполняемый файл *logger_test* с тестами находится в директории *build/logger_app/*
```./logger_test```