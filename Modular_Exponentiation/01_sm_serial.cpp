#include<bits/stdc++.h>
#include<omp.h>


using namespace std;

int powM(int x,int y , int m){
	if(y==0){
		return 1; 
		
	}
	int k = powM(x,y/2,m);
	
	if(y%2 == 1){
		return( (( (1LL*k*k)%m )*x )%m    );
	}else{
		return (  ((1LL*k*k)%m)  );
	}
}


int main(){

	int x,y,m;
	cin>>x>>y>>m;
	
	double tdata = omp_get_wtime();
	cout<<powM(x,y,m)<<endl;
	tdata = omp_get_wtime()-tdata;
	cout<<"Time taken to find modular exponent  :"<<tdata<<endl;
	
	return 0;



}
