#include "iostream"
#include "time.h"
using namespace std;
template<typename T>
void Swap(T& a, T& b)
{
	T s;
	s=a;a=b;b=s;
}
template<typename T>
void quicksort(T* list, int* I, int m,int n)
{
   int i,j,k;
   T key;
   if( m < n)
   {
      k = (m+n)/2;
      Swap(list[m],list[k]);
	  Swap(I[m],I[k]);
      key = list[m];
      i = m+1;
      j = n;
      while(i <= j)
      {
         while((i <= n) && (list[i] <= key))
                i++;
         while((j >= m) && (list[j] > key))
                j--;
         if( i < j){
                Swap(list[i],list[j]);
				Swap(I[i],I[j]);
		 }
      }
     // 交换两个元素的位置
      Swap(list[m],list[j]);
	  Swap(I[m],I[j]);
     // 递归地对较小的数据序列进行排序
      quicksort(list,I,m,j-1);
      quicksort(list,I,j+1,n);
   }
}
template<typename T>
void quicksort(T* list, int m,int n)
{
   int i,j,k;
   T key;
   if( m < n)
   {
      k = (m+n)/2;
      Swap(list[m],list[k]);
      key = list[m];
      i = m+1;
      j = n;
      while(i <= j)
      {
         while((i <= n) && (list[i] <= key))
                i++;
         while((j >= m) && (list[j] > key))
                j--;
         if( i < j){
                Swap(list[i],list[j]);
		 }
      }
     // 交换两个元素的位置
      Swap(list[m],list[j]);
     // 递归地对较小的数据序列进行排序
      quicksort(list,m,j-1);
      quicksort(list,j+1,n);
   }
}
template<typename T>
void _print(T* a,int* I, int n)
{
	for(int i=0;i<n;i++)
		cout<<a[i]<<" "<<I[i]<<endl;
}
void main()
{
	float a[2000];
	int I[2000];
	for(int i=0;i<2000;i++){
		a[i]=rand()*2.0;
		I[i]=i;
	}
	int t=clock();
	quicksort(a,I,0,1999);
	cout<<clock()-t<<endl;
	int stop;
	cin>>stop;
}