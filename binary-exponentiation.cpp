ll bpow( ll a, ll b)
{
	if( !b) return 0;
	ll res = binpow(a, b/2);
	if( b % 2 )
		return res*res*a;
	else return res*res;
}