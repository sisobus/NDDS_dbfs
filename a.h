#include <cstdio>
#include <queue>
#include <ctime>
#include <cassert>
#include <cstdlib>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;
#define DEBUG_MODE

#define DEFAULT_DIMENSION       40
#define DEFAULT_NUMBER_OF_VP    15
#define DEFAULT_CARDINALITY     10
#define PARAMETER_DIMENSION     "-d"
#define PARAMETER_NUMBER_OF_VP  "-m"
#define PARAMETER_CARDINALITY   "-a"
#define PARAMETER_HELP          "-h"
#define HELP_MESSAGE            "help] ./run -d dimension(40) -m number_of_vp(15) -a cardinality(10)"
typedef unsigned int uint;
typedef string Data;

class Option {
public:
    uint dimension;
    uint numberOfVP;
    uint cardinality;
    Option():
        dimension(DEFAULT_DIMENSION),
        numberOfVP(DEFAULT_NUMBER_OF_VP),
        cardinality(DEFAULT_CARDINALITY){}
    void getOption(int argc,char* argv[]) {
        if ( argc == 1 ) {
            puts(HELP_MESSAGE);
            exit(-1);
        }
        for ( int i = 0 ; i < argc ; i++ ) {
            if ( string(argv[i]) == PARAMETER_HELP ) {
                puts(HELP_MESSAGE);
                exit(-1);
            }
            if ( string(argv[i]) == PARAMETER_DIMENSION ) {
                sscanf(argv[i+1],"%u",&this->dimension);
                i++;
            }
            if ( string(argv[i]) == PARAMETER_NUMBER_OF_VP ) {
                sscanf(argv[i+1],"%u",&this->numberOfVP);
                i++;
            }
            if ( string(argv[i]) == PARAMETER_CARDINALITY ) {
                sscanf(argv[i+1],"%u",&this->cardinality);
                i++;
            }
        }
    }
    void printOption() {
        printf("dim : %u | numberOfVP : %u | cardinality : %u\n",
                this->dimension,this->numberOfVP,this->cardinality);
    }
};
class Printer {
public:
    void print(string message,int a) {
        printf("%s %d\n",message.c_str(),a);
    }
    void print(string message,uint a) {
        printf("%s %u\n",message.c_str(),a);
    }
    void print(string message,string s) {
        printf("%s %s\n",message.c_str(),s.c_str());
    }
    void print(string message,double d) {
        printf("%s %lf\n",message.c_str(),d);
    }
    void print(string message,float f) {
        printf("%s %f\n",message.c_str(),f);
    }
    void print(string message,char *s) {
        printf("%s %s\n",message.c_str(),s);
    }
};

void initializing();
uint calculateHammingDistance(Data& s1,Data& s2);
char generateDifferentCharacter(char c,Option& option);
Data generateDataPointWithDistance(Data data,int distance,Option& option);
Data generateDataPoint(Option& option);
void dfs(vector<Data>& datas,vector<Data>& ans,Option& option);
