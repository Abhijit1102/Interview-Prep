class Animal:
    def __init__(self, name:str, age:int):
        self.name = name
        self.age = age

    def move(self):
        print("I am moving")  

class Dog(Animal):
    def __init__(self, name, age, breed):
        self.name = name
        self.age = age
        self.breed = breed

    def bark(self):
        print("I am barking!")

    def display(self):
        print(f"Name is {self.name} ,  age is {self.age} & breed is {self.breed}")
    
    # Over ridding
    def move(self):
        print("I am moving in four legs")


dog = Dog("huttu", 2, "German")
dog.move()                          