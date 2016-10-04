#include <stdio.h>
#include <memory.h>

int n,t;
double p;

bool check[2020][2020];
double dp[2020][2020];

double solve(int idx,int time) {
	if( idx == 0 || time == 0) return 0.;
	if(check[idx][time]) return dp[idx][time];
	
	double part1 = p*(1 + solve(idx-1,time-1));
	double part2 = (1-p)*(solve(idx,time-1));
	
	//printf("%lf %lf\n",part1,part2);
	dp[idx][time] = part1+part2;
	check[idx][time] = true;
	
	return dp[idx][time];
}


int main() {
	scanf("%d %lf %d",&n,&p,&t);
	
	//printf("%d %lf %d",n,p,t);
	for(int i = 0; i < 2020;i++) {
		for(int j = 0; j < 2020;j++) {
			check[i][j] = false;
		}
	}
	
	double result = solve(n,t); 
	printf("%lf",result);
	
	return 0;
}
