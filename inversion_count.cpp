#include<bits/stdc++.h>
#include<algorithm>
#include<stack>
#include<queue>
using namespace std;
typedef long long int ll;
#define mod 1000000007
int max(int a,int b){return(a>b?a:b);}
int min(int a,int b){return((a<b)?a:b);}
int gcd(int a,int b)
{
	if(a==0)
	return b;
	else
	return gcd(b%a,a);
}
int merge(int a[],int l,int m,int r)
{	int inv=0;
	int n1=m-l+1;
	int n2=r-m;
	int l1[n1],r1[n2];
	for(int i=0;i<n1;i++)
		l1[i]=a[l+i];
	for(int j=0;j<n2;j++)
		r1[j]=a[m+1+j];
	int i=0,j=0,k=l;
	while(i<n1&&j<n2)
	{
		if(l1[i]>r1[j])
		{	
			inv+=n1-i;
			a[k]=r1[j];
			k++;
			j++;
		}
		else
		{
			a[k]=l1[i];
			k++;
			i++;
		}
	}
	while(i<n1)
	{
		a[k]=l1[i];
			k++;
			i++;
	}
	while(j<n2)
	{
		a[k]=r1[j];
			k++;
			j++;
	}
	return inv;
}
int mergesort(int a[],int l,int r)
{	int inv=0;
	if(l<r)
	{
		int m=l+(r-l)/2;
		//cout<<"l="<<l<<"r="<<r<<" m="<<m<<endl;
		inv=mergesort(a,l,m);
		inv+=mergesort(a,m+1,r);
		inv+=merge(a,l,m,r);
	}
	return inv;
}
int main()
{	
	#ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output1.txt","w",stdout);
    #endif
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int a[n],invc;
		for(int i=0;i<n;i++)
			cin>>a[i];
		invc=mergesort(a,0,n-1);
		cout<<"The sorted array is:";
		for(int i=0;i<n;i++)
			cout<<a[i]<<" ";
		cout<<"\ninversion count="<<invc<<endl;
	}
}
