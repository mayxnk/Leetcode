class Solution {
public:
    int solve(int tl,int tr,int br,int bl,int p,int rayDist,int q)
    {
        if(rayDist == p)
            return tr;
        if(rayDist == 0)
            return br;
        if((long)rayDist*2 <= p)
            return solve(tr,tl,br,bl,p,rayDist+q,q);
        else
            return solve(tr,tl,br,bl,p,rayDist-q+p,q);
    }
    int mirrorReflection(int p, int q) 
    {
        // int tl = 2,tr = 1,br = 0,bl = -1;
        // return solve(tl,tr,br,bl,p,q,q);
        while (p % 2 == 0 && q % 2 == 0)
        { 
            p/=2;
            q/=2;
        }
        return 1 - p % 2 + q % 2;
    }
};