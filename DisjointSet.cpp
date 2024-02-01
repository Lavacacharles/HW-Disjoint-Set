#include <iostream>
#include <vector>

using namespace std;
// implementar DisjointSet
class DisjointSet{
private:
    vector<int> parent;
    vector<int> rank;
    int n;

public:
    DisjointSet(int n){
        this->n = n;
        parent.resize(n);
        rank.resize(n);
        for(int i = 0; i < n; i++){
            parent[i] = i;
            rank[i] = 0;
        }
    }
    // Find with no rank
    int find(int x){
        if(parent[x] != x){
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    // Union with no rank
    void Union(int x, int y){
        int rootX = find(x);
        int rootY = find(y);
        if(rootX != rootY){
            parent[rootX] = rootY;
        }
    }

    // Find with rank
    int FindR(int x){
        if(parent[x] != x){
            parent[x] = FindR(parent[x]);
        }
        return parent[x];
    }

    // Union with rank
    void UnionR(int x, int y){
        int rootX = FindR(x);
        int rootY = FindR(y);
        if(rootX != rootY){
            if(rank[rootX] > rank[rootY]){
                parent[rootY] = rootX;
            }else if(rank[rootX] < rank[rootY]){
                parent[rootX] = rootY;
            }else{
                parent[rootX] = rootY;
                rank[rootY]++;
            }
        }
    }
};


int main(){
// Prueba pequeña para comprobar el disjoin set
    DisjointSet ds(5);
    ds.UnionR(0, 2);
    ds.UnionR(4, 2);
    ds.UnionR(3, 1);
    for(int i = 0; i < 5; i++){
        cout << ds.FindR(i) << " ";
    }
    cout << endl;
    return 0;
}
