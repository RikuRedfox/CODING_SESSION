# templated Contructor
class Employee:
    def __init__(self, name, id):
        self.id = id
        self.name = name
    def display(self):
        print(f"ID: {self.id}\nName: {self.name}\n")
        
employee1 = Employee("Andrew Jules R. Miyajima", 21007949710)
print(f"{employee1.name}")
employee1.display()

# Default constructor
class Student:
    def __init__(self):
        self.name = "Andrew Jules"
        self.age = 20
        self.grade = "A+"
        
student1 = Student()
print(f"Name: {student1.name}")
print(f"Age: {student1.age}")
print(f"Grade: {student1.grade}\n")

class Person:
    def __init__(self) -> None:
        self.name = "Andrew Jules"
        self.age = 20
        
person1 = Person()
print(f"Name: {person1.name}")
print(f"Age: {person1.age}")

class Rectangle:
    def __init__(self, length, width) -> None:
        self.length = length
        self.width = width
    def Display(self):
        print(f"Length: {self.length}\nWidth: {self.width}")
    def Area(self):
        return self.length * self.width

rectangle1 = Rectangle(4, 9)
rectangle1.Display()
print(f"Area: {rectangle1.Area()}")