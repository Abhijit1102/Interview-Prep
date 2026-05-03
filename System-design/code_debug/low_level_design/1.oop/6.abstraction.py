from abc import ABC, abstractmethod

class Shape(ABC):
    @abstractmethod
    def area(self):
        pass

    @abstractmethod    
    def perimeter(self):
        pass    

# Concrete Clases
class Rectange(Shape):
    def __init__(self, length, breath):
        self.length = length
        self.breath = breath

    def area(self):
        print("The area of given rectange is :", self.length * self.breath)    

    def perimeter(self):
        print("The perimter of given rectange is :", 2 *(self.length + self.breath))    



r = Rectange(2,3)
r.area()
r.perimeter()