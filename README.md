Baremetal assessment -
The objective of the project is to create a vector datatype using structure and create another quantity called quaternion including the vector.
A quaternion is quantity having a scalar part and a vector part ,often used for denoting rotation in space.
Here  a vector quantity is created with the help of structure aliased to "vector". Basic operations like dot and cross are also created
Another structre representing the quaternion which also have the vector as one member.
Created the required functions like creating,complementing, multiply and dot operations on the quaternion created(0,1,1,1)
Among them Multiplying quaternion is quite challenging as it needs a series of steps including obtaing the scalar part which uses the equation q1.s *q2.s - (v1.x.v2.x)+v1.y.v2.y+v1.z*v2.z) ie the dot product
next step is to obtain the vector part by the given formula in the code.
Quaternion q is created and quantities are entered by the user. 
Operations like complementing,dot,multiply etc are perfomed as per the function call
