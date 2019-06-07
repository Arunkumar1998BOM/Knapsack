//
// Created by ak47a on 06-06-2019.
//

#include "Knapsackproblem.h"
#include <iostream>

using namespace std;
knapsack::knapsack(int _no_of_items, int _capacity_knapsack, const vector<int>&w, const vector<int>&v){
    weights=w;
    values=v;
    no_of_items=_no_of_items;
    capacity_knapsack=_capacity_knapsack;
    //no of rows is no_of_items+1, because we must also consider the case where there are no items in the knapsack
    knapsack_table.resize(no_of_items+1);

    for(auto &it:knapsack_table)
        it.resize(capacity_knapsack+1);
}

//now we define the operation for the overloaded operator ()
void knapsack::operator ()(){
    //we need to keep considering different scenarios of the items in the box and decide whether to keep the item or not
    //the time complexity is O(N*W)

    for (int i=1;i<no_of_items;i++){
        for(int w=1;w<capacity_knapsack;w++){
            //maximum value of the knapsack if we do not take item
            //The S[i][w] value
            int not_taking_item=knapsack_table[i-1][w];

            int taking_item=0;
            //Now we shall compute the value of the knapsack if we take the item i
            if(weights[i]<=w){
                taking_item=values[i]+knapsack_table[i-1][w-weights[i]];

            }

            //now if we wanna maximize our profits
            knapsack_table[i][w]=std::max(not_taking_item,taking_item);
        }
    }
    //maximized profit is the value of the last cell
    //because this is the case when we have as many items as the number of items and as much capacity as the capacity of knapsack
    total_benefit=knapsack_table[no_of_items][capacity_knapsack];
}

//This function is used to print the result
void knapsack::show_result() {
    //we start with the last row adn the last column
    for (int n=no_of_items,w=capacity_knapsack;n>0;n--){
        //we take the item if its value differs from the value in the above row
        if(knapsack_table[no_of_items][w]!=knapsack_table[no_of_items-1][w]){

        }
    }

}