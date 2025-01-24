from functools import reduce

class Identify:
    def __init__(self, identification):
        self.identification = identification


class Dish(Identify):
    def __init__(self, identification, size, price):
        super().__init__(identification)
        self.size = size
        self.price = price


class CookedDish(Dish):
    def __init__(self, identification, size, price, time):
        super().__init__(identification, size, price)
        self.time = time


class Drink(Dish):
    def __init__(self, identification, size, price, abv):
        super().__init__(identification, size, price)
        self.abv = abv


class Customer(Identify):
    def __init__(self, identification, name, address):
        super().__init__(identification)
        self.name = name
        self.address = address


class Order(Identify):
    def __init__(self, identification, customer_id, dish_id, drink_id, costs):
        super().__init__(identification)
        self.customer_id = customer_id
        self.dish_id = [dish_id]
        self.drink_id = [drink_id]
        self.costs = costs


    def calculate_cost(self, dishes, drinks):
        dish_prices = [dish.price for dish in dishes if dish.identification in self.dish_id]
        drink_prices = [drink.price for drink in drinks if drink.identificaton in self.drink_id]
        dish_cost = reduce(lambda x, y: x + y, dish_prices, 0)
        drink_cost = reduce(lambda x, y: x + y, drink_prices, 0)
        return dish_cost + drink_cost


    def generate_invoice_string(self, dishes, drinks):
        dish_names = [dish.identification for dish in dishes if dish.identification in self.dish_id]
        drink_names = [drink.identification for drink in drinks if drink.identification in self.drink_id]
        invoice_string = f"Customer ID: {self.customer_id}\n"
        invoice_string += "Preparatul comandat: " + ", ".join(map(str, dish_names)) + "\n"
        invoice_string += "Băutura comandată: " + ", ".join(map(str, drink_names)) + "\n"
        invoice_string += f"Costuri totale: {self.costs} lei\n"
        return invoice_string

