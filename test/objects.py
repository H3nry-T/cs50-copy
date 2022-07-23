import



def main():
    henry = Student("Henry", 111)
    print(henry.name, henry.id)
    henry.changeID(50)
    print(henry.name, henry.id)



























class Student():
    def __init__(self, name, id):
        self.name = name
        self.id = id

    def changeID(self, id):
        self.id = id

    def print(self):
        print("{} - {}".format(self.name, self.id))



if __name__ == "__main__":
    main()