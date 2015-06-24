#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <queue>
#include "vec2.h"
#include "vec3.h"
#include "segment.h"
#include "polygon.h"

using namespace std;
using namespace fim;

int main()
{
	if (!freopen("in.txt", "r", stdin)) {
		cout << "Fail open in.txt!" << endl;
		exit(0);
	};
	if (!freopen("out.txt", "w", stdout)) {
		cout << "Fail open out.txt!" << endl;
		exit(0);
	}
	Polygon ori;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		double tx, ty;
		cin >> tx >> ty;
		ori.push_back(vec2(tx, ty));
	}
	///*
	auto ans = ori.convexDecomposition();
	for (int i = 0; i < (int)ans.size(); i++) {
		auto tmp = ans[i];
		cout << tmp.size() << endl;
		for (int j = 0; j < (int)tmp.size(); j++) {
			cout << tmp[j].x << " " << tmp[j].y << endl;
		}
	}
	//*/
	/*
	auto ans = ori.collideRay(vec2(-0.115, 0.485), vec2(1.675, 2.245) - vec2(-0.115, 0.485));
	cout << ans.size() << endl;
	for (int i = 0; i < (int)ans.size(); i++) {
		cout << ans[i].x << " " << ans[i].y << endl;
	}
	*/
	return 0;
}

