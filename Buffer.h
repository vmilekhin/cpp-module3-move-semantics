#pragma once
#include <cstddef>
#include <iostream>

class Buffer {
public:
    // 1. Конструктор
    explicit Buffer(std::size_t size);
    
    // 2. Деструктор
    ~Buffer();

    // 3. Конструктор копирования (Copy Constructor)
    Buffer(const Buffer& other);

    // 4. Оператор копирующего присваивания (Copy Assignment)
    Buffer& operator=(const Buffer& other);

    // 5. Конструктор перемещения (Move Constructor)
    Buffer(Buffer&& other) noexcept;

    // 6. Оператор перемещающего присваивания (Move Assignment)
    Buffer& operator=(Buffer&& other) noexcept;

    // Геттеры для демонстрации
    int* data() const { return data_; }
    std::size_t size() const { return size_; }

private:
    int* data_;
    std::size_t size_;
};
