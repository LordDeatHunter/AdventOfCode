fn main() {
    let input = include_str!("input.txt");
    let mut sum = 0;
    let mut max_sum = 0;
    for line in input.lines() {
        if line.is_empty() {
            max_sum = max_sum.max(sum);
            sum = 0;
            continue;
        }
        sum += line.parse::<i32>().unwrap();
    }
    println!("{}", max_sum.max(sum));
}