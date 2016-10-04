#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>

using namespace std;
int k,n;

long long input[100010];
int cum[100010];
bool qu[100010];
char inputString[50];


int main() {

	scanf("%d %d",&n,&k);

	for(int i = 0; i< n;i++) {

		scanf("%s",inputString);

		if(inputString[0] == '?') {
			qu[i] = true;
		} else {
			qu[i] = false;
			long long temp = 1;
			input[i] = 0;
			for(int j = strlen(inputString)-1;j>0;j--) {
				input[i] += (inputString[j]-'0')*temp;
				temp*=10;
			}

			if(inputString[0] == '-') input[i]*=(-1);
			else input[i] += (inputString[0]-'0')*temp;

		}
	}
	
	
	for(int i = 0;i < k;i++) {

		int firstOcc = -1;

		if(!qu[i]) {
			firstOcc = i; 
		}
		
		for(int j = i+k; j < n;j+=k) {
			if(!qu[j]) {
				if(firstOcc != j-k) {
					if(firstOcc == -1) {
					
						long long numbers = (j / k )/2;
						numbers = min(numbers,input[j]-1);
						
						for(int l = j - k; l >= 0; l-=k) {
							input[l] = numbers;
							numbers--;
						} 
						
					} else {
						long long numbers = (j -(firstOcc+k))/k;
						
						if(input[firstOcc] > 0 && input[j] > 0 ) {
							long long start = input[firstOcc]+1;					
							for(int l = firstOcc + k; l < j; l+=k) {
								input[l] = start;
								start++;
							} 
						} else if(input[firstOcc] < 0 && input[j] < 0) {
							long long start = input[j] -1;
							for(int l = j-k; l > firstOcc; l-=k) {
								input[l] = start;
								start--;
							}
						} else {
							long long start;
							numbers/=2;
							if(numbers > input[j]) numbers += (numbers - input[j]) + 1;
							
							start = max(input[firstOcc]+1,(long long)(-1*numbers));
							
							for(int l = firstOcc+k; l < j;l+=k) {
								input[l] = start;
								start++;
							}
						}
					} 
				}
				firstOcc = j;
			}
		}
		if(firstOcc + k < n) {
			if(firstOcc == -1) {
				long long numbers = -1*(n / k)/2;
				for(int l = i; l < n; l+=k) {
					input[l] = numbers;
					numbers++;
				} 
			} else {
				long long start;
				if(input[firstOcc] > 0 ) start = input[firstOcc] + 1;
				else start = max(input[firstOcc]+1, (long long)(-1*((n-(firstOcc+k))/k)/2));
				
				for(int l = firstOcc + k;l < n;l+=k) {
					input[l] = start;
					start++;
				}
			}
		}
	}
	
	bool flag = true;
	for(int i = 0; i < n-k;i++) { 
		if(input[i] >= input[i+k]) flag = false;
	}
	
	if(flag) {
		for(int i = 0; i< n;i++) cout << input[i] << " ";
	} else {
		printf("Incorrect sequence");
	}
	
	return 0;
}

