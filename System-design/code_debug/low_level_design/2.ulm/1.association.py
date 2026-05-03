class Teacher:
    def __init__(self, name: str) -> None:
        self.__name: str = name

    def get_name(self) -> str:
        return self.__name

    def teach(self, student: "Student") -> None:
        print(f"{self.__name} is teaching {student.get_name()}")

class Student:
    def __init__(self, name: str) -> None:
        self.__name: str = name

    def get_name(self) -> str:
        return self.__name

teacher1 = Teacher("Sharma Sir")
student1 = Student("Rahul")

teacher1.teach(student1)
