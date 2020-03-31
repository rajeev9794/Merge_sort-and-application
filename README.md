# Merge_sort-and-application
In this application we will implement the merge_Sort and Inversion_count application to solve different algorithmic problem.
It tells about the number of inversion required to sort the array.
Ex-{6,4,3,1} after sorting {1,3,4,6}
the inversion {(6,4),(6,3),(6,1),(4,3),(4,1),(3,1)} so tatal number of inversion required is 6.
The approach used for inversion count using merge sort-
We know that at time of merging array is sorted and if i is index from first half and j is index from second half and if(a[i]>a[j])
then inv_count+=(mid-i); that value is larger then current value.
