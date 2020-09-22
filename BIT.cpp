ll bit[MAXN];

void updt(int x, int val)
{
	for(; x<=n; x += x&(-x))
		bit[x] += val;
}

ll query(int x)
{
	ll ans = 0 ;
	for(; ~x+1; x -= x&(-x))
		ans += bit[x];
	return ans;
}
