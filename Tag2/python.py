# if __name__ == '__main__':
#     input = open('input.txt', 'r').readlines()
#     depth = 0
#     horizontal = 0

#     for line in input:
#         (direction, amount) = line.split(' ')
#         if direction == 'forward':
#             horizontal += int(amount)
#         elif direction == 'down':
#             depth += int(amount)
#         elif direction == 'up':
#             depth -= int(amount)

#     print(depth)
#     print(horizontal)
#     print(depth * horizontal)
if __name__ == '__main__':
    input = open('input.txt', 'r').readlines()
    depth = 0
    horizontal = 0
    aim = 0

    for line in input:
        (direction, amount) = line.split(' ')
        if direction == 'forward':
            horizontal += int(amount)
            depth += aim*int(amount)
        elif direction == 'down':
            aim += int(amount)
        elif direction == 'up':
            aim -= int(amount)

    print(depth)
    print(horizontal)
    print(depth * horizontal)
