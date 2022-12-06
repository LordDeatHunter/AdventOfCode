use std::collections::HashSet;

fn main() {
    let input = include_str!("input.txt");
    let mut sum = 0;
    for line in input.lines().collect::<Vec<&str>>().chunks(3) {
        let first_set: HashSet<char> = line[0].chars().collect();
        let second_set: HashSet<char> = line[1].chars().collect();
        let third_set: HashSet<char> = line[2].chars().collect();
        let first_intersection = first_set.intersection(&second_set).copied().collect::<HashSet<char>>();
        let intersected = *first_intersection.intersection(&third_set).next().unwrap() as u8;
        sum += 1 + intersected as i32 - if intersected >= ('A' as u8) && intersected <= ('Z' as u8) { 'A' as i32 - 26 } else { 'a' as i32 };
    }
    println!("{}", sum);
}