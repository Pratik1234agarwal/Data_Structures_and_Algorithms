#include <bits/stdc++.h>
using namespace std;

class ProductOfKNumbers {
public:
	vector<int> stack;
    int cur = 0;
	ProductOfKNumbers() {
		stack.emplace_back(1);
	}

	void add(int num) {
		if(num == 0){
            stack.clear();stack.emplace_back(1);
            cur = 0;
        }else{
            stack.emplace_back(stack[cur] * num);
            cur++;
        }
	}

	int getProduct(int k) {
		if(cur >= k){
            return stack[cur]/stack[cur-k]; 
        }else{
            return 0;
        }
	}
};

int main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);

	int Q;
	cin >> Q;

	ProductOfKNumbers productOfKNumbers;

	while(Q--) {
		string op;
		cin >> op;

		if (op == "add") {
			int num;
			cin >> num;
			productOfKNumbers.add(num);
		}
		else {
			int k;
			cin >> k;

			cout << productOfKNumbers.getProduct(k) << "\n";
		}
	}

	return 0;
}