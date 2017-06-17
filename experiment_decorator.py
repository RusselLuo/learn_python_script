'''def zsq(func):
    def nei():
        print('我在传入的函数执行之前做一些操作')
        ret = func()  # 执行函数
        print('我在目标函数执行后再做一些事情')
        return ret
    return nei


@zsq  # 自动将其下面的函数作为参数传到装饰函数中去
def login():
    print('我进行了登录功能')
    return '函数返回值'


print(login())'''
#====================================================================


def ex(arg):
    def helper(func):
        def oh():
            print('before entering the function')
            print('and the argument', arg, 'was passed into the decorator')
            ret = func()
            print('after entering the function')
            return ret
        return oh
    return helper


@ex(123)
def wrapped():
    print('executing the wrapped function')
    return 'return value'


wrapped()
