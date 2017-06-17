def producer(i):
    def multi(a):
        return a**i
    print('produce a function to calculate exponation with index of', i)
    return multi


square = producer(2)
cube = producer(3)

print(square(2))
print(cube(2))
