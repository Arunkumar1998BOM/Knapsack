#include"Knapsackproblem.h"
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int total_benefit;

//first we shall define the get_elements function
void knapsack::get_elements() {
    cout<<"Please enter the number of items";
    cin>>no_of_items;
    knapsack_table.resize(no_of_items+1);
    for(auto &p:knapsack_table)
        p.resize(no_of_items+1);
    weights.resize(no_of_items+1);
    values.resize(no_of_items+1);
    cout<<"Please enter the elements weights ";
    for (int i=1; i<=no_of_items; i++){
        cin>>weights[i];
    }
    cout<<"Please enter the elements values for the particular weight";
    for(int i=1;i<=no_of_items;i++){
        cout<<"enter the value for element with weight "<<weights[i]<<endl;
        cin>>values[i];
    }
    //all the weights with their respective values have been loaded
    //Now we need the capacity of the knapsack
    cout<<"Please enter the capacity of the knapsack"<<endl;
    cin>>capacity_knapsack;

}

//now we shall define the operation function

void knapsack::operate() {
    for (int i=1;i<no_of_items+1;i++){
        for(int w=1;w<capacity_knapsack+1;w++){

            //define the item which we are not taking (nothing but the previous item which we had considered with
            //the constraint, for the given same weight)
            int not_taking_item=knapsack_table[i-1][w];

            int taking_item=0;
            //now just check the weight, if it lies in our limits
            if(weights[i]<=w){
                //okay,we can consider this element (which has weight[i])
                taking_item=values[i]+knapsack_table[i-1][w-weights[i]];
            }

            //now assign the maximum of the two values (either the previous value or the newly taken value)
            knapsack_table[i][w]=std::max(taking_item,not_taking_item);
        }

    }
    //now ,all the benefits for the constraints have been arranged in the table
    total_benefit=knapsack_table[no_of_items][capacity_knapsack];
}

//this function will be used to print the items and their respective values, which we have taken
void knapsack::show_result() {
    cout<<"the total loot as benfit"<<total_benefit<<endl;
    cout<<"these are the elements which we had considered"<<endl;
    //start from the last element
    for (int i=no_of_items,w=capacity_knapsack;i>0;i--){
        //take the last item, if the item differs from the previous item
        if(knapsack_table[i][w]!=0 && knapsack_table[i][w]!=knapsack_table[i-1][w])
        {
            cout<<"We have considered the element "<<i<<" with weight "<<weights[i]<<" and value "<<values[i]<<endl;

            w=w-weights[i];
        }
    }

}