#include <iostream>
#include <vector>

using namespace std;

int n;
pair<int,int> link_node[26];

void preorder(char data);
void inorder(char data);
void postorder(char data);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);	
	cout.tie(0);
	
	cin>>n;
	for(int i = 0; i<n; i++) {
		char p, ch1, ch2;
		cin>>p>>ch1>>ch2;
		link_node[p-'A'] = { ch1,ch2 };
	}
	preorder('A');
	cout<<'\n';
	inorder('A');
	cout<<'\n';
	postorder('A');
} 

void preorder(char data) {
	if(data == '.') {
		return;
	}
	cout<<data;
	preorder(link_node[data-'A'].first);
	preorder(link_node[data-'A'].second);
}

void inorder(char data) {
	if(data == '.') {
		return;
	}
	inorder(link_node[data-'A'].first);
	cout<<data;
	inorder(link_node[data-'A'].second);
}

void postorder(char data) {
	if(data == '.') {
		return;
	}
	postorder(link_node[data-'A'].first);
	postorder(link_node[data-'A'].second);
	cout<<data;
}


