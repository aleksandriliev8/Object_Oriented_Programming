#pragma once

namespace FileConstants {
    const char INPUT_NAME[] = "inputFlights.txt";
    const char OUTPUT_NAME[] = "outputFlights.txt";
    const size_t LINE_MAX_LENGTH = 3;
    const size_t INITIAL_CAPACITY = 4;
}

class File {
private:
    class Line {
    private:
        char origin[FileConstants::LINE_MAX_LENGTH + 1];
        char dest[FileConstants::LINE_MAX_LENGTH + 1];
        unsigned int priceInEuro = 0;
    public:
        Line();
        Line(const char* _origin, const char* _dest, unsigned int _priceInEuro);

        void setOrigin(const char* _origin);
        void setDest(const char* _dest);
        void setPrice(unsigned int _priceInEuro);
    };

    Line** data;
    const char* fileName;
    size_t size = 0;
    size_t capacity;

public:
    File();
    ~File();

    void inputFile();

private:
    void free();
    size_t getFileSize(std::ifstream& _input) const;
};