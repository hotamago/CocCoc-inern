import os
import random
import sys

def bresenham(x0, y0, x1, y1):
    points = []
    dx = abs(x1 - x0)
    dy = abs(y1 - y0)
    sx = 1 if x0 < x1 else -1
    sy = 1 if y0 < y1 else -1
    err = dx - dy

    while True:
        points.append((x0, y0))
        if x0 == x1 and y0 == y1:
            break
        e2 = 2 * err
        if e2 > -dy:
            err -= dy
            x0 += sx
        if e2 < dx:
            err += dx
            y0 += sy
    return points

def process_commands(commands):
    grid = []
    current_pos = (0, 0)
    for line in commands:
        line = line.strip()
        if not line: 
            continue
        if line.startswith("DIMENSION"):
            parts = line.split()
            n = int(parts[1])
            grid = [['.' for _ in range(n)] for _ in range(n)]
        elif line.startswith("MOVE_TO"):
            _, coords = line.split()
            x, y = map(int, coords.split(','))
            current_pos = (x, y)
        elif line.startswith("LINE_TO"):
            _, coords = line.split()
            x, y = map(int, coords.split(','))
            points = bresenham(current_pos[0], current_pos[1], x, y)
            for px, py in points:
                grid[py][px] = '+'
            current_pos = (x, y)
    return grid

def gen_testcase():
    n = random.randint(100, 10000)
    commands = [
        f"DIMENSION {n}",
    ]
    num_commands = random.randint(1000, 5000)

    # Random choice of commands
    for _ in range(num_commands):
        command = random.choice(["MOVE_TO", "LINE_TO"])
        x = random.randint(0, n-1)
        y = random.randint(0, n-1)
        commands.append(f"{command} {x},{y}")
    return commands

def main():
    for i in range(20):
        i = i + 1
        if os.path.exists(f"testcases/{i}.in") and os.path.exists(f"testcases/{i}.out"):
            print(f"Skipping testcase_{i}")
        else:
            commands = None
            if not os.path.exists(f"testcases/{i}.in"):
                print(f"Generating testcase_{i}.in")
                with open(f"testcases/{i}.in", "w") as f:
                    commands = gen_testcase()
                    f.write("\n".join(commands))
            else:
                # Read the commands from the input file
                with open(f"testcases/{i}.in", "r") as f:
                    commands = f.readlines()
            
            # Process the commands and write the output to the output file
            if not os.path.exists(f"testcases/{i}.out"):
                print(f"Generating testcase_{i}.out")
                with open(f"testcases/{i}.out", "w") as f:
                    grid = process_commands(commands)
                    f.write("\n".join(" ".join(row) for row in grid) + "\n")

if __name__ == "__main__":
    main()
