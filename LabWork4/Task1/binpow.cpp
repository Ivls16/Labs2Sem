int binpow(int a, int n, int mod) {
    if (n == 1) {
        return a % mod;
    }
    if (n & 1) {
        return (int)(1ll * binpow(a, n - 1, mod) * a % mod);
    }
    int b = (int)(1ll * binpow(a, n / 2, mod));
    return b * b % mod;
}