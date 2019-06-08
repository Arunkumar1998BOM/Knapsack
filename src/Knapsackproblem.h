//
// Created by ak47a on 06-06-2019.
//

#ifndef KNAPSACK_PROBLEM_KNAPSACKPROBLEM_H
#define KNAPSACK_PROBLEM_KNAPSACKPROBLEM_H

#include <vector>
using namespace std;
class knapsack{
    int no_of_items;
    int capacity_knapsack;

    vector<int>weights;
    vector<int>values;

    //Now we create a knapsack table
    vector<vector<int>>knapsack_table;




public:
    void get_elements();
    //we are overloading the operator ()
    void operate();

    void show_result();
};
#endif //KNAPSACK_PROBLEM_KNAPSACKPROBLEM_H
