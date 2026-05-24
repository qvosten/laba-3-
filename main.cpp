#include <iostream>
#include <stack>


class QueueWithTwoStacks {
private:
    std::stack<int> stack1;
    std::stack<int> stack2;


public:
    void enqueue(int x) {
        stack1.push(x);
    }
    void shiftStacks() {
        if (stack2.empty()) {
            while (stack1.empty() == false) {
                stack2.push(stack1.top());
                stack1.pop();
            }
        }
    }

    void dequeue() {
        if (stack1.empty() && stack2.empty()) {
            std::cout << "Ошибка: Очередь пуста, удалять нечего!" << std::endl;
            return;
        }
        shiftStacks();
        stack2.pop();
    }

    int front(){
        if (stack1.empty() && stack2.empty()) {
            std::cout << "Ошибка: Очередь пуста!" << std::endl;
            return -1;
        }

        shiftStacks();
        return stack2.top();
    }
    bool contains(int x) {
        std::stack<int> temp1 = stack1;
        std::stack<int> temp2 = stack2;

        while (temp1.empty() == false) {
            if (temp1.top() == x) {
                return true;
            }
            temp1.pop();
        }


        while (temp2.empty() == false) {
            if (temp2.top() == x) {
                return true;
            }
            temp2.pop();
        }

        return false;
    }
};



int main()
{
    setlocale(LC_ALL, "Russian");
    QueueWithTwoStacks q;
    int choice;
    int value;
 
    
    while (true) {
        std::cout << "1. Добавить элемент (enqueue)" << std::endl;
        std::cout << "2. Удалить элемент (dequeue)" << std::endl;
        std::cout << "3. Посмотреть первый элемент (front)" << std::endl;
        std::cout << "4. Проверить наличие элемента (contains)" << std::endl;
        std::cout << "5. Выйти из программы" << std::endl;
        std::cout << "Выберите действие (1-5): ";

        std::cin >> choice;
        switch (choice) {
        case 1:
            std::cout << "Введите целое число для добавления: ";
            std::cin >> value;
            q.enqueue(value);
            std::cout << "Элемент " << value << " успешно добавлен!" << std::endl;
            break;

        case 2:
            q.dequeue();
            break;

        case 3:
            value = q.front();
            if (value != -1) {
                std::cout << "Первый элемент в очереди: " << value << std::endl;
            }
            break;

        case 4:
            std::cout << "Введите число для поиска: ";
            std::cin >> value;
            if (q.contains(value)) {
                std::cout << "Да, число " << value << " есть в очереди." << std::endl;
            }
            else {
                std::cout << "Нет, числа " << value << " в очереди не найдено." << std::endl;
            }
            break;

        case 5:
            std::cout << "Выход из программы!" << std::endl;
            return 0;

        default:
            std::cout << "Неверный ввод! Пожалуйста, выберите пункт от 1 до 5." << std::endl;
            break;
        }
    }
}


