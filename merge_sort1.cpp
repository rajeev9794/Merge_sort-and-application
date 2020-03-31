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
void merge(int a[],int l,int m,int r)
{
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
		if(l1[i]>=r1[j])
		{
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
}
void mergesort(int a[],int l,int r)
{
	if(l<r)
	{
		int m=l+(r-l)/2;
		mergesort(a,l,m);
		mergesort(a,m+1,r);
		merge(a,l,m,r);
	}
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
		int a[n];
		for(int i=0;i<n;i++)
			cin>>a[i];
		mergesort(a,0,n-1);
		for(int i=0;i<n;i++)
			cout<<a[i]<<" ";
	}
}