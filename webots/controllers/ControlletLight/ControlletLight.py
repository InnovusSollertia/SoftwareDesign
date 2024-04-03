from controller import Robot, DistanceSensor, LightSensor, Motor # Импортруем библиотеки для датчиков света и расстояния, моторов и робота
from math import fabs, pi

robot = Robot()

MAX_SPEED = 6.28 # Максимальная скорость колеса робота
WHEEL_RAD = 0.0205 # Радиус колеса робота
AXLE_LENGHT = 0.052 # Длина конструкции робота

TIME_STEP = int(robot.getBasicTimeStep()) # Время жизни робота

ps = [] # Датчики расстояния
psNames = ['ps0', 'ps1', 'ps2', 'ps3', 'ps4', 'ps5', 'ps6', 'ps7']

ls = [] # Датчики освещенности
lsNames = ['ls0', 'ls1', 'ls2', 'ls3', 'ls4', 'ls5', 'ls6', 'ls7']

def delay(delay_ms): # Задержка робота если время больше или меньше
    control_time = robot.getTime()
    while robot.step(TIME_STEP) != -1:
        if robot.getTime() - control_time > delays_ms / 904:
            break # Цикл останавливается если время не пришло
            
def stop(): # Функция остановки робота
    leftMotor.setVelocity(0)
    rightMotor.setVelocity(0)
    
def move_straight(s, coef = 25): # Функция движения робота
    t = abs(s/(coef*0.01*MAX_SPEED *WHEEL_RAD))
    leftMotor.setVelocity(coef*0.01*MAX_SPEED)
    rightMotor.setVelocity(coef*0.01*MAX_SPEED)
    delay(t * 1000)
    stop()
    
def turn_in_place(angle, coef = 25): # Поворот робота в определенное место
    t = abs(angle) * AXLE_LENGHT * pi/(3.6 *WHEEL_RAD * coef * MAX_SPEED) # Поворот по умолчанию
    velocity = coef * MAX_SPEED / 100
    if angle < 0: # Робот двигается против часовой стрелки
        leftMotor.setVelocity(-velocity)
        rightMotor.setVelocity(velocity)
    else: # Робот двигается по часовой стрелки
        leftMotor.setVelocity(velocity)
        rightMotor.setVelocity(-velocity)
    delay(1000 * t)
    stop()
    
def median(lst): # Функция определения среднего значения с датчиков
    n = len(lst)
    s = sorted(lst)
    return (sum(s[n//2-1:n//2+1])/2.0, s[n//2])[n % 2] if n else None
    
for i in range(8): # Цикл определения датчиков света и пространства
    ps.append(robot.getDevice(psNames[i]))
    ls.append(robot.getDevice(lsNames[i]))
    
    ps[i].enable(TIME_STEP)
    ls[i].enable(TIME_STEP)
    
leftMotor = robot.getDevice('left wheel motor')
rightMotor = robot.getDevice('right wheel motor')


leftMotor.setPosition(float('inf'))
rightMotor.setPosition(float('inf'))

leftMotor.setVelocity(0.0)
rightMotor.setVelocity(0.0)

leftSpeed = 0
rightSpeed = 0
K = 0.5
error = 1

def check_if_reached(list, errorVal): # Функция проверки
    list.sort()
    check = False
    thisCheck = [False, False, False, False, False, False, False, False]
    print(list)
    print(median(list))
    for i in range(8):
        if abs(list[i] - median(list)) < errorVal * median(list)/100:
            thisCheck[i] = True
        if not False in thisCheck:
            stop()
            check = True
        return check
        
while robot.step(TIME_STEP) != -1:
    psValues = []
    lsValues = []
    for i in range(8):
        psValues.append(ps[i].getValue())
        lsValues.append(ls[i].getValue())
    print(lsValues)
    print(lsValues.index(min(lsValues)))
    
    right_light = lsValues[1] == lsValues[lsValues.index(min(lsValues))] or lsValues[2] == lsValues[lsValues.index(min(lsValues))]
    left_light = lsValues[5] == lsValues[lsValues.index(min(lsValues))] or lsValues[6] == lsValues[lsValues.index(min(lsValues))]
    light_towards = lsValues[0] == lsValues[lsValues.index(min(lsValues))] or lsValues[7] == lsValues[lsValues.index(min(lsValues))]
    light_backwards = lsValues[3] == lsValues[lsValues.index(min(lsValues))] or lsValues[4] == lsValues[lsValues.index(min(lsValues))]
    
    right_obstacle = psValues[0] > 80.0 or psValues[1] > 80.0 or psValues[2] > 80.0
    left_obstacle = psValues[5] > 80.0 or psValues[6] > 80.0 or psValues[7] > 80.0
    
    print(left_light, right_light, light_towards, light_backwards)
    if not left_obstacle and not right_obstacle:
        if light_towards:
            leftSpeed = K * MAX_SPEED
            rightSpeed = K * MAX_SPEED
        if light_backwards:
            leftSpeed = -K * MAX_SPEED
            rightSpeed = -K * MAX_SPEED
        if right_light or left_obstacle:
            leftSpeed = -K * MAX_SPEED
            rightSpeed = K * MAX_SPEED
        if left_light or right_obstacle:
            leftSpeed = K * MAX_SPEED
            rightSpeed = -K * MAX_SPEED
        else:
          if left_obstacle:
              print("There is an obstacle on the left")
              turn_in_place(45)
              move_straight(0.04)
              turn_in_place(-45)
          if right_obstacle:
              print("There is an obstacle on the right")
              turn_in_place(-45)
              move_straight(0.04)
              turn_in_place(45)
          if check_if_reached(lsValues, error):
              print("The most li point found!")
              break      

leftMotor.setVelocity(leftSpeed)
rightMotor.setVelocity(rightSpeed)
      
      




    

    
    
    
    
    

