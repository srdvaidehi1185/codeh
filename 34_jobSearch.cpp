#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Job{
    int id;
    int profit;
    int deadline;
};

bool compare(Job a, Job b){
    return a.profit>b.profit;
}

int main(){
    int n;
    cin>>n;

    vector<Job>jobs(n);

    for(int i=0;i<n;i++){
        cin>>jobs[i].id>> 
        jobs[i].profit>> 
        jobs[i].deadline;

    }
    sort(jobs.begin(), jobs.end(), compare);

    int maxDeadline=0;

    for(int i=0;i<n;i++){
        if(jobs[i].deadline>maxDeadline){
            maxDeadline=jobs[i].deadline;
        }
    }
    vector<int> slot(maxDeadline,-1);

    int maxProfit=0;

    for(int i=0;i<n ;i++){
        for(int j=jobs[i].deadline-1;j>=0;j--){
            if(slot[j]==-1){
                slot[j]=i;
                maxProfit+=jobs[i].profit;

                cout<<jobs[i].id<<endl;
                break;
            }
        }
    }
    cout<<"max profit:"<<maxProfit<<endl;




    
    return 0;
}