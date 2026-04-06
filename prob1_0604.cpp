#include<bits/stdc++.h>
using namespace std;

int main() {
    cout<<"Enter number of locations: ";
    int loc;
    cin>>loc;
    cout<<"Enter number of possible roads: ";
    int num;
    cin>>num;
    cout<<"Enter roads (u v cost):\n";
    int connections[loc][loc],result[loc][loc],max=INT16_MAX;
    for(int i=0;i<loc;i++) {
        for(int j=0;j<loc;j++) {
        connections[i][j]=max;
        result[i][j]=max;
        }
    }
    for(int k=0;k<num;k++) {
        int i,j,a;
        cin>>i>>j>>a;
        connections[i][j]=a;
    }
    vector<int> count(loc, 0);
    for(int j=0;j<loc;j++) {
        int min=max;
        for(int i=0;i<loc;i++) {
            if(connections[i][j]<min) 
                min=connections[i][j];
        } 
        for(int i=0;i<loc;i++) {
            if(connections[i][j]==min) {
                result[i][j]=min;
                count[j]++;
            }
        } 
    }
    int networkcount=1,sum;
    for(int i=1;i<loc;i++)
    networkcount*=count[i];
    while(networkcount>=1) {
        cout<<"\nOptimal Road Network:\n";
        sum=0;
        for(int j=0;j<loc;j++) {
            for(int i=0;i<loc;i++) {
                if(result[i][j]!=max) {
                    if(count[j]>1) {
                        count[j]--;
                        continue;
                    }
                cout<<i<<" -- "<<j<<" == "<<result[i][j]<<'\n';
                sum+=result[i][j];
                break;
                }
            }
        }
        cout<<"Total Cost = "<<sum<<'\n';
        networkcount--;
}
    cout<<"\nFinal Minimum Cost = "<<sum;
}