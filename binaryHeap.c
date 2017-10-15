#include<stdio.h>
#include<stdlib.h>
#define maxheap 1
#define minheap 0
typedef struct heap{
	int* array;
	int count;
	int capacity;
	int heap_type;
}heap;
 heap* createHeap(int capacity,int heap_type){
	 heap* h=(heap*)malloc(sizeof(heap));
	 if(h==NULL){
		 printf("memory error");
		 return;
	 }
	 h->heap_type=heap_type;
	 h->count=0;
	 h->array=(int*)malloc(sizeof(int)*(h->capacity));
	 if(h->array==NULL){
		 printf("memory array error"); return;
	 }
	 return h;
 }
 int Parent(heap* h,int i){
	 if(i<=0||i>=h->count)
		 return -1;
	 return (i-1)/2;
 }
 int Leftchild(heap* h,int i){
	 int left=2*i+1;
	 if(left>=h->count)
		 return -1;
	 return left;
 }
 int Rightchild(heap* h,int i){
	 int right=2*i+2;
	 if(right>=h->count)
		 return -1;
	 return right;
 }
 int Getmaximum(heap* h){
	 if(h->count==0)
		 return -1;
	 return h->array[0];
 }
 proclateDown(heap* h,int i){
	 int left,right,max,temp;
	 left=Leftchild(h,i);
	 right=Rightchild(h,i);
	 if(left!= -1&& h->array[left]>h->array[i])
		 max=left;
	 else 
		 max=i;
	 if(right!= -1&& h->array[right]>h->array[max])
		 max=right;
	 if(max==i||(right== -1 && left== -1)) return;
	 if(max!= i){
		 temp=h->array[i];
		 h->array[i]=h->array[max];
		 h->array[max]=temp;
		 }
		 proclateDown(h,max);
 }
 insert(heap* h,int data){
	 int i;
if(h->count==h->capacity)
{  printf("\nheap is full"); return;}  
 
	 h->count++;
	 i=h->count-1;
	 while(i>0&& data> h->array[(i-1)/2]){
		 h->array[i]= h->array[(i-1)/2];
		 i=(i-1)/2;	 }
		 h->array[i]=data;
 }
 void destroyHeap(heap* h){
	 if(h==NULL)
		 return;
	 free(h->array);
	 free(h);
	 h=NULL;
 }
 int deleteMax(heap* h){
	 int data;
	 if(h->count==0) return -1;
	 data=h->array[0];
	 h->array[0]=h->array[h->count-1];
	 h->count--;
	 proclateDown(h,0);
	 return data;
 }
 int main(){
	heap* h=createHeap(20,maxheap); int j;
	insert(h,31);
	insert(h,10);
	insert(h,16);
	insert(h,9);
	insert(h,8);
	insert(h,14);
	insert(h,12);
	insert(h,3);
	insert(h,1);
	insert(h,5);
	insert(h,7);
	insert(h,19);
	proclateDown(h,0);
	printf("\n maximum elemnt is %d",Getmaximum(h));int m=deleteMax(h);
	for(j=0;j<12;j++) printf("\n %d--%d",j, h->array[j]);
	printf("\n m is--%d",m);
	while(h->count!=0){printf("\n %d",deleteMax(h));}
    destroyHeap(h);
	
	}