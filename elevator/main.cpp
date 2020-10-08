#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

#include "Elevator.h"

    

int main()
{
    int min_floor_num, max_floor_num;
    std::size_t max_capacity;

    std::cout << "Enter minimum floor number, maximum floor number in the building\n";
    std::cin >> min_floor_num >> max_floor_num;

    std::cout << "Enter maximum capacity for the elevator\n";
    std::cin >> max_capacity;

    Elevator elevator(min_floor_num, max_floor_num, max_capacity);
    elevator.start_elevator();  
}