#include "schedular.hpp"
#include <iostream>
#include <iomanip>

int main(int argc, char* argv[])
{
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " <program_file>\n";
        return 1;
    }

    std::string program_file = argv[1];
    schedular s;

    s.load_program(program_file);

    std::cout << "==== Program Queue Binary Dump ====\n";
    s.dump_program_queue_binary();
    std::cout << "==== End of Dump ====\n";

    return 0;
}