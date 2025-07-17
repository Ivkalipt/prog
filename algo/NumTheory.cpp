//Кол-во делителей
int cntd(ll n) {
    if(n == 1) return 1;
    ll cnt = 2;
    ll i = 2;
    while (i * i < n) {
        if (n % i == 0) {
            cnt += 2;
        }
        i += 1;
    }
    if (i * i == n) {
        cnt += 1;
    }
    return cnt;
}

// Факторизация
vector<int> factorize(int x) {
    vector<int> factors;

    for (int i = 2; i <= sqrt(x); i++) {
        while (x % i == 0) {
            factors.push_back(i);
            x /= i;
        }
    }

    if (x > 1) {
        factors.push_back(x);
    }

    return factors;
}

// Решето
fastio;
    ll m, n;
    bool flag = 0;
    cin >> m >> n;
    vll primes(n+1);
    for (int i = 0; i < n + 1; i++) primes[i] = i;
    for(ll i = 2; i <= n; i++) {
        if(!primes[i]) continue;
        for(ll j = i*i; j <= n; j+= i) primes[j] = 0;

    }

// Простота
bool isPrime(ll n) {
    for (ll i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}
