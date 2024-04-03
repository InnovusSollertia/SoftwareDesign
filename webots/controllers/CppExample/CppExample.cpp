#include <webots/Robot.hpp>
#include <webots/Motor.hpp>
#include <webots/DistanceSensor.hpp>

using namespace webots;

int main(int argc, char **argv) {
  Robot *robot = new Robot();

  int timeStep = (int)robot->getBasicTimeStep();

  Motor *motor = robot->getMotor("motorname");
  DistanceSensor *ds = robot->getDistanceSensor("dsname");
  ds->enable(timeStep);

  while (robot->step(timeStep) != -1) {
    double val = ds->getValue();

    motor->setPosition(10.0);
  };

  delete robot;
  return 0;
}
