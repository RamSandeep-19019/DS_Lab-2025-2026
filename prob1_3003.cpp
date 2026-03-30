#include<bits/stdc++.h>
using namespace std;

int findStudent(string str[], string name, int n) {
    for(int i=0;i<n;i++) {
        if(name==str[i])
        return i;
    }
    return -1;
}

int main() {
    cout<<"===Friend Network in a Class===\n";
    cout<<"Enter number of students: ";
    int total;
    cin>>total;
    cout<<"Enter student names:\n";
    string str[total];
    for(int i=0;i<total;i++)
    cin>>str[i];
    cout<<"Enter number of friendships: ";
    int friends;
    cin>>friends;
    cout<<"Enter friendships (name1 name2):\n";
    string frnd1[friends],frnd2[friends];
    for(int i=0;i<friends;i++)
    cin>>frnd1[i]>>frnd2[i];
    int direct_network[total][total];
    for(int i=0;i<total;i++) {
        for(int j=0;j<total;j++)
        direct_network[i][j]=0;
        direct_network[i][i]=1;
    }
    for(int i=0;i<friends;i++) {
        int f1=findStudent(str, frnd1[i], total);
        int f2=findStudent(str, frnd2[i], total);
        direct_network[f1][f2]=1;
        direct_network[f2][f1]=1;
    }
    cout<<"\nDirect Friendships:\n\n";
    for(int i=0;i<total;i++) {
        int count=0;
        cout<<str[i]<<"\t-> ";
        for(int j=0;j<total;j++) {
            if(direct_network[i][j]==1&&i!=j) {
            cout<<str[j]<<' ';
            count++;
            }
        }
        if(count==0)
        cout<<"No friends";
        cout<<'\n';
    }
    int network[total][total];
    for(int i=0;i<total;i++) {
        for(int j=0;j<total;j++)
        network[i][j]=0;
    }
    for(int i=0;i<total;i++) {
        for(int j=0;j<total;j++) {
            if(direct_network[i][j]==1&&i!=j) {
                network[i][j]=1;
                network[j][i]=1;
                for(int k=0;k<total;k++) {
                    if(network[j][k]==1&&j!=k) {
                        network[i][k]=1;
                        network[k][i]=1;
                    }
                }
            }
        }
    }
    cout<<"\nFriendship Network Matrix:\n\n";
    cout<<"\t";
    for(int i=0;i<total;i++)
    cout<<str[i]<<'\t';
    cout<<'\n';
    for(int i=0;i<total;i++) {
        cout<<str[i]<<"\t";
        for(int j=0;j<total;j++) 
        cout<<network[i][j]<<'\t';
        cout<<'\n';
    }

    cout<<"\nFriend Groups: \n";
    int num=0;
    for(int i=0;i<total;) {
        cout<<"Friend Group "<<++num<<": ";
        int alpha;
        cout<<str[i]<<' ';
        for(alpha=i+1;alpha<total;) {
            if(network[i][alpha]==1)
            cout<<str[alpha]<<' ';
            else 
            break;
            alpha++;
        }
        cout<<'\n';
        i+=alpha;
    }
}