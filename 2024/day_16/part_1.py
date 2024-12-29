with open('input.txt', 'r') as f:
    maze = f.read().splitlines()

DIRECTIONS = ((0, 1), (1, 0), (0, -1), (-1, 0))


def is_wall(x, y):
    return x < 0 or y < 0 or x >= len(maze[0]) or y >= len(maze) or maze[y][x] == '#'


def is_fork(x, y):
    if is_wall(x, y):
        return False

    for x_offset in (-1, 1):
        for y_offset in (-1, 1):
            if not is_wall(x + x_offset, y) and not is_wall(x, y + y_offset):
                return True
    return False


def is_start_or_end(x, y):
    return maze[y][x] == 'S' or maze[y][x] == 'E'


def is_valid_point(x, y):
    return not is_wall(x, y) and (is_fork(x, y) or is_start_or_end(x, y))


def find_path(graph, start, end):
    visited = set()
    queue = [(start, 0, 'none')]
    optimal_distances = {start: 0}

    while queue:
        queue = sorted(queue, key=lambda x: x[1])
        current, distance, direction = queue.pop(0)
        visited.add(current)

        if current == end:
            break

        for nx, ny, ndistance in graph[current]:
            neighbour_pos = (nx, ny)
            if neighbour_pos in visited:
                continue

            new_direction = 'none'
            if nx != current[0]:
                new_direction = 'horizontal'
            elif ny != current[1]:
                new_direction = 'vertical'

            new_distance = distance + ndistance + (1000 if new_direction != direction and direction != 'none' else 0)
            if neighbour_pos not in optimal_distances or new_distance < optimal_distances[neighbour_pos]:
                optimal_distances[neighbour_pos] = new_distance
                queue.append((neighbour_pos, new_distance, new_direction))

    return optimal_distances[end]


def main():
    corners = set([(x, y) for y in range(len(maze)) for x in range(len(maze[0])) if is_valid_point(x, y)])
    # for x, y in corners:
    #     maze[y] = maze[y][:x] + '-' + maze[y][x + 1:]
    # print('\n'.join(maze))
    # print(len(corners), corners)

    graph = {}
    start, end = None, None

    for x, y in corners:
        if maze[y][x] == 'S':
            start = (x, y)
        elif maze[y][x] == 'E':
            end = (x, y)
        graph[(x, y)] = []
        for dx, dy in DIRECTIONS:
            cx, cy = x, y
            while not is_wall(cx + dx, cy + dy):
                cx += dx
                cy += dy
                if (cx, cy) in corners:
                    distance = abs(cx - x) + abs(cy - y)
                    graph[(x, y)].append((cx, cy, distance))

    # print(graph)

    result = find_path(graph, start, end)
    print(result)


if __name__ == '__main__':
    main()
