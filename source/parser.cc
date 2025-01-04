// Local
#include "utils/parser.h"


Parser::Parser(std::string data_directory) {
    cwd = fs::current_path();
    data = cwd / data_directory;

    // Resolve directory tree.
    if (!fs::exists(data_directory)) {
        fs::create_directories(data_directory);
    }
}

void Parser::save(std::string save_path, const Array<float> &arr) {
    fs::path file_path = data / save_path;
    std::ofstream file(file_path);

    // Declare eigen format (csv).
    Format csv(
        Eigen::FullPrecision, Eigen::DontAlignCols, ", ", "\n"
    ); 

    if (file.is_open()) {
        // Pipe array to file.
        file << arr.format(csv);
        file.close();
    } else {
        std::cerr << "Failed to open file @ " << filePath << std::endl;
    }
}

array Parser::read(std::string readPath) {
    // Expects readPath to contain file extension.
    fs::path filePath = _dataDirectory / readPath;
    std::ifstream file(filePath);

    if (!file.is_open()) {
        std::cerr << "Failed to open file @ " << filePath << std::endl;
        return array();
    }

    std::string matrixRowStr, matrixEntriesStr;
    std::vector<double> matrixEntries;
    unsigned int matrixRowCount = 0;

    while (getline(file, matrixRowStr)) {
        std::stringstream matrixRowStrStream(matrixRowStr);
        while (getline(matrixRowStrStream, matrixEntriesStr, ',')) {
            matrixEntries.push_back(std::stod(matrixEntriesStr)); 
        }
        
        matrixRowCount++;
    }

    if (matrixRowCount == 0) {
        std::cerr << "Empty file @ " << filePath << std::endl;
        return array();
    }

    return Eigen::Map<array>(matrixEntries.data(), matrixRowCount, 
        matrixEntries.size() / matrixRowCount);
}
