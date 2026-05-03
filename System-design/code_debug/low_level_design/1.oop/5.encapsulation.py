class Bank:
    def __init__(self, name:str, balance: int):
        self.name = name
        # Private
        self.__balance = balance

   # Getter method
    def get_balance(self):
        print(f"Current balance = {self.__balance}\n") 

  # Setter method
    def set_balance(self, new_amount):
        self.__balance = new_amount
        print(f"Current balance = {self.__balance}\n")       

    def deposit(self, amount : int):
        self.__balance += amount
        print(f"Amount deposited, current balance = {self.__balance}\n")    

    def withdraw(self, amount: int):
        if amount > self.__balance:
            print("Not enought money in bank!\n")
        else:
            self.__balance -= amount
            print(f"Amount deposited, current balance = {self.__balance}\n")


acc = Bank("Abi", 1000)
acc.deposit(1000)
acc.__balance = 100000 # not accessable by outside
acc.get_balance() 
acc.withdraw(500)
acc.get_balance()
acc.set_balance(1000) 
acc.get_balance() 