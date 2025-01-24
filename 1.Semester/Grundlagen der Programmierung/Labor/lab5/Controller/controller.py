from Repository.repository import (FileDataRepo, CookedDishRepo, OrderRepo, CustomerRepo, DrinkRepo, IdentifyRepo)

class Controller:
    def __init__(self, repo: FileDataRepo, id_repo: IdentifyRepo, cooked_dish_repo: CookedDishRepo,
                 drink_repo: DrinkRepo, customer_repo: CustomerRepo, order_repo: OrderRepo):

        self.repo = repo
        self.cooked_dish_repo = cooked_dish_repo
        self.drink_repo = drink_repo
        self.customer_repo = customer_repo
        self.order_repo = order_repo
        self.id_repo = id_repo
        self.customers = self.customer_repo.load()
        self.orders = self.order_repo.load()

    def add_cooked_dish(self, dish):
        dishes = self.cooked_dish_repo.load()
        dishes.append(dish)
        self.cooked_dish_repo.save()

    def add_drink(self, drink):
        drinks = self.drink_repo.load()
        drinks.append(drink)
        self.drink_repo.save()

    def add_customer(self, customer):
        customers = self.customer_repo.load()
        customers.append(customer)
        self.customer_repo.save()

    def add_order(self, order):
        orders = self.order_repo.load()
        orders.append(order)
        self.order_repo.save()

    def add_id(self, identification):
        number = self.id_repo.load()
        number.append(identification)
        self.id_repo.save()

    def search_customer_by_name(self, name):
        return list(filter(lambda c: name.lower() in c.name.lower(), self.customers))

    def search_customer_by_address(self, address):
        return list(filter(lambda c: address.lower() in c.address.lower(), self.customers))

    def search_customer_by_id(self, identification):
        return list(filter(lambda c: c.identification == identification, self.customers))

    def search_order_by_id(self, identification):
        for order in self.orders:
            if order.identification == identification:
                return [order]
        return []

    def update_customer_name(self, customer_id, new_name):
        if not self.customers:
            self.customers = self.customer_repo.load()
        found = False

        for customer in self.customers:
            if str(customer.identification) == str(customer_id):
                customer.name = new_name
                found = True
        if found:
            self.customer_repo.save(self.customers)
        else:
            print("Nu există client cu id-ul dat")