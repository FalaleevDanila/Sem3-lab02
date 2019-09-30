//
// Created by danf2 on 17.09.2019.
//

#ifndef LAB302_LAB02_H
#define LAB302_LAB02_H

#include <cstddef>

#include <ctime> // содержит time()
#include <cstdlib> // содержит srand() и rand()
#include <string>
#include <time.h>
#include <numeric>
#include <algorithm>
#include <random>
#include <iostream>
#include <GL/glut.h>




class Lab02 {
    int *array;
    size_t size;
public:


    Lab02(size_t const &size);

    static std::vector <int>  amountOfExperiments();

    double firstToEnd();

    double endToFirst();

    double randomWay();

    static void resultWindow(std::string const &travelVariant, size_t const &numberOfExperiment, int const &size, double const &timeOfArray);

    static void chart(std::vector <int> sizeOfHash, std::vector <double> first, std::vector <double> second, std::vector <double> third);

    ~Lab02();
};


#endif //LAB302_LAB02_H
