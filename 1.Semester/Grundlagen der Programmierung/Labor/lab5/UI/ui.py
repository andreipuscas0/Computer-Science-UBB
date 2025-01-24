from Repository.repository import (FileDataRepo, CookedDishRepo, OrderRepo, CustomerRepo, DrinkRepo, IdentifyRepo)
from Controller.controller import (Controller)


class UI:
    def __init__(self):
        self.controller = Controller(
            repo=FileDataRepo(),
            id_repo=IdentifyRepo("ids.txt"),
            cooked_dish_repo=CookedDishRepo("cooked_dishes.txt"),
            drink_repo=DrinkRepo("drinks.txt"),
            customer_repo=CustomerRepo("customers.txt"),
            order_repo=OrderRepo("orders.txt")
        )

    def display_menu(self):
        print("**********")
        print("1. Manage Customers")
        print("2. Manage Orders")
        print("3. Manage Menu")
        print("0. Exit")

    def display_customers(self, customers):
        if customers:
            print("Clienți găsiți: ")
            for customer in customers:
                print(f"{customer.identification}. {customer.name} - {customer.address}")
        else:
            print("Niciun client găsit")

    def update_customer_name(self):
        customer_id = input("Introdu ID-ul clientului: ")
        new_name = input("Introdu noul nume pentru client: ")
        self.controller.update_customer_name(customer_id, new_name)
        print("Numele clientului a fost actualizat")

    def genereaza_factura_string(self, order_id):
        order = self.controller.search_order_by_id(order_id)
        if order:
            dishes = self.controller.cooked_dish_repo.load()
            drinks = self.controller.drink_repo.load()

            costs = order[0].calculate_cost(dishes, drinks)

            if costs is not None:
                invoice_string = order[0].generate_invoice_string(dishes, drinks)
                print(invoice_string)
                print(f"Factura pentru comanda nr {order_id}, in valoare de: {costs} lei.")
                print("Vă mulțumim!")
        else:
            print(f"Comanda cu ID-ul {order_id} nu a fost găsită.")
