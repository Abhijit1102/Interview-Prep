"""
Attributes:
movie_name -> name of the movie
total_seats -> total seats available in the threate
ticket_price -> price per ticket
booked_seats -> start at 0

Methods:
book_ticket(num_ticket) - books the given number of tickets. If enough seat are available,
confirm the booking and show the toatl amount to pay. If not, show "Sorry,not enought seats available".

show_status() - displays movie name, seats availanle, and seats booked so far.

"""


class Movie:
    def __init__(self, movie_name: str, total_seats: int, ticket_price: int):
        self.movie_name = movie_name
        self.total_seats = total_seats
        self.ticket_price = ticket_price
        self.booked_seats = 0

    def book_tickets(self, num_of_tickets: int):
        available_seats = self.total_seats - self.booked_seats

        if num_of_tickets > available_seats:
            print("Sorry, not enough seats available!")
        else:
            self.booked_seats += num_of_tickets
            print("Your ticket is booked")
            print(f"Total price = {self.ticket_price * num_of_tickets}\n")

    def show_status(self) -> None:
        available_seats = self.total_seats - self.booked_seats
        print(f"Movie name : {self.movie_name}")
        print(f"Seats available: {available_seats}")
        print(f"Total Booked : {self.booked_seats}")


movie = Movie("krish", 100, 400)
movie.show_status()
movie.book_tickets(70)
movie.show_status()         