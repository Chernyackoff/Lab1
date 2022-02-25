#include <iostream>
#include "PublicQueue.hpp"
#include "ProtectedQueue.hpp"
#include "PrivateQueue.hpp"

template<typename T>
T merge(const T &a, const T &b) {
    T result;
    for (auto curr = a.getHead(); curr != nullptr; curr = curr->next) {
        result.enqueue(curr->value);
    }
    for (auto curr = b.getHead(); curr != nullptr; curr = curr->next) {
        result.enqueue(curr->value);
    }
    return result;
}

template<typename T>
int real_main() {
    T q1, q2;

    while (true) {
        std::cout << "Select action:" << std::endl;
        std::cout << "1. Enqueue" << std::endl;
        std::cout << "2. Dequeue" << std::endl;
        std::cout << "3. Print" << std::endl;
        std::cout << "4. Calculate" << std::endl;
        std::cout << "5. Copy" << std::endl;
        std::cout << "6. Merge" << std::endl;
        std::cout << "7. Exit" << std::endl;

        int choice;

        std::cin >> choice;

        switch (choice) {
            case 1:
                std::cout << "Enter value to enqueue:" << std::endl;
                std::cin >> choice;
                q1.enqueue(choice);
                break;

            case 2:
                if (q1.length() < 1) {
                    std::cout << "Q1 is empty" << std::endl;
                    break;
                }
                std::cout << "Dequeued " << q1.front() << std::endl;
                q1.dequeue();
                break;

            case 3:
                std::cout << "Q1:";
                for (auto curr = q1.getHead(); curr != nullptr; curr = curr->next) {
                    std::cout << " " << curr->value;
                }
                std::cout << std::endl;

                std::cout << "Q2:";
                for (auto curr = q2.getHead(); curr != nullptr; curr = curr->next) {
                    std::cout << " " << curr->value;
                }
                std::cout << std::endl;
                break;

            case 4:
                std::cout << "Calculation result: " << q1.countAboveGap() << std::endl;
                break;

            case 5:
                std::cout << "Copying Q1 into Q2" << std::endl;
                q2 = q1;
                break;

            case 6:
                std::cout << "Q1:";
                for (auto curr = q1.getHead(); curr != nullptr; curr = curr->next) {
                    std::cout << " " << curr->value;
                }
                std::cout << std::endl;

                std::cout << "Q2:";
                for (auto curr = q2.getHead(); curr != nullptr; curr = curr->next) {
                    std::cout << " " << curr->value;
                }
                std::cout << std::endl;

                std::cout << "Merging Q2 into Q1" << std::endl;
                q1 = merge(q1, q2);
                break;

            case 7:
                return 0;

            default:
                std::cout << "Invalid action" << std::endl;
                break;
        }
    }


    return 0;
}

int main() {
    std::cout << "Select subclass:" << std::endl;
    std::cout << "1. PublicQueue" << std::endl;
    std::cout << "2. ProtectedQueue" << std::endl;
    std::cout << "3. PrivateQueue" << std::endl;
    int choice;
    std::cin >> choice;

    while (true) {
        switch (choice) {
            case 1:
                return real_main<PublicQueue>();
            case 2:
                return real_main<ProtectedQueue>();
            case 3:
                return real_main<PrivateQueue>();
            default:
                std::cout << "Value out of range" << std::endl;
                std::cin >> choice;
                break;
        }
    }


}
