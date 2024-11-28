#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
class Item{
    public:
    int profit;
    int weight;

    Item(int p,int w){
        profit=p;
        weight=w;
    }
};

bool comp(Item a,Item b){
    double r1=(double)a.weight/a.profit;
    double r2=(double)b.weight/b.profit;
    return r1<r2;
}

double fractional_knapsack(int w,vector<Item> vec){
    sort(vec.begin(),vec.end(),comp);
    double total_val=0;
    for(auto item:vec){
        if(w==0){
            break;
        }
        if(item.weight<=w){
            total_val+=item.profit;
            w-=item.weight;
        }else{
            total_val+=(double)w*item.profit/item.weight;
            w=0;
        }

    }
    return total_val;
}

int main(){
    int W=50;
    vector <Item>items={{60, 10}, {100, 20}, {120, 30}};
    cout<<"max profit is: "<<fractional_knapsack(W,items)<<endl;

}