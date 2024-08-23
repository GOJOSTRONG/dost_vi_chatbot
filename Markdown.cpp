#include <iostream>
#include <fstream>
#include <string>

void createMarkdown(const std::string &inputFile, const std::string &outputFile) {
    std::ifstream infile(inputFile);
    std::ofstream outfile(outputFile);

    if (!infile.is_open()) {
        std::cerr << "Error: Cannot open input file!" << std::endl;
        return;
    }

    if (!outfile.is_open()) {
        std::cerr << "Error: Cannot open output file!" << std::endl;
        return;
    }

    std::string line;
    while (std::getline(infile, line)) {
        // Process the line to convert it to Markdown format if necessary
        if (line.find("Sample Type:") != std::string::npos) {
            outfile << "### " << line << "\n\n";
        } else if (line.find("Test Service/Parameter:") != std::string::npos) {
            outfile << "- **" << line << "**\n";
        } else if (line.find("Test Method:") != std::string::npos) {
            outfile << "  - " << line << "\n";
        } else if (line.find("Fee Per Sample (Php):") != std::string::npos ||
                   line.find("Turnaround Time (Working Days):") != std::string::npos ||
                   line.find("Sample Requirement (Amount):") != std::string::npos ||
                   line.find("Sample Requirement (Container):") != std::string::npos) {
            outfile << "  - " << line << "\n";
        } else if (line.empty()) {
            outfile << "\n";
        }
    }

    infile.close();
    outfile.close();
}

int main() {
    std::string inputFile = "C:\Users\User\Desktop\DATASET (1).txt";  // Change this path to the input file
    std::string outputFile = "output.md";  // Output Markdown file

    createMarkdown(inputFile, outputFile);

    std::cout << "Markdown file created successfully: " << outputFile << std::endl;
    return 0;
}