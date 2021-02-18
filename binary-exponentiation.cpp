typedef long long int ll;

ll binpow( ll a, ll b)
{
	if( !b) return 1;
	ll res = binpow(a, b/2);
	if( b % 2 )
		return res*res*a;
	else 
		return res*res;
}