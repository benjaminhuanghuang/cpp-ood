- Elevator design implementation in C++
  - https://codereview.stackexchange.com/questions/232502/elevator-design-implementation-in-c

## Use case diagram

There are seven use cases based on the current requirement of the elevator system:

Process Car/Lift Calls: This use case includes several scenarios, which will be described in detail in later sections of this paper. These scenarios includes that the elevator receives lift/car calls from the passengers, turns on or turns off the light of lift/car call buttons, updates the record of lift/car calls stored in system controlling parts, etc.

Process Hall Calls: Similar to Lift/Car Call processing, this use case includes that the elevator receives hall calls from the passengers, turns on or turns off the light of hall call buttons, updates the record of hall calls in system controlling parts, etc.

Move/Stop the Car: The main function of an elevator will include the changing of driving speed, how to make the decision of stop, and driving directions of the car.

Indicating Moving Direction: The elevator should have this mechanism to let the passengers know the current moving direction of the car such that the passenger might decide whether to enter the car or not.

Indicating Car Position: Similarly, the elevator should let the passengers know whether his/her destination floor is reached so that the passenger may decide to leave the car.

Open/Close the Doors: The elevator should be able to open and close the doors for the passengers to get in and out of the car. The functional areas of this use case should also enable the passengers to make door reversals when the doors are closing and the passenger wants to get in the car.

Trigger Emergency Brake: There is safety mechanism within the car to make sure that an unsafe state is not transiently generated.


## Identifying Classes/Objects:
Control objects
ElevatorControl: The central controlling object in the elevator system. ElevatorControl communicates and controls all other objects in the system.
Door: There are two doors in the system, the “god” object — the ElevatorControl — command the doors to open and close.
Car/Lift: The car is being controlled to move up and down (in different speeds), to make stops at floors when necessary.
Button: The ElevatorControl class also controls the button class, which further generalizes two subclasses CarCallButton and HallCallButton. The control object communicates with the Button objects, get the information whether a button is pressed and in turn controls the illumination of Button lights.
Indicator: There are two kinds of indicators in the system, the CarPositionIndicator and the CarDirectionIndicator (i.e. the CarLantern). The indicators are controlled to show the information about the current position and moving direction of the car.
Safety: Whenever an emergency happens, the ElevatorControl commands the Safety