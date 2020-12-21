fn input<T: std::str::FromStr>() -> Vec<T> {
    let mut s = String::new();
    std::io::stdin().read_line(&mut s).unwrap();
    s.trim().split_whitespace().map(|e| e.parse().ok().unwrap()).collect()
    // parse だとResult型
    // ok()でOptionに変更
    // unwrapでOkのみを取り出す
    // collectでiter -> Vec
}


fn main() {
    let a: Vec<i32>= input();
    let n = a[0]; let m = a[1]; let t = a[2];
    let mut a = Vec::new(); let mut b = Vec::new();

    for _ in 0..m {
        let tmp : Vec<i32> = input();
        a.push(tmp[0]);
        b.push(tmp[1]);
    }

    let mut now_time : i32 = 0;
    let mut now_battery: i32 = n;
    let mut ans_flag: bool = true;
    // for (idx, tmp_a) in a.iter().enumerate() {
    for idx in 0..(m as usize) {
        let tmp_a = a[idx];
        let tmp_b = b[idx];
        now_battery -= tmp_a - now_time;
        // println!("before reach cafe {}", now_battery);
        if now_battery <= 0 {
            ans_flag = false;
        }
        now_battery += tmp_b - tmp_a;
        // println!("Now leave cafe {}", now_battery);
        if now_battery > n {
            now_battery = n;
        }
        now_time = tmp_b;
    }
    now_battery -= t - now_time;
    // println!("Go Home {}", now_battery);
    if now_battery <= 0 {
        ans_flag = false;
    }

    if ans_flag {
        println!("Yes");
    } else {
        println!("No");
    }

}
