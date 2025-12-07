import math

def f(x):
    i = 8
    num = -i + x
    den = 2.5 * i + 1.0 / (i + x)
    part1 = num / den
    part2 = math.tanh(x) ** (i + 1)
    return part1 + part2

# запис у файл (у поточну папку, де дозволено запис)
x = -1.0
h = 0.1

f_out = open("data.txt", "w")
while x <= 1.0 + 1e-9:
    fx = f(x)
    f_out.write(str(x) + " " + str(fx) + "\n")
    x = round(x + h, 10)
f_out.close()

# читання файлу і пошук f(0)
f_in = open("data.txt", "r")
for line in f_in:
    parts = line.split()
    x_val = float(parts[0])
    y_val = float(parts[1])
    if abs(x_val) < 1e-9:
        print("f(0) =", y_val)
        break
f_in.close()
