// cpptool:CXXFLAGS: -I./utils
// cpptool:LDFLAGS: -lm -lpthread

#include <cmath>
#include <iostream>

#include <pthread.h>

#include "defer.hpp"

void* thread_func(void*)
{
    auto result = std::sin(0.5);

#ifdef DEBUG
    std::cout << "Result: " << result << "\n";
#endif

    return nullptr;
}

int main(void)
{
    pthread_t thread;
    if (pthread_create(&thread, nullptr, thread_func, nullptr) != 0) {
        perror("pthread_create");
    }
    auto join = defer([&]{ pthread_join(thread, nullptr); });
    return 0;
}
