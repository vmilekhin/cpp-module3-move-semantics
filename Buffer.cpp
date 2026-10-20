#include "Buffer.h"
#include <utility>

Buffer::Buffer(std::size_t size) : data_(new int[size]), size_(size) {
    std::cout << "[Constructor] Выделена память на " << size_ << " элементов\n";
}

Buffer::~Buffer() {
    if (data_) {
        std::cout << "[Destructor] Освобождена память\n";
        delete[] data_;
    } else {
        std::cout << "[Destructor] Память уже была перемещена (nullptr)\n";
    }
}

// --- КОПИРОВАНИЕ ---
Buffer::Buffer(const Buffer& other) : data_(new int[other.size_]), size_(other.size_) {
    std::cout << "[Copy Constructor] Глубокое копирование\n";
    std::copy(other.data_, other.data_ + size_, data_);
}

Buffer& Buffer::operator=(const Buffer& other) {
    std::cout << "[Copy Assignment] Копирование\n";
    if (this != &other) {
        delete[] data_;
        size_ = other.size_;
        data_ = new int[size_];
        std::copy(other.data_, other.data_ + size_, data_);
    }
    return *this;
}

// --- ПЕРЕМЕЩЕНИЕ (noexcept!) ---
Buffer::Buffer(Buffer&& other) noexcept : data_(other.data_), size_(other.size_) {
    std::cout << "[Move Constructor] Перехват указателя (быстро)\n";
    other.data_ = nullptr; // Обнуляем источник, чтобы деструктор не удалил память дважды
    other.size_ = 0;
}

Buffer& Buffer::operator=(Buffer&& other) noexcept {
    std::cout << "[Move Assignment] Перехват указателя\n";
    if (this != &other) {
        delete[] data_;
        data_ = other.data_;
        size_ = other.size_;
        other.data_ = nullptr;
        other.size_ = 0;
    }
    return *this;
}
