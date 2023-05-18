#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <memory>

#include <libxml/parser.h>
#include <libxml/tree.h>
#include <libxml/HTMLparser.h>

std::string readFileContents(const std::string& filePath) {
    std::ifstream file(filePath);
    if (!file) {
        throw std::runtime_error("Failed to open file: " + filePath);
    }

    std::ostringstream contents;
    contents << file.rdbuf();
    return contents.str();
}

void convertXmlToHtmlTable(const std::string& xmlCode, const std::string& outputFilePath) {
    // Initialize the XML library
    xmlInitParser();

    // Parse the XML code
    xmlDocPtr doc = xmlReadMemory(xmlCode.c_str(), xmlCode.length(), nullptr, nullptr, XML_PARSE_RECOVER);
    if (doc == nullptr) {
        std::cerr << "Failed to parse XML" << std::endl;
        xmlCleanupParser();
        return;
    }

    // Create the HTML table structure
    xmlNodePtr rootNode = xmlDocGetRootElement(doc);
    xmlNodePtr cdNode = rootNode->children;

    std::ofstream outputFile(outputFilePath);
    if (!outputFile) {
        std::cerr << "Failed to open the output file" << std::endl;
        xmlFreeDoc(doc);
        xmlCleanupParser();
        return;
    }

    outputFile << "<table>" << std::endl;

    // Process each CD element
    while (cdNode != nullptr) {
        outputFile << "  <tr>" << std::endl;

        // Process each child element of CD
        xmlNodePtr childNode = cdNode->children;
        while (childNode != nullptr) {
            std::string elementName(reinterpret_cast<const char*>(childNode->name));
            std::string elementValue(reinterpret_cast<const char*>(xmlNodeGetContent(childNode)));

            outputFile << "    <td>" << elementValue << "</td>" << std::endl;

            childNode = childNode->next;
        }

        outputFile << "  </tr>" << std::endl;

        cdNode = cdNode->next;
    }

    outputFile << "</table>" << std::endl;

    // Cleanup
    xmlFreeDoc(doc);
    xmlCleanupParser();

    std::cout << "Conversion completed. HTML table saved to: " << outputFilePath << std::endl;
}

int main(int argc, char* argv[]) {
    if (argc < 3) {
        std::cerr << "Use: " << argv[0] << " <cd_catalog.xml> <output_html_file>" << std::endl;
        return 1;
    }

    std::string xmlFilePath(argv[1]);
    std::string outputFilePath(argv[2]);

    try {
        std::string xmlCode = readFileContents(xmlFilePath);
        convertXmlToHtmlTable(xmlCode, outputFilePath);
    } catch (const std::exception& ex) {
        std::cerr << "Error: " << ex.what() << std::endl;
        return 1;
    }

    return 0;
}
