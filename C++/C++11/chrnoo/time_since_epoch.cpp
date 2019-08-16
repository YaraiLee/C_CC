
#include <iostream>
#include <chrono>
#include <ctime>
 
int main()
{
    auto p0 = std::chrono::time_point<std::chrono::system_clock>{};
    auto p1 = std::chrono::system_clock::now();
    auto p2 = p1 - std::chrono::hours(24);
 
    auto epoch_time = std::chrono::system_clock::to_time_t(p0);
    std::cout << "epoch: " << std::ctime(&epoch_time);
    auto today_time = std::chrono::system_clock::to_time_t(p1);
    std::cout << "today: " << std::ctime(&today_time);
 
    std::cout << "hours since epoch: "
              << std::chrono::duration_cast<std::chrono::hours>(
                   p1.time_since_epoch()).count() 
              << '\n';
    std::cout << "yesterday, hours since epoch: "
              << std::chrono::duration_cast<std::chrono::hours>(
                   p2.time_since_epoch()).count() 
              << '\n';
}