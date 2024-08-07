
#!/bin/bash

# Перебираем все файлы в текущей директории и поддиректориях
find . -type f | while read -r file; do
    # Заменяем 's21_' на 'my_' в содержимом файла
    sed -i 's/s21_/my_/g' "$file"
    
    # Получаем относительный путь файла от начала дерева директорий
    relative_path=$(realpath --relative-to=. "$file")
    
    # Извлекаем имя файла из относительного пути
    filename=$(basename "$relative_path")
    
    # Заменяем 's21_' на 'my_' в имени файла
    new_filename="${filename//s21_/my_}"
    
    # Обновляем имя файла
    mv "$file" "$(dirname "$file")/$new_filename"
done
