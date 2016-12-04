list<int> gen_unirandint(int N, int L, int R) {
    list<int> numbers;
    random_device rd;
    mt19937 rng(rd());    
    uniform_int_distribution<int> uni(L,R);
    for (int i = 0; i < N; i++) {
        numbers.push_back(uni(rng));
    }
    return numbers;
}

list<double> gen_unirandreal(int N, int L, int R) {
    list<double> numbers;
    mt19937_64 rng;
    uint64_t timeSeed = high_resolution_clock::now().time_since_epoch().count();
    seed_seq ss{uint32_t(timeSeed & 0xffffffff), uint32_t(timeSeed>>32)};
    rng.seed(ss);
    std::uniform_real_distribution<double> uni(L, R);
    for (int i = 0; i < N; i++) {
        numbers.push_back(uni(rng));
    }
    return numbers;
}