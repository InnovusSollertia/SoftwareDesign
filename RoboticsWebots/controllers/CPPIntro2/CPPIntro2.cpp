#include <webots/Robot.hpp>
#include <webots/DistanceSensor.hpp>
#include <iostream>

#define TIME_STEP 32

using namespace webots;

int main() {
  Robot *robot = new Robot();

  DistanceSensor *sensor = robot->getDistanceSensor("my_distance_sensor");
  sensor->enable(TIME_STEP);

  while (robot->step(TIME_STEP) != -1) {
    const double value = sensor->getValue();
    std::cout << "Sensor value is: " << value << std::endl;
  }

  delete robot;
  return 0;
}