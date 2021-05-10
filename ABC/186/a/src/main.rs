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
    let ipt:Vec<u32> = input();
    println!("{}", ipt[0] / ipt[1]);
}
