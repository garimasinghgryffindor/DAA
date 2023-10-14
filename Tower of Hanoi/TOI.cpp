long long toh(int N, int from, int to, int aux) {
    // Your code here
    if(N <= 0) return 0;
    long long res = 1;
    res += toh(N-1, from, aux, to);
    cout<<"move disk "<<N<<" from rod "<<from<<" to rod "<<to<<endl;
    res += toh(N-1,aux,to,from);
    return res;
}

