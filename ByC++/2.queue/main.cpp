#include <iostream>
#include "queue.hpp"

int main() {
    CharQueueLL queue;
    enqueue(queue, 'Q');
    enqueue(queue, 'Q');
    enqueue(queue, 'Q');
    dequeue(queue);
    dequeue(queue);
//    dequeue(queue);
    if (!isEmpty(queue)) {
        dequeue(queue);
        std::cout << "run" << std::endl;
    }
    std::cout << "size=" << queue.size << std::endl;
    return 0;
}