#include<iostream>
using namespace std;
//Maleeha Hafeez S2025376059

/* Q1.A.1: Contiguous memory means elements are stored side-by-side in RAM Arrays use it so the computer can calculate the address of any element using a simple formula. The advantage is "Random Access," allowing us to jump to any index instantly
Q1.A.2: A memory leak is when memory is allocated but not freed Scenario: Creating a dynamic array inside a loop without deleting it, causing the RAM to fill up over time.
Q1.A.3: Fixed arrays have a set size; dynamic arrays can change. fixed size matters because we can not add more elements later.
Q1.A.4: Access is O(1) because we can calculate the exact address of any index. linked list needs traversal so it needs On.
*/

int linearSearch(int arr[],int size,int key){
for(int i=0;i<size;i++){
if(arr[i]==key)return i;}
return -1;}

void findMinMax(int arr[],int size,int &minVal,int &maxVal){
minVal=maxVal=arr[0];
for(int i=1;i<size;i++){
if(arr[i]<minVal)minVal=arr[i];
if(arr[i]>maxVal)maxVal=arr[i];}}

/* Q2.A.1: It compares neighbors and swaps them; the largest "bubbles" to the end
Q2.A.2: Worst/Average: O(n^2), Best: O(n)
optimisation stops early if no swaps happen
Q2.A.3: Selection sort is often preferred for fewer swaps
bubble sort is simpler and used for simpler arrays.
*/

void bubbleSort(int arr[],int size,int &swapCount){
swapCount=0;
for(int i=0;i<size-1;i++){
bool swapped=false;
for(int j=0;j<size-i-1;j++){
if(arr[j]>arr[j+1]){
swap(arr[j],arr[j+1]);
swapCount++;
swapped=true;}}
cout<<"After pass "<<i+1<<": ";
for(int k=0;k<size;k++)cout<<arr[k]<<" ";
cout<<endl;
if(!swapped)break;}}

/* Q3.A.1: The array must be sorted this is important because it divides the array into halves
Q3.A.2 Dry-run Binary Search on {2,5,8,12,16,23,38,45} with key = 23.
low=0 high=7 mid=3 ->12 so go right
low=4 high=7 mid=5 ->23 found at index 5
Q3.A.3: It's faster because it eliminates half the data in each step
linear search is O(n) because it checks each element.
*/

int binarySearch(int arr[],int size,int key,int &iterations){
int low=0,high=size-1;
iterations=0;
while(low<=high){
iterations++;
int mid=(low+high)/2;
if(arr[mid]==key)return mid;
else if(arr[mid]<key)low=mid+1;
else high=mid-1;}
return -1;}

/* Q4.A.1: Big O describes the upper bound (worst-case) growth rate of an algorithm. We use it instead of seconds because hardware and background tasks change runtime, but the step-count logic remains the same
Q4.A.2: Analogy: A race. Big O is the slowest possible time you'll finish. Big Omega is your personal best record. Big Theta is your consistent average speed.
Q4.A.3: Fast to Slow: O(1) < O(log n) < O(n) < O(n log n) < O(n^2)
Q4.A.4: Space Complexity is the extra memory used by an algorithm. An array of size n created internally results in O(n) space complexity
Q4.A.5: Incorrect. As 'n' grows to millions, the O(n^2) curve grows so steeply that even the fastest computer cannot beat O(n log n)
Q4.B.1 Nested loop: O(n^2)
*/

void nestedLoop(int arr[],int n){
for(int i=0;i<n;i++)
for(int j=0;j<n;j++)
cout<<arr[i]+arr[j]<<" ";}

void singleLoop(int arr[],int n){
for(int i=0;i<n;i++)
cout<<arr[i]<<" ";}

bool checkArrays(int A[],int B[],int n){
for(int i=0;i<n;i++){
bool found=false;
for(int j=0;j<n;j++){
if(A[i]==B[j]){
found=true;
break;}}
if(!found)return false;}
return true;}

/* Q5.A.1: A Singly Linked List is a series of nodes where each node points to the next. Unlike arrays, nodes are non-contiguous
Insert Head: O(1), Insert Tail: O(n), Delete Value: O(n)
Q5.A.3: Not deleting node causes memory leak
*/

struct Node{
int data;
Node*next;};

class LinkedList{
public:
Node*head;
LinkedList(){head=NULL;}

void insertAtHead(int val){
Node*newNode=new Node();
newNode->data=val;
newNode->next=head;
head=newNode;}

void insertAtTail(int val){
Node*newNode=new Node();
newNode->data=val;
newNode->next=NULL;
if(head==NULL){head=newNode;return;}
Node*temp=head;
while(temp->next!=NULL)temp=temp->next;
temp->next=newNode;}

void display(){
Node*temp=head;
while(temp!=NULL){
cout<<temp->data<<" -> ";
temp=temp->next;}
cout<<"NULL\n";}

void deleteByValue(int val){
if(head==NULL)return;
if(head->data==val){
Node*temp=head;
head=head->next;
delete temp;
return;}
Node*temp=head;
while(temp->next!=NULL&&temp->next->data!=val)
temp=temp->next;
if(temp->next==NULL){
cout<<"Value not found\n";
return;}
Node*delNode=temp->next;
temp->next=temp->next->next;
delete delNode;}};

int main(){

int arr1[10]={4,15,7,23,1,9,42,18,6,30};
int index=linearSearch(arr1,10,42);
if(index!=-1)cout<<"42 found at index "<<index<<endl;
else cout<<"42 not found\n";

int minVal,maxVal;
findMinMax(arr1,10,minVal,maxVal);
cout<<"Min: "<<minVal<<" Max: "<<maxVal<<endl;

int arr2[7]={64,34,25,12,22,11,90};
int swaps;
cout<<"Before sorting: ";
for(int i=0;i<7;i++)cout<<arr2[i]<<" ";
cout<<endl;

bubbleSort(arr2,7,swaps);
cout<<"Total swaps: "<<swaps<<endl;

int arr3[10]={2,5,8,12,16,23,38,45,56,72};
int iterations;

int result=binarySearch(arr3,10,56,iterations);
cout<<"Index of 56: "<<result<<", Iterations: "<<iterations<<endl;

result=binarySearch(arr3,10,100,iterations);
cout<<"Searching 100 -> Index: "<<result<<", Iterations: "<<iterations<<endl;

LinkedList list;
list.insertAtHead(10);
list.insertAtTail(20);
list.insertAtHead(5);
list.insertAtTail(30);
list.insertAtHead(1);

cout<<"Linked List: ";
list.display();

list.deleteByValue(20);
list.deleteByValue(100);

cout<<"After deletion: ";
list.display();

return 0;}

// GitHub: https://github.com/YourUsername/YourRepoName
