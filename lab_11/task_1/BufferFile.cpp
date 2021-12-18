#include "BufferFile.h"

BufferFile::BufferFile(std::string filePath) : filePath_(std::move(filePath)), file_(std::make_shared<std::fstream>()) {
    std::cout << "BufferFile constructor" << std::endl;
    file_->open(filePath_, std::fstream::out);
    file_->close();
}

void BufferFile::add(int a) {
    file_->open(filePath_, std::fstream::app);
    *file_ << a << std::endl;
    file_->close();
    std::cout << "Added: " << a << " to file" << std::endl;
}

void BufferFile::write() {
    file_->open(filePath_, std::fstream::in);
    std::string line;
    while (std::getline(*file_, line))
        std::cout << line << " ";
    std::cout << std::endl;
    file_->close();
}

BufferFile::~BufferFile() {
    std::cout << "BufferFile destructor" << std::endl;
}