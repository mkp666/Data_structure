#include <cstdio>
#include <cmath>

double a[5];
#define EPS 1e-6

bool isZero(double x){
	return fabs(x) <= EPS; 
}

bool count24(double a[], int n){
	if(n == 1){
		if(isZero(a[0] - 24))
			return true;
		else
			return false;
	}
	double b[5];
	for(int i = 0; i < n-1; i++)
		for(int j = i+1; j < n; j++){
			int m = 0;
			for(int k = 0; k < n; k++)
				if( k != i && k != j)
					b[m++] = a[k];
			b[m] = a[i] + a[j];
			if(count24(b, m+1))
				return true;
			b[m] = a[i] - a[j];
			if(count24(b, m+1))
				return true;
			b[m] = a[j] - a[i];
			if(count24(b, m+1))
				return true;
			b[m] = a[i] * a[j];
			if(count24(b, m+1))
				return true;
			if(!isZero(a[j])){
				b[m] = a[i]/a[j];
				if(count24(b,m+1))
					return true;
			}
			if(!isZero(a[i])){
				b[m] = a[j]/a[i];
				if(count24(b,m+1))
					return true;
			}
		}
	return false;
}

int main(){
	while(true){
		for(int i = 0; i < 4; i++)
			scanf("%lf", &a[i]);
		if(isZero(a[0]))
			break;
		if(count24(a,4))
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}
