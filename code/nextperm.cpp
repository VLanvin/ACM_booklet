// INPUT  a permutation (array) of length N
// OUTPUT true iff the next permutation has been succ. computed in the array

bool nextPermutation(int* perm) {
    int i = N - 1;
    while (i > 0 && perm[i - 1] >= perm[i])
        i--;
    
    if (i <= 0)
        return false;
    
    int j = N - 1;
    while (perm[j] <= perm[i - 1])
        j--;
    
    int temp = perm[i - 1];
    perm[i - 1] = perm[j];
    perm[j] = temp;
    
    j = N - 1;
    while (i < j) {
        temp = perm[i];
        perm[i] = perm[j];
        perm[j] = temp;
        i++;
        j--;
    }
    
    return true;
}
