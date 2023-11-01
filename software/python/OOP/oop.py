class ElectronicDevice:
    def __init__(self, name, brand, price):
        self.name = name
        self.brand = brand
        self.price = price
        
    def turn_on(self):
        print(f"{self.name} is turned on.")
        
    def turn_off(self):
        print(f"{self.name} is turned off.")
        
class Smartphone(ElectronicDevice):
    def __init__(self, name, brand, price, os):
        super().__init__(name, brand, price)
        self.os = os
        
    def make_call(self):
        print("Making a call...")
        
    def send_message(self):
        print("Sending a message...")
        
class Laptop(ElectronicDevice):
    def __init__(self, name, brand, price, screen_size):
        super().__init__(name, brand, price)
        self.screen_size = screen_size
        
    def open_app(self):
        print("Opening an application...")
        
    def close_app(self):
        print("Closing an application...")        
        
class TV(ElectronicDevice):
    def __init__(self, name, brand, price, size):
        super().__init__(name, brand, price)
        self.size = size
        
    def change_channel(self):
        print("Changing the channel...")
        
    def adjust_volume(self):
        print("Adjusting the volume...")        
        
smartphone = Smartphone("iPhone", "Apple", 999, "iOS")
laptop = Laptop("MacBook Pro", "Apple", 1499, 13)
tv = TV("Samsung TV", "Samsung", 899, 50)

smartphone.turn_on()
laptop.turn_on()
tv.turn_on()

smartphone.make_call()
laptop.open_app()
tv.change_channel()

smartphone.turn_off()
laptop.turn_off()
tv.turn_off()