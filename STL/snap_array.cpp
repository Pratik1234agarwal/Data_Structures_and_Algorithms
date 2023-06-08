#include <bits/stdc++.h>
using namespace std;

class SnapshotArray
{
    int snapId = 0;
    int maxsize;
    unordered_map<int,vector<int>> m;
public:
	
	SnapshotArray(int length)
	{
		maxsize = length;
        snapId = 0;
        for(int i=0;i<length;i++){
            m[i] = {0};
        }
	}

	void set(int index, int val)
	{
	 	if(m[index].size()-1 == snapId){
            m[index].pop_back();
        }
        m[index].push_back(val);
	}

	int snap()
	{
        int temp = snapId;
        snapId++;
        return temp;

	}

	int get(int index, int snap_id)
	{
		return m[index][snap_id];
	}
};

int main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);

	int Q, L;
	cin >> Q >> L;

	SnapshotArray snapshotArray(L);

	while (Q--)
	{
		string op;
		cin >> op;

		if (op == "set")
		{
			int index, val;
			cin >> index >> val;

			snapshotArray.set(index, val);
		}
		else if (op == "get")
		{
			int index, snap_id;
			cin >> index >> snap_id;

			cout << snapshotArray.get(index, snap_id) << "\n";
		}
		else if (op == "snap")
		{
			cout << snapshotArray.snap() << "\n";
		}
	}

	return 0;
}