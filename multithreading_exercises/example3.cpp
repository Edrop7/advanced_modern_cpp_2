#include <iostream>
#include <thread>
#include <list>
#include <algorithm>
#include <mutex>


// a global variable
std::list<int>myList;

// a global instance of std::mutex to protect the global variable
std::mutex myMutex;

void addToList(int max, int interval)
{
    // the access to this function is mutually exclusive
    std::lock_guard<std::mutex> guard(myMutex);
    for (int i = 0; i < max; i++) {
        if( (i % interval) == 0) myList.push_back(i);
    }
}


int main()
{
    int max = 100;

    std::thread t1(addToList, max, 1);
    std::thread t2(addToList, max, 10);

    t1.join();
    t2.join();

    return 0;
}