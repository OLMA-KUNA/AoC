# Task 2
import copy
def findJmpNop(commands, counter):
    counterIntern = 0
    position = 0
    if counter <= 0:
        print('counter to small')
        return -1
    for ele in commands:
        if (ele.name == 'jmp' or ele.name == 'nop'):
            counterIntern += 1
        if (counterIntern >= counter):
            return position
        position += 1
    print('nothing found')
    return -1


class Instruction:
    def __init__(self, name, value):
        self.name = name
        self.value = value
        self.visited = False


# code starts here

file = open('day_8_input.txt')

commands_org = []

for line in file:
    a = line.split()
    commands_org.append(Instruction(a[0], int(a[1])))

resultFound = False
nextFound = 0
#commands = []

while (not (resultFound)):
    nextFound += 1
    print(nextFound)
    #commands.clear()
    commands = copy.deepcopy(commands_org)

    nextFoundPos = findJmpNop(commands, nextFound)
    if (nextFoundPos == -1):
        print("not solveable")
        break
    if (commands[nextFoundPos].name == "jmp"):
        commands[nextFoundPos].name = "nop"
    elif commands[nextFoundPos].name == "nop":
        commands[nextFoundPos].name = "jmp"
    else:
        print('false position', nextFoundPos, commands[nextFoundPos].name)
        break
    count = 0
    result = 0
    resultFound = True
    while (len(commands) > count):
        if commands[count].visited != True:
            commands[count].visited = True
        else:
            resultFound = False
            break
        if commands[count].name == 'acc':
            result += commands[count].value
            count += 1
            #print("acc", count)
        elif commands[count].name == 'jmp':
            count += commands[count].value
        elif commands[count].name == 'nop':
            count += 1
        else:
            print("Ooops")
    print(len(commands), count)
    #    resultFound = False
        #    break

print(result)
print(nextFoundPos)
# print(entry.value)