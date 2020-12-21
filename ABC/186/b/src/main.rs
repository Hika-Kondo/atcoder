fn input<T: std::str::FromStr>() -> Vec<T> {
    let mut s = String::new();
    std::io::stdin().read_line(&mut s).unwrap();
    s.trim().split_whitespace().map(|oppai| oppai.parse().ok().unwrap()).collect()
}

fn main() {
    let ipt: Vec<u32> = input(); let h = ipt[0]; let w = ipt[1];
    let mut a = Vec::<u32>::new();
    for i in 0..h {
        let tmp: Vec<u32> = input();
        for j in 0..(w as usize) {
            a.push(tmp[j]);
        }
    }

    let mut ans = 0;
    let mi = a.iter().min().unwrap();
    for item in a.iter() {
        ans += item - mi;
    }
    println!("{}", ans);
}
