import sys
class Error(Exception):
    """Base class for exceptions in this module."""
    pass
# 自定义异常
class InputError(Error):
    """Exception raised for errors in the input.
    Attributes:
    expression -- input expression in which the error occurred
    message -- explanation of the error
    """
    def __init__(self, expression, message):
        self.expression = expression
        self.message = message
try:
    print('code start running...')
    raise InputError('input()', 'input error')
    # ValueError
    int('a')
    # TypeError
    s = 1 + 'a'
    dit = {'name': 'john'}
    # KeyError
    print(dit['1'])
except InputError as ex:
    print("InputError:", ex.message)
except TypeError as ex:
    print('TypeError:', ex.args)
    pass
except (KeyError, IndexError) as ex:
    """支持同时处理多个异常, 用括号放到元组里"""
    print(sys.exc_info())
except:
    """捕获其他未指定的异常"""
    print("Unexpected error:", sys.exc_info()[0])
    # raise 用于抛出异常
    raise RuntimeError('RuntimeError')
else:
    """当无任何异常时, 会执行 else 子句"""
    print('"else" 子句...')
finally:
    """无论有无异常, 均会执行 finally"""
    print('finally, ending')

'''
code start running...
InputError: input error
finally, ending
'''



