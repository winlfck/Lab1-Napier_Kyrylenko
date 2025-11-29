#!/bin/bash

# Кількість об'єктів (30 + 8 варіант)
COUNT=38

echo "Створення $COUNT користувачів..."

for (( i=1; i<=COUNT; i++ ))
do
    # Генеруємо ім'я: user + випадкове число
    USER_NAME="user$RANDOM"
    
    # Створюємо користувача (потрібно sudo, бо це useradd)
    # -m створює домашню папку, -s /bin/bash задає оболонку
    sudo useradd "$USER_NAME" -m -s /bin/bash
    
    echo "Користувач $USER_NAME створений."
done

echo "Завершено."
