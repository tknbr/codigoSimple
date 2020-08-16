/**
 * Implemented by Arnau Bagó Castro
 *
 * Linkedin: https://es.linkedin.com/in/arnaubago
 * Github collection: https://github.com/tknbr/algorithms
 */

#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

/** merge
 *  v: vector to be sorted, passed by ref to avoid copy memory
 *  s: index inside v to start sorting
 *  e: index inside v to end sorting
 *  m: index inside v pointing to mid (division of both parts)
 */

void merge(vector<int> &v, unsigned int s, unsigned int e, unsigned int m){
    vector<int> l; // temp vector to store first half of v
    vector<int> r; // temp vector to store second half of v
    unsigned int it_v = s; // v iterator
    unsigned int it_l = 0; // left part iterator
    unsigned int it_r = 0; // right part iterator
    unsigned int n1 = m - s + 1; // size of left part
    unsigned int n2 = e - m; // size of right part


    // store first half in temp vector
    for(int i = 0; i < m - s + 1; ++i){
        l.push_back(v[s + i]);
    }

    // store second half in temp vector
    for(int i = 0; i < e - m; ++i) {
        r.push_back(v[m + 1 + i]);
    }

    // keep filling final vector with both sorted halfs
    while (it_l < n1 && it_r < n2) {
        if (l[it_l] <= r[it_r]) {
            v[it_v++] = l[it_l++];
        } else {
            v[it_v++] = r[it_r++];
        }
    }

    // fill with remains of left part
    while (it_l < n1) {
        v[it_v++] = l[it_l++];
    }

    // fill with remains of right part
    while (it_r < n2) {
        v[it_v++] = r[it_r++];
    }
}

/** merge sort
 *  v: vector to be sorted, passed by ref to avoid copy
 *  s: index inside v to start sorting
 *  e: index inside v to end sorting
 */
void merge_sort(vector<int> &v, unsigned int s, unsigned int e){
    // exit case?
    if(s < e) {
        // get mid point, implicit floor()
        unsigned int m = (s + e) / 2;
        // sort recursively first half
        merge_sort(v, s, m);
        // sort recursively second half
        merge_sort(v, m + 1, e);
        // merge both (sorted) parts
        merge(v, s, e, m);
    }
}

int main(){
    vector<int> vectorToSort;
    vectorToSort.push_back(23);
    vectorToSort.push_back(-2);
    vectorToSort.push_back(-99);
    vectorToSort.push_back(12);
    vectorToSort.push_back(3);
    vectorToSort.push_back(2);
    vectorToSort.push_back(-23);
    merge_sort(vectorToSort, 0, vectorToSort.size() - 1);
    for(int i = 0; i < vectorToSort.size(); ++i)
        cout << " " << vectorToSort[i];
    cout << endl;
}