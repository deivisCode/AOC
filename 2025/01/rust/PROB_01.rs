#![allow(unused)]

use std::fs;

#[derive(PartialEq)]
enum Dir { L, R }

struct Rotacion {
    dir: Dir,
    clicks: i32
}

fn main()
{
    let rotacions: String = fs::read_to_string("../input.txt")
        .expect("Non se puido ler");

    let mut novo: i32 = 50;
    let mut pases: i32 = 0;
    let mut d_0: i32 = 0;

    for linha in rotacions.lines()
    {

        let rot = Rotacion
        {
            dir    : if linha[0..1] == *"L" { Dir::L } else { Dir::R },
            clicks : linha[1..].parse::<i32>().unwrap(),
        };

        match rot.dir {
            Dir::L => {
                d_0 = if novo != 0 { novo } else { 100 };
                novo = (novo + (100 - (rot.clicks % 100))) % 100;
                if (rot.clicks >= d_0)
                {
                    pases = pases + 1 + ((rot.clicks - d_0) / 100);
                }
            },
            Dir::R => {
                d_0 = (100 - novo);
                novo = (novo + rot.clicks) % 100;
                if (rot.clicks >= d_0) {
                    pases = pases + 1 + ((rot.clicks - d_0) / 100);
                }
            }
        }

    }

    println!("RESULTADO {}", pases);

}
