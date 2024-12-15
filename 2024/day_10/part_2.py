with open('input.txt', 'r') as f:
    matrix = f.read().splitlines()
    matrix = [[int(c) if c.isnumeric() else -1 for c in line] for line in matrix]


def hike(ix, iy):
    s = 0

    if matrix[iy][ix] != 0:
        return s

    q = [(ix, iy, -1)]
    while q:
        x, y, prev_val = q.pop(0)

        if x < 0 or y < 0 or x >= len(matrix[0]) or y >= len(matrix) or matrix[y][x] != prev_val + 1:
            continue

        cur_val = matrix[y][x]

        if cur_val == 9:
            s += 1
            continue

        q.append((x, y + 1, cur_val))
        q.append((x, y - 1, cur_val))
        q.append((x + 1, y, cur_val))
        q.append((x - 1, y, cur_val))

    return s

def main():
    final = 0
    for y, row in enumerate(matrix):
        for x, cell in enumerate(row):
            if cell != 0:
                continue
            h = hike(x, y)
            final += h
            print(f"({x}, {y}):\t{h}")

    print(f"Final: {final}")

if __name__ == '__main__':
    main()