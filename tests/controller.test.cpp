#include <cassert>
#include <iostream>
#include "../arduino/ultrasonic_servo/controller.h"

int main() {
  // Documented virtual examples: close object opens servo; far object closes it.
  assert(targetServoAngle(10, true) == 90);
  assert(targetServoAngle(30, true) == 0);
  // A timed-out echo must not open the servo on an invalid reading.
  assert(targetServoAngle(0, false) == 0);
  assert(targetServoAngle(-1, true) == 0);
  assert(targetServoAngle(20, true) == 90);
  assert(targetServoAngle(21, true) == 0);
  std::cout << "controller tests passed\n";
}
