
#include<iostream> 
#include <fstream>
using namespace std;
#include <string>
#include <windows.h>
#include <stdio.h>
static int no = 1;
//utility functions

			/************************************************************************************/
template<typename t>
t stringtoi(string s) {
	t number = 0;
	int l = s.length() - 1;
	for (int i = 0; i <= l; i++)
	{
		if (s[i] == '.') {
			number = std::stof(s.c_str());
			return number;
		}
	}

	for (int i = 0; l >= 0; l--, i++)
		number += (pow(10.0, double(i)))*(t(s[l]) - 48);
	return number;
}
string itos(int n) {

	string st = "";
	while (n) {  //int to string 

		st += char(n % 10) + 48;
		n = n / 10;
	}
	int l = st.length();
	char temp;
	for (int i = 0; i < l / 2; ++i) {//for inverting string 
		temp = st[i];
		st[i] = st[l - i - 1];
		st[l - i - 1] = temp;
	}
	return st;
}


/************************************************************************************/


//Linked List class
template <class DT> class Node {
public:
	DT value;
	Node *next;
};
template <class DT> class List {//index from 0 onwords
public:
	int count;
	Node <DT>*head;
	Node <DT>*cursor;

	List() {
		cursor = head = NULL;
		count = 0;
	}
	~List() {
		//	clear();
	}
	List<DT> operator =(List<DT> list) {
		this->clear();
		for (int i = 0; i < list.count; i++) {
			this->insert(list.returnAt(i));
		}
		return *this;

	}
	void insert(const DT &newDataItem)
	{
		cursor = head;
		Node <DT>*temp = new Node<DT>;
		temp->next = NULL;
		temp->value = newDataItem;
		if (!cursor)
		{
			head = temp;
			cursor = temp;
		}
		else
		{
			while (cursor->next)
			{
				cursor = cursor->next;
			}
			cursor->next = temp;
			cursor = temp;
		}
		count++;
	}
	void insertAt(const DT &newDataItem, int index)
	{
		if (index < 0)
			cout << "Index out of Range" << endl;
		else {
			count++;
			Node<DT> *temp = new Node<DT>;
			temp->value = newDataItem;
			if (index == 0)
			{
				temp->next = head;
				head = temp;
			}

			else {
				cursor = head;
				int tempInd = 1;

				while (cursor->next && tempInd < index)
				{
					cursor = cursor->next;
					tempInd++;
				}
				if (cursor->next) {
					temp->next = cursor->next;
					cursor->next = temp;
					cursor = temp->next;

				}
				else
				{
					cout << "Index out of Range" << endl;
					count--;
				}
			}
		}
	}
	DT returnAt(int index)
	{
		if (index < 0)
			cout << "1Index out of Range" << endl;
		else {
			if (index == 0)
				return head->value;
			else {
				cursor = head->next;
				int tempInd = 1;
				while (cursor && tempInd < index)
				{
					cursor = cursor->next;
					tempInd++;
				}
				if (cursor)
					return cursor->value;
				else
					cout << "2Index out of Range" << endl;
			}
		}
	}
	void returnAt(int index, DT &obj)
	{
		if (index <= 0)
			cout << "Index out of Range" << endl;
		else {
			if (index == 1)
				obj = head->value;
			else {
				cursor = head->next;
				int tempInd = 2;
				while (cursor && tempInd < index)
				{
					cursor = cursor->next;
					tempInd++;

				}
				if (cursor) {
					obj = cursor->value;
				}
				else
					cout << "Index out of Range" << endl;
			}
		}
	}
	void remove() {
		if (cursor)
		{
			count--;
			if (cursor->next)
			{
				Node<DT> *temp = cursor->next;
				cursor->value = temp->value;
				cursor->next = temp->next;
				delete temp;
			}
			else
			{
				if (cursor != head) {
					Node<DT> *temp = head;
					while (temp->next != cursor)
						temp = temp->next;
					temp->next = NULL;
					delete cursor;
					cursor = head;
				}
				else
				{
					delete cursor;
					cursor = head = NULL;

				}
			}
		}

	}
	bool removeAt(int index)
	{
		if (index >= 0 && head)
		{
			cursor = head;
			int tempInd = 0;
			while (cursor && tempInd != index)
			{
				cursor = cursor->next;
				tempInd++;
			}
			if (cursor)
			{
				remove();
				return 1;
			}
			else
			{
				cout << "Index out of Range" << endl;
				return 0;
			}
		}
		else
		{
			cout << "Index out of Range" << endl;
			return 0;
		}

	}
	void replaceAt(const DT &newDataItem, int index)
	{
		if (index >= 0 && head)
		{
			Node <DT> *temp = head;
			int tempInd = 0;
			while (temp && tempInd != index)
			{
				temp = temp->next;
				tempInd++;

			}
			if (temp)
			{
				cursor = temp;
				cursor->value = newDataItem;
			}
			else
				cout << "Index out of Range" << endl;
		}
		else
			cout << "Index out of Range" << endl;
	}
	void clear() {
		if (head)
		{
			cursor = head;
			while (cursor)
				remove();
		}
	}
	bool isEmpty() {

		if (head) return 0;
		else return 1;
	}
	void display() {
		if (!isEmpty())
		{
			cursor = head;
			cout << "List Pointed By Key is:" << '\n';
			while (cursor) {
				cout << cursor->value << endl;
				cursor = cursor->next;
			}
		}
		else
			cout << "No Edge" << endl << endl;
	}
	bool find(DT value, int &index)
	{
		cursor = head;
		index = 0;
		while (cursor) {
			if (cursor->value == value)
				return 1;
			cursor = cursor->next;
			index++;
		}
		return 0;

	}
};
//List class ends


			/************************************************************************************/



struct Duplicate {
	//public:
	int lineNo;
	string fileName;//data file reference (unn 10 files mei se)
	Duplicate(string s = "", int l = 0) {
		fileName = s;
		lineNo = l;
	}
	Duplicate operator = (const Duplicate d) {
		this->fileName = d.fileName;
		this->lineNo = d.lineNo;
		return *this;
	}
};
ostream& operator<<(ostream &obj, const Duplicate d) {
	ifstream read(d.fileName);
	if (read) {
		string line;
		for (int i = 0; i <= d.lineNo; ++i)
			getline(read, line);
		obj << line;
	}
	else obj << "Can't Open File From Duplicate" << endl;

	return obj;
}


/************************************************************************************/


template<typename T>
class ReferenceToFile {
public:
	T key;
	List<Duplicate> list;
	ReferenceToFile(string f, int l, T k) {

		key = k;
		Duplicate d;
		d.fileName = f;
		d.lineNo = l;
		list.insert(d);

	}
	ReferenceToFile(T k) {

		key = k;

	}
	ReferenceToFile() {}
	ReferenceToFile<T> operator = (ReferenceToFile<T> r) {
		this->key = r.key;
		this->list = r.list;
		return *this;
	}
	ReferenceToFile<T> operator = (T k) {
		this->key = k;
		return *this;
	}
	bool operator < (ReferenceToFile<T> r) {
		return this->key < r.key;

	}
	bool operator > (ReferenceToFile<T> r) {
		return this->key > r.key;

	}
	bool operator ==(ReferenceToFile<T> r) {
		return r.key == this->key;
	}
	bool operator >=(ReferenceToFile<T> r) {
		return this->key >= r.key;
	}
	bool operator <=(ReferenceToFile<T> r) {
		return this->key <= r.key;
	}
	bool operator < (T r) {
		return this->key < r;

	}
	bool operator > (T r) {
		return this->key > r;

	}
	bool operator ==(T r) {
		return r == this->key;
	}
	
	bool operator >=(T r) {
		return this->key >= r;
	}
	bool operator <=(T r) {
		return key <= key;
	}
	T operator [](int i) {
		return key;
	}

};
template<typename T>
ostream& operator<<(ostream &obj, const ReferenceToFile<T> &r) {

	for (int i = 0; i < r.list.count; ++i) {
		Duplicate temp = r.list.returnAt(i);
		ifstream file(temp.fileName);
		string line;
		if (file) {
			for (int i = 0; i <= temp.lineNo; i++)
				getline(file, line);
			obj << line;
		}
		else
			cout << "File didn't open";
	}
	return obj;
}


/************************************************************************************/

template<class T>
class BTree
{
public:
	string directory; // directory for storing nodess
	class BTreeNode
	{
	public:
		ReferenceToFile<T> *keys; // An array of keys 
		string *ref;//next file references 
		BTreeNode **C; // An array of child pointers 
		int keysNow;	 // Current number of keys 
		bool leaf; // Is true when node is leaf. Otherwise false 
		int t;	 // Minimum degree (defines the range for number of keys) 
		BTreeNode(int t1, bool leaf1)
		{
			t = t1;
			leaf = leaf1;
			keys = new ReferenceToFile<T>[2 * t - 1];
			C = new BTreeNode *[2 * t];
			ref = new string[2 * t];
			keysNow = 0;
		}
		void writeToFile(string path, BTreeNode *r) {

			ofstream obj(path);
			if (!obj)
				cout << "Can't open file" << endl;
			else {
				obj << r->leaf << "," << r->keysNow  << "\n";
				for (int i = 0; i < r->keysNow; i++) {
					obj << r->keys[i].key << "," << '"';
					for (int j = 0; j < r->keys[i].list.count; j++) {
						Duplicate temp = r->keys[i].list.returnAt(j);
						obj << temp.fileName << "," << temp.lineNo << ",";
					}
					obj << '"';
					if (!r->leaf)
						obj << r->ref[i] << "," << "\n";
					else
						obj << "\n";
				}
			}
			obj.close();
		}
		
		void traverse(string l, BTreeNode *cursor,const string &d) {
			if (!cursor->leaf) {
				for (int i = 0; i < cursor->keysNow; i++) {
					string l =	d + "\\" + "node" + itos(no++) + ".txt";
					cursor->ref[i] = l;
					
					traverse(l, cursor->C[i], d);
				}
			}
			writeToFile(l, cursor);
		}
		
		void insertNonFull(ReferenceToFile<T> k)
		{
			// Initialize index as index of rightmost element 
			int i = keysNow - 1;
			
			
			// If this is a leaf node 
			if (leaf == true)
			{
				// The following loop does two things 
				// a) Finds the location of new key to be inserted 
				// b) Moves all greater keys to one place ahead 
			
				while (i >= 0 && keys[i] >= k) //change to =>
				{
					if (keys[i] == k) {//handling duplicates
						for (int j = 0; j < k.list.count; j++)
							keys[i].list.insert(k.list.returnAt(j));
						return;
					}
					i--;
				}
				i = keysNow-1 ; 
				while (i >= 0 && keys[i] >= k) //change to =>
				{

					keys[i + 1] = keys[i];
					i--;
				}

				// Insert the new key at found location 
				keys[i + 1] = k;
				keysNow++;
			}
			else // If this node is not leaf 
			{
				// Find the child which is going to have the new key 
				while (i >= 0 && keys[i] >= k) {

					if (keys[i] == k) {//handling duplicates
						for (int j = 0; j < k.list.count; j++)
							keys[i].list.insert(k.list.returnAt(j));
						return;
					}
					i--;
				}
				i=keysNow-1;
				while (i >= 0 && keys[i] >= k) {

					i--;
				}

				//disk read should be from here
				/*string l = "node"+itos(no++)+".txt";
				writeToFile(l, keys);*/

				// See if the found child is full 
				if (C[i + 1]->keysNow == 2 * t - 1)
				{
					// If the child is full, then split it 
					splitChild(i + 1, C[i + 1]);

					// After split, the middle key of C[i] goes up and 
					// C[i] is splitted into two. See which of the two 
					// is going to have the new key 
					if (keys[i + 1] < k)
						i++;
				}
				C[i + 1]->insertNonFull(k);
			}
		}
		void splitChild(int i, BTreeNode *y)
		{
			// Create a new node which is going to store (t-1) keys 
			// of y 
			BTreeNode *z = new BTreeNode(y->t, y->leaf);
			z->keysNow = t - 1;

			// Copy the last (t-1) keys of y to z 
			for (int j = 0; j < t - 1; j++)
				z->keys[j] = y->keys[j + t];

			// Copy the last t children of y to z 
			if (y->leaf == false)
			{
				for (int j = 0; j < t; j++)
					z->C[j] = y->C[j + t];
			}

			// Reduce the number of keys in y 
			y->keysNow = t - 1;

			// Since this node is going to have a new child, 
			// create space of new child 
			for (int j = keysNow; j >= i + 1; j--)
				C[j + 1] = C[j];

			// Link the new child to this node 
			C[i + 1] = z;

			// A key of y will move to this node. Find location of 
			// new key and move all greater keys one space ahead 
			for (int j = keysNow - 1; j >= i; j--)
				keys[j + 1] = keys[j];

			// Copy the middle key of y to this node 
			keys[i] = y->keys[t - 1];

			// Increment count of keys in this node 
			keysNow = keysNow + 1;
			/*string l = "node"+itos(no++)+".txt";
			writeToFile(l, keys);*/
		}
		void clear() {}
	};
	BTreeNode *root; // Pointer to root node 
	int t; // Minimum degree 
	
	BTree(int _t)
	{
		root = NULL; t = _t;
	}
	void traverse() {//writing nodes on file
		if (root != NULL) {
			string l = directory +"\\"+ "root.txt";
			root->traverse(l, root, directory);
		}
	}
	void insert(ReferenceToFile<T> k)
	{
		// If tree is empty 
		if (root == NULL)
		{
			// Allocate memory for root 
			root = new BTreeNode(t, true);
			root->keys[0] = k; // Insert key 
			root->keysNow = 1; // Update number of keys in root 
		}
		else // If tree is not empty 
		{
			// If root is full, then tree grows in height 
			if (root->keysNow == 2 * t - 1)
			{
				// Allocate memory for new root 
				BTreeNode *s = new BTreeNode(t, false);
				// Make old root as child of new root 
				s->C[0] = root;
				// Split the old root and move 1 key to the new root 
				s->splitChild(0, root);
				// New root has two children now. Decide which of the 
				// two children is going to have new key 
				int i = 0;
				if (s->keys[0] == k) {//handling duplicates
					for (int j = 0; j < k.list.count; j++)
						s->keys[i].list.insert(k.list.returnAt(j));
					return;
				}
				if (s->keys[0] <= k) {
					
					i++;

				}
				s->C[i]->insertNonFull(k);

				// Change root 
				root = s;
			}
			else // If root is not full, call insertNonFull for root 
				root->insertNonFull(k);
		}
	}

	BTreeNode* LoadNodeFromFile(string path, BTreeNode *cursor) {

		ifstream obj(path);
		if (!obj)
		{
			//			cout << path << endl;
			cout << "Can't Open File For Writing Node" << endl;
			return 0;
		}
		else {
			cursor = new BTreeNode(t, 1);
			string line;
			getline(obj, line);
			cursor->leaf = int(line[0]) - 48;//as I created so [0]  for bool value		
			string temp = "";
			for (int i = 2; i < line.length(); ++i)//keys Count
				temp += line[i];

			cursor->keysNow = stoi(temp);


			for (int i = 0; i < cursor->keysNow && obj; ++i)
			{
				getline(obj, line);//line for node
				int j = 0;
				temp = "";
				while (line[j] != ',')
				{
					temp += line[j];//key
					j++;
				}
				
				/*if (std::is_same<T,string>::value)
					cursor->keys[i].key = temp;*/

				if	(std::is_same<T,int>::value)
					cursor->keys[i].key = stoi(temp);

				/*if	(std::is_same<T,float>::value)
					cursor->keys[i].key = stof(temp);*/
				
				temp = "";
				j += 2;//for a comma and '"'
				while (line[j] != '"')
				{
					Duplicate objT;
					while (line[j] != ',')
					{
						temp += line[j];
						j++;
					}
					objT.fileName = temp;
					j++; temp = "";
					while (line[j] != ',')
					{
						temp += line[j];
						j++;
					}

					objT.lineNo = stoi(temp);
					j++; temp = "";
					cursor->keys[i].list.insert(objT);
				}
				j++; temp = "";
				if (!(cursor->leaf))
				{
					while (line[j] != ',')
					{
						temp += line[j];//child Node string
						j++;
					}

					cursor->ref[i] = temp; temp = "";
				}
			}

		}

		obj.close();
		return cursor;
	}

	//--------------------------------------//
	BTreeNode* SearchNode(BTreeNode *cursor, T keyToFind, int &index, bool &ch) {
		int i = 0;
		while (cursor->keys[i] < keyToFind   && i < cursor->keysNow)
			i++;
		if (i < cursor->keysNow && cursor->keys[i] == keyToFind)
		{
			//	cout << cursor->keys[i];
			//	cursor->keys[i].list.display();
			//	return 1;
			index = i;
			ch = 1;
			return cursor;
		}
		if (!(cursor->leaf))
		{
			string path = cursor->ref[i];
			if (path == "")
				return 0;
			BTreeNode* cursor = root;
			//	if (cursor != root)
				//	cursor->clear;
			cursor = LoadNodeFromFile(path, cursor);

			return SearchNode(cursor, keyToFind, index, ch);
		}
		else return 0;
	}
	
	template <class u> 
	bool pointSearch(u key) {
		BTreeNode* cursor = root;

		int in = -1;
		bool ch = 0;
		cursor = SearchNode(cursor, key, in, ch);
		if (ch) {
			//		cout << 1;
			cursor->keys[in].list.display();
		}
		else cout << "Key Not Found" << endl;

		return ch;
		//if (SearchNode(cursor, key, in))
		//{
		//	cout << cursor->keys[in].key << endl;
		//	cursor->keys[in].list.display();
		//	return 1;
		//}
	}
	//---------------------------------//

	
	template <class u> void UpdateValue(T k, string Field, u oldVal, u newVal)
	{
		int f = FieldToInt(Field);
		if (f != -1) {
			BTreeNode *cursor = root;
			bool ch = 0; int in = -1;
			cursor = SearchNode(cursor, k, in, ch);
			if (ch)
			{
				List<Duplicate> list = cursor->keys[in].list;
				if (list.count == 1) {

				}
				else {


				}
			}
			else {
				cout << "Key For Updation is incorrect." << endl;
				return;
			}
		}
		else { cout << "You have entered Invalid Field Name to Update" << endl; }

	}

	int FieldToInt(string field)
	{
		if (field == "ID" || "id") { return 0; }
		if (field == "year" || field == "Year") { return 1; }
		if (field == "Cause" || "cause") { return 2; }
		if (field == "state" || field == "State") { return 3; }
		if (field == "Deaths" || "deaths") { return 4; }
		if (field == "death rate" || field == "Death Rate") { return 5; }
		return -1;
	}
	bool SearchRangeNodes(BTreeNode *cursor, T k1, T k2)
{
	for (int i = 0; i < cursor->keysNow; ++i)
	{
		//			int i = 0;
		if (cursor->keys[i].key > k1 && cursor->keys[i].key > k2)
		{
			if (cursor->leaf)
				return 0;
			else {//both keys less than key[i],so go down 
				string path = cursor->ref[i];
				if (path != "")
				{
					BTreeNode* temp = cursor;
					temp = LoadNodeFromFile(path, temp);
					return SearchRangeNodes(temp, k1, k2);
				}

				else return 0;

			}
		}
		else if (cursor->keys[i].key >= k1)
		{	//greater than or equal to k1
			int k = 0;//counting for how many nodes we have to visit
			int j = i;
			string *tempChildrenP;//for paths of that many children
			while (j < cursor->keysNow && cursor->keys[j].key <= k2)//for counting and displaying keys in given  range
			{
				cursor->keys[j].list.display();
				++k; ++j;
			}
			if (j <= cursor->keysNow && cursor->keys[j - 1].key <= k2)
				++k;
			if (!cursor->leaf) {//children exists in that node
				tempChildrenP = new string[k];//for holding k many child paths i.e string
				for (int temp = 0; temp < k; ++temp)//copying that children to our array
					tempChildrenP[temp] = cursor->ref[i + temp];
				for (int Count = 0; Count < k; ++Count) {//visiting children of that node
					cursor->clear();//disallocating memory to cusor
					if (tempChildrenP[Count] != "") {
						cursor = LoadNodeFromFile(tempChildrenP[Count], cursor);
						SearchRangeNodes(cursor, k1, k2);
					}
				}
			}
			return 1;
		}
	}

	if (!cursor->leaf && cursor->keys[cursor->keysNow - 1] < k2) {//last element of node
		string tempChildrenP = cursor->ref[cursor->keysNow];//for holding k many child paths i.e string
		cursor->clear();//disallocating memory to cusor
		if (tempChildrenP != "") {
			cursor = LoadNodeFromFile(tempChildrenP, cursor);
			SearchRangeNodes(cursor, k1, k2);
		}
	}
	else return 0;

}

bool RangeQuery(T k1, T k2)
{
	BTreeNode * cursor = root;
	return SearchRangeNodes(cursor, k1, k2);

}

};
//if key is integer or float


			/************************************************************************************/

template<typename t>
void readI(string path, int keytype, BTree <t> &b) {
	string line = "";
	//string directory;
	if (keytype == 1) {
			b.directory = "BTInID";
			CreateDirectoryA(b.directory.c_str(), NULL);
		}
		else if (keytype == 2) {
			b.directory = "BTInYear";
			CreateDirectoryA(b.directory.c_str(), NULL);

		}
		else if (keytype == 3) {
				b.directory="BTInDY";
			CreateDirectoryA(b.directory.c_str(), NULL);
			
		}
		else if (keytype == 4) {
			b.directory="BTInDR";
			CreateDirectoryA(b.directory.c_str(), NULL);
		}

for(int i=10;i>=1;i--)
{	
	string npath = path + itos(i) + ".csv";
	ifstream file(npath);
	if (file) {
		getline(file, line);
		int lineno = 1;
		line = "";
		while (!file.eof()) {
			string key = "";
		//	lineno = file.tellg();
			getline(file, line);
			int j = 0;
			if (keytype == 1)//keytype is ID
			{
				while (line != ""&& line[j] != ',')
					key += line[j++];
				j++;
			}
			else if (keytype == 2)//keytype is year
			{
				while (line != ""&&line[j] != ',')//seek to year
					j++;
				j++;
				while (line != ""&&line[j] != ',') {
					key += line[j];
					j++;
				}
			}
			else if (keytype == 3)//keytype is deaths
			{
				while(line!=""&&line[j]!=',')//seek to year
						j++;
				j++;
				while(line!=""&&line[j]!=',')//seek to causename
						j++;
				j++;
						
				if(line!=""&&line[j]=='"'){//if separator is ' "" '
						j++;
						while(line!=""&&line[j]!='"')//seek to causename2
								j++;
						j+=2;
				}else{
						while(line!=""&&line[j]!=',')//seek to causename2
							j++;
						j++;
						}
						
						while(line!=""&&line[j]!=',')//seek to state
							j++;
						j++;
						while(line!=""&&line[j]!=',')
							key+=line[j++];
					

			}
			else if (keytype == 4)//keytype is age adjusted death rate
			{
				while(line!=""&&line[j]!=',')//seek to year
							j++;
						j++;
						while(line!=""&&line[j]!=',')//seek to causename
							j++;
						j++;
						
						if(line!=""&&line[j]=='"'){//if separator is ' "" '
							j++;
							while(line!=""&&line[j]!='"')//seek to causename2
								j++;
						j+=2;
						}else{
							while(line!=""&&line[j]!=',')//seek to causename2
							j++;
						j++;
						}
						
						
						while(line!=""&&line[j]!=',')//seek to state
							j++;
						j++;
						while(line!=""&&line[j]!=',')//seek to deaths
							j++;
						j++;
						while(line!=""&&line[j]!=',')//seek to age adjusted rate
							j++;
						j++;

						while(line!=""&&j<line.length()&&line[j]!=',')
							key+=line[j++];

			}
			
			ReferenceToFile<t> obj(npath, lineno, stringtoi<t>(key));
			b.insert(obj);
			if(line!="")
			++lineno;
		}
		
		file.close();
	}

	else {
		cout << "DATA File didn't open" << endl;
	}
}
	
}
//if type is string
void readS(string path, int keytype, BTree<string> &b) {
	// key type
	//string directory;
	ifstream file;
	string line = "";
	string key;
	if (keytype == 1) {
			b.directory = "BTInCause";
			CreateDirectoryA(b.directory.c_str(), NULL);
		}
		else if (keytype == 2) {
			b.directory = "BTInState";
			CreateDirectoryA(b.directory.c_str(), NULL);
	}
	
for(int i=1;i<=10;i++)
{	
	string npath = path + itos(i) + ".csv";	
	file.open(npath);
	if (file) {
		getline(file, line);
		int lineno = 1;
		
		while (!file.eof()) {
			line = "";
			getline(file, line);
			int j = 0;
			key = "";
			if (keytype == 1)//keytype is cause name
			{
				while(line!=""&&line[j]!=',')//seek to year
							j++;
						j++;
						while(line!=""&&line[j]!=',')//seek to causename
							j++;
						j++;
						
						if(line!=""&&line[j]=='"'){//if separator is ' "" '
							j++;
							while(line!=""&&line[j]!='"')//seek to causename2
								j++;
						j+=2;
						}else{
							while(line!=""&&line[j]!=',')//seek to causename2
							j++;
						j++;
						}
						
						while(line!=""&&line[j]!=',')
							key+=line[j++];

			}
			else if (keytype == 2)//keytype is state
			{
				while(line!=""&&line[j]!=',')//seek to year
							j++;
						j++;
						while(line!=""&&line[j]!=',')//seek to causename
							j++;
						j++;
						
						if(line!=""&&line[j]=='"'){//if separator is ' "" '
							j++;
							while(line!=""&&line[j]!='"')//seek to causename2
								j++;
						j+=2;
						}else{
							while(line!=""&&line[j]!=',')//seek to causename2
							j++;
						j++;
						}
						while(line!=""&&line[j]!=',')
							j++;
						j++;
						while(line!=""&&line[j]!=',')
							key+=line[j++];
					
					}
			ReferenceToFile<string> obj(npath, lineno, key);
			b.insert(obj);
		if (line != "")
			++lineno;
			}	
	file.close();
		}
	
		
	else {
		cout << "File didn't open";
	}
}
	
}
