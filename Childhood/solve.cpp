#include <iostream>
using namespace std;
int main(){
	int n;
    cin >> n;
	int a[n], b[n];
	bool ans = false;
	for(int i=0; i<n; i++){
		cin >> a[i] >> b[i];
	}
	for(int i=0; i<n; i++){
		for(int j=i; j<n; j++){
			if(b[j] + b[i] == 0 && (a[i] + b[i] == a[j])){
				ans = true;break;
			}
		}
	}
	cout << ( ans ? "YES\n" : "NO\n");
}
