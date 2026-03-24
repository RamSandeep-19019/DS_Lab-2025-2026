#include<iostream>
#include<vector>
#include<iomanip>
using namespace std;
struct node{
    string name;
    int severity;
    int time;
    int age;
    int dist;
    int vip;
    float score;
};
void heapify(node v[],int i,int n){
    int left=2*i+1;
    int right=2*i+2;
    int largest=i;
    if(left<n&&v[left].score>v[largest].score){
        largest=left;
    }
    if(right<n&&v[right].score>v[largest].score){
        largest=right;
    }
    if(largest!=i){
        swap(v[i],v[largest]);
        heapify(v,largest,n);
    }
}
void heap_sort(node v[],int n){
    
    for (int i = n/2-1; i >=0 ; i--)
    {
        heapify(v,i,n);
    }
   
    for(int i=n-1;i>0;i--){
        swap(v[i],v[0]);
        heapify(v,0,i);

    }
    
}

int main(){
     
     int n;
     cout<<"Enter the number of patients: ";
     cin>>n;
     node arr[n];
     for(int i=0;i<n;i++){
       cout<<"Enter details for patient "<<i+1<<":\nName: ";
        cin>>arr[i].name;
cout<<"Severity (1-10): ";
cin>>arr[i].severity;
cout<<"Waiting Time (minutes):";
cin>>arr[i].time;
 
cout<<"Age: ";
cin>>arr[i].age;

cout<<"Distance (km): ";
cin >>arr[i].dist;
cout<<"VIP (0 or 1): ";
      cin>>arr[i].vip;
        arr[i].score=5*arr[i].severity+2*arr[i].time+1.5*arr[i].age-3*arr[i].dist+10*arr[i].vip;
        cout<<endl;
     }
     heap_sort(arr,n);
     int input;
    cout<<" -MENU--\n1. Show Next Patient\n2. Treat Patient\n3. Show Treatment Order\n4. Exit\nEnter choice: ";
int rank=1;
     cin>>input;
     while(input!=4){
     switch(input){
        case 1:
        if(n>0){

        cout<<"\nNext Patient: "<<arr[n-1].name<<"(Score: "<< fixed << setprecision(2)<<arr[n-1].score<<")"<<endl;
    }
        else{
            cout<<"\nNo patient available";
        }
        break;
        case 2:
        if(n>0){
         cout<<"\nTreating patient: "<<arr[n-1].name<<" ("<<arr[n-1].score<<")"<<"\n";
         swap(arr[0],arr[n-1]);
         n=n-1;
         heap_sort(arr,n);
        }
        else{
            cout<<"\nNo patient available";
        }
        break;
        case 3:
        if(n==0){
            cout<<"\nNo patient available";
        }
        else{
            cout<<"\nTreatment Order:\n";
        for (int i = n-1; i>=0; i--)
     {
        cout<<rank<<". "<<arr[i].name<<" (Score: "<<arr[i].score<<")"<<"\n";
        rank++;
     }
    }
        break;
     }
         cout<<"\n\n -MENU--\n1. Show Next Patient\n2. Treat Patient\n3. Show Treatment Order\n4. Exit\nEnter choice: ";

     cin>>input;
    }
}
