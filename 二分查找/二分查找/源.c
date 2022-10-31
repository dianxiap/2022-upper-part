//#define _CRT_SECURE_NO_WARNINGS 1
//#include <stdio.h>
//int q(int a[],int key,int len) {
//	int left=0, right=len-1;
//	int mid;
//	while (left<=right) {
//		mid = (left + right) / 2;
//
//		if (a[mid] > key)right = mid - 1;
//		else if (a[mid] < key)left = mid + 1;
//		else return mid;
//	}
//	return -1;
//}
//
//int main() {
//	int arr[] = { 0,5,1,2,4,9,6,3,7 };
//	int k = 5;
//	int len = sizeof(arr) / sizeof(arr[0]);
//	int p=q(arr,k,len);
//	printf("%d", p);
//	return 0;
//}
//#include <stdio.h>
//int main() {
//	int n = 43;
//	printf("%d", printf("%d", printf("%d", n)));
//}
//



int p(x) {
	x++;
	return x;
}
int q(x) {
	x-=2;
}
int main() {
	int x = 2;
	printf("%d",p(q(x)));

}