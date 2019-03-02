int main() {
  int arr[5]={1,2,3,4,5};
  int *pointer = arr; 
  int i;

  for(i=0;i<2;i++) 
  {
    int temp=*(pointer + i);
    *(pointer + i) = *(pointer + 4 - i);
    *(pointer + 4 - i)  = temp;
  } 

  for(i=0;i<5;i++) 
    cout<<arr[i]<<"\t";  

  return 0;
}
