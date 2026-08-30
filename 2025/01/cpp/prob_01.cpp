#include <filesystem>
#include <fstream>
#include <iostream>
#include <print>

int main() {

    std::filesystem::path ruta("input.txt");
    std::fstream fstream;
    fstream.open(ruta, std::ios::in);
    if (!fstream.is_open()) {
        std::print("Non se abriu");
    }
    fstream.close();

    return 0;

}
