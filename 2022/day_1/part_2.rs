fn main() {
    let input = include_str!("input.txt");
    let mut current_sum = 0;
    let mut sums = vec![0];
    for line in input.lines() {
        if line.is_empty() {
            sums.push(current_sum);
            current_sum = 0;
            continue;
        }
        current_sum += line.parse::<i32>().unwrap();
    }
    sums.push(current_sum);
    sums.sort_by(|a, b| b.cmp(a));

    println!("{}", sums[0] + sums[1] + sums[2]);
}