#include "a.h"
int main(int argc,char *argv[]) {
    Option option;
    Printer printer;
    option.getOption(argc,argv);
#ifdef DEBUG_MODE
    option.printOption();
#endif

    initializing();
    vector<Data> datas, ans;

    return 0;
}
void initializing() {
    srand((unsigned)time(NULL));
}
uint calculateHammingDistance(Data& s1,Data& s2) {
    assert((int)s1.length() == (int)s2.length());
    uint ret = 0;
    for ( int i = 0 ; i < (int)s1.length() ; i++ ) 
        ret += (s1[i] != s2[i]);
    return ret;
}
char generateDifferentCharacter(char c,Option& option) {
    char ret;
    while ( (ret=(uint)rand()%option.cardinality)+'A' == c );
    return ret+'A';
}
Data generateDataPointWithDistance(Data data,int distance,Option& option) {
    Data ret = data;
    set<int> changedIndex;
    while ( distance-- ) {
        uint curIndex = (uint)rand()%option.dimension;
        while ( changedIndex.count(curIndex) != 0 ) 
            curIndex = (uint)rand()%option.dimension;
        changedIndex.insert(curIndex);
        ret[curIndex] = generateDifferentCharacter(ret[curIndex],option);
    }
    return ret;
}
Data generateDataPoint(Option& option) {
    Data ret = "";
    for ( int i = 0 ; i < option.dimension ; i++ ) 
        ret += (int)rand()%option.cardinality + 'A';
    return ret;
}
