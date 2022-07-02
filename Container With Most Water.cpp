Naive Solution:  

Approach: The idea is quite simple and involves checking every pair of boundaries or array element and find out the maximum area under any pair of boundaries.
Algorithm: 
Create a nested loop, the outer loop traverses the array from 0 to end (index of this loop is i).
The inner loop traverses the array from i + 1 to end (index of this loop is j).
Find the water that can be contained in the container with height of boundaries as array[i] and array[j], i.e area = (j – i)* min(array[i],array[j]), if this area is greater than current maximum, update the current maximum
Print the current maximum.
  
  CODE : // C++ code for Max
// Water Container
#include <iostream>
using namespace std;

int maxArea(int A[], int len)
{
	int area = 0;
	for (int i = 0; i < len; i++) {
		for (int j = i + 1; j < len; j++) {
			// Calculating the max area
			area = max(area, min(A[j], A[i]) * (j - i));
		}
	}
	return area;
}

// Driver code
int main()
{
	int a[] = { 1, 5, 4, 3 };
	int b[] = { 3, 1, 2, 4, 5 };

	int len1 = sizeof(a) / sizeof(a[0]);
	cout << maxArea(a, len1);

	int len2 = sizeof(b) / sizeof(b[0]);
	cout << endl << maxArea(b, len2);
}

/*Time Complexity: O(n^2). 
As nested traversal of the array is required, so time complexity is O(n^2)*/

APPROACH 2 : Keep two index, first = 0 and last = n-1 and a value max_area that stores the maximum area.
Run a loop until first is less than the last.
  
  // C++ code for Max
// Water Container
#include<iostream>
using namespace std;

int maxArea(int A[], int len)
{
	int l = 0;
	int r = len -1;
	int area = 0;
	
	while (l < r)
	{
		// Calculating the max area
		area = max(area, min(A[l],
						A[r]) * (r - l));
						
			if (A[l] < A[r])
				l += 1;
				
			else
				r -= 1;
	}
	return area;
}

// Driver code
int main()
{
	int a[] = {1, 5, 4, 3};
	int b[] = {3, 1, 2, 4, 5};
	
	int len1 = sizeof(a) / sizeof(a[0]);
	cout << maxArea(a, len1);
	
	int len2 = sizeof(b) / sizeof(b[0]);
	cout << endl << maxArea(b, len2);
}

T.C -> O(n)
