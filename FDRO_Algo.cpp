// 22I2003                22I1899             DS-B        Project
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

class Queue
{
    int* arr;
    int cap;
    int front;
    int rear;
    int count;

public:
    // Constructor
    Queue(int size) : cap(size), front(0), rear(-1), count(0)
    {
    
        arr = new int[size];
    
    }

    // Destructor
    ~Queue()
    {
    
        delete[] arr;
    
    }

    // Enqueue operation
    void enqueue(int item)
    {
        if (isFull()) 
        {
        
            cerr << "Queue is already full" << endl;
            return;
        
        }
        
        rear = (rear + 1) % cap;
        arr[rear] = item;
        count++;
    
    }

    // Dequeue operation
    int dequeue()
    {
        if (isEmpty()) 
        {
        
            cerr << "Queue underflow " << endl;
            return -1;
        
        }
        
        int item = arr[front];
        front = (front + 1) % cap;
        count--;
        return item;
    
    }

    // Check if the queue is empty
    bool isEmpty()
    {
    
        return count == 0;
    
    }

    // Check if the queue is full
    bool isFull()
    {
    
        return count == cap;
    
    }

};

class Graph
{
    int size;
    int** paths;

public:
    // Constructor
    Graph(int n) : size(n)
    {
    
        paths = new int* [n * n];       // To represent the grid
        for (int i = 0; i < n * n; i++)
        {
    
            paths[i] = new int[4];
            memset(paths[i], -1, 4 * sizeof(int));
    
        }
        for (int i = 0; i < n * n; i++)
        {
    
            int r = i / n;      //To calculate the row r 
            int c = i % n;      //To calculate the column c 

            // To check validity
            if (c < n - 1) paths[i][0] = i + 1; // right
            if (c > 0) paths[i][1] = i - 1;     // left
            if (r > 0) paths[i][2] = i - n;     // above
            if (r < n - 1) paths[i][3] = i + n; // below
    
        }
    
    }

    // Destructor
    ~Graph()
    {
    
        for (int i = 0; i < size * size; i++)
        {
    
            delete[] paths[i];
    
        }
        delete[] paths;
    
    }

    // Breadth-first search algorithm
    int BFS(int start, int* dest_order, int* time_lim, int orders, const string& res_name)
    {

        bool* nodes_visited = new bool[size * size];

        int* dist = new int[size * size];

        int* path = new int[size * size];

        memset(nodes_visited, false, size * size * sizeof(bool));

        memset(dist, -1, size * size * sizeof(int));

        memset(path, -1, size * size * sizeof(int));
        Queue queue(size * size);


        nodes_visited[start] = true;


        dist[start] = 0;

        path[start] = start;

        queue.enqueue(start);

        while (!queue.isEmpty())

        {
    
            int node = queue.dequeue();
            for (int i = 0; i < 4; i++)
            {
    
                int adjacency = paths[node][i];
                if (adjacency != -1 && !nodes_visited[adjacency])
                {
    
                    nodes_visited[adjacency] = true;
                    dist[adjacency] = dist[node] + 1;
                    path[adjacency] = node;
                    queue.enqueue(adjacency);
    
                }
    
            }
    
        }
    
        int* newpath = path;
        for (int i = 0; i < 15; i++)
        {
    
            newpath[i] = path[15 - i];
    
        }
        int totalTime = 0;
        cout << res_name << " Route : ";


        // Process each order
        for (int i = 0; i < orders; i++)
        {
    
            // Get the current destination
            int current = dest_order[i];

            int pathLength = 0;


            cout << current << " ";

            // Trace back the shortest path from destination to start
            while (current != start && current != -1)
            {

                // Increment the path length
                pathLength++;

                // Move to the previous node in the path
                current = newpath[current];
                cout << " -> " << current;

            }
            if (dist[dest_order[i]] == -1)
            {
            
                cout << "( Infinity time units )" << endl;
            
            }


            else
            {
            
                cout << "( " << dist[dest_order[i]] << " time units )" << endl;
            
            }

            // failed to find a valid path
            if (dist[dest_order[i]] == -1 || pathLength > time_lim[i])
            {
            
                delete[] nodes_visited;
                delete[] dist;
                delete[] path;
                return -1;
            
            }
            totalTime += pathLength;
        
        }


        cout << "Total time for " << res_name << ": " << totalTime << " time units " << endl;


        delete[] nodes_visited;
        delete[] dist;
        delete[] path;

        return totalTime;
    
    }


    // Display the grid
    void displaygrid()
    {
    
        cout << "Graph" << endl;
        int num = 1;
        for (int i = 1; i <= size; ++i)
        {
    
            for (int j = 1; j <= size; ++j)
            {
    
                if (num <= size * size)
                {
    
                    if (num < 10)
                    {
    
                        cout << " ";
    
                    }
                    cout << num;

                    if (j != size)
                    {
    
                        cout << "--";
    
                    }
                    num++;
    
                }
    
            }
            cout << endl;
            for (int k = 1; k <= size; ++k)
            {
    
                if (i != size)
                    cout << " |  ";
    
            }
            cout << endl;
    
        }
    
    }

};

int main() 
{

    ifstream file("test_cases.txt");
    if (!file)

    {

        cerr << "Cannot open file" << endl;
        return 1;

    }

    int tc;
    file >> tc;

    for (int t = 0; t < tc; ++t) 
    {
    
        int n, i, r;
        file >> n >> i >> r;

        Graph graph(n);

        int min_time = 0;
        cout << "Test Case " << t + 1 <<": "<< endl;

        graph.displaygrid();

        while (r--)
        {
    
            string res_name;

            int location, orders;

            file >> res_name >> location >> orders;

            int* dest_order = new int[orders];

            int* time_lim = new int[orders];

            for (int o = 0; o < orders; o++)
            {
    
                string name_order;
                int dest, time_req;
                file >> name_order >> dest >> time_req;

                dest_order[o] = dest;
                time_lim[o] = time_req;
    
            }

            int result = graph.BFS(location, dest_order, time_lim, orders, res_name);

            if (result == -1)
            {
    
                min_time = -1;
                break;
    
            }


            min_time += result;
            delete[] dest_order;
            delete[] time_lim;
    
        }

        if (min_time != -1)
        {
    
            cout << "Total minimum time required for this test case: " << min_time << " units" << endl;
            cout << "\n";
        }
        else
        {
        
            cout << "Some orders are unreachable or cannot be delivered within the time constraints." << endl;
            cout << "\n";
        }

        cout << endl;
    
    }

    file.close();
    return 0;

}