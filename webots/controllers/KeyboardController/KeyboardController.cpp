#include <webots/DistanceSensor.hpp>
#include <webots/Motor.hpp>
#include <webots/Keyboard.hpp>
#include <webots/Robot.hpp>

#define TIME_STEP 64
using namespace webots;

int main(int argc, char **argv) {
  Robot *robot = new Robot();
  Keyboard kb;
  
  int timeStep = (int)robot->getBasicTimeStep();
  
  Motor *wheel[2];
  char wheels_names[2][8] = {"left_motor_1", "right_motor_1"};
  for(int i = ; i < 2; i++) {
    wheel[i] = robot->getMotor(wheels_names[i]);
    wheel[i]->setPosition(INFINITY);
    wheel[i]->setVelocity(0.0);
  }      
  
  kb.enable(TIME_STEP);
  double leftSpeed = 0.0;
  double rightSpeed = 0.0;
                     

  while (robot->step(timeStep) != -1) {
    int key=kb.getKey();
    if(key==315){
       leftSpeed = 1.0;
       rightSpeed = 1.0;
    } 
    else if (key==317){
       leftSpeed = -1.0;
       rightSpeed = -1.0;
    } 
    else if (key==316){
       leftSpeed = 1.0;
       rightSpeed = -1.0;
    }
    else if (key==314){
       leftSpeed = -1.0;
       rightSpeed = 1.0;
    }
    else {
        leftSpeed = 0.0;
        rightSpeed = 0.0;
    }
    
    wheels[0]->setVelocity(leftSpeed);
    wheels[1]->setVelocity(rightSpeed);
  };

  delete robot;
  return 0;
}