#include <thread>
#include <unistd.h>
#include <iostream>

void myThreadFunction() {
    for(int i = 0; i < 10; i++){
        sleep(1);
        std::cout << ("child" + std::to_string(i)) << std::endl;
    }

}

int main() {
    std::thread t(&myThreadFunction);

    for(int i = 0; i < 5; i++){
        sleep(1);
        std::cout << ("main" + std::to_string(i)) << std::endl;
    }

    if (t.joinable()) t.join();

    return 0;
}