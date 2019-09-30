#include <iostream>

#include "includes/Lab02.h"

#include <ctime> // содержит time()

#include <vector>

#include <GL/glut.h>

using namespace std;

using std::cout;
using std::endl;


int main(int argc, char **argv) {
    int numberOfExperiment = 1;

    std::vector <double> firstToEnd;
    std::vector <double> endToFirst;
    std::vector <double> randomWay;

    std::vector <int> ress = Lab02::amountOfExperiments();
    for (size_t i = 0; i < ress.size() ; i++ ){
        cout << "investigation:" << endl;
        Lab02 experiment(ress[i]*1024/ sizeof(decltype(ress)::value_type));
        firstToEnd.push_back(experiment.firstToEnd());
        Lab02::resultWindow(" 1 -> end", numberOfExperiment, ress[i], firstToEnd[i]);
        endToFirst.push_back(experiment.endToFirst());
        Lab02::resultWindow(" End -> 1", numberOfExperiment, ress[i], endToFirst[i]);
        randomWay.push_back(experiment.randomWay());
        Lab02::resultWindow(" Random ", numberOfExperiment, ress[i], randomWay[i]);
        numberOfExperiment++;
    }
    Lab02::chart(ress,firstToEnd,endToFirst,randomWay);




    return 0;
}