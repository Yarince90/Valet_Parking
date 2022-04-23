**# Valet Parking -Final Project Completed in Object Oriented Programming class at Seneca (OOP244) - Computer Programming Program**

This is a valet parking program which allows its users to keep track of and edit which vehicles (cars or motorcycles) are parked in the parking lot 

Once the program starts it displays a menu containing 5 items where the user can choose to either Park a vehicle of type Car or Motorcycle, return a vehicle, list currently parked vehicles, close the parking lot (removes all vehicles) or exit the program.

![image](https://user-images.githubusercontent.com/59423827/164942860-9cbbcc79-4216-4604-a420-0c9cc7997ea5.png)

During this assignment I learnt how to create a valet parking program which can hold up to 100 vehicles (either cars or motorcycles) and dynamically allocate them or deallocate them as needed using the vehicles licence plates to identify them, each vehicle also has an individual Boolean value to indicate if it would get a car wash (for cars) or if it would be stored with a sidecar (for motorcycles). This program also dynamically allocates menus as well as menu items for the options offered in the valet parking. I was able to complete this program by creating various classes and using them as bases to derive other classes from, for example the "Vehicle" class is the base class from which the "Car" and "Motorcycle" classes were derived from, the "Vehicle" class itself was derived from the "ReadWritable" class which allowed the program to read and write from a text file.
