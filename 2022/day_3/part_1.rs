use std::collections::HashSet;

fn main() {
    let input = include_str!("input.txt");
    let mut sum = 0;
    for line in input.lines() {
        let (first, second) = line.split_at(line.len()/2);
        let first_set: HashSet<char> = first.chars().collect();
        let second_set: HashSet<char> = second.chars().collect();
        let intersected = *first_set.intersection(&second_set).next().unwrap() as u8;
        sum += 1 + intersected as i32 - if intersected >= ('A' as u8) && intersected <= ('Z' as u8) { 'A' as i32 - 26 } else { 'a' as i32 };
    }
    println!("{}", sum);
}