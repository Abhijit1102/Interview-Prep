class Student:
    # Constructor(initailizer) when object is create data is given
    def __init__(self, name:str, age:int, gender:str) -> None:
        print("This is a Contructor or Initializer !")
        # Atrributes
        self.name = name
        self.age = age
        self.gender = gender

    # # Annotation
    # def set_info(self, name:str, age:int, gender: str):
    #     self.name = name
    #     self.age = age
    #     self.gender = gender

    # This display method
    def display(self):
        print("This is the display function!")
        print(f"My name is {self.name} having age {self.age} and gender {self.gender}")
    
    def get_age(self):
        return self.age

s1 = Student("Abhi", 12, "Male")
# s1.set_info("Abhi", 12, "45")
s1.display()
print(s1.get_age())
