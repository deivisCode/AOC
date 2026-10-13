use std::fs;

// funcion para validar na primeira parte do problema
// fn invalida(id: &str) -> bool {
//     let lonxitude: usize = id.len();
//     if lonxitude % 2 != 0 { return false } // número impar de caracteres, non pode ser
//     let metade_1: &str = &id[..lonxitude/2];
//     let metade_2: &str = &id[lonxitude/2..];
//     return metade_1 == metade_2
// }

fn invalida(id: &str) -> bool {
    let lonxitude: usize = id.len();
    // subsecuencias posibles
    // 1234 -> [1, 12, 123, 1234]
    let mut secuencias: Vec<String> = Vec::new();
    let mut repetido: bool = false;

    for i in 1..lonxitude {
        secuencias.push((&id[..i]).to_string());
    }

    for sec in secuencias {
        let l: usize = sec.len();
        if (lonxitude % l) != 0 {
            repetido = false;
        } else {
            for i in 0..(lonxitude/l) {
                // sub secuencias do id, para comparar
                // 1 2 3 4 5 6 7 8
                // 1 2
                //     1 2
                //         1 2
                //             1 2
                let sid: &str = &id[i*l..i*l+l];
                repetido = sec == sid ;
                if !repetido { break }
            }
        }
        if repetido { return true }
    }
    false
}

fn main() {

    let input : String = fs::read_to_string("../input.txt")
        .expect("Non se puido ler");

    let rangos_ids: Vec<&str> = input.split(",").collect();
    let mut resultado: usize = 0;

    for rango in rangos_ids {

        let mut valores = rango.split("-");
        // (suspira...) o do manexar a propagación de erros e tipos con Rust...
        let primeiro: usize = valores.next().expect("algo foi mal").trim().parse::<usize>().unwrap();
        let ultimo  : usize = valores.next().expect("algo foi mal").trim().parse::<usize>().unwrap();
        for i in primeiro..ultimo+1 {
            if invalida(i.to_string().as_str()) { resultado = resultado + i; }
        }

    }

    println!("RESULTADO: {}", resultado);

}
