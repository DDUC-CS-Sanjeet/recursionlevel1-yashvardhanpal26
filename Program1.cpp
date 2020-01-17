#include<iostream>
using namespace std;

int Factorial_R(int);    
int Factorial_I(int);

int GCD_I(int,int);	
int GCD_R(int,int); 
			
int Power_R(int,int); 
int Power_I(int,int);
		    
int Fibonacci_R(int);					
void Fibonacci_I(int);

int main()
{
	int m,n;
	
	cout<<"Power \n";
	cout<<"Enter Base - ";
	cin>>m;
	cout<<"Enter Power - ";
	cin>>n;
	
	try
	{
		if(n<0)
		throw  0;
		
		else if(n==0 &&m==0)
		throw "\nResult not defined...";
		
		cout<<"\nResult using recursion - "<<Power_R(m,n);
		cout<<"\nResult using iteration - "<<Power_I(m,n);
	}
	
	catch (int a)
	{
		cout<<"\nResult using recursion - 1/("<<Power_R(m,n)<<")";
		cout<<"\nResult using iteration - 1/("<<Power_I(m,n)<<")";
	}
	catch (const char *a)
	{
		cout<<a;
	}
	
	cout<<"\n\nFactorial\n";
	cout<<"Enter a number : ";
	cin>>n;
	try
	{
		if(n<0)
		throw "\nWrong input...\n";
		if (n==0)
		throw 1;
		cout<<"\nResult using recursion - "<<Factorial_R(n);
		cout<<"\nResult using iteration - "<<Factorial_I(n);
	}
	catch (int x)
	{
		cout<<"Factorial : "<<x;
	}
	catch (const char *a)
	{
		cout<<a;
	}
	
	cout<<"\n\nGCD  \n";
	cout<<"Enter two numbers :\n";
	cin>>n>>m;
	try
	{
		if(n<0&&m<0)
		throw "\nWrong input...\n";
		cout<<"\nResult using recursion - "<<GCD_R(m,n);
		cout<<"\nResult using iteration - "<<GCD_I(m,n);
	}
	catch (const char *a)
	{
		cout<<a;
	}
	
	cout<<"\n\nFibonacchi Series  \n";
	cout<<"Enter no of terms :\n";
	cin>>n;
	try
	{
		if(n<=0)
		throw "\nWrong input...\n";
			
		cout<<"\nResult using recursion - ";
		for(int i=1;i<=n;i++)
		cout<<Fibonacci_R(i)<<" ";
		cout<<"\nResult using iteration - \n";
		Fibonacci_I(n);
	}
	catch (const char *a)
	{
		cout<<a;
	}
	
	return 0;
}

int Factorial_R(int num)
{
	if(num==1)
	return 1;
	else
	return num*Factorial_R(num-1);
}

int GCD_R(int var_1, int var_2)
{
	if (var_2==0)
	return var_1;
	else
	return GCD_R(var_2,var_1%var_2);
}

int Fibonacci_R(int term)
{
	if(term==1)
	return 0;
	else if(term==2)
	return 1;
	
	return Fibonacci_R(term-2) + Fibonacci_R(term-1);
}

int Power_R(int m, int n)
{
	n=(n<0)?-n:n;
	if(n==0)
		return 1;
	else 
		return m*Power_R(m,n-1); 
}

int Factorial_I(int n)
{
	int fact=1;
	for(int i=1;i<=n;i++)
		fact*=i;
	return fact;
}

int Power_I(int m, int n)
{
	n=(n<0)?-n:n;
	int pow=1;
	for(;n!=0;n--)
	pow*=m;
	return pow;
}

int GCD_I(int num1,int num2)
{
	int t=0;
	while(num2!=0)
	{
		t=num1;
		num1=num2;
		num2=t%num2;
	}
	return num1;
}

void Fibonacci_I(int n)
{
	int a=0,b=1,s=0;
	cout<<"Fibonacci Series of "<<n<<" terms : ";
	for(int i=0;i<n;i++)
	{
		cout<<a<<" ";
		s=a+b;
		a=b;
		b=s;
	}
}
