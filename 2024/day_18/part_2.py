SIZE = 71

with open('input.txt', 'r') as f:
    points = f.read().splitlines()

DIRECTIONS = ((0, 1), (1, 0), (0, -1), (-1, 0))


def is_in_bounds(x, y):
    return 0 <= x < SIZE and 0 <= y < SIZE


def find_path(grid, start, end):
    visited = set()
    queue = [(start, 0)]
    optimal_distances = {start: 0}
    path = []

    while queue:
        queue = sorted(queue, key=lambda x: x[1])
        current, distance = queue.pop(0)
        visited.add(current)

        if current == end:
            break

        for dx, dy in DIRECTIONS:
            new_x, new_y = current[0] + dx, current[1] + dy
            new_distance = distance + 1
            new_point = (new_x, new_y)

            if not is_in_bounds(new_x, new_y) or grid[new_y][new_x] == '#' or new_point in visited or (
                    new_point in optimal_distances and new_distance >= optimal_distances[new_point]):
                continue

            optimal_distances[new_point] = new_distance
            queue.append((new_point, new_distance))
            path.append((new_point, new_distance))

    return optimal_distances[end]


def main():
    start, end = (0, 0), (SIZE - 1, SIZE - 1)

    matrix = ['.' * SIZE for _ in range(SIZE)]
    for i, point in enumerate(points):
        x, y = map(int, point.split(','))
        matrix[y] = matrix[y][:x] + '#' + matrix[y][x + 1:]

        try:
            result = find_path(matrix, start, end)
            print(f'{i} - {result}')
        except:
            print(f'No path found for {i}. Coords: {points[i]}')
            break


if __name__ == '__main__':
    main()
