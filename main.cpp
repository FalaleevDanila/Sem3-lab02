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

    std::vector <int> size = Lab02::amountOfExperiments();
    static const auto SIZE = 1024/sizeof(decltype(size)::value_type);
 vector <int> :: iterator i1=size.begin();
    vector <double> :: iterator i2;

    for (; i1 < size.end(); ++i1){
        cout << "investigation:" << endl;
        Lab02 experiment(*i1 * SIZE );
        firstToEnd.push_back(experiment.firstToEnd());
        std::cout << firstToEnd[0];
        i2 = firstToEnd.end()-1;
        Lab02::resultWindow(" 1 -> end", numberOfExperiment, *i1 , *i2);
        endToFirst.push_back(experiment.endToFirst());
        i2 = endToFirst.end()-1;
        Lab02::resultWindow(" End -> 1", numberOfExperiment, *i1 , *i2);
        randomWay.push_back(experiment.randomWay());
        i2 = randomWay.end()-1;
        Lab02::resultWindow(" Random ", numberOfExperiment, *i1 , *i2);
        numberOfExperiment++;
    }
   /*
    for (size_t i = 0 ; i < ress.size(); ++i){

        cout << "investigation:" << endl;

        Lab02 experiment(ress[i] * SIZE );

        firstToEnd.push_back(experiment.firstToEnd());

        Lab02::resultWindow(" 1 -> end", numberOfExperiment, ress[i], firstToEnd[i]);

        endToFirst.push_back(experiment.endToFirst());

        Lab02::resultWindow(" End -> 1", numberOfExperiment, ress[i], endToFirst[i]);

        randomWay.push_back(experiment.randomWay());

        Lab02::resultWindow(" Random ", numberOfExperiment, ress[i], randomWay[i]);

        numberOfExperiment++;
    }  */
    Lab02::chart(size, firstToEnd, endToFirst, randomWay);




    return 0;
}