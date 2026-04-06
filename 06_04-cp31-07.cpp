#include<bits/stdc++.h>
using namespace std;
int check(int xc,int yc,int xp,int yp,int a,int b){
    if(xp+a==xc&&yp+b==yc){
        return 1;
    }
    else if(xp+a==xc&&yp-b==yc){
        return 1;
    }
    else if(xp-a==xc&&yp+b==yc){
        return 1;
    }
    else if(xp-a==xc&&yp-b==yc){
        return 1;
    }
    else if(xp+b==xc&&yp+a==yc){
        return 1;
    }
    else if(xp+b==xc&&yp-a==yc){
        return 1;
    }
    else if(xp-b==xc&&yp+a==yc){
        return 1;
    }
    else if(xp-b==xc&&yp-a==yc){
        return 1;
    }
    else{
        return 0;
    }
}
int kng_g(int xk,int yk,int a,int b,int xq,int yq){
    int count=0;
    count+=check(xq,yq,xk+a,yk+b,a,b);
   count+= check(xq,yq,xk+a,yk-b,a,b);
    count+=check(xq,yq,xk-a,yk+b,a,b);
    count+=check(xq,yq,xk-a,yk-b,a,b);
    count+=check(xq,yq,xk+b,yk+a,a,b);
    count+=check(xq,yq,xk+b,yk-a,a,b);
    count+=check(xq,yq,xk-b,yk+a,a,b);
   count+= check(xq,yq,xk-b,yk-a,a,b);
   return count;
}
int main(){
    
}