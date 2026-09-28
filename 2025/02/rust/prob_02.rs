use std::fs;

fn invalida(id: &str) -> bool {
    let lonxitude: usize = id.len();
    if lonxitude % 2 != 0 { return false } // número impar de caracteres, non pode ser
    let metade_1: &str = &id[..lonxitude/2];
    let metade_2: &str = &id[lonxitude/2..];
    return metade_1 == metade_2
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
