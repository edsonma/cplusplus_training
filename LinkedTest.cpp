/*
 * 
 * Testando abordagem OO de linkedlist
 *
 */


#include <iostream>

using namespace std;

enum { kIgual, kMaior, kMenor };


/* Data class containing data values of linked list */

// interface
class Data{

	public:
		// Constructors and SeekDestroy!
		Data(int val);
		~Data() {};

		// Accessors
		int getValue() const;
		void setValue(int val);

		// Misc Methods
		int compare(const Data & otherData);
		void show();

	private:
		int myValue;
};

// Constructors implementation
Data::Data(int val):
	myValue(val) {
};

// Accessors implementation
int Data::getValue() const{
	return myValue;
};

void Data::setValue(int val){
	myValue=val;
};

// Misc Methods implementation
int Data::compare(const Data & otherData){
	if(myValue < otherData.getValue()){
		return kMenor;
	}else if(myValue > otherData.getValue()){
		return kMaior;
	}else{
		return kIgual;
	}
};

void Data::show() {
	cout << myValue << endl;
};

/* ================================================= */

// Abstract Node Class
class Node{
	public:
		Node(){};
		virtual ~Node(){};
		virtual Node * insert(Data *theData)=0;
		virtual void show() = 0;
	private:
};

class InternalNode: public Node{
	public:
		InternalNode(Data *theData, Node *next);

		~InternalNode() { 
			delete myNext; 
			delete myData; 
		};

		virtual Node * insert(Data *theData);

		virtual void show(){ 
			myData->show(); 
			myNext->show(); 
		}

	private:
		Data * myData;
		Node * myNext;
};

InternalNode::InternalNode(Data *theData, Node *next):
	myData(theData), 
	myNext(next){
	
};

Node* InternalNode::insert(Data *theData){

	int result = myData->compare(*theData);
	
	switch(result){
		case kIgual:
		case kMaior:{
			InternalNode *dataNode = new InternalNode(theData, this);
			return dataNode;
		}
		case kMenor:{
			myNext = myNext->insert(theData);
			return this;
		}
	}

	return this;
};


class TailNode : public Node{
	public:
		TailNode(){};
		~TailNode(){};
		virtual Node * insert(Data *theData);
		virtual void show() { };
	private:
};

Node* TailNode::insert(Data *theData){
	InternalNode *dataNode = new InternalNode(theData, this);
	return dataNode;	
}

class HeadNode: public Node{
	public:
		HeadNode();
		~HeadNode(){ delete myNext; };
		
		virtual Node * insert(Data *theData);
		virtual void show() { myNext->show(); };

	private:
		Node *myNext;
};

HeadNode::HeadNode(){
	myNext = new TailNode;
}

Node * HeadNode::insert(Data *theData){
	myNext = myNext->insert(theData);
	return this;
}

class LinkedList{
    public:
        LinkedList();
        ~LinkedList() { delete myHead; }
        void insert(Data *theData);
        void showAll() { myHead ->show(); }
    private:
        HeadNode *myHead;
};

LinkedList::LinkedList(){
    myHead = new HeadNode;
}

void LinkedList::insert(Data *pData){
    myHead->insert(pData);
}

int main(){
    Data *pData;
    int val;

    LinkedList ll;

    for(;;){
        cout << "What value? (0 to stop): ";
        cin >> val;

        if(!val) 
            break;

        pData = new Data(val);
        ll.insert(pData);

        ll.showAll();


    }

	return 0;
}


