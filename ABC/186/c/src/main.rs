fn check10(n: u32) -> bool {
    let mut flag = false;
    let mut x = n;
    while x != 0 {
        let ama = x % 10;
        if ama == 7 {
            flag = true;
        }
        x /= 10;
    } 
    flag
}

fn check8(n: u32) -> bool {
    let mut x = n;
    let mut flag = false;
    while x != 0 {
        let ama = x % 8;
        if ama == 7 {
            flag = true
        }
        x /= 8
    }
    flag
}

fn main() {
    let mut n = String::new();
    std::io::stdin().read_line(&mut n).unwrap();
    let mut n:u32 = n.trim().parse().ok().unwrap();
    for idx in 1..=n {
        if check10(idx) || check8(idx) {
            n -= 1;
        }
    }
    println!("{}", n);
}
