#include <iostream>
#include<vector>
#include <algorithm>
#include<iomanip>
using namespace std;

struct Item{
    int profit;
    int weight;
    float ratio;
};

bool compare(Item a, Item b){
    return a.ratio>b.ratio;
}

int main(){

    int n;
    cin>>n;
    vector<Item>items(n);

    for(int i=0;i<n;i++){
        cin>>items[i].profit>>items[i].weight;

        items[i].ratio=(float)items[i].profit /items[i].weight;
    }

    sort(items.begin(),items.end(),compare);

    int capacity;
    cin>>capacity;
    float totalProfit=0.0;

    for(int i=0;i<n;i++){
        if(items[i].weight<=capacity){
            capacity-=items[i].weight;
            totalProfit+=items[i].profit;

        }
        else{
            float fraction= (float)capacity/ items[i].weight;
            totalProfit+=fraction * items[i].profit;

            capacity=0;
            break;
        }
    }
    cout<<"Total Profit :"<<totalProfit<<endl;
    
    return 0;
}