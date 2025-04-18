/*

	Implementation of HashMap/HashTable

*/

#include<iostream>

using namespace std;

class node {

public :

	int K;
	int V;
	node* next;

	node(int K, int V) {
		this->K = K;
		this->V = V;
		this->next = NULL;
	}

};

class HashMap {
	int N; //  to store the hash table capacity
	int M; //  to store the hash table size
	double L; // to store the load factor threshold

	node** T; // to store the pointer to the  dynamic
	// array that represents the hash table

	int hashFn(int K) {
		// transform K into a hash index
		return K % N;
	}

	void transfer(node* head) {
		// 1. rehash (K, V) pairs present in the linkedList represented
		//    by "head" pointer to the updated hashMap

		node* temp = head;

		while (temp != NULL) {
			insert(temp->K, temp->V);
			temp = temp->next;
		}

		// 2. release memory allocated for the linkedList represented
		//    by "head" pointer

		while (head != NULL) {
			temp = head;
			head = head->next;
			delete temp;
		}
	}

	void rehash() {

		// 1. save pointer to the current hashMap and its capacity
		node** oldT = T;
		int oldN = N;

		// 2. create a hashMap with double capacity

		T = new node*[2 * N];
		for (int i = 0; i < 2 * N; i++) {
			T[i] = NULL;
		}
		this->N = 2 * N;
		this->M = 0;

		// 3. transfer (K, V) pairs from old hashMap to the updated hashMap

		for (int i = 0; i < oldN; i++) {
			transfer(oldT[i]);
		}

		// 4. release the memory allocated to the old hashMap

		delete [] oldT;

	}

public :

	HashMap(int N = 5, double L = 0.7) {
		this->N = N;
		this->M = 0;
		this->L = L;

		T = new node*[N];
		for (int i = 0; i < N; i++) {
			T[i] = NULL;
		}
	}

	void insert(int K, int V) {

		// 1. transform the key into hash index using the hash function
		int hashIdx = hashFn(K);

		// 2. create a node with the given (K, V) pair and insert it at
		//    head of the linkedList stored at the hash index

		node* n = new node(K, V);

		// 3. update the pointer to the head of the linkedList stored at
		//    the hash index such that it holds the address of the newly
		//    created node

		n->next = T[hashIdx];
		T[hashIdx] = n;

		// 4. rehash, if loadFactor exceeds the loadFactor Threshold

		M++;
		double LF = (double)M / N;
		if (LF > L) {
			// rehash...
			cout << "rehasing due LF = " << LF << endl;
			rehash();
		}

	}

	node* find(int K) {

		// 1. transform the key into hash index using the hash function

		int hashIdx = hashFn(K);

		// 2. search for the node with the given key in the  linkedList
		//    stored at the hash index

		node* temp = T[hashIdx];
		while (temp != NULL) {
			if (temp->K == K) {
				break;
			}
			temp = temp->next;
		}

		return temp;


	}

	void erase(int K) {

		// 1. transform the key into hash index using the hash function

		int hashIdx = hashFn(K);

		// 2. delete the node with the given key from the linkedList
		//    stored at the hash index

		node* temp = T[hashIdx];
		if (temp == NULL) {
			// linkedList at hashIndex is empty
			return; // optional
		} else {
			// there is a non-empty linkedList at the hashIndex
			// so search for the node in it whose key matches the
			// given key and if you find such a node then delete it
			if (temp->K == K) {
				// delete at head
				node* n = temp;
				T[hashIdx] = temp->next;
				delete n;
				M--;
				return; // optional
			} else {
				node* prev = NULL;
				while (temp != NULL) {
					if (temp->K == K) {
						prev->next = temp->next;
						delete temp;
						M--;
						break;
					}
					prev = temp;
					temp = temp->next;
				}
			}
		}

	}

	void printLinkedList(node* head) {
		while (head) { // head != NULL
			cout << "(" << head->K << ", " << head->V << ") ";
			head = head->next;
		}
		cout << endl;
	}

	void printHashMap() {
		// iterate over buckets in the hashMap
		for (int i = 0; i < N; i++) {
			// print the linkedList stored ith bucket of the hashMap
			cout << i << " : ";
			printLinkedList(T[i]);
		}
		cout << endl;
	}

	int& operator[](int K) {
		node* n = find(K);
		if (n == NULL) {
			int garbage;
			insert(K, garbage);
			n = find(K);
		}
		return n->V;
	}
};

int main() {

	HashMap hm;

	hm.insert(3, 9);
	hm.insert(2, 4);
	hm.insert(7, 49);

	hm.printHashMap();

	hm.insert(5, 25);

	hm.printHashMap();

	int key = 7;

	node* n = hm.find(key);
	if (n == NULL) {
		cout << key << " is not present" << endl;
	} else {
		cout << n->V << endl;
	}

	hm.erase(key);

	hm.printHashMap();

	n = hm.find(key);
	if (n == NULL) {
		cout << key << " is not present" << endl;
	} else {
		cout << n->V << endl;
	}

	cout << hm[2] << endl; // exp. o/p : 4 // hm.operator[](2)
	cout << hm[5] << endl; // exp. o/p : 25 // hn.operator[](5)

	hm[2] = 0;
	// hm.operator[](2) = 0;

	cout << hm[2] << endl;

	hm[12] = 144;
	// hm.operator[](12) = 144;

	cout << hm[12] << endl;

	return 0;
}