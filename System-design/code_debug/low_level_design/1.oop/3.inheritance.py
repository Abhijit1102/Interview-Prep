class Animal:
    def __init__(self,name:str,age:int):
        self.name = name
        self.age = age

    def eat(self):
        print("I am eating!")

    def sleep(self):
        print("I am sleeping!") 


class Dog(Animal):
    def __init__(self, name:str, age: int, breed: str):
        super().__init__(name,age) # add ing extra input
        self.breed = breed

    def bark(self):
        print("I am Barking") 

    def display(self):
        print(f"Name is {self.name} & age is {self.age} having bread is {self.breed}")    

dog = Dog("Kuttu", 2, "Bull Dog")
dog.bark()
dog.eat()
dog.sleep()   
dog.display()               