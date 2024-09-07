#include <iostream>
#include <fstream>

const size_t MAX_PAIRS_NUMBER = 25;

struct Pair {
    unsigned number1;
    unsigned number2;
};

struct Relation {
    size_t size;
    Pair pairs[MAX_PAIRS_NUMBER];
};

Pair createPair() {
    Pair pair;

    pair.number1 = 0;
    pair.number2 = 0;

    return pair;
}

Relation createRelation() {
    Relation relation;
    relation.size = 0;

    for (size_t i = 0; i < MAX_PAIRS_NUMBER; i++)
    {
        relation.pairs[i] = createPair();
    }

    return relation;
}

void initPair(Pair& pair) {
    std::cin >> pair.number1 >> pair.number2;
}


void addPairToRelation(const Pair& pair, Relation& relation) {
    if (relation.size < MAX_PAIRS_NUMBER) {
        relation.pairs[relation.size].number1 = pair.number1;
        relation.pairs[relation.size].number2 = pair.number2;
        relation.size++;
    }
    else {
        std::cout << "Reached max number of pairs in this relation!" << std::endl;
    }
    return;
}

//must be modified
//void readPairFromFile(Pair& pair, const char* fileName) {
//    std::ifstream input(fileName, std::ios::app);
//
//    if (!input.is_open()) {
//        std::cout << "Couldn't open the file!" << std::endl;
//        return;
//    }
//
//    input >> pair.number1 >> pair.number2;
//
//    input.close();
//}

void writePairToFile(const Pair& pair, const char* fileName) {
    std::ofstream output(fileName, std::ios::app);

    if (!output.is_open()) {
        std::cout << "Couldn't open the file!" << std::endl;
        return;
    }

    output << "(" << pair.number1 << "," << pair.number2 << ")" << std::endl;;

    output.close();
}

//must be modified
//void readRelationFromFile(Relation& relation, const char* fileName) {
//    std::ifstream input(fileName);
//
//    if (!input.is_open()) {
//        std::cout << "Couldn't open the file!" << std::endl;
//        return;
//    }
//
//    for (size_t i = 0; !input.eof() || i < MAX_PAIRS_NUMBER; i++)
//    {
//        readPairFromFile(relation.pairs[i], fileName);
//    }
//
//    input.close();
//}

void writeRelationToFile(const Relation& relation, const char* fileName) {
    std::ofstream output(fileName, std::ios::app);

    if (!output.is_open()) {
        std::cout << "Couldn't open the file!" << std::endl;
        return;
    }

    output << "Relation 1:" << std::endl;

    for (size_t i = 0; i < relation.size; i++)
    {
        writePairToFile(relation.pairs[i], fileName);
    }

    output.close();

    output << std::endl;
}

int main()
{
    Pair pair1 = createPair();
    std::cout << "Enter the new pair: ";
    initPair(pair1);

    Pair pair2 = createPair();
    std::cout << "Enter the new pair: ";
    initPair(pair2);

    Pair pair3 = createPair();
    std::cout << "Enter the new pair: ";
    initPair(pair3);

    Pair pair4 = createPair();
    std::cout << "Enter the new pair: ";
    initPair(pair4);

    Relation relation1 = createRelation();
    addPairToRelation(pair1, relation1);
    addPairToRelation(pair2, relation1);
    addPairToRelation(pair3, relation1);
    addPairToRelation(pair4, relation1);

    writeRelationToFile(relation1, "relations.txt");

    //Relation relation2 = createRelation();
    //readRelationFromFile(relation2, "relations.txt");

    //writeRelationToFile(relation2, "relations2.txt");
}