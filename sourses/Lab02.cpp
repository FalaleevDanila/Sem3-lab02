//
// Created by danf2 on 17.09.2019.
//

#include <vector>
#include "../includes/Lab02.h"
#include <fstream>

using std::cout;
using std::endl;

std::vector <int> Lab02::amountOfExperiments() {
    int n = 256;
    std::vector <int> experiments;
    static const auto MAX_SIZE = 9*1024*3/2;
    while(n < MAX_SIZE){
        experiments.push_back(n);
        n*=2;
    }
    return experiments;
}



 Lab02::Lab02(size_t const &size){
     this->size=size;
     array=new int[size];
     srand(time(NULL));
     for(size_t i = 0; i < size; ++i){
         srand(time(NULL));
         array[i]=rand();
     }
 }

double Lab02::firstToEnd() {
    srand(time(NULL));
    clock_t start = clock();

    static const auto SIZE = 1000;

    for(size_t i=0;i<SIZE;++i) {
        for (size_t j = 0; j < size; j++) {
            array[j] = rand();
        }
    }
    clock_t end = clock();
    return  (double)(end - start)/CLOCKS_PER_SEC;
}

double Lab02::endToFirst() {
    srand(time(NULL));
    clock_t start = clock();
    static const auto SIZE = 1000;
    for(size_t i=0;i<SIZE;++i) {
        for (size_t j = size; j > 0; j--) {
            array[j-1] = rand();
        }
    }
    clock_t end = clock();
    return  (double)(end - start)/CLOCKS_PER_SEC;
}

double Lab02::randomWay() {

    std::vector <size_t> indexes(size);
    srand(time(NULL));
    std::iota(indexes.begin(), indexes.end(), 0);
    std::shuffle(indexes.begin(), indexes.end(), std::mt19937(std::random_device()()));
    static const auto SIZE = 1000;
    clock_t start = clock();
    for(size_t i=0;i<SIZE;++i) {
        for (size_t j=0;j<size;++j) {
            array[indexes[j]] = rand();
        }
    }
    clock_t end = clock();
    return  (double)(end - start)/CLOCKS_PER_SEC;

}

void Lab02::resultWindow(std::string const &travelVariant, size_t const &numberOfExperiment, int const &size, double const &timeOfArray) {

    cout << "   travel_variant: " << travelVariant << endl;
    cout << "   experiments: " << endl;
    cout << "   - experiment: " << endl;
    cout << "       number: " << numberOfExperiment << endl;
    cout << "       input_data: " << endl;
    cout <<             "buffer_size: " << size << endl;
    cout << "       results: " << endl;
    cout << "           duration: " << timeOfArray << endl;
}

void Lab02::chart(std::vector<int> sizeOfCash, std::vector<double> first,
        std::vector<double> second, std::vector<double> third) {

    std::ofstream out;          // поток для записи
    out.open("/home/danila/Рабочий стол/lab302/firstToEnd.txt"); // окрываем файл для записи
    if (out.is_open())
    {
        for(size_t i=0;i< sizeOfCash.size();++i) {
            out << "(" << sizeOfCash[i] << ";" << first[i] << ")";
        }
    }
    out.close();

    out.open("/home/danila/Рабочий стол/lab302/endToFirst.txt"); // окрываем файл для записи
    if (out.is_open())
    {
        for(size_t i=0;i< sizeOfCash.size();++i) {
            out << "(" << sizeOfCash[i] << ";" << second[i] << ")";
        }
    }
    out.close();

    out.open("/home/danila/Рабочий стол/lab302/randomWay.txt"); // окрываем файл для записи
    if (out.is_open())
    {
        for(size_t i=0;i< sizeOfCash.size();++i) {
            out << "(" << sizeOfCash[i] << ";" << third[i] << ")";
        }
    }
    out.close();

}

Lab02::~Lab02() {
    delete[] array;
}