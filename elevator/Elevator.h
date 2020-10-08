
#include <vector>

class Elevator
{
    enum Direction{ UP, DOWN };
    Direction direction;

    std::vector<int> requests = {};
    int min_floor; //Undergroud floor will be shown using negative value
    int max_floor;
    int current_floor = 0; //ground floor
    std::size_t current_capacity = 0;
    std::size_t max_capacity;

 public:
    Elevator() = default;
    Elevator(int min_floor, int max_floor, std::size_t max_capacity) :
            min_floor(min_floor),
            max_floor(max_floor),
            max_capacity(max_capacity)
            {}
    ~Elevator() {};

    void start_elevator();

 private:
    void set_initial_request();
    void set_request();
    bool is_valid_request(int floor) const;
    void set_direction();

    int get_min_floor() const
    {
        return min_floor;
    }

    int get_max_floor() const
    {
        return max_floor;
    }

    int get_current_floor() const
    {
        return current_floor;
    }

    void set_current_floor(int floor)
    {
        current_floor = floor;
    }

    std::size_t get_max_capacity() const
    {
        return max_capacity;
    }

    std::size_t get_current_capacity() const
    {
        return current_capacity;
    }

    void set_current_capacity(std::size_t cap)
    {
        current_capacity = cap;
    }
 }; 