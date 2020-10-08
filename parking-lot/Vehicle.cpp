enum class VehicleSize { motorcycle = 0, car = 1, bus = 2 };

class Vehicle {
private:
    std::string numberPlate;
public:
    Vehicle() : numberPlate("0000") {};
    Vehicle(std::string numberPlate) : numberPlate(numberPlate) {};
    std::string getNumberPlate() const;
    virtual VehicleSize getSize() const = NULL;
    virtual ~Vehicle();
};

class Bus : public Vehicle {
private:
    const VehicleSize size = VehicleSize::bus;
    static int numOfVehicles;
public:
    Bus() : Vehicle("B" + std::to_string(numOfVehicles)) { ++numOfVehicles; };
    Bus(std::string numberPlate) : Vehicle(numberPlate) { ++numOfVehicles; };;
    virtual VehicleSize getSize() const;
    virtual ~Bus();
};

class Car : public Vehicle {
private:
    const VehicleSize size = VehicleSize::car;
    static int numOfVehicles;
public:
    Car() : Vehicle("C" + std::to_string(numOfVehicles)) { ++numOfVehicles; };
    Car(std::string numberPlate) : Vehicle(numberPlate) { ++numOfVehicles; };
    virtual VehicleSize getSize() const;
    virtual ~Car();
};

class Motorcycle : public Vehicle {
private:
    const VehicleSize size = VehicleSize::motorcycle;
    static int numOfVehicles;
public:
    Motorcycle() : Vehicle("M" + std::to_string(numOfVehicles)) { ++numOfVehicles; };
    Motorcycle(std::string numberPlate) : Vehicle(numberPlate) { ++numOfVehicles; };
    virtual VehicleSize getSize() const;
    virtual ~Motorcycle();
};