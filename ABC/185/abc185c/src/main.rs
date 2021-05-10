fn input<T: std::str::FromStr>() -> Vec<T> {
    let mut s = String::new();
    std::io::stdin().read_line(&mut s).unwrap();
    s.trim().split_whitespace().map(|oppai| oppai.parse().ok().unwrap()).collect()
    // parse だとResult型 parseは任意の方に変換する
    // ok()でOptionに変更
    // unwrapでOkのみを取り出す
    // collectでiter -> Vec
}

fn main() {
    let l: Vec<u128> = input(); let l: u128 = l[0];
    let mut ans: u128 = 1;
    for idx in 0..11u128 {
        ans *= l - 1 - idx;
        ans /= idx + 1;
    }
    println!("{}", ans);
}
