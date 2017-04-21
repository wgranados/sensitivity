#include <bits/stdc++.h>
#define MAXBITS 12
#define len(x) (int)(x).size()
using namespace std;

typedef unordered_map< bitset<MAXBITS>, vector< bitset<MAXBITS> > > State;


/**
 * Prints instructions for usage of programming to standard out.
 **/
void usage(){
    cout << "Usage:\n\tsim N K [LOG]\n";
    cout << "\tN - number to create a superset on in base 10 and greater than 0\n";
    cout << "\tK - maximum number of neighbours each element can have\n";
    cout << "\tLOG - optional, print the game to standard out, pass in as yes\n";
}

/**
 * Determine if two bitsets a,b differ by at most one bit.
 **/
bool differ_by_one_bit(const bitset<MAXBITS>&a, const bitset<MAXBITS>&b){
    int cnt = 0;
    for(int i = 0;i < MAXBITS;i++){
        if(a[i] != b[i]){
            cnt++;
        }
    }
    return cnt == 1;
}


/**
 * Prints out the adjacency list representation of the State object.
 **/
void print_state(const State &st){
    for(auto it: st){
        bitset<MAXBITS>node = it.first;
        vector< bitset<MAXBITS> >edges = it.second;
        cout << "node " << node.to_string() << ":";
        for(auto &adj_node: edges){
            cout << adj_node.to_string() << " ";
        }
        cout << "\n";
    }
}


/**
 * Obtain the argument values N and K from arguments pass to the program,
 * then stores it in the respective variables. Returns a 0 on successful validation of
 * input, -1 otherwise.
 **/
int get_nk(char **argv, int *N, int *K){
    string arg_one(argv[1]);
    string arg_two(argv[2]);
    stringstream ss;
    ss << arg_one;
    ss >> *N;
    if(!ss){
        return -1;
    }
    ss.clear();
    ss << arg_two;
    ss >> *K;
    if(!ss){
        return -1;
    }
    return 0;
}


/**
 * Determines if there exists an optimal strategy on this subgraph.
 */
bool optimal_strategy(const State &st){
    return false;
}

void simulate(const int &N, const int &K){
    bitset<MAXBITS>start;
    State start_adj;
    queue< State >q;
    start_adj[start] = vector< bitset<MAXBITS> >();
    q.push(start_adj);
    while(!q.empty()){
        State st = q.front();
        q.pop();
        if(optimal_strategy(st)){
            printf("Subgraph found\n");
            print_state(st);
            return;
        }
        for(auto it: st){
            bitset<MAXBITS>node = it.first;
            vector< bitset<MAXBITS> >edges = it.second;
            // check if the flipped node is already in our 
            for(int i = 0;i < N;i++){
                node[i] = ~node[i];
                if(!st.count(node)){
                    // determine all nodes which differ by one bit with
                    // new node we're going to add and determine if once
                    // this node is added if the graph is still maximal K
                    bool valid = true;
                    for(auto jt:st){
                        bitset<MAXBITS>node2 = jt.first;
                        if(differ_by_one_bit(node, node2)
                                && len(st[node]) +1 >= K ){
                            valid = false;
                            break;
                        }
                    }
                    if(valid){
                        // now add edges for nodes which differ by one bti
                        // with the new node we're adding to the graph
                        State st_cpy = st;
                        st_cpy[node] = vector< bitset<MAXBITS> >();
                        for(auto jt:st_cpy){
                            bitset<MAXBITS>node2 = jt.first;
                            if(differ_by_one_bit(node, node2)){
                                st_cpy[node].push_back(node2);
                                st_cpy[node2].push_back(node);
                            }
                        }
                        q.push(st_cpy);
                    }
                }
                node[i] = ~node[i];
            }
        }
    } 
}

int main(int argc, char**argv) {
    if(argc <= 1 or argc > 3){
        usage();
        exit(1);
    }else{
        int N, K;
        int result = get_nk(argv, &N, &K);
        if(result < 0){
            usage();
            exit(1);
        }else{
            simulate(N, K);
        }
    }
    return 0;
}
