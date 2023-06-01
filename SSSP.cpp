#include<iostream>
#include<vector>
#include<climits>
using namespace std;

float averages[6];

int miniDist(int distance[], bool Tset[]) // finding minimum distance
{
    int minimum = INT_MAX, ind;          
    for(int k=0;k<6;k++) 
    {
        if(Tset[k]==false && distance[k]<=minimum)      
        {
            minimum=distance[k];
            ind=k;
        }
    }
    return ind;
}

void DijkstraAlgo(int graph[6][6],int src) // adjacency matrix 
{
    int distance[6];        // array to calculate the minimum distance for each node                             
    bool Tset[6];           //boolean array to mark visited and unvisited for each node
    
     
    for(int k = 0; k < 6; k++)
    {
        distance[k] = INT_MAX;
        Tset[k] = false;    
    }
    
    distance[src] = 0;   // Source vertex distance is set 0               
    
    for(int k = 0; k<6; k++)                           
    {
        int m = miniDist(distance,Tset); 
        Tset[m]=true;
        for(int k = 0; k<6; k++)                  
        {
            // updating the distance of neighbouring vertex
            if(!Tset[k] && graph[m][k] && distance[m]!= INT_MAX && distance[m]+graph[m][k]<distance[k])
                distance[k]=distance[m]+graph[m][k];
        }
    }
    cout<<"Shortest distances from source vertex " << src <<endl;
    for(int k = 0; k<6; k++)                      
    { 
        cout<< "Distance of node "<< k << " - " <<distance[k]<<endl;
    }
    int sum = 0;
    float average;
    for(int i = 0; i < 6; i++){
        sum = sum + distance[i];
    }
    average = (float)sum/5;
    averages[src] = average;
}


int main() {
    int edgeList[6][6] = {
        {0, 10, 0, 0, 15, 5}, 
        {10, 0, 10, 30, 0, 0},
        {0, 10, 0, 12, 5, 0},
        {0, 30, 12, 0, 0, 20},
        {15, 0, 5, 0, 0, 0},
        {5, 0, 0, 20, 0, 0}
    };

    for(int k = 0; k < 6; k++){
        DijkstraAlgo(edgeList, k);
        cout << "The Average from city "<< k << " is - "<< averages[k] << endl;
        cout << endl;
    }

    cout << "The cities with there average time" << endl;
    for(int k = 0; k < 6; k++){
        cout << "The Average from city "<< k << " is - "<< averages[k] << endl;
    }

    cout << "\nBest city/ies to build a hospital is/are " << endl;
    float min = averages[0] ;
    for(int i = 0 ; i < 6; i++) {
        if(min > averages[i])
            min = averages[i];
    }

    for(int i = 0 ; i < 6; i++) {
        if(min == averages[i])
            cout << "City " << i << " - " << averages[i] << endl; 
    }
}
