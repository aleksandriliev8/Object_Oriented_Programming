#include <iostream>

//Task2

unsigned int biggerNumsThanSymbol(int* arrayInt, const int& N) {
    unsigned int counter = 0;

    for (size_t i = 0; i < N; i++)
    {

    }
}

//Task3

void initializeMatrix(int** matrix, const int& N, const int& M) {
    for (size_t i = 0; i < N; i++)
    {
        matrix[i] = new int[M];
    }
}

void fillMatrix(int** matrix, const int& N, const int& M) {
    std::cout << "Enter the matrix " << N << " x " << M << std::endl;
    for (size_t i = 0; i < N; i++)
    {
        for (size_t j = 0; j < M; j++)
        {
            std::cin >> matrix[i][j];
        }
    }
    std::cout << std::endl;
}

void printMatrix(int** matrix, const int& N, const int& M) {
    for (size_t i = 0; i < N; i++)
    {
        for (size_t j = 0; j < M; j++)
        {
            std::cout << matrix[i][j] << " ";
        }

        std::cout << std::endl;
    }

    std::cout << std::endl;
}

int** transposedMatrix(int** matrix, const int& N, const int& M) {
    int** transposed = new int*[M];

    initializeMatrix(transposed, M, N);

    for (size_t i = 0; i < N; i++)
    {
        for (size_t j = 0; j < M; j++)
        {
            transposed[j][i] = matrix[i][j];
        }
    }

    return transposed;
}

void deleteMatrix(int** matrix, const int& N, const int& M) {

    for (size_t i = 0; i < N; i++)
    {
        delete[] matrix[i];
    }

    delete[] matrix;
}

//Task4

const int MAX_NAME_STUDENT = 30;

struct Student {
    char name[MAX_NAME_STUDENT + 1];
    int fn;
};

void initStudent(Student& st) {
    std::cout << "Enter the student's name: ";
    std::cin.getline(st.name, MAX_NAME_STUDENT);

    std::cout << "Enter the student's FN: ";

    st.fn = -1;
    std::cin >> st.fn;

    while (st.fn < 0) {
        std::cout << std::endl;
        std::cout << "FN shouldn't be negative number!" << std::endl;
        std::cout << "Enter the student's FN: ";
        std::cin >> st.fn;
    } 
}

void printStudent(const Student& st) {
    std::cout << std::endl;
    std::cout << "Student's name: ";
    std::cout << st.name;

    std::cout << std::endl;
    std::cout << "Student's FN: " << st.fn;
}

//Task5

struct ComplexNumber {
    double real;
    double imaginary;
};

ComplexNumber sumComplex(const ComplexNumber& number1, const ComplexNumber& number2) {

    return { number1.real + number2.real, number1.imaginary + number2.imaginary };
}

void printComplex(const ComplexNumber& number) {
    std::cout << number.real << " + " << number.imaginary << "i";
}


int main()
{
    //Task1

    //Task2
    std::cout << "Enter N: " << std::endl;
    int N;
    std::cin >> N;

    int* arrayInt = new int[N];

    std::cout << "Enter the numbers: ";

    for (size_t i = 0; i < N; i++)
    {
        std::cin >> arrayInt[i];
    }

    char symbol;

    std::cout << "Enter the symbol: " << std::endl;
    std::cin >> symbol;

    delete[] arrayInt;

    //Task3

    std::cout << "Enter the matrix parameters: ";
    int N, M;
    std::cin >> N >> M;

    int** matrix = new int*[N];

    initializeMatrix(matrix, N, M);
    fillMatrix(matrix, N, M);
    std::cout << "Matrix: " << std::endl;
    printMatrix(matrix, N, M);

    int** transposed = transposedMatrix(matrix, N, M);
    std::cout << "Transposed matrix: " << std::endl;
    printMatrix(transposed, M, N);

    deleteMatrix(transposed, M, N);
    deleteMatrix(matrix, N, M);

    //Task4

    Student st = { "Gosho", 10 };//ok
    Student* pSt = &st;//ok
    const Student* pCSt = &st;//ok the object is const
    Student* const cPSt = &st;//ok the pointer is const
    const Student* const cpCSt = &st;// ok the both are const
    const Student& refCSt = st;//ok

    Student student;
    initStudent(student);
    printStudent(student);

    //Task5

    ComplexNumber number1 = {7, 8};
    ComplexNumber number2 = {5, 6};

    std::cout << "First number: ";
    printComplex(number1);
    std::cout << std::endl;

    std::cout << "Second number: ";
    printComplex(number2);
    std::cout << std::endl;

    std::cout << "Summary of number 1 and number 2: ";
    ComplexNumber result = sumComplex(number1, number2);
    printComplex(result);
    std::cout << std::endl;
}
