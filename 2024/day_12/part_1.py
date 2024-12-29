with open('input.txt', 'r') as f:
    matrix = f.read().splitlines()
    matrix = [list(row) for row in matrix]


def is_out_of_bounds(x, y):
    return not (0 <= x < len(matrix[0]) and 0 <= y < len(matrix))


def calculate_region_cost(x, y):
    fences = 0
    current_region = matrix[y][x]
    queue = [(x, y)]
    visited = set()
    size = 0

    while queue:
        current_x, current_y = queue.pop(0)

        if (current_x, current_y) in visited:
            continue

        if is_out_of_bounds(current_x, current_y) or matrix[current_y][current_x] != current_region:
            fences += 1
            continue

        visited.add((current_x, current_y))

        matrix[current_y][current_x] = ''
        size += 1

        for dx, dy in ((0, 1), (1, 0), (0, -1), (-1, 0)):
            queue.append((current_x + dx, current_y + dy))

    return size, fences


def main():
    s = 0
    for y in range(len(matrix)):
        for x in range(len(matrix[y])):
            region = matrix[y][x]
            if not region:
                continue
            size, fences = calculate_region_cost(x, y)
            s += size * fences
            print(region, size, fences)
    print(s)


if __name__ == '__main__':
    main()
