#include <iostream>

using namespace std;

class Tree
{
public:
	Tree(char code);
	~Tree();

	void printPreorder();
	void printPostorder();
	void printInorder();

	char code;
	Tree* a;
	Tree* b;

};

Tree::Tree(char code) : code(code)
{
	a = NULL;
	b = NULL;
}

Tree::~Tree()
{
}

void Tree::printPreorder()
{
	cout << code;
	if (a) a->printPreorder();
	if (b) b->printPreorder();
}

void Tree::printPostorder()
{
	if (a) a->printPostorder();
	if (b) b->printPostorder();
	cout << code;
}

void Tree::printInorder()
{
	if (a) a->printInorder();
	cout << code;
	if (b) b->printInorder();
}


int main() {

	int N;
	cin >> N;

	pair<char, char> treeset[26] = { {0,0}, };

	Tree* trees[26] = { nullptr, };

	for (size_t i = 0; i < N; i++)
	{
		char id, a, b;
		cin >> id >> a >> b;

		trees[id - 'A'] = new Tree(id);

		if (a != '.')
			treeset[id - 'A'].first = a;
		if (b != '.')
			treeset[id - 'A'].second = b;
	}

	for (size_t i = 0; i < 26; i++)
	{
		if (treeset[i].first)
			trees[i]->a = trees[treeset[i].first - 'A'];
		if (treeset[i].second)
			trees[i]->b = trees[treeset[i].second - 'A'];
	}

	trees[0]->printPreorder(); cout << endl;
	trees[0]->printInorder(); cout << endl;
	trees[0]->printPostorder(); cout << endl;

	for (auto& i : trees)
	{
		if (i) delete i;
	}
	return 0;
}