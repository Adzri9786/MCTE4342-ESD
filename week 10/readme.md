DC MOTOR

A DC motor is a type of electric motor that runs on direct current (DC) electricity. DC motors can be used to power a wide variety of devices, including fans, pumps, and robots.

DC motors consist of a stator, which is a stationary part that provides the magnetic field, and a rotor, which is a rotating part that is attracted to the magnetic field. The rotor is connected to an output shaft, which can be used to transmit mechanical power to a load.

DC motors are classified based on the type of current they use and the type of magnet used in the stator. There are several types of DC motors, including brushed DC motors, brushless DC motors, and stepper motors.

DC motors can be controlled using a variety of techniques, including pulse width modulation (PWM), voltage control, and current control. To control a DC motor with an Arduino, you will need a DC motor driver (such as the L293D or TB6612FNG) to convert the control signals from the Arduino into the high current and voltage signals required by the DC motor.

![Screenshot_20221230_110631](https://user-images.githubusercontent.com/84280005/210084655-de26d1c5-ba61-4e79-95ee-5a9d1384448d.png)

as i do not have the required component (dc motor driver) at the moment i could only show an image of the circuit

STEPPER MOTOR

A stepper motor is a type of electric motor that can rotate in small, precise increments, or "steps." Stepper motors are commonly used in robotics and automation applications because they can be controlled with high precision and accuracy.

To control a stepper motor with an Arduino, you will need a stepper motor driver (such as the A4988 or DRV8825) to convert the control signals from the Arduino into the high current and voltage signals required by the stepper motor. You will also need jumper wires to connect the stepper motor, the driver, and the Arduino.

![stepper motor circuit](https://user-images.githubusercontent.com/84280005/210080993-0b924209-2eb5-4094-a6d6-db681a32bb3b.png)

as i do not have the required component (stepper motor driver) at the moment i could only show an image of the circuit

SERVO MOTOR

A servo motor is a type of electric motor that is designed for precise control of angular position. Servo motors are commonly used in robotics and automation applications because they can rotate to a specific position and hold that position with high accuracy.

Servo motors typically consist of a DC motor, a set of gears, and a control circuit. The control circuit monitors the position of the motor and adjusts the power supplied to the motor to maintain the desired position.

Servo motors can be controlled using pulse width modulation (PWM) signals. The pulse width of the control signal determines the position of the servo, and the frequency of the control signal determines the speed at which the servo moves to the desired position.

To control a servo motor with an Arduino, you will need a servo motor, a breadboard, and jumper wires. You will also need to include the Servo.h library in your sketch to use the servo motor with the Arduino.

To control the speed of a servo motor with an Arduino, you can use the writeMicroseconds() function to set the pulse width of the control signal sent to the servo. The pulse width determines the position of the servo, and a longer pulse width will result in a slower movement of the servo.

https://drive.google.com/file/d/1FBorGzgZxLKxp0mFmx-Gbr7UTtTfO4y9/view?usp=share_link

