#!/bin/bash

# Перевірка наявності параметру
if [ $# -eq 0 ]; then
    echo "для команди треба вказати параметр"
    exit 1
fi

PARAM_NAME=$1

# Додатковий опис, якщо вказано другий аргумент 'info'
if [ "$PARAM_NAME" == "SwapTotal" ] && [ "$2" == "info" ]; then
    echo "Загальний розмір області підкачки (Swap):"
fi

# Пошук параметру у файлі /proc/meminfo
RESULT=$(grep "^$PARAM_NAME:" /proc/meminfo)

# Перевірка, чи знайдено параметр
if [ -z "$RESULT" ]; then
    echo "параметр не знайдено"
    exit 1
else
    # Вивід значення (використовуємо awk для красивого формату)
    echo "$RESULT" | awk '{print $2, $3}'
fi
