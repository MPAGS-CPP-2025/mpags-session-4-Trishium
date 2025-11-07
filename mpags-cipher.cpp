#include <cctype>
#include <iostream>
#include <string>
#include <vector>

int main(int argc, char* argv[])
{

    const std::vector<std::string> cmdLineArgs { argv, argv+argc };
    bool help{false};
    bool version{false};
    std::string input_file{""};
    bool input_given(false);
    bool output_given(false);
    std::string output_file{""};
    for (int i{0}; i < argc; i++){
        
        if (cmdLineArgs[i][0] == '-'){
            if (cmdLineArgs[i] == "-h" || cmdLineArgs[i] == "--help"){
                help = true;
            }
            else if (cmdLineArgs[i] == "-v" || cmdLineArgs[i] == "--version"){
                version = true;
            }
            else if (cmdLineArgs[i] == "-i"){
                if (i == argc-1){
                    std::cout << "ERROR: Missing input file parameter" << std::endl;
                    return 1;
                }
                else if (cmdLineArgs[i+1][0] == '-'){
                    std::cout << "ERROR: Missing input file parameter" << std::endl;
                    return 1;
                }
                else if (input_given){
                    std::cout << "ERROR: Input file given more than once" << std::endl;
                    return 1;
                }
                else {
                    input_file = cmdLineArgs[i+1];
                    input_given = true;
                    i++;
                }
            }
            else if (cmdLineArgs[i] == "-o"){
                if (i == argc-1){
                    std::cout << "ERROR: Missing output file parameter" << std::endl;
                    return 1;
                }
                else if (cmdLineArgs[i+1][0] == '-'){
                    std::cout << "ERROR: Missing output file parameter" << std::endl;
                    return 1;
                }
                else if (output_given){
                    std::cout << "ERROR: Output file given more than once" << std::endl;
                    return 1;
                }
                else {
                    output_file = cmdLineArgs[i+1];
                    output_given = true;
                    i++;
                }
            }
            else if (i < argc-1){
                if (cmdLineArgs[i+1][0] != '-'){
                    std::cout << cmdLineArgs[i+1] << std::endl;
                    i++;
                }
            }  
        }
        else{
            std::cout << cmdLineArgs[i] << std::endl;
        }

    }
    if (help){
        std::cout << "INFO: Welcome to the help mode for ./mpags-cipher\n\n"
        << "INFO: ./mpags-cipher is a program to encode and decode messages\n"
        << "INFO: Usage: ./mpags-cipher [-h -v] -i input-file -o output-file\n\n"
        << "INFO: Options:\n"
        << "INFO:     -h/--help: enter help mode\n"
        << "INFO:     -v/--version: prints the version number\n"
        << "INFO: end of help\n\n" 
        << std::endl;
        return 0;
    }
    if (version){
        std::cout << "INFO: Program version is 0.4" << std::endl;
    }
    if (input_file != ""){
        std::cout << "Input file name was passed\n"
        << "Will read input from " << input_file << " \n"
        << std::endl;
    }
    if (output_file != ""){
        std::cout << "Output file name was passed\n"
        << "Will write output to " << output_file << " \n"
        << std::endl;
    }
    // Initialise variables
    char c{'x'};
    std::string out_text;

    // loop over each character from user input
    while (std::cin >> c) {
        // Uppercase alphabetic characters
        if (std::isalpha(c)) {
            out_text += std::toupper(c);
            continue;
        }

        // Transliterate digits to English words
        switch (c) {
            case '0':
                out_text += "ZERO";
                break;
            case '1':
                out_text += "ONE";
                break;
            case '2':
                out_text += "TWO";
                break;
            case '3':
                out_text += "THREE";
                break;
            case '4':
                out_text += "FOUR";
                break;
            case '5':
                out_text += "FIVE";
                break;
            case '6':
                out_text += "SIX";
                break;
            case '7':
                out_text += "SEVEN";
                break;
            case '8':
                out_text += "EIGHT";
                break;
            case '9':
                out_text += "NINE";
                break;
        }

        // If the character isn't alphabetic or numeric, DONT add it
    }

    // Print out the transliterated text
    std::cout << out_text << std::endl;
}