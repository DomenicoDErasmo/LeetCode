// hack file to get this working on VS code
// perhaps this could be test entry point too

pub mod p520;

fn main() {
    println!("Hello, world!");

    let problem = p520::DetectCapital {};
    problem.detect_capital_use("test".to_string());
}
