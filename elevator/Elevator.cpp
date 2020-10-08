#include <iostream>
#include <algorithm>

#include "Elevator.h"

void Elevator::set_initial_request()
{
  std::size_t num_of_reqs;
  int dest_floor;

  std::cout << "\nEnter number of requests \n"; //<< get_current_floor() << "\n";
  std::cin >> num_of_reqs;

  std::cout << "\nEnter destination floor number.\n";
  std::cin >> dest_floor;
  requests.emplace_back(dest_floor);
  set_current_capacity(1 + get_current_capacity());
  set_direction();

  for (std::size_t i = 1; i < num_of_reqs; ++i)
  {
    std::cin >> dest_floor;
    if (is_valid_request(dest_floor))
    {
      requests.emplace_back(dest_floor);
      set_current_capacity(1 + get_current_capacity());
    }

    if (get_current_capacity() == get_max_capacity())
    {
      std::cout << "No more entry. Elevator is full!!\n";
      break;
    }
  }
}

void Elevator::set_request()
{
  std::size_t num_of_reqs;
  int dest_floor;

  std::cout << "\nEnter number of requests \n";
  std::cin >> num_of_reqs;

  std::cout << "\nEnter destination floor number.\n";
  for (std::size_t i = 0; i < num_of_reqs; ++i)
  {
    std::cin >> dest_floor;
    if (is_valid_request(dest_floor))
    {
      requests.emplace_back(dest_floor);
      set_current_capacity(1 + get_current_capacity());
    }

    if (get_current_capacity() == get_max_capacity())
    {
      std::cout << "No more entry. Elevator is full!!\n";
      break;
    }
  }
}

bool Elevator::is_valid_request(int floor) const
{
  if (get_current_capacity() >= get_max_capacity())
  {
    std::cout << "Elevator is Full!!\n";
    return false;
  }
  else if (direction == UP && floor < get_current_floor())
  {
    std::cout << "Elevator is going UP.\n";
    return false;
  }
  else if (direction == DOWN && floor > get_current_floor())
  {
    std::cout << "Elevator is going DOWN.\n";
    return false;
  }
  else if (floor > get_max_floor() || floor < get_min_floor())
  {
    std::cout << "This floor does not exist\n";
    return false;
  }
  else
  {
    return true;
  }
}

void Elevator::set_direction()
{
  if (requests[0] > get_current_floor())
  {
    direction = UP;
  }
  else if (requests[0] < get_current_floor())
  {
    direction = DOWN;
  }
}

void Elevator::start_elevator()
{
  int curr_floor = get_current_floor();
  std::size_t curr_capacity = get_current_capacity();

  std::cout << "\nThe current floor is " << curr_floor << " and number of person in elevator are " << curr_capacity << "\n";

  //Entering requests for first time
  set_initial_request();
  std::sort(requests.begin(), requests.end());

  while (!requests.empty())
  {
    if (direction == UP)
    {
      set_current_floor(requests[0]);
    }
    else if (direction == DOWN)
    {
      set_current_floor(requests[requests.size() - 1]);
    }
    curr_floor = get_current_floor();
    curr_capacity = get_current_capacity();

    auto curr_floor_req = std::find(requests.begin(), requests.end(), get_current_floor());
    while (curr_floor_req != requests.end())
    {
      requests.erase(curr_floor_req); //removing current floor's requests
      curr_capacity--;
      curr_floor_req = std::find(requests.begin(), requests.end(), get_current_floor());
    }

    set_current_capacity(curr_capacity);

    std::string dir;
    if (direction == UP)
    {
      dir = "UP";
    }
    else
    {
      dir = "DOWN";
    }

    //Entering requests for current floor
    std::cout << "\n=======================================================\n";
    std::cout << "The current floor is " << curr_floor << " and number of person in elevator are " << curr_capacity << "\n";
    std::cout << "\nDirection of elevator is " << dir << " and Total capacity of the elevator is " << get_max_capacity() << "\n";
    std::cout << "\nMinimum floor number is " << get_min_floor() << " and Maximum floor number is " << get_max_floor() << "\n";
    std::cout << "\n=======================================================\n";

    if (curr_floor == get_max_floor())
    {
      direction = DOWN;
    }
    else if (curr_floor == get_min_floor())
    {
      direction = UP;
    }

    if (current_capacity == 0) //Elevator is empty
    {
      set_initial_request();
      std::sort(requests.begin(), requests.end());
    }
    else
    {
      set_request();
      std::sort(requests.begin(), requests.end());
    }
  }
}