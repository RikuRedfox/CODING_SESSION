class Employee:
    def __init__(self, name, salary, project, timeline) -> None:
        self.name = name;
        self.__salary = salary
        self._project = project
        self._timeline = timeline
        
    def show(self):
        print(f"Name: {self.name}\nSalary: {self.__salary}")
        return self
        
    def work(self):
        print(f"{self.name} is doing the project {self._project}")
        return self
    
    def timeline(self):
        print(f"{self._timeline}")
        return self
        
emp1 = Employee("Yes", 100_000, "No", "F")
print(f"{emp1._Employee__salary}")
empl = []
empl.append(Employee("Andrew Jules", 200_000_000, "NLP pitch", "T W F"))
empl.append(Employee("Miguel", 500_000_000, "Sleep", "M T S"))
for i in empl:
    i.work().show().timeline()