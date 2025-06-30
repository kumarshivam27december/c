#include <iostream>
#include <thread>
#include <mutex>
#include <queue>
#include <condition_variable>
#include <chrono>

std::queue<int> buffer;
const unsigned int MAX_BUFFER_SIZE = 5;

std::mutex mtx;
std::condition_variable cv;

void producer() {
    for (int i = 0; i < 10; ++i) {
        std::unique_lock<std::mutex> lock(mtx);
        cv.wait(lock, [] { return buffer.size() < MAX_BUFFER_SIZE; }); // wait if full

        buffer.push(i);
        std::cout << "Produced: " << i << std::endl;

        lock.unlock();
        cv.notify_all(); // notify consumers

        std::this_thread::sleep_for(std::chrono::milliseconds(200));
    }
}

void consumer() {
    for (int i = 0; i < 10; ++i) {
        std::unique_lock<std::mutex> lock(mtx);
        cv.wait(lock, [] { return !buffer.empty(); }); // wait if empty

        int item = buffer.front();
        buffer.pop();
        std::cout << "Consumed: " << item << std::endl;

        lock.unlock();
        cv.notify_all(); // notify producers

        std::this_thread::sleep_for(std::chrono::milliseconds(300));
    }
}

int main() {
    std::thread prod(producer);
    std::thread cons(consumer);

    prod.join();
    cons.join();

    std::cout << "All items produced and consumed." << std::endl;
    return 0;
}
