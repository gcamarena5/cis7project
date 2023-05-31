#include <iostream>

using namespace std;
//validation function
bool isValid(int choice)
{
  bool valid = false;
  if (choice <= 5 && choice > 0)
  {
    valid = true;
  }
  return valid;
}
//route struct
 struct Route
{
int first, second, third, fourth, totaldistance;
};
// edge struct to hold variables
struct Edge 
{
  int source, destination, distance;
};
// nodes
struct Node {
  Node *next;
  int distance;
  int des;
}; 

// graph class
//==================================================
class Graph {
  Node *adjListNode(int destination, int distance, Node *head) { //add a node function
    Node *newNode = new Node;
    newNode->des = destination;
    newNode->distance = distance;

    newNode->next = head;

    return newNode;
  }

  int N; // num of nodes

public:
  Node **head;
  Graph(Edge edges[], int n, int N) {

    // constructoR
    head = new Node *[N]();
    this->N = N;

    for (int i = 0; i < N; ++i) // INITALIZING all vertices to null
    {
      head[i] = nullptr;
    }

    // add edges to the graph
    for (unsigned i = 0; i < n; i++) {
      int src = edges[i].source;
      int dest = edges[i].destination;
      int weight = edges[i].distance;

      // insert in the beginning
      Node *newNode = adjListNode(dest, weight, head[src]);

      // point head pointer to new node
      head[src] = newNode;
    };
  };
  ~Graph() {
    
    for (int i = 0; i < N; i++) {
      delete[] head[i];
    }
    delete[] head;
  }
};
//==================================================
//print the list
void printList(Node *ptr, int i) {
  while (ptr != nullptr) {
    
    cout << "(" << i << ", " << ptr->des << ", " << ptr->distance << " miles ) ";

    ptr = ptr->next;
  }

  cout << endl;
}
//===============================================================
//display functions
int displayMenu(int &choice);
void displayRoutes();
void displayShortest();
void displayEdges();
void displayAdjs();
//============================================================

int main() {
  int  choice;
  
  cout << "Welcome to Greg's solar sales program! Providing nothing "
       << "but the best for the I.E." << endl;
do{
  
  displayMenu(choice);
  while(!isValid(choice))
  {
    cout << "The option you have entered was not correct. Please try again!" << endl;
    cin >> choice;
  }
  if(choice == 1) // display routes
  {
    displayRoutes();
  }
  
  else if (choice == 2) // display shortest trips
  {
    displayShortest();
  }
  
  else if(choice == 3) //display edges
  {
    displayEdges();   
  }  
  else if (choice == 4) //display adjaceny matrix
  {
    displayAdjs();
  }
}while(choice != 5);
  cout << "Thank you for using the program!";
  return 0;
}
//==========================================================================
int displayMenu(int &choice)
{
  cout << "Please chose from the following options: " << endl;
  cout << "1) Routes + cheapest trip" << endl;
  cout << "2) Shortest paths" << endl;
  cout << "3) Connecting cities - edges" << endl;
  cout << "4) Map - adjacency" << endl;
  cout << "5) Exit" << endl;
  cin >> choice;
  return choice;
}
//==========================================================================
void displayRoutes()
{
  int R = 5;
    int lowIndex = 0;
    Route routes[]
    {
      {1,2,3,4, 72}, {1,2,4,3, 64}, {1,3,2,4, 77},{1,4,2,3,68 },{1,4,3,2,80}
    };
    
    cout << "Riverside = 1\nMoreno Valley = 2\nHemet = 3\nPerris = 4" << endl;
    cout << "Possible routes starting from Riverside include: " << endl;
   
    
    for(int i = 0; i < R; i++)
      {
        cout << routes[i].first << " -> "  << routes[i].second << " -> " 
           << routes[i].third << " -> "  << routes[i].fourth << " Route total distance " <<     
            routes[i].totaldistance <<endl; 
        if(routes[lowIndex].totaldistance > routes[i].totaldistance)
        {
          lowIndex = i;
        }
      }
 cout << "The cheapest trip starting from Riverside would be the following: " << endl;
    cout << routes[lowIndex].first << " -> "  << routes[lowIndex].second << " -> " 
           << routes[lowIndex].third << " -> "  << routes[lowIndex].fourth << endl; 
    cout << "With a total distance of  " << routes[lowIndex].totaldistance <<endl;
}
//===================================================================
void displayShortest() 
{
  int p = 3;
  int lowest = 0;
  Edge shortest[]{{1,2, 16}, {1,3, 33}, {1,4, 24}};
  
  cout << "Riverside = 1\nMoreno Valley = 2\nHemet = 3\nPerris = 4" << endl;
  cout << "The shortest paths to each city starting from Riverside would be as follows: " << endl;
  for(int i = 0; i < p; i++)
    {
      cout << shortest[i].source << " -> " << shortest[i].destination << " with a distance of " << shortest[i].distance << endl;
      if (shortest[lowest].distance > shortest[i].distance)
      {
          lowest = i;
      }
    }
  cout << "The shortest possible path from Riverside is: " << shortest[lowest].source << " -> " << shortest[lowest].destination
      << " with a distance of " << shortest[lowest].distance << endl;
  
}
//======================================================
void displayEdges()
{
  int e = 4;
   cout << "Riverside = 1\nMoreno Valley = 2\nHemet = 3\nPerris = 4" << endl;
  cout << "Connecting cities include: " << endl;
    Edge connections[]
    {
      {1,2}, {1,3}, {1,4}, {3,4}
    };

    
    for (int i = 0; i < e; i++)
      {
        cout << connections[i].source << " -> " << connections[i].destination << endl;
      };
}
//========================================================================
void displayAdjs()
{
  int v, V;
  V = 5;
  Edge edges[] = {// riverside = 1
                  // moreno valley = 2
                  // hemet = 3
                  // perris = 4
                  {1, 2, 16}, {1, 3, 33}, {1, 4, 24}, {2, 1, 16},
                  {2, 3, 26}, {2, 4, 18}, {3, 1, 33}, {3, 2, 26},
                  {3, 4, 30}, {4, 1, 24}, {4, 2, 18}, {4, 3, 30}};
  v = sizeof(edges) / sizeof(edges[0]);
  Graph graph(edges, v, V);
    cout << "Riverside = 1\nMoreno Valley = 2\nHemet = 3\nPerris = 4" << endl;
  // print adjacency list representation of graph
  for (int i = 0; i < V; i++) 
  {
    // print all neighboring vertices of vertex i
    printList(graph.head[i], i);
  }
}
//=========================================================================
