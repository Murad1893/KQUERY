/*
Made by: K173722
Q3
K-query problem
*/

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

template <typename t>
class Dynamicsafearray{
	
	private:
	t *ptr;
	int size;
	
	public:
	Dynamicsafearray(){
		ptr=NULL;
		size=0;
	}
	
	//parameterized constructor
	Dynamicsafearray(int a){
		size=a;
		ptr=new t[size];
		memset(this->ptr,0,sizeof(t)*size);
	}
	
    //copy constructor
	Dynamicsafearray(const Dynamicsafearray<t>& obj){
	this->ptr=0;
	this->size=obj.size;
	this->ptr=new t[obj.size];
	memset(this->ptr,0,sizeof(t)*this->size);
	
	memcpy(this->ptr,obj.ptr,sizeof(t)*obj.size);
	}
	
	//set get functionalities
	void setelement(t a,int i){
		ptr[i]=a;
	}	
	void setsize(int a){size=a;}	
	
	int getsize(){
		return size;
	}
	
	void output(){ //to display output of array
		for(int i=0;i<size;i++){
			cout<<ptr[i];
		}
	}
	
    void kquery(int lower_bound,int upper_bound,int k,fstream& file1){
		
		int count=0;
		for(int j=lower_bound;j<=upper_bound;j++){ //loop for getting number of integers satisfying the query this is inclusive
		if(ptr[j]==0){ //if the input element in the limit becomes zero then querry is skipped
		file1<<"Query skipped because 0 occured in the elements between lower and upper bound\n";
		count=0;
		return; //control transfered back to main
	    }
	    else{
	    if(ptr[j]>k){
		count++;
		}
	    }
	    }
	    
	    file1<<count<<'\n'; //write the count into the file
	}
	
	//destructor
	~Dynamicsafearray(){
		if(ptr!=0)
		delete[] ptr;
		ptr=NULL;	
	}
	
};

int main(){

	int upper_bound,lower_bound,k=0,size,t;
	
	fstream file,file1;
	///*********hardcoded testcase. You can manually input your testcase file name here***************
	file.open("input3.txt",ios::in); //file hardcoded
	
	if(!file){
	cout<<"\nfile not found\n";
	exit(0);
	}
	
	file>>size;

    file1.open("outputA1P3.txt",ios::out|ios::trunc); //output file hardcoded
    
	try{ //exception handling for size
		if(size<=1 || size>=30000){
			throw 1;
		}
	}
	catch(int a){
		cout<<"\nOut of bound. Specified range is 1 <= size <= 30000\n";
		exit(0);
	}
	
	Dynamicsafearray<int> d(size);
	
	for(int i=0;i<size;i++){
		int k;
		file>>k;
		d.setelement(k,i);
	}

    file>>t; //where t is the number of queries
    
    try{ //exception handling for query
		if(t<=1 || t>=5000){
			throw 1;
		}
	}
	catch(int a){
		cout<<"\nOut of bound. Specified range is 1 <= t <=5000\n";
		exit(0);
	}
    
    for(int i=0;i<t;i++){ //loop for number of queries
    	int count=0;
	
		file>>lower_bound; //taking input of bounds and query from file
		file>>upper_bound;
        file>>k;
        
        if(lower_bound>upper_bound){ //error testing
        	cout<<"test case not fulfilled. "<<lower_bound<<">"<<upper_bound<<endl;
        	file1<<"test case not fulfilled. "<<lower_bound<<">"<<upper_bound<<endl;
        	continue;
		}	
		else if(lower_bound<0){  //error testing
			cout<<"test case not fulfilled. "<<lower_bound<<"< 0"<<endl;
        	file1<<"test case not fulfilled. "<<lower_bound<<"< 0"<<endl;
        	continue;
		}
		else if(upper_bound>size){  //error testing
			cout<<"test case not fulfilled. "<<upper_bound<<">"<<size<<endl;
        	file1<<"test case not fulfilled. "<<upper_bound<<">"<<size<<endl;
        	continue;
		}
				
   	    d.kquery(lower_bound,upper_bound,k,file1); 
    
    }
    
    file.close();
    file1.close();
    
}
