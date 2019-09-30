class Person:
    """人员信息"""
    # 姓名(共有属性)
    name = ''
    # 年龄(共有属性)
    age = 0
    
    def __init__(self, name='', age=0):
        self.name = name
        self.age = age
        
    # 重载专有方法: __str__
    def __str__(self):
        return "这里重载了 __str__ 专有方法, " + str({'name': self.name, 'age': self.age})
    def set_age(self, age):
        self.age = age
        
class Account:
    """账户信息"""
    # 账户余额(私有属性)
    __balance = 0
    # 所有账户总额
    __total_balance = 0
    
    # 获取账户余额
    # self 必须是方法的第一个参数
    def balance(self):
        return self.__balance
    
    # 增加账户余额
    def balance_add(self, cost):
        # self 访问的是本实例
        self.__balance += cost
        # self.__class__ 可以访问类
        self.__class__.__total_balance += cost
        
    # 类方法(用 @classmethod 标识，第一个参数为 cls)
    @classmethod
    def total_balance(cls):
        return cls.__total_balance
    
    # 静态方法(用 @staticmethod 标识，不需要类参数或实例参数)
    @staticmethod
    def exchange(a, b):
        return b, a
    
class Teacher(Person, Account):
    """教师"""
    # 班级名称
    _class_name = ''
    
    def __init__(self, name):
        # 第一种重载父类__init__()构造方法
        # super(子类，self).__init__(参数1，参数2，....)
        super(Teacher, self).__init__(name)
        
    def get_info(self):
        # 以字典的形式返回个人信息
        return {
        'name': self.name, # 此处访问的是父类Person的属性值
        'age': self.age,
        'class_name': self._class_name,
        'balance': self.balance(), # 此处调用的是子类重载过的方法
        }
    
    # 方法重载
    def balance(self):
        # Account.__balance 为私有属性，子类无法访问，所以父类提供方法进行访问
        return Account.balance(self) * 1.1

class Student(Person, Account):
    """学生"""
    _teacher_name = ''
    
    def __init__(self, name, age=18):
        # 第二种重载父类__init__()构造方法
        # 父类名称.__init__(self,参数1，参数2，...)
        Person.__init__(self, name, age)
    def get_info(self):
        # 以字典的形式返回个人信息
        return {
        'name': self.name, # 此处访问的是父类Person的属性值
        'age': self.age,
        'teacher_name': self._teacher_name,
        'balance': self.balance(),
        }
# 教师 John
john = Teacher('John')
john.balance_add(20)
john.set_age(36) # 子类的实例可以直接调用父类的方法
print("John's info:", john.get_info())

# 学生 Mary
mary = Student('Mary', 18)
mary.balance_add(18)
print("Mary's info:", mary.get_info())
# 学生 Fake
fake = Student('Fake')
fake.balance_add(30)
print("Fake's info", fake.get_info())
'''
John's info: {'name': 'John', 'age': 36, 'class_name': '', 'balance': 22.0}
Mary's info: {'name': 'Mary', 'age': 18, 'teacher_name': '', 'balance': 18}
Fake's info {'name': 'Fake', 'age': 18, 'teacher_name': '', 'balance': 30}
'''
# 三种不同的方式调用静态方法
print("john.exchange('a', 'b'):", john.exchange('a', 'b'))
print('Teacher.exchange(1, 2)', Teacher.exchange(1, 2))
print('Account.exchange(10, 20):', Account.exchange(10, 20))
'''
john.exchange('a', 'b'): ('b', 'a')
Teacher.exchange(1, 2) (2, 1)
Account.exchange(10, 20): (20, 10)
'''
# 类方法、类属性
print('Account.total_balance():', Account.total_balance())
print('Teacher.total_balance():', Teacher.total_balance())
print('Student.total_balance():', Student.total_balance())
# 重载专有方法
print(fake)
'''
Account.total_balance(): 0
Teacher.total_balance(): 20
Student.total_balance(): 48
这里重载了 __str__ 专有方法, {'name': 'Fake', 'age': 18}
'''








