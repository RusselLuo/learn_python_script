class cat_feeder:
    def __init__(self, volume, times=1):
        self.__vol = volume
        self.__t = times

    @property
    def volume(self):
        return self.__vol

    @volume.setter
    def volume(self, v):
        self.__vol = v

    @property
    def times(self):
        return self.__t

    @times.setter
    def times(self, t):
        self.__t = t
