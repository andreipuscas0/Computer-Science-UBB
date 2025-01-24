import pickle


class DataRepo:

    def __init__(self):
        self.dishes = []

    def add(self, dish):
        self.dishes.append(dish)
        print(self.dishes)

    def delete(self, identification):
        for dish in self.dishes:
            if dish.identification == identification:
                self.dishes.remove(dish)

    def update(self, identification, new_price=None, new_size=None, new_time=None):
        for dish in self.dishes:
            if dish.identification == identification:
                if new_price is not None:
                    dish.price = new_price
                if new_size is not None:
                    dish.size = new_size
                if new_time is not None:
                    dish.time = new_time


class FileDataRepo(DataRepo):
    def __init__(self, datei="data.txt"):
        super().__init__()
        self.datei = datei
        self.load()
        self.data = []

    def add(self, data):
        super().add(data)
        self.save()

    def save(self, saved_data=None):
        if saved_data is not None:
            self.data = saved_data
        try:
            with open(self.datei, 'wb') as f:
                pickle.dump(self.data, f)
        except Exception as e:
            print(f"eroare la salvare in fișierul {self.datei}: {e}")

    def load(self):
        try:
            with open(self.datei, 'rb') as f:
                self.data = pickle.load(f)
        except (EOFError, FileNotFoundError):
            self.data = []

        return self.data


class CookedDishRepo(FileDataRepo):

    def __init__(self, datei="cooked_dishes.txt"):
        super().__init__(datei)

    def convert_to_string(self, data):
        pass

    def convert_from_string(self, data_string):
        pass


class DrinkRepo(FileDataRepo):
    def __init__(self, datei="drinks.txt"):
        super().__init__(datei)

    def convert_to_string(self, data):
        pass

    def convert_from_string(self, data_string):
        pass


class CustomerRepo(FileDataRepo):
    def __init__(self, datei="customers.txt"):
        super().__init__(datei)

    def convert_to_string(self, data):
        pass

    def convert_from_string(self, data_string):
        pass


class OrderRepo(FileDataRepo):
    def __init__(self, datei="orders.txt"):
        super().__init__(datei)

    def convert_to_string(self, data):
        pass

    def convert_from_string(self, data_string):
        pass


class IdentifyRepo(FileDataRepo):
    def __init__(self, datei="ids.txt"):
        super().__init__(datei)

    def convert_to_string(self, data):
        pass

    def convert_from_string(self, data_string):
        pass
