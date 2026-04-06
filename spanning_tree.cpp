#include<bits/stdc++.h>
using namespace std;
int minpath(int n,int *arr){
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    int minp=0;
    bool box[n]={false};
    pq.push({0,0});
    vector<pair<int,int>,int> v;
    int w,u;
    int *ptr;
    while(!pq.empty()){
        auto p=pq.top();
        w=p.second;
        u=p.first;
       
        pq.pop();
        if(!box[u]){
            minp+=w;
            ptr=arr+n*u;
            box[u]=true;
            for (int i = 0; i < n; i++)
            {
                if(*(ptr+i)!=0){
                    pq.push({i,*(ptr+i)});
                }
            }
            
        }
    }
    return minp;
}
int main(){
    int n,r,a,b,c;
    cout<<"No of locations: ";
    cin>>n;
    cout<<"No of roads: ";
    cin>>r;
   
    int arr[n][n];
    for (int i = 0; i < n; i++)
    {   for (int j = 0; j < n; j++)
    {
        arr[i][j]=0;
    }
    }
    
    for (int i = 0; i < r; i++)
    {
        cin>>a>>b>>c;
       
        arr[a][b]=c;
        arr[b][a]=c;
    }
    for (int i = 0; i < n; i++)
    {   for (int j = 0; j < n; j++)
    {
        cout<<arr[i][j]<<" ";
    } cout<<endl;
    }
    cout<<minpath(n,arr[0]);

}