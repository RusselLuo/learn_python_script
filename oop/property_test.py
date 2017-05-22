class Dog:
    def __init__(self):
        self.__type = 'unknown'
        """set the type value as private value"""

    @property
    def type(self):
        return self.__type
        """property of type, get method of type"""

    @type.setter
    def type(self, t):
        if not isinstance(t, str):
            raise ValueError('type should be a string')
        self.__type = t
# set method of type

    def __str__(self):
        return "This dog is a %s" % self.__type
    __repr__ = __str__
