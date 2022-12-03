fn main() {
    let input = include_str!("input.txt");
    let mut score = 0;
    for line in input.lines() {
        let parts: Vec<u8> = line.split_whitespace().map(|s| s.as_bytes()[0]).collect();
        let first = (parts[0] - 'A' as u8 + 1) as i32;
        let mut second = (parts[1] - 'X' as u8 + 1) as i32;

        second = match second {
            1 if first - 1 < 1 => 3,
            1 => first - 1,
            2 => first,
            3 if first + 1 > 3 => 1,
            3 => first + 1,
            _ => second,
        };

        score += match second - first {
            1 | -2 => 6,
            0 => 3,
            _ => 0,
        } + second;
    }
    println!("{}", score);
}