from controller import Robot, Motor

TIME_STEP = 64

robot = Robot()

leftMotor = robot.getDevice('left wheel motor')
rightMotor = robot.getDevice('right wheel motor')

leftMotor.setPosition(1000.0)
rightMotor.setPosition(200.0)

#  motor = robot.getDevice('motorname')
#  ds = robot.getDevice('dsname')
#  ds.enable(timestep)

while robot.step(TIME_STEP) != -1:
    #  val = ds.getValue()
    #  motor.setPosition(10.0)
    pass

# Enter here exit cleanup code.
