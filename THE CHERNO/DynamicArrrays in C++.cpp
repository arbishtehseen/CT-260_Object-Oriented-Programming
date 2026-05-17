#include<iostream>
#include<vector>
using namespace std;

class Vertex{
	public:
		float x, y , z;
	
	friend ostream& operator<<(ostream& stream, const Vertex& temp);
	
};

ostream& operator<<(ostream& stream, const Vertex& temp)
{
	stream<< "("<<temp.x<<" , "<<temp.y<<" , "<<temp.z<<")"<<endl;
	return stream;
}

int main()
{
	/* array on stack. (we're stuck to the size 5)
	Vertex vertices[5];
	*/
	/* array on heap. (still we are stuck to size 5!)
	Vertex* vertices = new int[5];
	only 0 till 4 index can be accessed.
	
	Solution --> is using vector!(dynamic array).
	*/
	// vector<datatype> nameofarray
	vector<Vertex> vertices;
	vertices.push_back({1 , 2 , 3}); // push_back() means adding some element to the end of array.
	vertices.push_back({4 , 5 , 6});
	
	for(int i = 0; i < vertices.size() ; i++)
	{
		cout<< vertices[i];
	}
	
	// insted of using this for loop , we can also use, range based for loop.
	// as it is { Vertex v} , it copies each vertices, to avoid we can use Vertex&.
	
	//  vertices.erase( vertices.begin() + 1);
	
	for(Vertex& v : vertices)
	{
		cout<< v;
	}
	
	//  if we want to delete the entire array we can : 
	//  - vertices.clear();
	
	// we can remove individually.
	// - vertices.erase();
	// - vertices.erase( vertices.begin() + 1). { this will remove second element}.
	
	/* if storing pointers it'll look like dis.
	vector<Vertex*> vertices;
	*/
	
	/* 
	  whenever passing this kinda array anywhere, make sure to pass it by refrence like
	  vector<Vertex>& vertices;
	  or
	  const vector<Vertex>& vertices;
	
	
	
	*/
	
	
	
	
	return 0;
}