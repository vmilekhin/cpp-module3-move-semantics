#include "Buffer.h"
#include <utility>

int main() {
    std::cout << "--- 1. Создание ---\n";
    Buffer a(5);
    a.data()[0] = 42;

    std::cout << "\n--- 2. Копирование (Copy) ---\n";
    Buffer b = a; // Вызовется Copy Constructor

    std::cout << "\n--- 3. Перемещение (Move) ---\n";
    Buffer c = std::move(a); // Вызовется Move Constructor

    std::cout << "\n--- 4. Проверка ---\n";
    std::cout << "a.data() = " << a.data() << " (должен быть 0/nullptr)\n";
    std::cout << "c.data() = " << c.data() << " (получил данные от a)\n";

    std::cout << "\n--- 5. Конец main ---\n";
    return 0;
}
