#include <iostream>

#define ll unsigned long long
#define maxn 500005

int n;
int cnt;
int head[maxn], nxt[maxn], to[maxn],fa[maxn]; 
char ch[maxn];
int s[maxn], top;
ll contri[maxn], sum[maxn];

void addEdge(int u, int v)
{
    nxt[++cnt] = head[u];
    head[u] = cnt;
    to[cnt] = v;
}

void dfs(int i)
{
    int tmp = 0;
    if (ch[i] == '(')
    {
        s[++top] = i;
    }
    else
    {
        if (top)
        {
            tmp = s[top];
            contri[i] = contri[fa[tmp]] + 1;
            top --;
        }
    }
    sum[i] = sum[fa[i]] + contri[i];

    for (int x = head[i]; x; x = nxt[x])
    {
        dfs(to[x]);
    }
    if (tmp)
    {
        s[++top] = tmp;
    }
    else if (top)
    {
        top--;
    }

}

int main()
{
    std::cin >> n;
    std::cin >> (char*)(ch + 1);
    for (int i = 0; i < n - 1;i++)
    {
        int v = i + 2, u;
        std::cin >> u;
        addEdge(u, v);
        fa[v] = u;
    }
    dfs(1);
    ll res = 0;
    for (ll i = 1; i <= n; i++)
    {
        res ^= i * sum[i]; 
    }
    std::cout << res;
    return 0;
} 