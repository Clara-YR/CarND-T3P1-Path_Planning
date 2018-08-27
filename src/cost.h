//
// Created by Ryan on 2018/8/26.
//

#ifndef PATH_PLANNING_COST_H
#define PATH_PLANNING_COST_H

#include <iostream>
#include <random>
#include <vector>
#include <map>
#include <string>

using namespace std;

class Cost {

private:
    // set the cost weights
    // Feasibility >> Safety >> Legality >> Comfort >> Efficiency
    double w_f = 10000.0;  // weight for feasibility cost
    double w_s = 1000.0;  // weight for safety cost
    double w_l = 100.0;  // weight for legality cost
    double w_c = 10.0;  // weight for comfort cost
    double w_e = 1.0;  // weight for efficiency cost

public:
    // initialize each cost
    double cost_f = 0.0;  // feasiblility cost
    double cost_s = 0.0;  // safety cost
    double cost_l = 0.0;  // legality cost
    double cost_c = 0.0;  // comfort cost
    double cost_e = 0.0;  // efficiency cost

    /**
     *  Cosntructor
     */
    Cost();

    /**
     *  Destructor
     */
    virtual ~Cost();

    double calculate_cost();
};

#endif //PATH_PLANNING_COST_H
