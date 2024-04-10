#include <iostream>
#include "Document.h"

int main() {
    // Test the Document class
    Document doc1;
    doc1.addString("Hello");
    doc1.addString("world");
    doc1.addString("!");

    std::cout << "Document 1: " << doc1 << std::endl;
    std::cout << "Total length of Document 1: " << doc1.getLength() << std::endl;

    // Test the copy constructor
    Document doc2(doc1);
    std::cout << "Document 2 (copy of Document 1): " << doc2 << std::endl;
    std::cout << "Total length of Document 2: " << doc2.getLength() << std::endl;

    // Add more strings to Document 2
    doc2.addString("This");
    doc2.addString("is");
    doc2.addString("a");
    doc2.addString("test.");

    std::cout << "Document 2 after adding more strings: " << doc2 << std::endl;
    std::cout << "Total length of Document 2: " << doc2.getLength() << std::endl;

    // Test chaining addString method
    Document doc3;
    doc3.addString("Chained").addString("addString").addString("method").addString("test.");

    std::cout << "Document 3 created using chained addString method: " << doc3 << std::endl;
    std::cout << "Total length of Document 3: " << doc3.getLength() << std::endl;

    // Test adding empty string
    Document doc4;
    doc4.addString("");
    std::cout << "Document 4 with empty string: " << doc4 << std::endl;
    std::cout << "Total length of Document 4: " << doc4.getLength() << std::endl;

    return 0;
}
