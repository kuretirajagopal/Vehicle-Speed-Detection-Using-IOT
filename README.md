# Vehicle_Speed_Detection_Using_IOT

This project involves two-way communication and utilizes Arduino, NodeMCU, IR proximity sensors, and an alert device (buzzer) to accomplish its objectives. The process operates as follows:

1. Two IR proximity sensors are positioned along a road. As a vehicle passes the first sensor, it records the time. The second sensor does the same as the vehicle crosses it.

2. The time difference between the two sensors is calculated, and by dividing the distance between them by this time difference, the vehicle's speed is determined.

3. The calculated speed is transmitted to the cloud via NodeMCU. Within the cloud, a speed legality check is performed to verify if the vehicle's speed complies with regulations.

4. In the event of an illegal speed, an alert is dispatched to a secondary alert system situated further down the road.

5. The NodeMCU on the secondary alert system receives this alert and communicates it to the Arduino through serial communication.

6. The Arduino, upon receiving the alert, triggers an alert mechanism (buzzer or similar) to notify the driver of the violation.

Here the files are uploaded as CPP files rather than traditional Arduino IDE readables.
