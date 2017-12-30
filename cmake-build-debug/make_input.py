from random import randint
f = open("input", "w")
for i in range(10000000):
    f.write(str(randint(0, 100000)) + "\n");
f.close()
