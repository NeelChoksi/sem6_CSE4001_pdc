#include<bits/stdc++.h>
#include<omp.h>


using namespace std;

int powM(int x,int y , int m){
	if(y==0){
		return 1; 
		
	}
	int k;
	
	
		 k = powM(x,y/2,m);
		
		if(y%2 == 1){
		#pragma omp task shared(k,x,m)
			printf("[TID:%d] powM(%d,%d,%d)\n",omp_get_thread_num(),x,y,m);
			return( (( (1LL*k*k)%m )*x )%m    );
		}else{
		#pragma omp task shared(k,x,m)
			printf("[TID:%d] powM(%d,%d,%d)\n",omp_get_thread_num(),x,y,m);
			return (  ((1LL*k*k)%m)  );
		}
	
	
	
}


int main(){

	int x,y,m;
	cin>>x>>y>>m;
	
	double tdata = omp_get_wtime();
	
	#pragma omp parallel 
	{
		
	
		#pragma omp single
		{
			cout<<powM(x,y,m)<<endl;
		
		}
	
		
	}
	tdata = omp_get_wtime()-tdata;
	cout<<"Time taken to find modular exponent  :"<<tdata<<endl;
	
	
	
	return 0;



}
