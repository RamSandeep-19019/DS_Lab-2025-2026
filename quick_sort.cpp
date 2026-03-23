#include<iostream>
#include<vector>
#include<algorithm>
#include<iomanip>
using namespace std;
struct node
{       
    int roll_No;
    string name;
    float marks;
};
int partioning(node arr[],int start,int end){
  int idx=start-1;
  node temp;
  for(int j=start;j<end;j++){
  if(arr[end].marks>=arr[j].marks){
    idx++;
    swap(arr[idx],arr[j]);
    if(arr[idx].marks==arr[end].marks){
      if(arr[end].roll_No>arr[idx].roll_No){
        swap(arr[end],arr[idx]);
      }
    }
    
  }
  }
  idx++;
  swap(arr[end],arr[idx]);
  return idx;
}
void quick_sort(node arr[],int start,int end){
  int pivot;   
  if(end>start){
      pivot=partioning(arr,start,end);
      quick_sort(arr,start,pivot-1);
      quick_sort(arr,pivot+1,end);
     }
     
    
}
int main(){
  int n;
  cout<<"Enter number of students: ";
  cin>>n;
  node arr[n];
  for (int i = 0; i < n; i++)
  { cout<<"Enter Roll No, name , Marks: ";
    cin>>arr[i].roll_No>>arr[i].name>>arr[i].marks;
  }
  quick_sort(arr,0,n-1);
  
  int rank=1;
  cout<<"Rank    Roll_No name    Marks\n";
   for (int i = n-1; i >= 0; i--)
  { 


cout << left<<setw(8) << rank
     <<left<< setw(8) << arr[i].roll_No
     <<left<< setw(8) << arr[i].name
     <<fixed<< setprecision(2) << arr[i].marks<<endl;  
   
   rank++; } 
    cout<<"--- Topper Details ---\nRoll: "<<left<<setw(16)<<arr[n-1].roll_No<<"Name: "<<left<<setw(11)<<arr[n-1].name<<"Marks: "<<fixed<< setprecision(2) <<arr[n-1].marks;
}
