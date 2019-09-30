class Money:
    currency_rates = {
    '$': 1,
    '€': 0.88,
    }
    def __init__(self, symbol, amount):
        self.symbol = symbol
        self.amount = amount
    def __repr__(self):
        return '%s%.2f' % (self.symbol, self.amount)
    def convert(self, other):
        """ Convert other amount to our currency """
        new_amount = (
        other.amount / self.currency_rates[other.symbol]
        * self.currency_rates[self.symbol])
        return Money(self.symbol, new_amount)
    def __add__(self, other):
        """ Add 2 Money instances using '+' """
        new_amount = self.amount + self.convert(other).amount
        return Money(self.symbol, new_amount)
soda_cost = Money('$', 5.25)
print(soda_cost)

pizza_cost = Money('€', 7.99)
print(pizza_cost)
print(soda_cost + pizza_cost)
print(pizza_cost + soda_cost)
'''
$5.25
€7.99
$14.33
€12.61
'''

# 在字典中通过索引或键来获得一项，其实是使用了 __getitem__ 方法
d = {'one': 1, 'two': 2}
print(d['two'])
print(d.__getitem__('two'))
'''
2
2'''

# 一些魔术方法甚至映射到内置函数，例如 __len__() 映射到 len()。
class Alphabet:
    letters = 'ABCDEFGHIJKLMNOPQRSTUVWXYZ'
    def __len__(self):
        return len(self.letters)
my_alphabet = Alphabet()
print(len(my_alphabet))
# 26

'''
自定义迭代器
要成为一个可迭代对象，一个类需要实现 __iter__()
__iter__() 方法需要返回一个迭代器
要成为一个迭代器，一个类需要实现 __next__()（或 在 Python 2 中是 next()），
当没有更多的项要迭代时，必须抛出一个 StopIteration 异常。
'''
class IterableServer:

    def __init__(self):
        self.services = [
        {'active': False, 'protocol': 'ftp', 'port': 21},
        {'active': True, 'protocol': 'ssh', 'port': 22},
        {'active': True, 'protocol': 'http', 'port': 80},
        ]
        self.current_pos = 0 # 我们初始化当前位置为 0
    def __iter__(self): # 我们可以在这里返回 self，因为实现了 __next__
        return self
    def __next__(self):
        while self.current_pos < len(self.services):
            service = self.services[self.current_pos]
            self.current_pos += 1
            if service['active']:
                return service['protocol'], service['port']
        raise StopIteration
        next = __next__ # 可选的 Python2 兼容性

for protocol, port in IterableServer():
    print('service %s is running on port %d' % (protocol, port))
'''
service ssh is running on port 22
service http is running on port 80'''


# 在这样类似的实例中，我们的迭代器不需要维护大量的状态，
# 我们可以简化代码并使用 generator（生成器） 来代替。
class Server:
    services = [
    {'active': False, 'protocol': 'ftp', 'port': 21},
    {'active': True, 'protocol': 'ssh', 'port': 22},
    {'active': True, 'protocol': 'http', 'port': 80},
    ]
    def __iter__(self):
        for service in self.services:
            if service['active']:
                yield service['protocol'], service['port']

for protocol, port in Server():
    print('service %s is running on port %d' % (protocol, port))

'''
service ssh is running on port 22
service http is running on port 80'''


class Dog:
    sound = 'Bark'
    def speak(self):
        print(self.sound + '!', self.sound + '!')
fido = Dog()
print(fido.sound)
print(getattr(fido, 'sound'))
fido.speak()
print(getattr(fido, 'speak'))
speak_method = getattr(fido, 'speak')
speak_method()
'''
Bark
Bark
Bark! Bark!
<bound method Dog.speak of <__main__.Dog object at 0x022E5DF0>>
Bark! Bark!'''

class Operations:
    def say_hi(self, name):
        print('Hello,', name)
    def say_bye(self, name):
        print ('Goodbye,', name)
    def default(self, arg):
        print ('This operation is not supported.')
if __name__ == '__main__':
    operations = Operations()
    # 假设我们做了错误处理
    command, argument = input('> ').split()
    func_to_call = getattr(operations, command, operations.default)
    func_to_call(argument)
'''
> say_hi Nina
Hello, Nina'''



