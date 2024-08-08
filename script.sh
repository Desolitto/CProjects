#!/bin/bash

# Функция для замены текста внутри файлов
replace_text_in_files() {
    local directory=$1
    local old_text=$2
    local new_text=$3
    find "$directory" -type f \( -name "*.c" -o -name "*.cc" -o -name "*.cpp" -o -name "*.h" \) | while read -r file; do
        sed -i '' "s/$old_text/$new_text/g" "$file"
    done
}

# Функция для переименования файлов
rename_files() {
    local directory=$1
    local old_prefix=$2
    local new_prefix=$3
    find "$directory" -type f -name "${old_prefix}*" | while read -r file; do
        new_file="${file/$old_prefix/$new_prefix}"
        mv "$file" "$new_file"
    done
}

# Директория, в которой выполняются замены (можно изменить на нужную директорию)
directory="."

# Замена текста и переименование файлов
replace_text_in_files "$directory" "s21_" "my_"
rename_files "$directory" "s21_" "my_"

echo "Замены выполнены."
