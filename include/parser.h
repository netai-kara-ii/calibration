#ifndef PARSER_H
#define PARSER_H


#include <filesystem>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

// Local
#include "types.h"

namespace fs = std::filesystem;


using Format = Eigen::IOFormat;

// implementation sucks but i refuse to do it again.

class Parser {

    // Read/write eigen arrays in csv files.
    // By default assumes data is always sourced from or written to "data".

    public:
        Parser(std::string data = "data");
        ~Parser(void) = default;

        void save(std::string savePath, const Array<float> &arr);
        array read(std::string readPath);

    private:
        fs::path cwd; 
        fs::path data;
};

#endif // PARSER_H
