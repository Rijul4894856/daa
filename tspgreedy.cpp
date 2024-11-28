#include<iostream>
#include<vector>
#include<climits>

using namespace std;

pair<vector<int>,int> graph_tsp(vector<vector<int>>graph,int start){
    int n=graph.size();
    vector<bool>visited(n,false);
    vector<int>path;
    int curr_state=start;
    visited[curr_state]=true;
    path.push_back(curr_state);
    int total_cost=0;

    for(int i=0;i<n-1;++i){
        int nearest_city=-1;
        int nearest_cost=INT_MAX;
        for(int city=0;city<n;++city){
            if(graph[curr_state][city]<nearest_cost && visited[city]==false ){
                nearest_cost=graph[curr_state][city];
                nearest_city=city;
            }
        }

        total_cost+=nearest_cost;
        curr_state=nearest_city;
        visited[curr_state]=true;
        path.push_back(curr_state);
    }
    total_cost+=graph[curr_state][start];
    path.push_back(start);

    return {path,total_cost};

}

int main(){
    vector<vector<int>>graph={
        {0,10,15,20},
        {10,0,35,25},
        {15,35,0,30},
        {20,25,30,0}
    };

    int start=0;
    auto result=graph_tsp(graph,start);
    cout<<"Path :";
    for(auto i:result.first){
        cout<<i<<" ";
    }
    cout<<endl;

    cout<<"Total cost "<<result.second<<endl;


}
