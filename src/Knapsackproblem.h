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
    //Now we create a knapsack table
    vector<vector<int>>knapsack_table;

    int total_benefit;
    vector<int>weights;
    vector<int>values;


public:
    // we shall define the constructor
    knapsack(int _no_of_items, int _capacity_knapsack, const vector<int> &weights, const vector<int> &values);
    //we are overloading the operator ()
    void operator()();

    void show_result();
};
#endif //KNAPSACK_PROBLEM_KNAPSACKPROBLEM_H
