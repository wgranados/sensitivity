#include <bits/stdc++.h>
#define MAXBITS 12
using namespace std;

void usage(){
    printf("Usage:\n\tsim N K [LOG]\n");
    printf("\tN - number to create a superset on in base 10 and greater than 0\n");
    printf("\tK - maximum number of neighbours each element can have\n");
    printf("\tLOG - optional, print the game to standard out, pass in as yes\n");
}

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


void simulate(int N, int K){
    typedef unordered_map< bitset<MAXBITS>, vector< bitset<MAXBITS> > > State;
    bitset<MAXBITS>start;
    State start_adj;
    queue< State >q;
    start_adj[start] = vector< bitset<MAXBITS> >();
    q.push(start_adj);
    while(!q.empty()){
        State st = q.front();
        q.pop();
        for(auto it: st){
            bitset<MAXBITS>node = it.first;
            vector< bitset<MAXBITS> >sub_graph = it.second;

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
